#include "SLAC2016Cruncher.h"
#include "TFile.h"

#include <iostream>
//#include <unistd.h>

void SLAC2016Cruncher::Loop(){
	cout << "Loop()" << endl;

	initialize();

	clear();
	execute();

	finalize();
}

void SLAC2016Cruncher::initialize(){

	// prepare NTple tree
	char tID[50]    = "ntMonFrame";		// tree ID
	char tTitle[50] = "DAQ data";	// Tree title
	ntple  = new TBmakeNTP(tID,tTitle);		// Create class

	cout << "initialize()" << endl;
}

void SLAC2016Cruncher::execute(){
	//cout << "execute()" << endl;
	FILE *fpIN=fopen(sfile,"r");

	if (fpIN!=NULL)
	{
		int qq=1;
		while (qq>0)
		{
			qq=fscanf(fpIN,"%d %d %d %d ",&t_year, &t_mon, &t_day, &t_secday);
			//cout << " frame " << " day " << t_day << " sec_day " << t_secday  << endl;
			qq=fscanf(fpIN,"%d %d ",&ErrorCode, &frameloc);
			if (ErrorCode==0)
			{
				qq=fscanf(fpIN,"%x %x %x %x %x %x %x %x %x\n",&NBOF, &NTimeTrgBOF, &NtrgBOF, &FlagType, &boardTemp, &cspTemp, &extTemp, &Vbias, &ADCVal);

				BoardAdr= (FlagType&0x000F);
				ChBoard=  (FlagType&0x00F0)>>4;
				PulseType= (FlagType&0xFF00)>>8;

				//fill ntuple
				if (ChBoard==10 || ChBoard==11 || ChBoard==12)
				ntple->NTPfill(ChBoard,NBOF,NTimeTrgBOF,NtrgBOF,BoardAdr,
						boardTemp,cspTemp,extTemp,Vbias,ADCVal,PulseType,
						t_year,t_mon,t_day,t_secday);	// Fill NTPle arrays
			}
			else
			{
				printf("ErrorFrame: nloc %d\n",frameloc);
				for (int ibyte=0;ibyte<frameloc;ibyte++)
				{
					qq=fscanf(fpIN,"%x ",&byteRD);
					//printf("loc %d byteRD %.2x \n",ibyte,byteRD);
				}

				qq=fscanf(fpIN,"\n");
				qq=1;
			}
		} // if
	}  // end if file
	else {
		printf("file NULL\n");
	}
}

void SLAC2016Cruncher::finalize(){

	// Write out TTree, close output file
	// Prepare output file
	//==============================
	// Output File
	char output_ROOT[200], sTemp[200];
	strcpy(output_ROOT,sfile);
	sprintf(sTemp,".root");
	strcat(output_ROOT,sTemp);
	TFile *hfile = new TFile(output_ROOT,"RECREATE");
	hfile->cd();
	ntple->Write();
	hfile->Close();
	delete hfile;
	cout << "finalize()" << endl;
}

void SLAC2016Cruncher::clear(){
	ntple->NTPreset();
	//cout << "clear()" << endl;
}
