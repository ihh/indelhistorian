#include <fstream>
#include <random>
#include "recon.h"
#include "util.h"
#include "forward.h"
#include "jsonutil.h"
#include "logger.h"

Reconstructor::Reconstructor()
  : profileSamples (100),
    profileNodeLimit (0),
    includeBestTraceInProfile (true),
    rndSeed (ForwardMatrix::random_engine::default_seed),
    tree (NULL),
    maxDistanceFromGuide (10)
{ }

Reconstructor::~Reconstructor()
{
  if (tree)
    kn_free (tree);
}

bool Reconstructor::parseReconArgs (deque<string>& argvec) {
  if (argvec.size()) {
    const string& arg = argvec[0];
    if (arg == "-tree") {
      Require (argvec.size() > 1, "%s must have an argument", arg.c_str());
      treeFilename = argvec[1];
      argvec.pop_front();
      argvec.pop_front();
      return true;

    } else if (arg == "-model") {
      Require (argvec.size() > 1, "%s must have an argument", arg.c_str());
      modelFilename = argvec[1];
      argvec.pop_front();
      argvec.pop_front();
      return true;

    } else if (arg == "-seqs") {
      Require (argvec.size() > 1, "%s must have an argument", arg.c_str());
      Require (guideFilename.size() == 0, "Can't specify both -guide and -seqs");
      seqsFilename = argvec[1];
      argvec.pop_front();
      argvec.pop_front();
      return true;

    } else if (arg == "-guide") {
      Require (argvec.size() > 1, "%s must have an argument", arg.c_str());
      Require (seqsFilename.size() == 0, "Can't specify both -seqs and -guide");
      guideFilename = argvec[1];
      argvec.pop_front();
      argvec.pop_front();
      return true;

    } else if (arg == "-band") {
      Require (argvec.size() > 1, "%s must have an argument", arg.c_str());
      maxDistanceFromGuide = atoi (argvec[1].c_str());
      argvec.pop_front();
      argvec.pop_front();
      return true;

    } else if (arg == "-samples") {
      Require (argvec.size() > 1, "%s must have an argument", arg.c_str());
      profileSamples = atoi (argvec[1].c_str());
      argvec.pop_front();
      argvec.pop_front();
      return true;

    } else if (arg == "-allrandom") {
      includeBestTraceInProfile = false;
      argvec.pop_front();
      return true;

    } else if (arg == "-seed") {
      Require (argvec.size() > 1, "%s must have an argument", arg.c_str());
      rndSeed = atoi (argvec[1].c_str());
      argvec.pop_front();
      argvec.pop_front();
      return true;
    }
  }
  
  return false;
}

Alignment Reconstructor::loadFilesAndReconstruct() {
  Require (seqsFilename.size() > 0 || guideFilename.size() > 0, "Must specify sequences");
  Require (treeFilename.size() > 0, "Must specify a tree");
  Require (modelFilename.size() > 0, "Must specify an evolutionary model");

  ifstream treeFile (treeFilename);
  tree = kn_parse (JsonUtil::readStringFromStream (treeFile).c_str());

  if (seqsFilename.size()) {
    seqs = readFastSeqs (seqsFilename.c_str());
  } else {
    const vguard<FastSeq> gapped = readFastSeqs (guideFilename.c_str());
    const Alignment align (gapped);
    guide = align.path;
    seqs = align.ungapped;
  }

  ifstream modelFile (modelFilename);
  ParsedJson pj (modelFile);
  model.read (pj.value);

  buildIndices();
  return reconstruct();
}

