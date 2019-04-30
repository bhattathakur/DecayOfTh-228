{
  TCanvas * c=new TCanvas("c","graph",10,20,2000,4000);
  c->SetGrid();
  TGraph *graph=new TGraph("energy_eff_and_error.txt","%lg%lg%*lg","");/*Energy efficiency error*/
  graph->GetXaxis()->SetTitle("Energy(eV)");
  graph->GetYaxis()->SetTitle("Efficiency(%)");
  graph->SetTitle("Energy Vs Efficiency plot");
  graph->SetLineColor(2);
  graph->SetLineWidth(2);
  graph->SetMarkerStyle(kFullDotLarge);
  graph->SetMarkerSize(2);
  graph->SetMarkerColor(4);
  graph->Draw("APL");
  //graph->Draw();
  c->Update();
  
}
