
void gonly() {
   TH1F *h1 = new TH1F("h1","test1",100,-2,2);
   TF1 f1("f1","gaus",-2,2);
   f1->SetParameters(1,-0.5,1);
   h1->FillRandom("f1",10000);
   TH1F *h2 = new TH1F("h2","test2",100,-2,2);
   f1->SetParameters(1,0.5,0.3);
   h2->FillRandom("f1",3200);
   h1->Fit("gaus","0");
   h2->Fit("gaus","0");
   TF1 *fit1 = (TF1*)h1->GetFunction("gaus");
   TF1 *fit2 = (TF1*)h2->GetFunction("gaus");
   fit1->SetLineColor(kRed);
   fit2->SetLineColor(kBlue);
   fit1->Draw();
   fit2->Draw("same");
   char text[100];
   sprintf(text,"f1 = %g*e^{#frac{x%g}{%g}}",
      fit1->GetParameter(0),
      fit1->GetParameter(1),
      fit1->GetParameter(2));
   TLatex *l1 = new TLatex(-1.7,60,text);
   l1->SetTextSize(0.04);
   l1->SetTextFont(72);
   l1->SetTextColor(kRed);
   l1->Draw();
   sprintf(text,"f2 = %g*e^{#frac{x-%g}{%g}}",
      fit2->GetParameter(0),
      fit2->GetParameter(1),
      fit2->GetParameter(2));
   TLatex *l2 = new TLatex(0.7,160,text);
   l2->SetTextSize(0.04);
   l2->SetTextFont(72);
   l2->SetTextColor(kBlue);
   l2->Draw();
}   
/*Hi Farah,

An example below

Rene Brun

On Sat, 7 Dec 2002, Farahnaaz Nauyock wrote:

> Hi there,
> 
> I'm trying to fit my histogram by using a gaussian distribution. It works
> fine except from the fact that....
> 
> I want to:
> 
> 1.end up with only the gaussian plot and not the original graph that was
> being fitted (I used the function Get to get the original graph but it
> didn't work)
> 
> 2.draw other fitted gaussian plots on the same canvas for different
> graphs.
> 
> Also is there a way for root to give the gaussian equation on the canvas,
> rather than the fitted parameters?
> 
> Cheers,
> Farah
> 
> */
