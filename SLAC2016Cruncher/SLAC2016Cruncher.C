#include "SLAC2016Cruncher.h"
#include "TBtrace.h"
#include <iostream>

void SLAC2016Cruncher::Loop(string &filename){
    cout << "Loop()" << endl;

    initialize(filename);

    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();

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
	ch= new TBconfig(filename); // channel analyzer

	//short routine to extract file number
	nrun = ch->GetNRun(); //exctract run number from file name

	// prepare NTple tree
	char tID[10]    = "tNTP";		// tree ID
	char tTitle[50] = "Reconstructed pulses type FB";	// Tree title
	ntple  = new TBmakeNTP(tID,tTitle);		// Create class
	tNTP = ntple->NTPsetup();

	// Trace data storage
	TrLen = 1024;
	Ltime=caen_5742_system_clock;
	p="LM";

	// reset NTple counters
	// Traces to process
	NTr= ch->GetNTr();
	TrCh=new Int_t[NTr];
	TrCh=ch->GetChConfig();

	cout << "initialize()" << endl;
}

void SLAC2016Cruncher::execute(){
    //cout << "execute()" << endl;

	//Active channel loop
	for(Int_t ic=0; ic<NTr; ic++)
	{
		// Copy trace
		Int_t ich = TrCh[ic];
		p=ch->GetConfType(ich);

		// Process trace checking if given channel configuration belongs to digitizer caen 5742 or to digitizer caen 5730
		Int_t Tlen;
		Double_t *data;
		TBtrace *Tr;
		Double_t sign = 1;
		Tlen = TrLen;
		data = new Double_t[TrLen];
		for(int j=0;j<Tlen;j++) data[j] = (Double_t) caen_5742_trace[ich][j];
		//
		Tr = new TBtrace(Tlen,data,sign,p);
		Int_t Np = Tr->GetNpulse();
		//cout<<"N pulse found = "<<Np<<endl;
		for(Int_t k=0; k<Np; k++)
		{
			Double_t charge = Tr->GetCharge(k);
			Double_t time   = Tr->GetTime(k);
			Double_t ampl   = Tr->GetAmpl(k);
			Double_t timee  = (Double_t) Tr->GetXmax(k);
			/*cout<<"Pulse #"<<k<<": Charge = "<<charge
				<<", time = "<<time
				<<", Ampl = "<<ampl
				<<", timee= "<<timee
				<<endl;
			//*/
			ntple->NTPfill(nrun,ich,k,charge,ampl,time,timee,Ltime);	// Fill NTPle arrays
		}
		Tr->~TBtrace();
		delete[] data;

	}// end of loop over the channels

	tNTP->Fill();
}

void SLAC2016Cruncher::finalize(string &filename){

	// Write out TTree, close output file
	// Prepare output file
	char* cFile  = new char[100];
	sprintf(cFile,"%i.root",nrun);
	TFile OutF(cFile,"recreate");
	OutF.cd();
	tNTP->Write();
	OutF.Close();
	delete tNTP;

    cout << "finalize()" << endl;

}

void SLAC2016Cruncher::clear(){
	ntple->NTPreset();
	//cout << "clear()" << endl;
}
