#include "Riostream.h"

void histogram{
  TString dir=gSystem->UnixPathName(gInterpreter->GetCurrentMacroName());
  dir.ReplaceAll("histogram.C","");
  dir.ReplaceAll("/./","/");
  ifstream in; //name of input file stream
  in.open(Form("out2.txt",dir.Data()));//opening the data filee
  Float_t x,y;             //defining the data type
  int_t nlines=0;
  Tfile *f=new Tfile("out2.root","RECREATE");//creating the root file
  TH1F *h1=new TH1F("h1","x distribution",100,0,200);
  TNtuple *ntuple=new TNtuple ("ntuple","data from ascii file","x:y");
  while(1){
    in>>x>>y;               //input from text file
    if(!in.good())break; //check if file is good
    if(nlines<5)printf("x=%8f,y=%8f\n",x,y);
    //h1->Fill(y);
    h1->SetBinContent(x,y);
    ntuple->Fill(x,y);
    nlines++;
  }
  printf("found %d points\n";nlines);
  in.close();
  f->Write(); 
}
