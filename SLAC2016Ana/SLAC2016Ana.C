#include "SLAC2016Ana.h"
#include <TMath.h>
#include <TF1.h>
#include <TF2.h>
#include <TCanvas.h>

#include <iostream>

void SLAC2016Ana::Loop(string &filename){
    cout << "Loop()" << endl;

    initialize(filename);

    if (fChain == 0) return;

    nentries = fChain->GetEntriesFast();

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

	//histograms for SiPMS analysis
	histo= new TH1D("histo","Spectrum",400,0,10000);
	hc= new TH1D("hc","Spectrum C",400,0,10000);
	hl= new TH1D("hl","Spectrum L",400,0,10000);
	hr= new TH1D("hr","Spectrum R",400,0,10000);
	ht= new TH1D("ht","Spectrum T",400,0,10000);
	hb= new TH1D("hb","Spectrum B",400,0,10000);

	//
	hqt  = new TH2D("hqt","Correlations",50,0.5,50.5,100,0.,10000.);
	hqt1 = new TH2D("hqt1","Correlations peak1",50,0.5,50.5,100,0.,2500.);
	hqt2 = new TH2D("hqt2","Correlations peak2",50,0.5,50.5,100,2500.,4000.);
	hqt3 = new TH2D("hqt3","Correlations peak3",50,0.5,50.5,100,4000.,5800.);
	hqt4 = new TH2D("hqt4","Correlations peak4",50,0.5,50.5,100,5800.,7600.);
	hqt5 = new TH2D("hqt5","Correlations peak5",50,0.5,50.5,100,7600.,9500.);

	//
	Ndum = 10;

	//
	ratio = new Double_t[nentries];
	p1 = new Double_t[nentries];
	p2 = new Double_t[nentries];

	iter = 0;

	cout << "initialize()" << endl;
}

void SLAC2016Ana::execute(){

	if(NpTrL==0 && NpTrA==0)				// laser and americium condition
	{
		Double_t esum = 0;

		if(NpSiC == 1)
		{
			hc->Fill(SiPMcen_q[0]);
			esum += SiPMcen_q[0];
		}
		if(NpSiL == 1)
		{
			hl->Fill(SiPMlef_q[0]);
			esum += SiPMlef_q[0]*calibcen/caliblef;
		}
		if(NpSiR == 1)
		{
			hr->Fill(SiPMrig_q[0]);
			esum += SiPMrig_q[0]*calibcen/calibrig;
		}
		if(NpSiB == 1)
		{
			hb->Fill(SiPMbot_q[0]);
			esum += SiPMbot_q[0]*calibcen/calibbot;
		}
		if(NpSiT == 1)
		{
			ht->Fill(SiPMtop_q[0]);
			esum += SiPMtop_q[0]*calibcen/calibtop;
		}
		histo->Fill(esum);
		hqt->Fill(SiPMcen_te[0]-SiPMcen_t[0],esum);
		if(esum<2500) hqt1->Fill(SiPMcen_te[0]-SiPMcen_t[0],esum);
		if(esum>2500 && esum<4000) hqt2->Fill(SiPMcen_te[0]-SiPMcen_t[0],esum);
		if(esum>4000 && esum<5800) hqt3->Fill(SiPMcen_te[0]-SiPMcen_t[0],esum);
		if(esum>5800 && esum<7600) hqt4->Fill(SiPMcen_te[0]-SiPMcen_t[0],esum);
		if(esum>7600 && esum<9500) hqt5->Fill(SiPMcen_te[0]-SiPMcen_t[0],esum);
	}									// end of laser and americium condition

	//LM1
	if(LM1_a[0]!=0)
	ratio[iter] = LM1_a[1]/LM1_a[0];
	p1[iter] = LM1_a[0];
	p2[iter] = LM1_a[1];
	iter++;
	//cout << "execute()" << endl;
}

