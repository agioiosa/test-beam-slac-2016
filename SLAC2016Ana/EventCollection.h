//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat May 28 14:39:05 2016 by ROOT version 6.06/04
// from TTree tNTP/Reconstructed pulses type FB
// found on file: 1089.root
//////////////////////////////////////////////////////////

#ifndef EventCollection_h
#define EventCollection_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

using namespace std;

// Header file for the classes stored in the TTree if any.

class EventCollection {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        LabTime;
   Int_t           NpPIN1;
   Double_t        PIN1_q[2];   //[NpPIN1]
   Double_t        PIN1_a[2];   //[NpPIN1]
   Double_t        PIN1_t[2];   //[NpPIN1]
   Int_t           NpPIN2;
   Double_t        PIN2_q[2];   //[NpPIN2]
   Double_t        PIN2_a[2];   //[NpPIN2]
   Double_t        PIN2_t[2];   //[NpPIN2]
   Int_t           NpSM;
   Double_t        SM_q[3];   //[NpSM]
   Double_t        SM_a[3];   //[NpSM]
   Double_t        SM_t[3];   //[NpSM]
   Int_t           NpHAM;
   Double_t        HAM_q[4];   //[NpHAM]
   Double_t        HAM_a[4];   //[NpHAM]
   Double_t        HAM_t[4];   //[NpHAM]
   Int_t           NpLM1;
   Double_t        LM1_q[2];   //[NpLM1]
   Double_t        LM1_a[2];   //[NpLM1]
   Double_t        LM1_t[2];   //[NpLM1]
   Int_t           NpLM2;
   Double_t        LM2_q[2];   //[NpLM2]
   Double_t        LM2_a[2];   //[NpLM2]
   Double_t        LM2_t[2];   //[NpLM2]
   Int_t           NpSiB;
   Double_t        SiPMbot_q[2];   //[NpSiB]
   Double_t        SiPMbot_a[2];   //[NpSiB]
   Double_t        SiPMbot_t[2];   //[NpSiB]
   Double_t        SiPMbot_te[2];   //[NpSiB]
   Int_t           NpSiL;
   Double_t        SiPMlef_q[2];   //[NpSiL]
   Double_t        SiPMlef_a[2];   //[NpSiL]
   Double_t        SiPMlef_t[2];   //[NpSiL]
   Double_t        SiPMlef_te[2];   //[NpSiL]
   Int_t           NpSiC;
   Double_t        SiPMcen_q[2];   //[NpSiC]
   Double_t        SiPMcen_a[2];   //[NpSiC]
   Double_t        SiPMcen_t[2];   //[NpSiC]
   Double_t        SiPMcen_te[2];   //[NpSiC]
   Int_t           NpSiR;
   Double_t        SiPMrig_q[2];   //[NpSiR]
   Double_t        SiPMrig_a[2];   //[NpSiR]
   Double_t        SiPMrig_t[2];   //[NpSiR]
   Double_t        SiPMrig_te[2];   //[NpSiR]
   Int_t           NpSiT;
   Double_t        SiPMtop_q[2];   //[NpSiT]
   Double_t        SiPMtop_a[2];   //[NpSiT]
   Double_t        SiPMtop_t[2];   //[NpSiT]
   Double_t        SiPMtop_te[2];   //[NpSiT]
   Int_t           NpTrL;
   Double_t        TrigL_q[2];   //[NpTrL]
   Double_t        TrigL_a[2];   //[NpTrL]
   Double_t        TrigL_t[2];   //[NpTrL]
   Int_t           NpTrA;
   Double_t        TrigA_q[2];   //[NpTrA]
   Double_t        TrigA_a[2];   //[NpTrA]
   Double_t        TrigA_t[2];   //[NpTrA]
   Int_t           NpTrG;
   Double_t        TrigG_q[2];   //[NpTrL]
   Double_t        TrigG_a[2];   //[NpTrL]
   Double_t        TrigG_t[2];   //[NpTrL]
   Int_t           NpHF;
   Double_t        HF_q[2];   //[NpTrL]
   Double_t        HF_a[2];   //[NpTrL]
   Double_t        HF_t[2];   //[NpTrL]
   Int_t           NpVF;
   Double_t        VF_q[2];   //[NpTrL]
   Double_t        VF_a[2];   //[NpTrL]
   Double_t        VF_t[2];   //[NpTrL]

