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
	pmt_adcval = new Int_t[nentries];
	p1_adcval = new Int_t[nentries];
	p2_adcval = new Int_t[nentries];

	pmt_nbof = new Double_t[nentries];
	p1_nbof = new Double_t[nentries];
	p2_nbof = new Double_t[nentries];

	pmt_vbias = new Double_t[nentries];
	p1_vbias = new Double_t[nentries];
	p2_vbias = new Double_t[nentries];

	pmt_extemp = new Double_t[nentries];
	p1_extemp = new Double_t[nentries];
	p2_extemp = new Double_t[nentries];

	pmt_csptemp = new Double_t[nentries];
	p1_csptemp = new Double_t[nentries];
	p2_csptemp = new Double_t[nentries];

	pmt_boardtemp = new Double_t[nentries];
	p1_boardtemp = new Double_t[nentries];
	p2_boardtemp = new Double_t[nentries];

	pmt_time = new Double_t[nentries];
	p1_time = new Double_t[nentries];
	p2_time = new Double_t[nentries];

	cout << "initialize()" << endl;
	cout << "N. entries: " << nentries << endl;
}

void SLAC2016Ana::execute(){
	//cout << "pmt ADCValue " << pmt_ADCVal << endl;
	pmt_adcval[iter] = pmt_ADCVal;
	p1_adcval[iter] = pin1_ADCVal;
	p2_adcval[iter] = pin2_ADCVal;

	pmt_nbof[iter] = pmt_NBOF*1.;
	p1_nbof[iter] = pin1_NBOF*1.;
	p2_nbof[iter] = pin1_NBOF*1.;

	pmt_vbias[iter] = 0.437*pmt_Vbias;
	p1_vbias[iter] = -30.*pin1_Vbias;
	p2_vbias[iter] = -30.*pin2_Vbias;

	pmt_extemp[iter] = pmt_extTemp*200./2047.-50.;
	p1_extemp[iter] = pin1_extTemp*200./2047.-50.;
	p2_extemp[iter] = pin2_extTemp*200./2047.-50.;

	pmt_boardtemp[iter] = pmt_boardTemp*200./2047.-50.;
	p1_boardtemp[iter] = pin1_boardTemp*200./2047.-50.;
	p2_boardtemp[iter] = pin2_boardTemp*200./2047.-50.;

	pmt_csptemp[iter] = pmt_cspTemp*1.;
	p1_csptemp[iter] = pin1_cspTemp*1.;
	p2_csptemp[iter] = pin2_cspTemp*1.;

	pmt_time[iter] = (pmt_t_day*86400. + pmt_t_secday)/3600.-72.;
	p1_time[iter] = (pin1_t_day*86400. + pin1_t_secday)/3600. -72.;
	p2_time[iter] = (pin2_t_day*86400. + pin2_t_secday)/3600. -72.;
	iter++;
	//cout << "execute()" << endl;
}

