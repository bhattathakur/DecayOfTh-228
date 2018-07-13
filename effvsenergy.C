//Efficiey vs energy
//Energy Efficiency
/*235.5	 0.0497836
273.7	 0.00197125
296.2	 0.003523689
504.1	 0.00571586
775.6	 0.0202072
718	 0.00420127
849.7	 0.00265624
2582	 0.00896576*/
/*
{
  Int_t n=8;
  Double_t x[]={235.5,273.7,296.2,504.1,775.6,718,849.7,2582};
  Double_t y[]={0.0497836,0.00197125,0.003523689,0.00571586,0.0202072,0.00420127,0.00265624,0.00896576};
  TGraph *gr=new TGraph(n,x,y);
  //TCanvas *c1=new TCanvas("c1","Graph Draw Options",200,10,600,400);
  gr->Draw("AC");
}*/
//Method 2
{
  //Constructor for the graph when data are given in the column form
  //TGraph(const char* filename, const char* format = "%lg %lg", Option_t* option = "")
  //When don't want to include any column use *after % i.e. "%lg %*lg %lg excludes the second column of the data

  TGraph *graph=new TGraph("finalresult.txt","%lg%lg","");
  graph->Draw("AC*");
  graph->SetLineColor(kBlue);
  graph->GetXaxis()->SetTitle("Energy (KeV)");
    
}
