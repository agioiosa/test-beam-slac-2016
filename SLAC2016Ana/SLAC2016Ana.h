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
  static  Double_t fFit(Double_t *x, Double_t *p);
  static  Double_t fFit2(Double_t *x, Double_t *p);

  // calibration parameter for SiPMS
  const Double_t calibbot= 4.7;
  const Double_t calibtop= 5.5;
  const Double_t caliblef= 4.6;
  const Double_t calibcen= 4.1;
  const Double_t calibrig= 5.1;

  //histograms for SiPMS analysis
  TH1D *histo;
  TH1D *hc;
  TH1D *hl;
  TH1D *hr;
  TH1D *ht;
  TH1D *hb;

  //
  TH2D *hqt;
  TH2D *hqt1;
  TH2D *hqt2;
  TH2D *hqt3;
  TH2D *hqt4;
  TH2D *hqt5;

  //
  Int_t Ndum;

  //histograms for LM analysis
  TProfile *prof_LM1_P1;
  TProfile *prof_LM1_P2;
  TProfile *prof_LM1_ratio;
  Double_t *ratio;
  Double_t *p1;
  Double_t *p2;
  Int_t iter;
};
#endif
