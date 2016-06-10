#ifndef SLAC2016Ana_h
#define SLAC2016Ana_h

#include "TBmakeNTP.h"
#include <stdio.h>
#include "TH1D.h"
#include "TH2D.h"
#include "TGraph.h"
#include <iostream>
#include <fstream>

// Namespace
using namespace std;

class SLAC2016Cruncher {
 public:
  SLAC2016Cruncher(string &filename) {
		strcpy(sfile,filename.c_str());
  };

  ~SLAC2016Cruncher() {
	  //delete ntple;
	  //delete tNTP;
  };
  virtual void Loop();
  void initialize();
  void execute();
  void finalize();
  void clear();

 private:
  	int  NtrgBOF, NBOF, BoardAdr, ChBoard, PulseType, NTimeTrgBOF, FlagType;
  	int  boardTemp, cspTemp, extTemp, Vbias, ADCVal;
  	int t_year, t_mon, t_day, t_secday;
  	int ErrorCode, frameloc;
    int byteRD;
    char sfile[200];

	TBmakeNTP *ntple;
	TTree *tNTP;
};
#endif