void SLAC2016Ana::finalize(string &filename){
	//histograms for LM analysis
	Double_t t_pmt = TMath::MaxElement(iter,pmt_time);
	Double_t t_p1 = TMath::MaxElement(iter,p1_time);
	Double_t t_p2 = TMath::MaxElement(iter,p2_time);

	Double_t nbof_max_pmt = TMath::MaxElement(iter,pmt_nbof);
	Double_t nbof_max_p1 = TMath::MaxElement(iter,p1_nbof);
	Double_t nbof_max_p2 = TMath::MaxElement(iter,p2_nbof);

	Double_t pmt_vbias_mean = TMath::Mean(iter,pmt_vbias);
	Double_t p1_vbias_mean = TMath::Mean(iter,p1_vbias);
	Double_t p2_vbias_mean = TMath::Mean(iter,p2_vbias);

	char title[100];
	sprintf(title,"Time profile for pmt ADC Value file %s",filename.c_str());
	prof_pmt_adcval = new TProfile("prof_pmt_adcval",title,24,0,t_pmt);
	sprintf(title,"Time profile for pmt NBOF Value file %s",filename.c_str());
	h2_pmt_nbof = new TH2D("prof_pmt_nbof",title,1000,0,t_pmt, 1000,0,nbof_max_pmt);
	sprintf(title,"Time profile for pmt Vbias Value file %s",filename.c_str());
	prof_pmt_vbias = new TProfile("prof_pmt_vbias",title,24,0,t_pmt);
	sprintf(title,"Time profile for pmt external Temperature Value file %s",filename.c_str());
	prof_pmt_extemp = new TProfile("prof_pmt_extemp",title,24,0,t_pmt);
	sprintf(title,"Time profile for pmt board Temperature Value file %s",filename.c_str());
	prof_pmt_boardtemp = new TProfile("prof_pmt_boardtemp",title,24,0,t_pmt);
	sprintf(title,"Time profile for pmt csp Temperature Value file %s",filename.c_str());
	prof_pmt_csptemp = new TProfile("prof_pmt_csptemp",title,24,0,t_pmt);

	sprintf(title,"Histogram for pmt ADC Value file %s",filename.c_str());
	h_pmt_adcval = new TH1D("h_pmt_adcval",title,200,0,10000);


	sprintf(title,"Time profile for pin1 ADC Value file %s",filename.c_str());
	prof_pin1_adcval = new TProfile("prof_pin1_adcval",title,24,0,t_p1);
	sprintf(title,"Time profile for pin1 NBOF Value file %s",filename.c_str());
	h2_pin1_nbof = new TH2D("prof_pin1_nbof",title,1000,0,t_p1, 1000,0,nbof_max_p1);
	sprintf(title,"Time profile for pin1 Vbias Value file %s",filename.c_str());
	prof_pin1_vbias = new TProfile("prof_pin1_vbias",title,24,0,t_p1);
	sprintf(title,"Time profile for pin1 external Temperature Value file %s",filename.c_str());
	prof_pin1_extemp = new TProfile("prof_pin1_extemp",title,24,0,t_p1);
	sprintf(title,"Time profile for pin1 board Temperature Value file %s",filename.c_str());
	prof_pin1_boardtemp = new TProfile("prof_pin1_boardtemp",title,24,0,t_p1);
	sprintf(title,"Time profile for pin1 csp Temperature Value file %s",filename.c_str());
	prof_pin1_csptemp = new TProfile("prof_pin1_csptemp",title,24,0,t_p1);

	sprintf(title,"Histogram for pin1 ADC Value file %s",filename.c_str());
	h_pin1_adcval = new TH1D("h_pin1_adcval",title,100,0,2000);


	sprintf(title,"Time profile for pin2 ADC Value file %s",filename.c_str());
	prof_pin2_adcval = new TProfile("prof_pin2_adcval",title,24,0,t_p2);
	sprintf(title,"Time profile for pin2 NBOF Value file %s",filename.c_str());
	h2_pin2_nbof = new TH2D("prof_pin2_nbof",title,1000,0,t_p2, 1000,0,nbof_max_p2);
	sprintf(title,"Time profile for pin2 Vbias Value file %s",filename.c_str());
	prof_pin2_vbias = new TProfile("prof_pin2_vbias",title,24,0,t_p2);
	sprintf(title,"Time profile for pin2 external Temperature Value file %s",filename.c_str());
	prof_pin2_extemp = new TProfile("prof_pin2_extemp",title,24,0,t_p1);
	sprintf(title,"Time profile for pin2 board Temperature Value file %s",filename.c_str());
	prof_pin2_boardtemp = new TProfile("prof_pin2_boardtemp",title,24,0,t_p2);
	sprintf(title,"Time profile for pin2 csp Temperature Value file %s",filename.c_str());
	prof_pin2_csptemp = new TProfile("prof_pin2_csptemp",title,24,0,t_p2);

	sprintf(title,"Histogram for pin2 ADC Value file %s",filename.c_str());
	h_pin2_adcval = new TH1D("h_pin2_adcval",title,100,0,2000);

	for (int j = 0; j < iter; ++j){
		prof_pmt_adcval->Fill(pmt_time[j],pmt_adcval[j]);
		prof_pin1_adcval->Fill(p1_time[j],p1_adcval[j]);
		prof_pin2_adcval->Fill(p2_time[j],p2_adcval[j]);

		h2_pmt_nbof->Fill(pmt_time[j],pmt_nbof[j]);
		h2_pin1_nbof->Fill(p1_time[j],p1_nbof[j]);
		h2_pin2_nbof->Fill(p2_time[j],p2_nbof[j]);

		prof_pmt_extemp->Fill(pmt_time[j],pmt_extemp[j]);
		prof_pin1_extemp->Fill(p1_time[j],p1_extemp[j]);
		prof_pin2_extemp->Fill(p2_time[j],p2_extemp[j]);

		prof_pmt_boardtemp->Fill(pmt_time[j],pmt_boardtemp[j]);
		prof_pin1_boardtemp->Fill(p1_time[j],p1_boardtemp[j]);
		prof_pin2_boardtemp->Fill(p2_time[j],p2_boardtemp[j]);

		prof_pmt_csptemp->Fill(pmt_time[j],pmt_csptemp[j]);
		prof_pin1_csptemp->Fill(p1_time[j],p1_csptemp[j]);
		prof_pin2_csptemp->Fill(p2_time[j],p2_csptemp[j]);

		prof_pmt_vbias->Fill(pmt_time[j],pmt_vbias[j]/pmt_vbias_mean);
		prof_pin1_vbias->Fill(p1_time[j],p1_vbias[j]/p1_vbias_mean);
		prof_pin2_vbias->Fill(p2_time[j],p2_vbias[j]/p2_vbias_mean);

		h_pmt_adcval->Fill(pmt_adcval[j]);
		h_pin1_adcval->Fill(p1_adcval[j]);
		h_pin2_adcval->Fill(p2_adcval[j]);
	}

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
	delete prof_pmt_adcval;
	delete prof_pin1_adcval;
	delete prof_pin2_adcval;

	delete h2_pmt_nbof;
	delete h2_pin1_nbof;
	delete h2_pin2_nbof;

	delete prof_pmt_vbias;
	delete prof_pin1_vbias;
	delete prof_pin2_vbias;

	delete prof_pmt_extemp;
	delete prof_pin1_extemp;
	delete prof_pin2_extemp;

	delete prof_pmt_boardtemp;
	delete prof_pin1_boardtemp;
	delete prof_pin2_boardtemp;

	delete prof_pmt_csptemp;
	delete prof_pin1_csptemp;
	delete prof_pin2_csptemp;

	delete h_pmt_adcval;
	delete h_pin1_adcval;
	delete h_pin2_adcval;

	cout << "delete()" << endl;
}

void SLAC2016Ana::clear(){
	//cout << "clear()" << endl;
}
