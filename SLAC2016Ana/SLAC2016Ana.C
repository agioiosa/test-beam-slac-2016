#include "SLAC2016Ana.h"
#include <TMath.h>
#include <TF1.h>
#include <TF2.h>
#include <TCanvas.h>

#include <iostream>

void SLAC2016Ana::Loop(string &filename){
    cout << "Loop()" << endl;

    //initialize(filename);

    if (fChain == 0) return;

    //nentries = fChain->GetEntriesFast();
    nentries = fChain->GetEntries();
    initialize(filename);

    Int_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;

        clear();
        execute();
    }

    finalize(filename);
}

void SLAC2016Ana::initialize(string &filename){

	iter = 0;

	//histograms for LM analysis
	char title[100];
	sprintf(title,"Time profile for pmt ADC Value file %s",filename.c_str());
	prof_pmt = new TProfile("prof_pmt",title,24,0,iter);

	cout << "initialize()" << endl;
	cout << "N. entries: " << nentries << endl;
}

void SLAC2016Ana::execute(){
	//cout << "pmt ADCValue " << pmt_ADCVal << endl;
	prof_pmt->Fill(pmt_t_secday/3600,pmt_ADCVal);
	iter++;
	//cout << "execute()" << endl;
}

void SLAC2016Ana::finalize(string &filename){

	// Write out TTree, close output file
	// Prepare output file
	char* cFile  = new char[100];
	sprintf(cFile,"analyzed_%s",filename.c_str());
	TFile *OutF = new TFile(cFile,"recreate");
	OutF->cd();
	gROOT->GetList()->Write();
	OutF->Close();
	delete OutF;
	delete [] cFile;
	useDelete();
	cout << "finalize()" << endl;
}

void SLAC2016Ana::useDelete(){
	delete prof_pmt;

	cout << "delete()" << endl;
}

void SLAC2016Ana::clear(){
	//cout << "clear()" << endl;
}