void Reconstructor::buildIndices() {
  for (size_t n = 0; n < seqs.size(); ++n) {
    Assert (seqIndex.find (seqs[n].name) == seqIndex.end(), "Duplicate sequence name %s", seqs[n].name.c_str());
    seqIndex[seqs[n].name] = n;
  }

  for (int node = 0; node < nodes(); ++node)
    if (!isLeaf(node))
      Assert (nChildren(node) == 2, "Tree is not binary: node %d has %s\nSubtree rooted at %d: %s\n", node, plural(nChildren(node),"child","children").c_str(), node, treeString(node).c_str());

  AlignPath reorderedGuide;
  for (int node = 0; node < nodes(); ++node)
    if (isLeaf(node)) {
      Assert (nodeName(node).length() > 0, "Leaf node %d is unnamed", node);
      Assert (seqIndex.find (nodeName(node)) != seqIndex.end(), "Can't find sequence for leaf node %s", nodeName(node).c_str());
      const size_t seqidx = seqIndex[nodeName(node)];
      nodeToSeqIndex[node] = seqidx;

      if (!guide.empty())
	reorderedGuide[node] = guide.at(seqidx);

      closestLeaf.push_back (node);
      closestLeafDistance.push_back (0);

      rowName.push_back (nodeName(node));

    } else {
      int cl = -1;
      double dcl = 0;
      for (int nc = 0; nc < nChildren(node); ++nc) {
	const int c = getChild(node,nc);
	const double dc = closestLeafDistance[c] + branchLength(c);
	if (nc == 0 || dc < dcl) {
	  cl = closestLeaf[c];
	  dcl = dc;
	}
      }
      closestLeaf.push_back (cl);
      closestLeafDistance.push_back (dcl);

      rowName.push_back (ForwardMatrix::ancestorName (rowName[getChild(node,0)], branchLength(getChild(node,0)), rowName[getChild(node,1)], branchLength(getChild(node,1))));
    }

  guide = reorderedGuide;
}

Alignment Reconstructor::reconstruct() {
  gsl_vector* eqm = model.getEqmProb();
  auto generator = ForwardMatrix::newRNG();
  generator.seed (rndSeed);

  LogProb lpFinal = -numeric_limits<double>::infinity();
  AlignPath path;
  map<int,Profile> prof;
  for (int node = 0; node < nodes(); ++node) {
    if (isLeaf(node))
      prof[node] = Profile (model.alphabet, seqs[nodeToSeqIndex[node]], node);
    else {
      const int lChildNode = getChild(node,0);
      const int rChildNode = getChild(node,1);
      const Profile& lProf = prof[lChildNode];
      const Profile& rProf = prof[rChildNode];
      ProbModel lProbs (model, branchLength(lChildNode));
      ProbModel rProbs (model, branchLength(rChildNode));
      PairHMM hmm (lProbs, rProbs, eqm);

      LogThisAt(2,"Aligning " << lProf.name << " and " << rProf.name << endl);

      ForwardMatrix forward (lProf, rProf, hmm, node, guide.empty() ? GuideAlignmentEnvelope() : GuideAlignmentEnvelope (guide, closestLeaf[lChildNode], closestLeaf[rChildNode], maxDistanceFromGuide));
      LogThisAt(3,"Forward log-likelihood is " << forward.lpEnd << endl);

      if (node == nodes() - 1) {
	path = forward.bestAlignPath();
	prof[node] = forward.bestProfile();
	lpFinal = forward.lpEnd;
      } else
	prof[node] = forward.sampleProfile (generator, profileSamples, profileNodeLimit, ForwardMatrix::KeepHubsAndAbsorbers, includeBestTraceInProfile);

      LogThisAt(5,prof[node].toJson());
    }
  }

  gsl_vector_free (eqm);

  LogThisAt(1,"Final log-likelihood is " << lpFinal << endl);

  vguard<FastSeq> ungapped (nodes());
  for (int node = 0; node < nodes(); ++node) {
    if (isLeaf(node)) 
      ungapped[node] = seqs[seqIndex.at(rowName[node])];
    else {
      ungapped[node].seq = string (alignPathResiduesInRow(path.at(node)), '*');
      ungapped[node].name = rowName[node];
    }
  }

  return Alignment (ungapped, path);
}

string Reconstructor::nodeName (int node) const {
  if (tree->node[node].name)
    return string (tree->node[node].name);
  return string();
}

double Reconstructor::branchLength (int node) const {
  return tree->node[node].d;
}

int Reconstructor::nodes() const {
  return tree->n;
}

int Reconstructor::parentNode (int node) const {
  return tree->node[node].parent;
}

bool Reconstructor::isLeaf (int node) const {
  return nChildren (node) == 0;
}

int Reconstructor::nChildren (int node) const {
  return tree->node[node].n;
}

int Reconstructor::getChild (int node, int childNum) const {
  return tree->node[node].child[childNum];
}

string Reconstructor::treeString (int root) const {
  kstring_t str;
  str.l = str.m = 0; str.s = 0;
  kn_format(tree->node, root, &str);
  string s (str.s);
  free (str.s);
  return s;
}

string Reconstructor::treeString() const {
  return treeString (tree->n - 1);
}
