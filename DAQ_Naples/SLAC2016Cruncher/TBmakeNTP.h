#ifndef G__TBMAKENTP_H
#define G__TBMAKENTP_H

#include "TTree.h"


class TBmakeNTP{

	// Example usage:
	//
	// TFile *f = new TFile("run345.root","recreate");
	// char tID[10] = "tNTP";
	// char tTitle[50] = "Compressed NTPle";
	// TBmakeNTP *A = new TBmakeNTP(tID,tTitle);
	// EventLoop:
	//	A->NTPreset();
	//	Ltime = LocalTime;
	//	ChannelLoop: (ch)
	//		PulseNrLoop: (Np)
	//			charge = ...
	//			ampl = ...
	//			time = ...
	//			A->NTPfill(nrun, ch, Np, charge, ampl, time, Ltime);
	//		PulseNrLoop end
	//	ChannelLoop end
	// EventLoop end
	// f->cd();
	// t->Write();
	// f->Close();

private:
	typedef struct {
		Int_t NBOF;
		Int_t NTimeTrgBOF;
		Int_t NtrgBOF;
		Int_t BoardAdr;
		Int_t boardTemp;
		Int_t cspTemp;
		Int_t extTemp;
		Int_t Vbias;
		Int_t ADCVal;
		Int_t PulseType;
		Int_t t_year;
		Int_t t_mon;
		Int_t t_day;
		Int_t t_secday;
		Int_t fired;
	} DEVICE;

	char* ftID;					// Tree identifier
	char* ftTitle;				// Tree description
	DEVICE pmt, pin1, pin2;
	TTree *tNTP;
	TBranch* b10;
	TBranch* b11;
	TBranch* b12;

public:
	//
	//constructor
	TBmakeNTP(char* tID, char* tTitle);

	//
	// destructor
	~TBmakeNTP();

	//
	// Configure NTPle tree structure
	void NTPsetup();

	//
	// Pulse counter reset.
	void NTPreset();

	//
	// Generic NTP filling routine
	//void NTPfill(Int_t ChBoard,Int_t BoardAdr, Double_t boardTemp, Double_t cspTemp, Double_t extTemp, Double_t Vbias, Double_t ADCVal, Int_t PulseType, Double_t refTime);
	void NTPfill(Int_t ChBoard, Int_t NBOF,	Int_t NTimeTrgBOF,	Int_t NtrgBOF,
			Int_t BoardAdr, Int_t boardTemp, Int_t cspTemp, Int_t extTemp,
			Int_t Vbias, Int_t ADCVal, Int_t PulseType, Int_t t_year, Int_t t_mon,
			Int_t t_day, Int_t t_secday);

	//write tNTP
	void Write();
};

#endif
