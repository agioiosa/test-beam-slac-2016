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
  	Int_t NtrgBOF;
  	Int_t NBOF;
  	Int_t BoardAdr;
  	Int_t ChBoard;
  	Int_t PulseType;
  	Int_t NTimeTrgBOF;
  	Int_t FlagType;

  	Int_t boardTemp;
  	Int_t cspTemp;
  	Int_t extTemp;
  	Int_t Vbias;
  	Int_t ADCVal;
  	Int_t t_year;
  	Int_t t_mon;
  	Int_t t_day;
  	Int_t t_secday;

  	Int_t ErrorCode;
  	Int_t frameloc;
  	Int_t byteRD;
    char sfile[200];

	TBmakeNTP *ntple;
};
#endif