   // List of branches
   TBranch        *b_LabTime;   //!
   TBranch        *b_NpPIN1;   //!
   TBranch        *b_PIN1_q;   //!
   TBranch        *b_PIN1_a;   //!
   TBranch        *b_PIN1_t;   //!
   TBranch        *b_NpPIN2;   //!
   TBranch        *b_PIN2_q;   //!
   TBranch        *b_PIN2_a;   //!
   TBranch        *b_PIN2_t;   //!
   TBranch        *b_NpSM;   //!
   TBranch        *b_SM_q;   //!
   TBranch        *b_SM_a;   //!
   TBranch        *b_SM_t;   //!
   TBranch        *b_NpHAM;   //!
   TBranch        *b_HAM_q;   //!
   TBranch        *b_HAM_a;   //!
   TBranch        *b_HAM_t;   //!
   TBranch        *b_NpLM1;   //!
   TBranch        *b_LM1_q;   //!
   TBranch        *b_LM1_a;   //!
   TBranch        *b_LM1_t;   //!
   TBranch        *b_NpLM2;   //!
   TBranch        *b_LM2_q;   //!
   TBranch        *b_LM2_a;   //!
   TBranch        *b_LM2_t;   //!
   TBranch        *b_NpSiB;   //!
   TBranch        *b_SiPMbot_q;   //!
   TBranch        *b_SiPMbot_a;   //!
   TBranch        *b_SiPMbot_t;   //!
   TBranch        *b_SiPMbot_te;   //!
   TBranch        *b_NpSiL;   //!
   TBranch        *b_SiPMlef_q;   //!
   TBranch        *b_SiPMlef_a;   //!
   TBranch        *b_SiPMlef_t;   //!
   TBranch        *b_SiPMlef_te;   //!
   TBranch        *b_NpSiC;   //!
   TBranch        *b_SiPMcen_q;   //!
   TBranch        *b_SiPMcen_a;   //!
   TBranch        *b_SiPMcen_t;   //!
   TBranch        *b_SiPMcen_te;   //!
   TBranch        *b_NpSiR;   //!
   TBranch        *b_SiPMrig_q;   //!
   TBranch        *b_SiPMrig_a;   //!
   TBranch        *b_SiPMrig_t;   //!
   TBranch        *b_SiPMrig_te;   //!
   TBranch        *b_NpSiT;   //!
   TBranch        *b_SiPMtop_q;   //!
   TBranch        *b_SiPMtop_a;   //!
   TBranch        *b_SiPMtop_t;   //!
   TBranch        *b_SiPMtop_te;   //!
   TBranch        *b_NpTrL;   //!
   TBranch        *b_TrigL_q;   //!
   TBranch        *b_TrigL_a;   //!
   TBranch        *b_TrigL_t;   //!
   TBranch        *b_NpTrA;   //!
   TBranch        *b_TrigA_q;   //!
   TBranch        *b_TrigA_a;   //!
   TBranch        *b_TrigA_t;   //!
   TBranch        *b_NpTrG;   //!
   TBranch        *b_TrigG_q;   //!
   TBranch        *b_TrigG_a;   //!
   TBranch        *b_TrigG_t;   //!
   TBranch        *b_NpHF;   //!
   TBranch        *b_HF_q;   //!
   TBranch        *b_HF_a;   //!
   TBranch        *b_HF_t;   //!
   TBranch        *b_NpVF;   //!
   TBranch        *b_VF_q;   //!
   TBranch        *b_VF_a;   //!
   TBranch        *b_VF_t;   //!

   EventCollection(TTree *tree=0);
   virtual ~EventCollection();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef EventCollection_cxx
EventCollection::EventCollection(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("1089.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("1089.root");
      }
      f->GetObject("tNTP",tree);

   }
   Init(tree);
}

