#ifndef SEQGRAPH_INCLUDED
#define SEQGRAPH_INCLUDED

#include <list>
#include "profile.h"

struct SeqGraph {
  typedef size_t NodeIndex;

  struct Edge {
    NodeIndex src, dest;
    Edge (NodeIndex s, NodeIndex d) : src(s), dest(d) { }
    bool operator< (const Edge& e) const { return src == e.src ? (dest < e.dest) : (src < e.src); }
  };

  struct Node {
    list<Edge> in, out;
    string seq;
    bool isNull() const { return seq.empty(); }
  };

  vguard<Node> node;
  set<Edge> edge;
  
  SeqGraph() { }
  SeqGraph (const Profile& prof, const string& alphabet, const vguard<LogProb>& logCptWeight, const vguard<vguard<LogProb> >& logInsProb, double minPostProb);

  void buildIndices();
  
  NodeIndex nodes() const { return node.size(); }
  NodeIndex edges() const { return edge.size(); }

  vguard<NodeIndex> nodeIndices() const;
  vguard<NodeIndex> reverseNodeIndices() const;
  
  void assertToposort() const;
  
  SeqGraph eliminateNull() const;
  SeqGraph eliminateDuplicates() const;
  SeqGraph mergeCharClasses() const;
  SeqGraph collapseChains() const;

  SeqGraph simplify() const;

  void writeDot (ostream& out) const;
};

#endif /* SEQGRAPH_INCLUDED */
