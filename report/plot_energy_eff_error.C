{
  c1=new TCanvas("c1","Energy Vs Efficiency Graph with error bars",20,10,8000,6000);
  //c1->SetFillColor(42);
  c1->SetGrid();
  TGraphErrors *graph = new TGraphErrors("energy_eff_and_error.txt","%lg%lg%lg","");
  graph->SetTitle(";""Energy(eV);""Efficiency(%)");
  graph->GetYaxis()->SetTitleOffset(1.10);
  graph->SetMarkerStyle(20);
  graph->SetMarkerColor(4);
  graph->SetLineColor(kRed);
  // graph->SetLineWidth(2);
  graph->Draw("AP");
  c1->Update();
  //c1->GetFrame()->SetFillColor(21);
  //c1->GetFrame()->SetBorderSize(12);
  c1->Modified();
  c1->SaveAs("witherror.pdf")
}
