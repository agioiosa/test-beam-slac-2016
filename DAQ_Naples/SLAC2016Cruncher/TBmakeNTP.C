#include "TString.h"
#include "TFile.h"
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
	NTPsetup();
}

//
// Destructor
//
TBmakeNTP::~TBmakeNTP()
{
	// Delete all arrays
	delete b10;
	delete b11;
	delete b12;
	delete tNTP;
}

//
//
void TBmakeNTP::NTPreset()
{
	//
	// Zero all structures;
	//
	pmt.NBOF = 0;
	pmt.NTimeTrgBOF = 0;
	pmt.NtrgBOF = 0;
	pmt.BoardAdr = 0;
	pmt.boardTemp = 0;
	pmt.cspTemp = 0;
	pmt.extTemp = 0;
	pmt.Vbias = 0;
	pmt.ADCVal = 0;
	pmt.PulseType = 0;
	pmt.t_year = 0;
	pmt.t_mon = 0;
	pmt.t_day = 0;
	pmt.t_secday = 0;
	pmt.fired = 0;

	pin1.NBOF = 0;
	pin1.NTimeTrgBOF =  0;
	pin1.NtrgBOF =  0;
	pin1.BoardAdr =  0;
	pin1.boardTemp =  0;
	pin1.cspTemp =  0;
	pin1.extTemp =  0;
	pin1.Vbias =  0;
	pin1.ADCVal =  0;
	pin1.PulseType =  0;
	pin1.t_year =  0;
	pin1.t_mon =  0;
	pin1.t_day =  0;
	pin1.t_secday =  0;
	pin1.fired = 0;

	pin2.NBOF = 0;
	pin2.NTimeTrgBOF = 0;
	pin2.NtrgBOF = 0;
	pin2.BoardAdr = 0;
	pin2.boardTemp = 0;
	pin2.cspTemp = 0;
	pin2.extTemp = 0;
	pin2.Vbias = 0;
	pin2.ADCVal = 0;
	pin2.PulseType = 0;
	pin2.t_year = 0;
	pin2.t_mon = 0;
	pin2.t_day = 0;
	pin2.t_secday = 0;
	pin2.fired = 0;
}

//
void TBmakeNTP::NTPfill(Int_t ChBoard, Int_t NBOF,	Int_t NTimeTrgBOF,	Int_t NtrgBOF,
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
			pmt.NTimeTrgBOF = NTimeTrgBOF;
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
			pmt.fired = 1;

			pin1.NBOF = 0;
			pin1.NTimeTrgBOF =  0;
			pin1.NtrgBOF =  0;
			pin1.BoardAdr =  0;
			pin1.boardTemp =  0;
			pin1.cspTemp =  0;
			pin1.extTemp =  0;
			pin1.Vbias =  0;
			pin1.ADCVal =  0;
			pin1.PulseType =  0;
			pin1.t_year =  0;
			pin1.t_mon =  0;
			pin1.t_day =  0;
			pin1.t_secday =  0;
			pin1.fired = 0;

			pin2.NBOF = 0;
			pin2.NTimeTrgBOF = 0;
			pin2.NtrgBOF = 0;
			pin2.BoardAdr = 0;
			pin2.boardTemp = 0;
			pin2.cspTemp = 0;
			pin2.extTemp = 0;
			pin2.Vbias = 0;
			pin2.ADCVal = 0;
			pin2.PulseType = 0;
			pin2.t_year = 0;
			pin2.t_mon = 0;
			pin2.t_day = 0;
			pin2.t_secday = 0;
			pin2.fired = 0;

			//b10->Fill();
			tNTP->Fill();
			break;
		}
	case 11:
		{
			pin1.NBOF = NBOF;
			pin1.NTimeTrgBOF = NTimeTrgBOF;
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
			pin1.fired = 1;

			pmt.NBOF = 0;
			pmt.NTimeTrgBOF = 0;
			pmt.NtrgBOF = 0;
			pmt.BoardAdr = 0;
			pmt.boardTemp = 0;
			pmt.cspTemp = 0;
			pmt.extTemp = 0;
			pmt.Vbias = 0;
			pmt.ADCVal = 0;
			pmt.PulseType = 0;
			pmt.t_year = 0;
			pmt.t_mon = 0;
			pmt.t_day = 0;
			pmt.t_secday = 0;
			pmt.fired = 0;

			pin2.NBOF = 0;
			pin2.NTimeTrgBOF = 0;
			pin2.NtrgBOF = 0;
			pin2.BoardAdr = 0;
			pin2.boardTemp = 0;
			pin2.cspTemp = 0;
			pin2.extTemp = 0;
			pin2.Vbias = 0;
			pin2.ADCVal = 0;
			pin2.PulseType = 0;
			pin2.t_year = 0;
			pin2.t_mon = 0;
			pin2.t_day = 0;
			pin2.t_secday = 0;
			pin2.fired = 0;

			//b11->Fill();
			tNTP->Fill();
			break;
		}
	case 12:
		{
			pin2.NBOF = NBOF;
			pin2.NTimeTrgBOF = NTimeTrgBOF;
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
			pin2.fired = 1;

			pmt.NBOF = 0;
			pmt.NTimeTrgBOF = 0;
			pmt.NtrgBOF = 0;
			pmt.BoardAdr = 0;
			pmt.boardTemp = 0;
			pmt.cspTemp = 0;
			pmt.extTemp = 0;
			pmt.Vbias = 0;
			pmt.ADCVal = 0;
			pmt.PulseType = 0;
			pmt.t_year = 0;
			pmt.t_mon = 0;
			pmt.t_day = 0;
			pmt.t_secday = 0;
			pmt.fired = 0;

			pin1.NBOF = 0;
			pin1.NTimeTrgBOF =  0;
			pin1.NtrgBOF =  0;
			pin1.BoardAdr =  0;
			pin1.boardTemp =  0;
			pin1.cspTemp =  0;
			pin1.extTemp =  0;
			pin1.Vbias =  0;
			pin1.ADCVal =  0;
			pin1.PulseType =  0;
			pin1.t_year =  0;
			pin1.t_mon =  0;
			pin1.t_day =  0;
			pin1.t_secday =  0;
			pin1.fired = 0;

			//b12->Fill();
			tNTP->Fill();
			break;
		}
	default:
		tNTP->Fill();
		break;
	}
}

void TBmakeNTP::NTPsetup()
{
	tNTP = new TTree(ftID,ftTitle);

	b10 = tNTP->Branch("pmt",&pmt,  "NBOF/I:NTimeTrgBOF/I:NtrgBOF/I:BoardAdr/I:boardTemp/I:cspTemp/I:extTemp/I:Vbias/I:ADCVal/I:PulseType/I:t_year/I:t_mon/I:t_day/I:t_secday/I:fired/I");
	b11 = tNTP->Branch("pin1",&pin1,"NBOF/I:NTimeTrgBOF/I:NtrgBOF/I:BoardAdr/I:boardTemp/I:cspTemp/I:extTemp/I:Vbias/I:ADCVal/I:PulseType/I:t_year/I:t_mon/I:t_day/I:t_secday/I:fired/I");
	b12 = tNTP->Branch("pin2",&pin2,"NBOF/I:NTimeTrgBOF/I:NtrgBOF/I:BoardAdr/I:boardTemp/I:cspTemp/I:extTemp/I:Vbias/I:ADCVal/I:PulseType/I:t_year/I:t_mon/I:t_day/I:t_secday/I:fired/I");
}

void TBmakeNTP::Write()
{
	tNTP->Write();
}
