#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

//Constants used 
const  double Activity=3.7*pow(10.0,4.0);
const double bRatio_Th228=0.356;
const double liveTime=1319.10;
//Function to calculate the efficiency for the given branching ratio and Number of Counts (N)	    
double efficiency(double bRatio_Tl208,double N)
{
  
  return (N*100.0)/(bRatio_Th228*Activity*bRatio_Tl208*liveTime);
}

int main()
{
  ifstream input("energy_N_BR.txt");/*Stores Energy of peak, Number of Counts in each peak and Branching ratio closer to peak energy*/
  ofstream output("energy_efficiency.txt");

  //Check if the file is opened properly
  if(input.fail())
    {
      cout<<"could not open the file \"energy_N_BR.txt\"! "<<endl;
      return 0;
    }
  
  while(true)
    {
      double x,y,z;//energy, N ,BR
      input>>x>>y>>z;
      if(input.eof())break;/*If we try to use eof in while get repetation of last line */
      double result=efficiency(z,y);
      output<<setprecision(5);
      output<<x<<'\t'<<'\t'<<result<<'\n';
    }
  input.close();
  output.close();
  cout<<"Successfully stored the data in the file \"energy_efficiency.txt\" "<<endl;
  return 0;
}
