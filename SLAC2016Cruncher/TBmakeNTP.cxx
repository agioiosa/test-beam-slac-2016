#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TGraph.h"
#include <TLine.h>
#include <TStyle.h>
#include <iostream>
#include "TBmakeNTP.h"

//
// Constructor
//
TBmakeNTP::TBmakeNTP(char* tID, char* tTitle)
{
	//
	// tID     = tree name/ID
	// tTitle  - tree description
	//
	ftID = tID;
	ftTitle = tTitle;
}

//
// Destructor
//
TBmakeNTP::~TBmakeNTP()
{
	// Delete all arrays
}

//
//
void TBmakeNTP::NTPreset()
{
	//
	// Zero all structures;
	//
}

//
void TBmakeNTP::NTPfill(Int_t ChBoard, Int_t NBOF,	Int_t NTimeBOF,	Int_t NtrgBOF,
		Int_t BoardAdr, Int_t boardTemp, Int_t cspTemp, Int_t extTemp,
		Int_t Vbias, Int_t ADCVal, Int_t PulseType, Int_t t_year, Int_t t_mon,
		Int_t t_day, Int_t t_secday)
{
	//
	// Fill NTPle
	//
	switch (ChBoard){
	case 10:
		{
			pmt.NBOF = NBOF;
			pmt.NTimeBOF = NTimeBOF;
			pmt.NtrgBOF = NtrgBOF;
			pmt.BoardAdr = BoardAdr;
			pmt.boardTemp = boardTemp;
			pmt.cspTemp = cspTemp;
			pmt.extTemp = extTemp;
			pmt.Vbias = Vbias;
			pmt.ADCVal = ADCVal;
			pmt.PulseType = PulseType;
			pmt.t_year = t_year;
			pmt.t_mon = t_mon;
			pmt.t_day = t_day;
			pmt.t_secday = t_secday;
			break;
		}
	case 11:
		{
			pin1.NBOF = NBOF;
			pin1.NTimeBOF = NTimeBOF;
			pin1.NtrgBOF = NtrgBOF;
			pin1.BoardAdr = BoardAdr;
			pin1.boardTemp = boardTemp;
			pin1.cspTemp = cspTemp;
			pin1.extTemp = extTemp;
			pin1.Vbias = Vbias;
			pin1.ADCVal = ADCVal;
			pin1.PulseType = PulseType;
			pin1.t_year = t_year;
			pin1.t_mon = t_mon;
			pin1.t_day = t_day;
			pin1.t_secday = t_secday;
			break;
		}
	case 12:
		{
			pin2.NBOF = NBOF;
			pin2.NTimeBOF = NTimeBOF;
			pin2.NtrgBOF = NtrgBOF;
			pin2.BoardAdr = BoardAdr;
			pin2.boardTemp = boardTemp;
			pin2.cspTemp = cspTemp;
			pin2.extTemp = extTemp;
			pin2.Vbias = Vbias;
			pin2.ADCVal = ADCVal;
			pin2.PulseType = PulseType;
			pin2.t_year = t_year;
			pin2.t_mon = t_mon;
			pin2.t_day = t_day;
			pin2.t_secday = t_secday;
			break;
		}
	default:
		break;
	}
}

TTree *TBmakeNTP::NTPsetup()
{
	TTree *tNTP = new TTree(ftID,ftTitle);

	tNTP->Branch("pmt",&pmt,  "NBOF/I:NTimeBOF/I:NtrgBOF/I:BoardAdr/I:boardTemp/I:cspTemp/I:extTemp/I:Vbias/I:ADCVal/I:PulseType/I:t_year/I:t_mon/I:t_day/I:t_secday/I");
	tNTP->Branch("pin1",&pin1,"NBOF/I:NTimeBOF/I:NtrgBOF/I:BoardAdr/I:boardTemp/I:cspTemp/I:extTemp/I:Vbias/I:ADCVal/I:PulseType/I:t_year/I:t_mon/I:t_day/I:t_secday/I");
	tNTP->Branch("pin2",&pin2,"NBOF/I:NTimeBOF/I:NtrgBOF/I:BoardAdr/I:boardTemp/I:cspTemp/I:extTemp/I:Vbias/I:ADCVal/I:PulseType/I:t_year/I:t_mon/I:t_day/I:t_secday/I");

	return tNTP;
}