void SLAC2016Ana::finalize(string &filename){

	//LM1
	Double_t mean = 0;
	Double_t mean1 = 0;
	Double_t mean2 = 0;
	for(int i = 0;i<iter;i++) mean = (mean + ratio[i])/2;
	for(int i = 0;i<iter;i++) mean1 = (mean1 + p1[i])/2;
	for(int i = 0;i<iter;i++) mean2 = (mean2 + p2[i])/2;
	cout<<mean<<" "<<mean1<<" "<<mean2<<endl;

	//histograms for LM analysis
	char title[100];
	sprintf(title,"Time profile for LM1 peaks ratio file %s",filename.c_str());
	prof_LM1_ratio = new TProfile("prof_LM1_ratio",title,24,0,iter);
	sprintf(title,"Time profile for LM1 peak 1 file %s",filename.c_str());
	prof_LM1_P1 = new TProfile("prof_LM1_P1",title,24,0,iter);
	sprintf(title,"Time profile for LM1 peak 2 file %s",filename.c_str());
	prof_LM1_P2 = new TProfile("prof_LM1_P2",title,24,0,iter);

	for (int j = 0; j < iter; ++j){
		prof_LM1_ratio->Fill(j,(ratio[j]/mean-1)*100);
		prof_LM1_P1->Fill(j,(p1[j]/mean1-1)*100);
		prof_LM1_P2->Fill(j,(p2[j]/mean2-1)*100);
	}

	//
	// Fit histograms
	//
	TF1* fc = new TF1("fc",fFit,0.0,10000.0,9);
	fc->SetParName(0,"Norm1");
	fc->SetParName(1,"Norm2");
	fc->SetParName(2,"Norm3");
	fc->SetParName(3,"Norm4");
	fc->SetParName(4,"Norm5");
	fc->SetParName(5,"Norm6");
	fc->SetParName(6,"Electron peak");
	fc->SetParName(7,"Npe conversion");
	fc->SetParName(8,"Shift");
	Double_t pc[9] = {2e4,1e5,1e5,6e4,2e4,1e4,1500,18,0};
	fc->SetParameters(pc);
	fc->SetNpx(400);
	hc->Fit("fc");

	//
	TF1* fall = new TF1("fall",fFit,0.0,10000.,9);
	fall->SetParName(0,"Norm1");
	fall->SetParName(1,"Norm2");
	fall->SetParName(2,"Norm3");
	fall->SetParName(3,"Norm4");
	fall->SetParName(4,"Norm5");
	fall->SetParName(5,"Norm6");
	fall->SetParName(6,"Electron peak");
	fall->SetParName(7,"Npe conversion");
	fall->SetParName(8,"Shift");
	Double_t pall[9] = {2e4,1e5,1e5,6e4,2e4,1e4,1500,18,0};
	fall->SetParameters(pall);
	fall->SetNpx(400);
	histo->Fit("fall");

	TProfile *hqt1_pfx = hqt1->ProfileX(); hqt1_pfx->Fit("pol1","","",11,19);
	TProfile *hqt2_pfx = hqt2->ProfileX(); hqt2_pfx->Fit("pol1","","",11,19);
	TProfile *hqt3_pfx = hqt3->ProfileX(); hqt3_pfx->Fit("pol1","","",11,19);
	TProfile *hqt4_pfx = hqt4->ProfileX(); hqt4_pfx->Fit("pol1","","",11,19);

	//
	// 2 dimensional fit
	//
	TF2* f2all = new TF2("f2all",fFit2,10.,25.,0.,10000.,17);
	f2all->SetParName(0,"Norm1");
	f2all->SetParName(1,"Norm2");
	f2all->SetParName(2,"Norm3");
	f2all->SetParName(3,"Norm4");
	f2all->SetParName(4,"Norm5");
	f2all->SetParName(5,"Norm6");
	f2all->SetParName(6,"Electron peak");
	f2all->SetParName(7,"Npe conversion");
	f2all->SetParName(8,"t1");
	f2all->SetParName(9,"tn");
	f2all->SetParName(10,"Sigma t");
	f2all->SetParName(11,"s1");
	f2all->SetParName(12,"s2");
	f2all->SetParName(13,"s3");
	f2all->SetParName(14,"s4");
	f2all->SetParName(15,"s5");
	f2all->SetParName(16,"s6");

	Double_t p2all[17];

	for(Int_t i=0; i<8; i++) p2all[i]= fall->GetParameter(i);
	p2all [8] = 13;
	p2all [9] = 15;
	p2all[10] =  2;
	p2all[11] =  14;
	p2all[12] = -17;
	p2all[13] = -13;
	p2all[14] = -13;
	p2all[15] = -13;
	p2all[16] = -13;
	f2all->SetParameters(p2all);
	f2all->SetNpx(400);
	hqt->Fit("f2all");

	// Write out TTree, close output file
	// Prepare output file
	char* cFile  = new char[100];
	sprintf(cFile,"analyzed_%s",filename.c_str());
	TFile OutF(cFile,"recreate");
	OutF.cd();
	gROOT->GetList()->Write();
	OutF.Close();
	delete [] cFile;
	useDelete();
	cout << "finalize()" << endl;
}

