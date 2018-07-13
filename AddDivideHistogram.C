{
 
  auto sig_h=new TH1F("sig_h","Signal Histogram",50,0,10);
  auto gaus_h1=new TH1F("gaus_h1","Gauss Histo1",30,0,10);
  auto gaus_h2=new TH1F("gaus_h2","Gauss Histo2",30,0,10);
  auto bkg_h=new TH1F("exp_h","Exponential Histo",50,0,10);
  //Simulate the measurements
  TRandom3 rndgen_5_2;

  for(int imeas=0;imeas<4000;imeas++)
    {
      bkg_h->Fill(rndgen_5_2.Exp(4));
      if(imeas%4==0)gaus_h1->Fill(rndgen_5_2.Gaus(5,2));
      if(imeas%4==0)gaus_h2->Fill(rndgen_5_2.Gaus(5,2));
      if(imeas%10==0)sig_h->Fill(rndgen_5_2.Gaus(5,0.5));
				  
		  
    }
  //Format Histogram
  int i=0;
  for(auto hist:{sig_h,bkg_h,guas_h1,gaus_h2}){
    format_h(hist,1+i++);
  }
  //Sum
  auto sum_h=new TH1F(*bkg_h);
  sum_h->Add(sig_h,1.);
  sum_h->SetTitle("Exponential + Gaussian;X variable;Y variable");
  format_h->(sum,kBlue);
  auto canvas_5_2_sum=new TCanvas();
  sum_h->Draw("hist");
  bkg_h->Draw("SameHist");
  sig_h->Draw("SameHist");
}
 void format_h(TH1F* h,int linecolor)
  {
    h->SetLineWidth(3);
    h->SetLineColor(linecolor);
  }
