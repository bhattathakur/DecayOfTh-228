{
  TCanvas *c=new TCanvas("c","square and cubic graph",400,300);
  // c->Divide(2,1);
  // c->cd(1);
  TGraph *g=new TGraph("test.dat","%lg%lg%*lg","");
  g->Draw("AC");
  // c->cd(2);
  TGraph *f=new TGraph("test.dat","%lg%*lg%lg","");
  //  f->Draw("AC");
  f->Draw("SAME");
}