void SLAC2016Ana::useDelete(){
	delete histo;
	delete hc;
	delete hl;
	delete hr;
	delete ht;
	delete hb;

	//
	delete hqt;
	delete hqt1;
	delete hqt2;
	delete hqt3;
	delete hqt4;
	delete hqt5;

	delete prof_LM1_P1;
	delete prof_LM1_P2;
	delete prof_LM1_ratio;
	delete[] ratio;
	delete[] p1;
	delete[] p2;

	cout << "delete()" << endl;
}

void SLAC2016Ana::clear(){
	//cout << "clear()" << endl;
}

Double_t SLAC2016Ana::fFit(Double_t *x, Double_t *p)
{
	//
	Double_t A1   = p[0];		// Normalization factor 1
	Double_t A2   = p[1];		// Normalization factor 2
	Double_t A3   = p[2];		// Normalization factor 3
	Double_t A4	  = p[3];		// Normalization factor 4
	Double_t A5   = p[4];		// Normalization factor 5
	Double_t A6   = p[5];		// Normalization factor 6
	Double_t mu	  = p[6];		// Single electron peak
	Double_t k	  = p[7];		// Width calibration (S^2 = Snoise^2+k*mu)
	Double_t Shf  = p[8];		// Shift

	//
	Double_t q  = x[0] - Shf;

	//
	Double_t A[6] = {A1,A2,A3,A4,A5,A6};

	//
	Double_t Val = 0;
	for(Int_t n=0; n<6; n++)	// loop on numbero of electrons
	{
		Double_t m = mu*(n+1);
		Double_t Sig = TMath::Sqrt(m*k);
		Double_t Arg = 0.5*(q-m)*(q-m)/(Sig*Sig);
		if(Arg<30)Val += A[n]*TMath::Exp(-Arg)/Sig;
	}

	//
	return Val;
}

//
//
Double_t SLAC2016Ana::fFit2(Double_t *x, Double_t *p)
{
	//
	Double_t A1   = p[0];		// Normalization factor 1
	Double_t A2   = p[1];		// Normalization factor 2
	Double_t A3   = p[2];		// Normalization factor 3
	Double_t A4	  = p[3];		// Normalization factor 4
	Double_t A5   = p[4];		// Normalization factor 5
	Double_t A6   = p[5];		// Normalization factor 6
	Double_t mu	  = p[6];		// Single electron peak
	Double_t k	  = p[7];		// Width calibration (S^2 = Snoise^2+k*mu)
	Double_t t1   = p[8];		// Reference pulse width 1 el
	Double_t tn   = p[9];		// Reference pulse width n el
	Double_t Sigt = p[10];		// Time difference distribution sigma
	Double_t s[6];
	s[0]		  = p[11];		// width dependence 1 electron
	s[1]		  = p[12];		// width dependence 2 electron
	s[2]		  = p[13];		// width dependence 3 electron
	s[3]		  = p[14];		// width dependence 4 electron
	s[4]		  = p[15];		// width dependence 5 electron
	s[5]		  = p[16];		// width dependence 6 electron

	//
	Double_t q  = x[1];
	Double_t t  = x[0];

	//
	Double_t A[6] = {A1,A2,A3,A4,A5,A6};

	//
	Double_t Val = 0;
	for(Int_t n=0; n<6; n++)	// loop on numbero of electrons
	{
		Double_t m = mu*(n+1);
		if(n==0) m += s[n]*(t-t1);
		else m += s[n]*(t-tn);
		Double_t Sig = TMath::Sqrt(m*k);
		Double_t Arg1 = 0.5*(q-m)*(q-m)/(Sig*Sig);
		Double_t Arg2;
		if(n==0)Arg2 = 0.5*(t-t1)*(t-t1)/(Sigt*Sigt);
		else Arg2 = 0.5*(t-tn)*(t-tn)/(Sigt*Sigt);
		if(Arg1<30&&Arg2<30)Val += A[n]*TMath::Exp(-Arg1)*TMath::Exp(-Arg2)/(Sig*Sigt);
	}
	//
	return Val;
}
