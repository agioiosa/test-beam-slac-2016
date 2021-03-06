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
  Int_t pmt_iter;
  Int_t p1_iter;
  Int_t p2_iter;

  Double_t *pmt_Fired;
  Double_t *p1_Fired;
  Double_t *p2_Fired;
  
  Double_t *pmt_adcval;
  Double_t *p1_adcval;
  Double_t *p2_adcval;

  Double_t *pmt_nbof;
  Double_t *p1_nbof;
  Double_t *p2_nbof;

  Double_t *pmt_ntimetrgbof;
  Double_t *p1_ntimetrgbof;
  Double_t *p2_ntimetrgbof;

  Double_t *pmt_vbias;
  Double_t *p1_vbias;
  Double_t *p2_vbias;

  Double_t *pmt_time;
  Double_t *p1_time;
  Double_t *p2_time;

  Double_t *pmt_extemp;
  Double_t *p1_extemp;
  Double_t *p2_extemp;

  Double_t *pmt_boardtemp;
  Double_t *p1_boardtemp;
  Double_t *p2_boardtemp;

  Double_t *pmt_csptemp;
  Double_t *p1_csptemp;
  Double_t *p2_csptemp;

  //histograms for analysis
  TProfile *prof_pmt_ls_adcval;
  TProfile *prof_pmt_am_adcval;
  TProfile *prof_pin1_adcval;
  TProfile *prof_pin2_adcval;
  TProfile *prof_pin1Dpin2_adcval;
 
  TProfile *prof_pmt_vbias;
  TProfile *prof_pin1_vbias;
  TProfile *prof_pin2_vbias;

  TProfile *prof_pmt_extemp;
  TProfile *prof_pin1_extemp;
  TProfile *prof_pin2_extemp;

  TProfile *prof_pmt_boardtemp;
  TProfile *prof_pin1_boardtemp;
  TProfile *prof_pin2_boardtemp;

  TProfile *prof_pmt_csptemp;
  TProfile *prof_pin1_csptemp;
  TProfile *prof_pin2_csptemp;

  TH2D *h2_pmt_nbof;
  TH2D *h2_pin1_nbof;
  TH2D *h2_pin2_nbof;

  TH2D *h2_pin1Vpin2_adcval;

  TH2D *h2_pmt_ntimetrgbof;
  TH2D *h2_pin1_ntimetrgbof;
  TH2D *h2_pin2_ntimetrgbof;

  TH1D *h1_pmt_ntimetrgbof;
  TH1D *h1_pin1_ntimetrgbof;
  TH1D *h1_pin2_ntimetrgbof;

  TH1D *h1_pmt_adcval;
  TH1D *h1_pin1_adcval;
  TH1D *h1_pin2_adcval;

  TH1D *h1_pin1Dpin2_adcval;
  TH1D *h1_lsDam_adcval;
   
};
#endif
