#ifndef G__TBMAKENTP_H
#define G__TBMAKENTP_H


class TBmakeNTP{

	// NTPle building class for Frascati test beam.
	//
	// Example usage:
	//
	// TFile *f = new TFile("run345.root","recreate");
	// char tID[10] = "tNTP";
	// char tTitle[50] = "Compressed NTPle";
	// TBmakeNTP *A = new TBmakeNTP(tID,tTitle);
	// TTree *t = A->NTPsetup();
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
	//	t->Fill();
	// EventLoop end
	// f->cd();
	// t->Write();
	// f->Close();

private:
	typedef struct {
		Int_t NBOF;
		Int_t NTimeBOF;
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
	} DEVICE;

	char* ftID;					// Tree identifier
	char* ftTitle;				// Tree description
	DEVICE pmt, pin1, pin2;

public:
	//
	//constructor
	TBmakeNTP(char* tID, char* tTitle);

	//
	// destructor
	~TBmakeNTP();

	//
	// Configure NTPle tree structure
	TTree *NTPsetup();

	//
	// Pulse counter reset.
	void NTPreset();

	//
	// Generic NTP filling routine
	//void NTPfill(Int_t ChBoard,Int_t BoardAdr, Double_t boardTemp, Double_t cspTemp, Double_t extTemp, Double_t Vbias, Double_t ADCVal, Int_t PulseType, Double_t refTime);
	void NTPfill(Int_t ChBoard, Int_t NBOF,	Int_t NTimeBOF,	Int_t NtrgBOF,
			Int_t BoardAdr, Int_t boardTemp, Int_t cspTemp, Int_t extTemp,
			Int_t Vbias, Int_t ADCVal, Int_t PulseType, Int_t t_year, Int_t t_mon,
			Int_t t_day, Int_t t_secday);
};

#endif
