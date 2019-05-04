{
  TCanvas * c=new TCanvas("c","graph",10,20,2000,3000);
  c->SetGrid();
  TGraph *graph=new TGraph("gaussianmean_bin.txt","%lg%lg","");
  graph->GetXaxis()->SetTitle("BinNumber");
  graph->GetYaxis()->SetTitle("Gaussian mean(eV)");
  graph->SetTitle("");
  graph->SetLineColor(4);
  graph->SetMarkerStyle(20);
  graph->Draw();
  graph->Fit("pol1");
  graph->SetMarkerSize(2);
  graph->GetYaxis()->SetTitleOffset(1.5);
  //TPaveStats * stats1 = (TPaveStats*)graph->GetListOfFunctions()->FindObject("stats");
  //stats1->SetX1NDC(0.12); stats1->SetX2NDC(0.32); stats1->SetY1NDC(0.75);
  gStyle->SetOptFit(0);//SetOptFit(pcev), p->prob ,c->chi square/#df, e->error,v->value of parameters when e=1,v=1, SetOptFit(1)=SetOptFit(111),v=1->only non fixed0 parameters, v=2->all paramters

  //Trying to modify the statbox using TPaveStat
  TPaveText * pt=new TPaveText(0.75,0.63,0.90,0.73,"NDC");
  //  pt->SetNDC();
  double par0=graph->GetFunction("pol1")->GetParameter(0);
  double par1=graph->GetFunction("pol1")->GetParameter(1);
  double par0error=graph->GetFunction("pol1")->GetParError(0);
  double par1error=graph->GetFunction("pol1")->GetParError(1);
  
  
  pt->AddText("Parameters");
  pt->AddText(Form("p0      \t%f#pm%f",par0,par0error));
  pt->AddText(Form("p1      \t%f#pm%f",par1,par1error));
  
  gPad->Modified();
  gPad->Update();

  graph->Draw();
    pt->Draw();
    c->Update();
    c->SaveAs("meanvsbin.pdf");
  
}
