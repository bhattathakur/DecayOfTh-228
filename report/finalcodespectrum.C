//Name of data file out2.txt
// two columns: Count vs Runnumber
void finalcodespectrum(){
  ifstream in;
  in.open("out2.txt");//opening data file
  Float_t x,y;
  Int_t nlines=0;//For counting the number of lines
  // double calibration=0.35427681;// Energy calibration function...:    -1.42832947 keV +     0.35427681 keV/chn
  TCanvas *c=new TCanvas("c","Histogram",500,300);
  c->Divide(4,2);                                //Divide(column,row)
  TFile *f=new TFile("histo2.root","RECREATE");
  TH1F *h=new TH1F ("h","",8192,-1.4,2900); 
  while(1)
    {
      in>>x>>y;
      if(!in.good())break;
      h->SetBinContent(x,y); //SetBinContent(bin,content)
      h->GetXaxis()->SetTitle("Energy (keV)");
      h->GetYaxis()->SetTitle("Counts/channel");
      nlines++; 
    }
  printf("found %d points\n",nlines);
  // h->SaveAs("mainmain.pdf");not working 
  
 //First Range
 c->cd(1);
 TH1F *h1=(TH1F*)h->Clone("h1");
 h1->GetXaxis()->SetTitle("Energy(keV)");
 h1->GetXaxis()->CenterTitle();
 h1->GetYaxis()->SetTitle("Counts/Channel");
 h1->GetYaxis()->CenterTitle();
 h1->GetYaxis()->SetTitleOffset(1.5);
 TF1 *f1=new TF1("f1","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f1->SetParNames("#mu","#sigma","A","a","b");
 
 // f1->SetParNames("mean1","SD1","height1","a1","b1");
 f1->SetParameters(276.8,1.4,236.7,0,0);
 h1->Fit("f1","rem+","",273,280);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit,
 //+->Add fitted fn to the list of functions
 //Printing the fitting parameters in the text file
 h1->Sumw2();
 gStyle->SetOptStat(0);
 gStyle->SetOptFit(1111);//SetOptFit(pcev), p->prob ,c->chi square/#df, e->error,v->value of parameters when e=1,v=1,
 //SetOptFit(1)=SetOptFit(111),v=1->only non fixed parameters, v=2->all paramters
 h1->Draw();
 
 //Second Range
 c->cd(2);
 TH1F *h2=(TH1F *)h->Clone("h2");
 h2->GetXaxis()->SetTitle("Energy/Channel");
 h2->GetXaxis()->CenterTitle();
 h2->GetYaxis()->SetTitle("Counts");
 h2->GetYaxis()->CenterTitle();
  h2->GetYaxis()->SetTitleOffset(1.25);
 TF1 *f2=new TF1("f2","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f2->SetParNames("#mu","#sigma","A","a","b");
 f2->SetParameters(510.24,1.8,433.34,0,0);
 h2->Fit("f2","rem+","",505,516);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit,
 //+->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h2->Sumw2();
 h2->Draw();
 //h2->Print("4th.pdf");

 //Third Range
 c->cd(3);
 TH1F *h3=(TH1F *)h->Clone("h3");
 h3->GetXaxis()->SetTitle("Energy/Channel");
 h3->GetXaxis()->CenterTitle();
  h3->GetYaxis()->SetTitle("Counts");
  h3->GetYaxis()->CenterTitle();
    h3->GetYaxis()->SetTitleOffset(1.25);
 TF1 *f3=new TF1("f3","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f3->SetParNames("mean3","SD3","height3","a3","b3");
 f3->SetParameters(582.5,2.15,1371,0,0);
 h3->Fit("f3","rem+","",579,586.5);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit,
 //+->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h3->Sumw2();
 h3->Draw();
 
 //Fourth Range
 c->cd(4);
 TH1F *h4=(TH1F *)h->Clone("h4");
 h4->GetXaxis()->SetTitle("Energy/Channel");
 h4->GetXaxis()->CenterTitle();
 h4->GetYaxis()->SetTitle("Counts");
 h4->GetYaxis()->CenterTitle();
   h4->GetYaxis()->SetTitleOffset(1.25);
 TF1 *f4=new TF1("f4","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f4->SetParNames("mean4","SD4","height4","a4","b4");
 f4->SetParameters(748.37,0.83,14.95,0,0);
 h4->Fit("f4","rem+","",747,750);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit,
 //+->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h4->Sumw2();
 h4->Draw();

 //Fifth Range
 c->cd(5 );
 TH1F *h5 =(TH1F *)h->Clone("h5 ");
 h5 ->GetXaxis()->SetTitle("Energy/Channel");
 h5 ->GetXaxis()->CenterTitle();
 h5 ->GetYaxis()->SetTitle("Counts");
 h5 ->GetYaxis()->CenterTitle();
   h5->GetYaxis()->SetTitleOffset(1.25);
 TF1 *f5 =new TF1("f5","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f5 ->SetParNames("mean5","SD5","height5","a5","b5");
 f5 ->SetParameters(762.4,2,24,0,0);
 h5 ->Fit("f5","rem+","",755,775);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit,
 //+->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h5->Sumw2();
 h5 ->Draw();
 
 //Sixth Range
 c->cd(6);
 TH1F *h6=(TH1F *)h->Clone("h6");
 h6->GetXaxis()->SetTitle("Energy/Channel");
 h6->GetXaxis()->CenterTitle();
  h6->GetYaxis()->SetTitle("Counts");
  h6->GetYaxis()->CenterTitle();
    h6->GetYaxis()->SetTitleOffset(1.25);
 TF1 *f6=new TF1("f6","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f6->SetParNames("mean6","SD6","height6","a6","b6");
 f6->SetParameters(858.86,1.837,150.119,0,0);
 h6->Fit("f6","rem+","",850,870);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit, +->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h6->Sumw2();
 h6->Draw();
 //Seventh Range
 c->cd(7);
 TH1F *h7=(TH1F *)h->Clone("h7");
 h7->GetXaxis()->SetTitle("Energy/Channel");
 h7->GetXaxis()->CenterTitle();
 
 h7->GetYaxis()->SetTitle("Counts");
 h7->GetYaxis()->CenterTitle();
   h7->GetYaxis()->SetTitleOffset(1.25);
 TF1 *f7=new TF1("f7","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f7->SetParNames("mean7","SD7","height7","a7","b7");
 f7->SetParameters(1092.91,2.15,25.07,0,0);
 h7->Fit("f7","rem+","",1084,1101);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit,
 //+->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h7->Sumw2();
 h7->Draw();
 
 //Eighth Range
 c->cd(8);
 TH1F *h8=(TH1F *)h->Clone("h8");
 h8->GetXaxis()->SetTitle("Energy/Channely");
 h8->GetXaxis()->CenterTitle();
  h8->GetYaxis()->SetTitle("Counts");
  h8->GetYaxis()->CenterTitle();
    h8->GetYaxis()->SetTitleOffset(1.25);
 TF1 *f8=new TF1("f8","[2]*TMath::Gaus(x,[0],[1],1)+pol0(3)*(x<[0])+pol0(4)*(x>=[0])");  //Gaus->(x,mean,sigma,normalization) 1->normalization -true
 f8->SetParNames("mean8","SD8","height8","a8","b8");
 f8->SetParameters(2613.41,3.65,272.6,0,0);
 h8->Fit("f8","rem+","",2601,2627);//r-in given range,e->with better error estimation, m->improve fitting result,last two options are range of fit,
 //+->Add fitted fn to the list of functions
 gStyle->SetOptFit(1111);
 h8->Sumw2();
 h8->Draw();

/*
Writing the parameters in the file
N counts is obtained from the peak,
N=Area of the peak/binwidth,
heightparameter->Area of peak, 
bindwidth->width of any bin (example:h->GetBinWidth(1))
n (# of gamma rays from the source)=N/efficiency
n/B.R.(0.99754)=n(Tl-208)
n(Tl-208)/B.R.(0.356)=n(Th-228)
n(Th-228)=A_measured (Assumed to be 1 uCi for this case) 1 Ci=3.7e+10;
Solving we get:
N/(E*0.99754*0.356)=n(Th-228)
After using: n(Th-228)=10 microCurie=10*3.7*e10*10-6,we get : Efficiency(E)=7.611e-6*N)
*/
 // const double multiplier=7.611e-6;
 ofstream myfile("correctmeanN.txt");//Saving the mean energy and number of counts in the given peak
 const double binWidth=h->GetBinWidth(1);
 if(myfile.is_open())
   {
       myfile<<f1->GetParameter(0)<<"\t"<<f1->GetParameter(2)/binWidth<<"\n"
       <<f2->GetParameter(0)<<"\t"<<f2->GetParameter(2)/binWidth<<"\n"
       <<f3->GetParameter(0)<<"\t"<<f3->GetParameter(2)/binWidth<<"\n"
       <<f4->GetParameter(0)<<"\t"<<f4->GetParameter(2)/binWidth<<"\n"
       << f5->GetParameter(0)<<"\t"<<f5->GetParameter(2)/binWidth<<"\n"
         /*(Abnormal termination of minimization. FCN=7.79731 FROM MIGRAD  STATUS=FAILED)*/
       <<f6->GetParameter(0)<<"\t"<<f6->GetParameter(2)/binWidth<<"\n"
       <<f7->GetParameter(0)<<"\t"<<f7->GetParameter(2)/binWidth<<"\n"
       <<f8->GetParameter(0)<<"\t"<<f8->GetParameter(2)/binWidth<<"\n";
       cout<<"successfully stored the data in the file \"correctmeanN.txt\""<<endl;
   }
 else cout<<"Unable to open the \"filecorrectmeanN.txt\" "<<endl;

 /*
 //Writing the Numbers of counts in the different peaks in the file
 myfile<<"//N"<<"\tdN"<<"\n";
 //myfile<<fixed<<setprecision(3); //It is Okay and we can use it
 myfile<<f1->GetParameter(2)<<"\t"<<f1->GetParError(2)<<"\n"
       <<f2->GetParameter(2)<<"\t"<<f2->GetParError(2)<<"\n"
       <<f3->GetParameter(2)<<"\t"<<f3->GetParError(2)<<"\n"
       <<f4->GetParameter(2)<<"\t"<<f4->GetParError(2)<<"\n"
       <<f5->GetParameter(2)<<"\t"<<f5->GetParError(2)<<"\n"
       <<f6->GetParameter(2)<<"\t"<<f6->GetParError(2)<<"\n"
       <<f7->GetParameter(2)<<"\t"<<f7->GetParError(2)<<"\n"
       <<f8->GetParameter(2)<<"\t"<<f8->GetParError(2)<<"\n";*/

 // in.close();
 // myfile.close();
 /*//Storing the value of gaussian mean and bin number
 //Gaussian mean is obtained from paramter 0 of the function where as bin number is
 //obtained from the function
 The function used here is (h->GetXaxis())->FindBin(f1->GetParameter(0))
  FindBin gives the bin corresponding to abscissa*/

 //Creating the file to store the data
 ofstream output("gaussianmean_bin.txt"); 
 if(output.is_open())
   {
     output<<fixed<<setprecision(3);
     output<<(h->GetXaxis())->FindBin(f1->GetParameter(0))<<'\t'<<f1->GetParameter(0)<<'\n'
	 <<(h->GetXaxis())->FindBin(f2->GetParameter(0))<<'\t'<<f2->GetParameter(0)<<'\n'
	 <<(h->GetXaxis())->FindBin(f3->GetParameter(0))<<'\t'<<f3->GetParameter(0)<<'\n'
	 <<(h->GetXaxis())->FindBin(f4->GetParameter(0))<<'\t'<<f4->GetParameter(0)<<'\n'
	 <<(h->GetXaxis())->FindBin(f5->GetParameter(0))<<'\t'<<f5->GetParameter(0)<<'\n'
           //This range is having error in fitting
	 <<(h->GetXaxis())->FindBin(f6->GetParameter(0))<<'\t'<<f6->GetParameter(0)<<'\n'
	 <<(h->GetXaxis())->FindBin(f7->GetParameter(0))<<'\t'<<f7->GetParameter(0)<<'\n'
	 <<(h->GetXaxis())->FindBin(f8->GetParameter(0))<<'\t'<<f8->GetParameter(0)<<'\n';
     cout<<"Successfully stored the mean and bin in the file \"gaussianmean_bin.txt\" "<<endl;
     output.close();
       
   }
 else cout<<"Unable to one the file\" gaussianmean_bin.txt \""<<endl;

 ////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Macro to write measured mean, error in mean, measured number of counts in the peak and error in counts
  ofstream myout("mean_error_N_error.txt");
 if(myout.is_open())
   {
	   myout<<f1->GetParameter(0)<<"\t"<<f1->GetParError(0)<<"\t"
		  <<f1->GetParameter(2)/binWidth<<"\t"<<f1->GetParError(2)<<"\n";
	   myout<<f2->GetParameter(0)<<"\t"<<f2->GetParError(0)<<"\t"
		  <<f2->GetParameter(2)/binWidth<<"\t"<<f2->GetParError(2)<<"\n";
	   myout<<f3->GetParameter(0)<<"\t"<<f3->GetParError(0)<<"\t"
		  <<f3->GetParameter(2)/binWidth<<"\t"<<f3->GetParError(2)<<"\n";
	   myout<<f4->GetParameter(0)<<"\t"<<f4->GetParError(0)<<"\t"
		  <<f4->GetParameter(2)/binWidth<<"\t"<<f4->GetParError(2)<<"\n";
	   myout<<f5->GetParameter(0)<<"\t"<<f5->GetParError(0)<<"\t"
		  <<f5->GetParameter(2)/binWidth<<"\t"<<f5->GetParError(2)<<"\n";
	   myout<<f6->GetParameter(0)<<"\t"<<f6->GetParError(0)<<"\t"
		  <<f6->GetParameter(2)/binWidth<<"\t"<<f6->GetParError(2)<<"\n";
	   myout<<f7->GetParameter(0)<<"\t"<<f7->GetParError(0)<<"\t"
		  <<f7->GetParameter(2)/binWidth<<"\t"<<f7->GetParError(2)<<"\n";
	   myout<<f8->GetParameter(0)<<"\t"<<f8->GetParError(0)<<"\t"
		  <<f8->GetParameter(2)/binWidth<<"\t"<<f8->GetParError(2)<<"\n";
   }
 else
   {
     cout<<"Unable to open the file to write mean, error, N and error"<<endl;
   }
 
 ////////////////////////////////////////////////////////////////////////////////////////////////////////
// myo>Write();

 }
