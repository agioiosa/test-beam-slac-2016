#ifndef SLAC2016Ana_h
#define SLAC2016Ana_h

#include "EventCollection.h"
#include "TBmakeNTP.h"
#include <stdio.h>
#include "TH1D.h"
#include "TH2D.h"
#include "TGraph.h"
#include <iostream>
#include <fstream>

class SLAC2016Cruncher : public EventCollection {
 public:
  SLAC2016Cruncher(TTree *tree=0):EventCollection(tree){};
  ~SLAC2016Cruncher() {};
  virtual void Loop(string &filename);
  void initialize(string &filename);
  void execute();
  void finalize(string &filename);
  void clear();

 private:
  TBmakeNTP *ntple;
  TTree *tNTP;
};
#endif
