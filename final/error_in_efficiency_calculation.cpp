#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
  //Defining the input file and output file
  ifstream input("datafor_error_inefficiency.txt");//Contains N,dN,BR1,dBR1,BR2,dBR2,Eff
  ofstream output("efficiency_error.txt");

  //Checking if input file exists
  if(input.fail())
    {
      cout<<"Unable to open the file"<<endl;
      return 0;
    }
  
  /*Defining the variables for the different columns of the data.
Input file consists of columns of N->NumberOfCounts obtaiend from the fit
 N=constant parameter/h->GetBinWidth(1)
dN is also obtained from the error of constant parameter, 
BR1 is obtained from the branching ratios of Tl-208 based on Nudat2 dBR1 are the corresponding errors. 
BR2 is fixed actually obtained form
the Branching ratio of Bi-212. Efficiency is calculated from differently using the file.
   */
  
  double N,dN,BR1,dBR1,BR2,dBR2,E;
  while(true)
    {
      input>>N>>dN>>BR1>>dBR1>>BR2>>dBR2>>E;
      if(input.eof())break;
      double a=dN/N;
      double b=dBR1/BR1;
      double c=dBR2/BR2;
      double dE=sqrt(a*a+b*b+c*c)*E;
      output<<E<<'\t'<<'\t'<<dE<<endl;
    }
  cout<<"Successfully stored the ouptut in the file \"efficiency_error.txt\"!"<<endl;
  return 0;
}
