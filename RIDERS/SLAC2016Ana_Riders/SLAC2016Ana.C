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
 	FC7_clockcounter = new Double_t[nentries];

 	pmt_amplitude = new Double_t[nentries];
 	pin1_amplitude = new Double_t[nentries];
 	pin2_amplitude = new Double_t[nentries];

 	pmt_clockCounter = new Double_t[nentries];
 	pin1_clockCounter = new Double_t[nentries];
 	pin2_clockCounter = new Double_t[nentries];

 	pmt_time = new Double_t[nentries];
 	pin1_time = new Double_t[nentries];
 	pin2_time = new Double_t[nentries];

	anatree = new TTree("anatree","antree");
	anatree->Branch("FC7_clockcounter",&tFC7_clockcounter,"FC7_clockcounter/D");
	anatree->Branch("pmt_amplitude",&tpmt_amplitude,"pmt_amplitude/D");
	anatree->Branch("pin1_amplitude",&tpin1_amplitude,"pin1_amplitude/D");
	anatree->Branch("pin2_amplitude",&tpin2_amplitude,"pin2_amplitude/D");

	cout << "initialize()" << endl;
	cout << "N. entries: " << nentries << endl;
}

void SLAC2016Ana::execute(){
	FC7_clockcounter[iter] = 25E-9*FC7_ClockCounter->at(0);

	pmt_amplitude[iter] = Italiano_Amplitude->at(0);
	pin1_amplitude[iter] = Italiano_Amplitude->at(2);
	pin2_amplitude[iter] = Italiano_Amplitude->at(4);

	tFC7_clockcounter = 25E-9*FC7_ClockCounter->at(0);
	tpmt_amplitude = Italiano_Amplitude->at(0);
	tpin1_amplitude = Italiano_Amplitude->at(2);
	tpin2_amplitude = Italiano_Amplitude->at(4);

	pmt_time[iter] = Italiano_Time->at(0);
	pin1_time[iter] = Italiano_Time->at(2);
	pin2_time[iter] = Italiano_Time->at(4);

	pmt_clockCounter[iter] = Italiano_ClockCounter->at(0);
	pin1_clockCounter[iter] = Italiano_ClockCounter->at(2);
	pin2_clockCounter[iter] = Italiano_ClockCounter->at(4);

	anatree->Fill();

	cout << "--> execute(), eventNum: "<< EventNum <<endl;

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
	anatree->Write();
	OutF->Close();
	delete OutF;
	delete [] cFile;
	useDelete();
	cout << "finalize()" << endl;
}

void SLAC2016Ana::useDelete(){
	cout << "delete()" << endl;
}

void SLAC2016Ana::clear(){
	//cout << "clear()" << endl;
}
