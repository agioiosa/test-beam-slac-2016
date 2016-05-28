//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu May 26 18:16:12 2016 by ROOT version 6.06/04
// from TTree t/t
// found on file: frascatirun_00254.root
//////////////////////////////////////////////////////////

#ifndef EventCollection_h
#define EventCollection_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Namespace
using namespace std;

// Header file for the classes stored in the TTree if any.

class EventCollection {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   ULong64_t       caen_5742_system_clock;
   ULong64_t       caen_5742_device_clock[18];
   UShort_t        caen_5742_trace[18][1024];

   // List of branches
   TBranch        *b_caen_5742;   //!

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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("frascatirun_01095.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("frascatirun_01095.root");
      }
      f->GetObject("t",tree);

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

   fChain->SetBranchAddress("caen_5742", &caen_5742_system_clock, &b_caen_5742);
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