EventCollection::~EventCollection()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t EventCollection::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t EventCollection::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void EventCollection::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("LabTime", &LabTime, &b_LabTime);
   fChain->SetBranchAddress("NpPIN1", &NpPIN1, &b_NpPIN1);
   fChain->SetBranchAddress("PIN1_q", PIN1_q, &b_PIN1_q);
   fChain->SetBranchAddress("PIN1_a", PIN1_a, &b_PIN1_a);
   fChain->SetBranchAddress("PIN1_t", PIN1_t, &b_PIN1_t);
   fChain->SetBranchAddress("NpPIN2", &NpPIN2, &b_NpPIN2);
   fChain->SetBranchAddress("PIN2_q", PIN2_q, &b_PIN2_q);
   fChain->SetBranchAddress("PIN2_a", PIN2_a, &b_PIN2_a);
   fChain->SetBranchAddress("PIN2_t", PIN2_t, &b_PIN2_t);
   fChain->SetBranchAddress("NpSM", &NpSM, &b_NpSM);
   fChain->SetBranchAddress("SM_q", SM_q, &b_SM_q);
   fChain->SetBranchAddress("SM_a", SM_a, &b_SM_a);
   fChain->SetBranchAddress("SM_t", SM_t, &b_SM_t);
   fChain->SetBranchAddress("NpHAM", &NpHAM, &b_NpHAM);
   fChain->SetBranchAddress("HAM_q", HAM_q, &b_HAM_q);
   fChain->SetBranchAddress("HAM_a", HAM_a, &b_HAM_a);
   fChain->SetBranchAddress("HAM_t", HAM_t, &b_HAM_t);
   fChain->SetBranchAddress("NpLM1", &NpLM1, &b_NpLM1);
   fChain->SetBranchAddress("LM1_q", LM1_q, &b_LM1_q);
   fChain->SetBranchAddress("LM1_a", LM1_a, &b_LM1_a);
   fChain->SetBranchAddress("LM1_t", LM1_t, &b_LM1_t);
   fChain->SetBranchAddress("NpLM2", &NpLM2, &b_NpLM2);
   fChain->SetBranchAddress("LM2_q", LM2_q, &b_LM2_q);
   fChain->SetBranchAddress("LM2_a", LM2_a, &b_LM2_a);
   fChain->SetBranchAddress("LM2_t", LM2_t, &b_LM2_t);
   fChain->SetBranchAddress("NpSiB", &NpSiB, &b_NpSiB);
   fChain->SetBranchAddress("SiPMbot_q", SiPMbot_q, &b_SiPMbot_q);
   fChain->SetBranchAddress("SiPMbot_a", SiPMbot_a, &b_SiPMbot_a);
   fChain->SetBranchAddress("SiPMbot_t", SiPMbot_t, &b_SiPMbot_t);
   fChain->SetBranchAddress("SiPMbot_te", SiPMbot_te, &b_SiPMbot_te);
   fChain->SetBranchAddress("NpSiL", &NpSiL, &b_NpSiL);
   fChain->SetBranchAddress("SiPMlef_q", SiPMlef_q, &b_SiPMlef_q);
   fChain->SetBranchAddress("SiPMlef_a", SiPMlef_a, &b_SiPMlef_a);
   fChain->SetBranchAddress("SiPMlef_t", SiPMlef_t, &b_SiPMlef_t);
   fChain->SetBranchAddress("SiPMlef_te", SiPMlef_te, &b_SiPMlef_te);
   fChain->SetBranchAddress("NpSiC", &NpSiC, &b_NpSiC);
   fChain->SetBranchAddress("SiPMcen_q", SiPMcen_q, &b_SiPMcen_q);
   fChain->SetBranchAddress("SiPMcen_a", SiPMcen_a, &b_SiPMcen_a);
   fChain->SetBranchAddress("SiPMcen_t", SiPMcen_t, &b_SiPMcen_t);
   fChain->SetBranchAddress("SiPMcen_te", SiPMcen_te, &b_SiPMcen_te);
   fChain->SetBranchAddress("NpSiR", &NpSiR, &b_NpSiR);
   fChain->SetBranchAddress("SiPMrig_q", SiPMrig_q, &b_SiPMrig_q);
   fChain->SetBranchAddress("SiPMrig_a", SiPMrig_a, &b_SiPMrig_a);
   fChain->SetBranchAddress("SiPMrig_t", SiPMrig_t, &b_SiPMrig_t);
   fChain->SetBranchAddress("SiPMrig_te", SiPMrig_te, &b_SiPMrig_te);
   fChain->SetBranchAddress("NpSiT", &NpSiT, &b_NpSiT);
   fChain->SetBranchAddress("SiPMtop_q", SiPMtop_q, &b_SiPMtop_q);
   fChain->SetBranchAddress("SiPMtop_a", SiPMtop_a, &b_SiPMtop_a);
   fChain->SetBranchAddress("SiPMtop_t", SiPMtop_t, &b_SiPMtop_t);
   fChain->SetBranchAddress("SiPMtop_te", SiPMtop_te, &b_SiPMtop_te);
   fChain->SetBranchAddress("NpTrL", &NpTrL, &b_NpTrL);
   fChain->SetBranchAddress("TrigL_q", TrigL_q, &b_TrigL_q);
   fChain->SetBranchAddress("TrigL_a", TrigL_a, &b_TrigL_a);
   fChain->SetBranchAddress("TrigL_t", TrigL_t, &b_TrigL_t);
   fChain->SetBranchAddress("NpTrA", &NpTrA, &b_NpTrA);
   fChain->SetBranchAddress("TrigA_q", TrigA_q, &b_TrigA_q);
   fChain->SetBranchAddress("TrigA_a", TrigA_a, &b_TrigA_a);
   fChain->SetBranchAddress("TrigA_t", TrigA_t, &b_TrigA_t);
   fChain->SetBranchAddress("NpTrG", &NpTrG, &b_NpTrG);
   fChain->SetBranchAddress("TrigG_q", TrigG_q, &b_TrigG_q);
   fChain->SetBranchAddress("TrigG_a", TrigG_a, &b_TrigG_a);
   fChain->SetBranchAddress("TrigG_t", TrigG_t, &b_TrigG_t);
   fChain->SetBranchAddress("NpHF", &NpHF, &b_NpHF);
   fChain->SetBranchAddress("HF_q", HF_q, &b_HF_q);
   fChain->SetBranchAddress("HF_a", HF_a, &b_HF_a);
   fChain->SetBranchAddress("HF_t", HF_t, &b_HF_t);
   fChain->SetBranchAddress("NpVF", &NpVF, &b_NpVF);
   fChain->SetBranchAddress("VF_q", VF_q, &b_VF_q);
   fChain->SetBranchAddress("VF_a", VF_a, &b_VF_a);
   fChain->SetBranchAddress("VF_t", VF_t, &b_VF_t);
   Notify();
}

Bool_t EventCollection::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void EventCollection::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t EventCollection::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef EventCollection_cxx
