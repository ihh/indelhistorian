#ifndef MODEL_INCLUDED
#define MODEL_INCLUDED

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <string>

#include "gason.h"
#include "fastseq.h"
#include "logsumexp.h"
#include "alignpath.h"
#include "tree.h"

using namespace std;

struct AlphabetOwner {
  string alphabet;
  AlphabetOwner() { }
  AlphabetOwner (const string& a) : alphabet(a) { }
  AlphabetOwner (const AlphabetOwner& ao) : alphabet(ao.alphabet) { }
  inline size_t alphabetSize() const { return alphabet.size(); }
  void readAlphabet (const JsonValue& json);
  UnvalidatedAlphTok tokenize (char c) const;
  AlphTok tokenizeOrDie (char c) const;
  gsl_matrix* newAlphabetMatrix() const;
  gsl_vector* newAlphabetVector() const;
};

struct RateModel : AlphabetOwner {
  double insRate, delRate, insExtProb, delExtProb;
  gsl_vector* insProb;
  gsl_matrix* subRate;

  RateModel();
  RateModel(const RateModel& model);
  ~RateModel();

  RateModel& operator= (const RateModel& model);
  
  void read (const JsonValue& json);
  void write (ostream& out) const;
  gsl_vector* getEqmProbVector() const;
  gsl_matrix* getSubProbMatrix (double t) const;

  double mlDistance (const FastSeq& xGapped, const FastSeq& yGapped, int maxIterations = 100) const;
  vguard<vguard<double> > distanceMatrix (const vguard<FastSeq>& gappedSeq, int maxIterations = 100) const;

  void writeSubCounts (ostream& out, const vguard<double>& rootCounts, const vguard<vguard<double> >& subCountsAndWaitTimes, size_t indent = 0) const;
};

class ProbModel : public AlphabetOwner {
public:
  double t, ins, del, insExt, delExt;
  gsl_vector* insVec;
  gsl_matrix* subMat;
  ProbModel (const RateModel& model, double t);
  ~ProbModel();
  void write (ostream& out) const;
private:
  ProbModel (const ProbModel&) = delete;
  ProbModel& operator= (const ProbModel&) = delete;
};

struct LogProbModel {
  vguard<LogProb> logInsProb;
  vguard<vguard<LogProb> > logSubProb;
  LogProbModel (const ProbModel& pm);
};

struct IndelCounts {
  double ins, del, insExt, delExt, matchTime, delTime;
  IndelCounts();
  IndelCounts operator+ (const IndelCounts& c) const;
  IndelCounts operator* (double w) const;
  IndelCounts& operator+= (const IndelCounts& c);
  IndelCounts& operator*= (double w);
  void accumulateIndelCounts (const AlignRowPath& parent, const AlignRowPath& child, double time, double weight = 1.);
  void accumulateIndelCounts (const AlignPath& align, const Tree& tree, double weight = 1.);
  void writeJson (ostream& out, const size_t indent = 0) const;
};

struct EigenCounts {
  IndelCounts indelCounts;
  vguard<double> rootCount;
  vguard<vguard<gsl_complex> > eigenCount;

  EigenCounts (size_t alphabetSize = 0);

  EigenCounts operator+ (const EigenCounts& c) const;
  EigenCounts operator* (double w) const;
  EigenCounts& operator+= (const EigenCounts& c);
  EigenCounts& operator*= (double w);

  void accumulateSubstitutionCounts (const RateModel& model, const Tree& tree, const vguard<FastSeq>& gapped, double weight = 1.);
  void accumulateCounts (const RateModel& model, const Alignment& align, const Tree& tree, double weight = 1.);

  void writeJson (const RateModel& model, ostream& out) const;
};

#endif /* MODEL_INCLUDED */
