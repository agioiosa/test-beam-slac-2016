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

	Double_t *aFC7_clockcounter;
	Double_t *apmt_amplitude;
	Double_t *apin1_amplitude;
	Double_t *apin2_amplitude;

	TProfile *prof_pmt_vs_time;
	TProfile *prof_pin1_vs_time;
	TProfile *prof_pin2_vs_time;

	TProfile *prof_pin1_vs_pin2;
	TProfile *prof_ratio_pins;
	TProfile *prof_sum_pins;

	TH2D *h2_pmt_vs_time;
	TH2D *h2_pin1_vs_time;
	TH2D *h2_pin2_vs_time;

	TH2D *h2_pin1_vs_pin2;
	TH2D *h2_ratio_pins;
	TH2D *h2_sum_pins;

	TH1D *h1_pmt_charge;
	TH1D *h1_pin1_charge;
	TH1D *h1_pin2_charge;
	TH1D *h1_ratio_pins;
	TH1D *h1_sum_pins;
};
#endif
