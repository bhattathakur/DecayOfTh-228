//void ntuplesample()
{
 
  gROOT->Reset();
   //file to store root file
  TFile *f=new TFile("sample.root","RECREATE");
  //TTree/ntuple
  TTree *T=new TTree("ntuple","data from ascii file");//key,title
  Long64_t line = T->ReadFile("out2.txt","x:y");
  T->Write();
}
