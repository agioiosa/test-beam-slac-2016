#ifndef TBconfig_h
#define TBconfig_h

#include <TROOT.h>

// Namespace
using namespace std;

const Int_t conf1min =  214; const Int_t conf1max =  420;
const Int_t conf2min =  816; const Int_t conf2max = 1071;
const Int_t conf3min = 1072; const Int_t conf3max = 1107;
const Int_t conf4min = 1137; const Int_t conf4max = 1191;

class TBconfig {
private:
	Int_t nrun;
	Int_t NTr; // number of used channels
	Int_t *TrCh;
	char s[28][100];

public:
	TBconfig(string &filename);
	~TBconfig();

	Int_t GetNRun();
	Int_t *GetChConfig();
	Int_t GetNTr();
	char *GetConfType(Int_t chn);
	Int_t GetRunNumber(string &runfile);
};
#endif
