{
  c1=new TCanvas("c1","Energy Vs Efficiency Graph with error bars",20,10,8000,6000);
  c1->SetFillColor(42);
  c1->SetGrid();
  TGraphErrors *graph = new TGraphErrors("energy_efficiency_error.txt","%lg%lg%lg","");
  graph->SetTitle("Efficiency Vs Energy with Error;""Energy(eV);""Efficiency(%)");
  graph->SetMarkerStyle(21);
  graph->SetMarkerColor(4);
  graph->SetLineColor(2);
  graph->SetLineWidth(2);
  graph->Draw("AP");
  c1->Update();
  c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(12);
  c1->Modified();
}
