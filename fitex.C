void fitex()
{
   // example of macro creating an histogram, fitting it
   // and accessing the fit results
   
   TH1F *h = new TH1F("h","test",100,-4,4);
   ofstream myfile("example1.txt");
   h->FillRandom("gaus",3000);
   h->Fit("pol7");
   
   //Get a pointer to the fitted function
   TF1 *func = (TF1*)h->GetFunction("pol7");
   Int_t npar = func->GetNpar();
   Double_t chi2 = func->GetChisquare();
   printf("Function has % parameters. Chisquare = %g\n",
        npar,func->GetChisquare());
   for (Int_t i=0;i<npar;i++) {
     /* printf("% %s\t, = %\tg, +- %g\n",
	     myfile<<func->GetParName(i),
	     myfile<< func->GetParameter(i),
	     myfile<<func->GetParError(i));
	     /* */
     myfile<<func->GetParName(i);
     // cout<<endl;
     myfile<<'\n';
     myfile<<func->GetParameter(i);
      // cout<<endl;
      myfile<<'\n';
      myfile<<func->GetParError(i);
      myfile<<'\n';
   }
   TFile f("fitex.root","recreate");
   //write histo to the file. Note that the full information about
   //the histogram including the fitted function and its parameters
   // are saved to the file
   h->Write();
   /*  ofstream myfile ("example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile<<func->GerParName(1);
    myfile << "This is another line.\n";
    myfile.close();
    }*/
   // in a new session, one can then do:
   //  TFile *f = new TFile("fitex.root");
   //  TH1F *h = (TH1F*)f->Get("h");
   // and access the info from h as shown above
}
