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
  gStyle->SetOptFit(0011);//SetOptFit(pcev), p->prob ,c->chi square/#df, e->error,v->value of parameters when e=1,v=1, SetOptFit(1)=SetOptFit(111),v=1->only non fixed parameters, v=2->all paramters
  graph->Draw();
  c->Update();
  
}
