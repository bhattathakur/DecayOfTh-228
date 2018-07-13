//Name of data file out2.txt
// two columns: Count vs Runnumber
//#include "Riostream.h"
void tryfill(){
  ifstream in;
  in.open("out2.txt");
  
  Float_t x,y;
  Int_t nlines=0;
  // double calibration=0.35427681;// Energy calibration function...:    -1.42832947 keV +     0.35427681 keV/chn
  TCanvas *c=new TCanvas("c","Histogram",500,300);
  c->Divide(4,2);                                //Divide(column,row)
  TFile *f=new TFile("histo2.root","RECREATE");
  TH1F *h=new TH1F ("h","Histogram with energy Calibration",8192,-1.4,2865.45);
 
  //  TNtuple *ntuple=new TNtuple ("ntuple","data from ascii file","x:y");//After correction of calibration function
  while(1)
    {
      in>>x>>y;
      if(!in.good())break;
      //  h1->Fill(x,y);
      h->SetBinContent(x,y); //SetBinContent(bin,content)
      // ntuple->Fill(x,y);
      nlines++;
      
    }
 printf("found %d points\n",nlines);
 //First Range
 c->cd(1);
 TH1F *h1=(TH1F*)h->Clone("h1");
 h1->GetXaxis()->SetTitle("ChannelNumber");
 h1->GetXaxis()->CenterTitle();
 
 h1->GetYaxis()->SetTitle("Energy(eV)");
 h1->GetYaxis()->CenterTitle();
 TF1 *f1=new TF1("f1","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f1->SetParNames("mean1","SD1","height1","a1","b1");
 f1->SetParameters(235,5,4050,0,0);
 h1->Fit("f1","rem+","",230,240);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit, +->Add fitted fn to the list of functions
 //Printing the fitting parameters in the text file
 /* TF1 *func=(TF1*)h1->GetFunction("f1");
 Int_t npar=func->GetNpar();
 for(Int_t i=0;i<npar;i++){
   printf("% %s,=%g,+- %g\n",func->GerParName(i),func->GetParameter(i),func->GetParError(i));
 }
 TFile *file =new TFile("parameters.dat",RECREATE);
 npar->Write();*/
 h1->Sumw2();
 gStyle->SetOptFit(1111);//SetOptFit(pcev), p->prob ,c->chi square/#df, e->error,v->value of parameters when e=1,v=1, SetOptFit(1)=SetOptFit(111),v=1->only non fixed parameters, v=2->all paramters
 h1->Draw();
 
 //Second Range
 c->cd(2);
  TH1F *h2=(TH1F *)h->Clone("h2");
  h2->GetXaxis()->SetTitle("ChannelNumber");
 h2->GetXaxis()->CenterTitle();
 
 h2->GetYaxis()->SetTitle("Energy(eV)");
 h2->GetYaxis()->CenterTitle();
 TF1 *f2=new TF1("f1","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f2->SetParNames("mean2","SD2","height2","a2","b2");
 f2->SetParameters(273,4,236,0,0);
 h2->Fit("f1","rem+","",271,276);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit, +->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h2->Sumw2();
 h2->Draw();

 //Third Range
 c->cd(3);
 TH1F *h3=(TH1F *)h->Clone("h3");
 h3->GetXaxis()->SetTitle("ChannelNumber");
 h3->GetXaxis()->CenterTitle();
 
 h3->GetYaxis()->SetTitle("Energy(eV)");
 h3->GetYaxis()->CenterTitle();
 TF1 *f3=new TF1("f3","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f3->SetParNames("mean3","SD3","height3","a3","b3");
 f3->SetParameters(296,4,312,0,0);
 h3->Fit("f3","rem+","",293,299);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit, +->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h3->Sumw2();
 h3->Draw();
 //Fourth Range
 c->cd(4);
 TH1F *h4=(TH1F *)h->Clone("h4");
 h4->GetXaxis()->SetTitle("ChannelNumber");
 h4->GetXaxis()->CenterTitle();
 
 h4->GetYaxis()->SetTitle("Energy(eV)");
 h4->GetYaxis()->CenterTitle();
 TF1 *f4=new TF1("f4","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f4->SetParNames("mean4","SD4","height4","a4","b4");
 f4->SetParameters(504,5,433,0,0);
 h4->Fit("f4","rem+","",500,507);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit, +->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h4->Sumw2();
 h4->Draw();

 //Fifth Range
 c->cd(5 );
 TH1F *h5 =(TH1F *)h->Clone("h5 ");
 h5 ->GetXaxis()->SetTitle("ChannelNumber");
 h5 ->GetXaxis()->CenterTitle();
 
 h5 ->GetYaxis()->SetTitle("Energy(eV)");
 h5 ->GetYaxis()->CenterTitle();
 TF1 *f5 =new TF1("f5 ","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f5 ->SetParNames("mean5","SD5","height5","a5","b5");
 f5 ->SetParameters(575.5,4,1371,0,0);
 h5 ->Fit("f5 ","rem+","",573,578);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit, +->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h5->Sumw2();
 h5 ->Draw();
 //Sixth Range
 c->cd(6);
 TH1F *h6=(TH1F *)h->Clone("h6");
 h6->GetXaxis()->SetTitle("ChannelNumber");
 h6->GetXaxis()->CenterTitle();
 
 h6->GetYaxis()->SetTitle("Energy(eV)");
 h6->GetYaxis()->CenterTitle();
 TF1 *f6=new TF1("f6","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f6->SetParNames("mean6","SD6","height6","a6","b6");
 f6->SetParameters(718,4,303,0,0);
 h6->Fit("f6","rem+","",715,721);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit, +->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h6->Sumw2();
 h6->Draw();
 //Seventh Range
 c->cd(7);
 TH1F *h7=(TH1F *)h->Clone("h7");
 h7->GetXaxis()->SetTitle("ChannelNumber");
 h7->GetXaxis()->CenterTitle();
 
 h7->GetYaxis()->SetTitle("Energy(eV)");
 h7->GetYaxis()->CenterTitle();
 TF1 *f7=new TF1("f7","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f7->SetParNames("mean7","SD7","height7","a7","b7");
 f7->SetParameters(859.5,4,150,0,0);
 h7->Fit("f7","rem+","",846,853);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit, +->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h7->Sumw2();
 h7->Draw();
 
 //Eighth Range
 c->cd(8);
 TH1F *h8=(TH1F *)h->Clone("h8");
 h8->GetXaxis()->SetTitle("ChannelNumber");
 h8->GetXaxis()->CenterTitle();
 
 h8->GetYaxis()->SetTitle("Energy(eV)");
 h8->GetYaxis()->CenterTitle();
 TF1 *f8=new TF1("f8","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f8->SetParNames("mean8","SD8","height8","a8","b8");
 f8->SetParameters(2582.5,4,272.6,0,0);
 h8->Fit("f8","rem+","",2574,2588);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit, +->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h8->Sumw2();
 h8->Draw();
 //Strong fit parameters in the text file
 /* FILE *fp=fopen("filename.dat","w");
 if(fp!=NULL){
   for(int i=0;i<GetNpar();i++){
     Float_t value=fit->GetParameter(i);
     fprintf(fp,"%d %f",i,value);
   }
 }
 fclose(fp);*/
   
 in.close();
 f->Write();
  
}
