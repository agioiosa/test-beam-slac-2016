#ifndef SLAC2016Ana_h
#define SLAC2016Ana_h

#include "EventCollection.h"
#include <stdio.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TGraph.h>
#include <TProfile.h>
#include <iostream>
#include <fstream>

class SLAC2016Ana : public EventCollection {
 public:
	SLAC2016Ana(TTree *tree=0):EventCollection(tree){};
	~SLAC2016Ana() {};
	virtual void Loop(string &filename);
	void initialize(string &filename);
	void execute();
	void finalize(string &filename);
	void useDelete();
	void clear();

 private:
	Long64_t nentries;
	Int_t iter;

	Double_t tFC7_clockcounter;
	Double_t tpmt_amplitude;
	Double_t tpin1_amplitude;
	Double_t tpin2_amplitude;

	Double_t *FC7_clockcounter;
	Double_t *pmt_amplitude;
	Double_t *pin1_amplitude;
	Double_t *pin2_amplitude;

	Double_t  *pmt_clockCounter;
	Double_t  *pin1_clockCounter;
	Double_t  *pin2_clockCounter;

	Double_t *pmt_time;
	Double_t *pin1_time;
	Double_t *pin2_time;

	TTree *anatree;
};
#endif
