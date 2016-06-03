#include "SLAC2016Cruncher.h"

#include <iostream>
//#include <unistd.h>

void SLAC2016Cruncher::Loop(string &filename){
    cout << "Loop()" << endl;

    initialize(filename);

    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntries();
    cout<< nentries<<endl;
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

void SLAC2016Cruncher::initialize(string &filename){

	// prepare NTple tree
	char tID[10]    = "tNTP";		// tree ID
	char tTitle[50] = "DAQ data";	// Tree title
	ntple  = new TBmakeNTP(tID,tTitle);		// Create class
	tNTP = ntple->NTPsetup();

	cout << "initialize()" << endl;
}

void SLAC2016Cruncher::execute(){
    //cout << "execute()" << endl;
	if (ErrorCode == 0 && frameloc == 28){

		ntple->NTPfill(ChBoard,NBOF,NTimeBOF,NtrgBOF,BoardAdr,
				boardTemp,cspTemp,extTemp,Vbias,ADCVal,PulseType,
				t_year,t_mon,t_day,t_secday);	// Fill NTPle arrays
		tNTP->Fill();
	}
}

void SLAC2016Cruncher::finalize(string &filename){

	// Write out TTree, close output file
	// Prepare output file
	char* cFile  = new char[100];
	sprintf(cFile,"out_%s",filename.c_str());
	TFile OutF(cFile,"recreate");
	OutF.cd();
	tNTP->Write();
	OutF.Close();
	//usleep(1000);
	//delete ntple;
	//delete tNTP;

    cout << "finalize()" << endl;
}

void SLAC2016Cruncher::clear(){
	ntple->NTPreset();
	//cout << "clear()" << endl;
}
