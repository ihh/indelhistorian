#ifndef NEXUS_INCLUDED
#define NEXUS_INCLUDED

#include "tree.h"
#include "fastseq.h"

// very crude Nexus format parser

#define DefaultNexusTreeName "tree"

struct NexusData {
  static const char gapChar, wildcardChar;

  vguard<FastSeq> gapped;
  vguard<string> rowName;
  string treeName;
  Tree tree;

  NexusData (const vguard<FastSeq>& matrix, const Tree& tree);
  NexusData (const string& nexusString);
  NexusData (istream& in);

  void read (const string& nexusString);
  void write (ostream& out) const;

  void convertNexusToAlignment();  // converts Nexus gap/wildcard characters to our gap/wildcard characters
  void convertAlignmentToNexus();  // converts our gap/wildcard characters to Nexus gap/wildcard characters
};

#endif /* NEXUS_INCLUDED */
