#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main()
{
  //Entering data from two input files
  ifstream meanfile("datafor_error_inefficiency.txt");
  ifstream eff_errorfile("error_in_efficiency.txt");

  //Storing the result in the outputfile
  ofstream output("energy_eff_and_error.txt");

  //Check if the input files are retrieved properly
  if(meanfile.fail())
    {
      cout<<"data_for_efficiency_calculation.txt can't be opend "<<endl;
      return 0;
    }
  if(eff_errorfile.fail())
    {
      cout<<"final_error_efficinecy.txt can't be opend "<<endl;
      return 0;
    }
  //Defining the variable for storing the data from two different files to a single file
  //mean file consists fo three columns of energy, Number of counts and BR for Tl-208
  //eff_errorfile consist of two columns of efficiency and error in efficiency
  double energy,N,BR,eff,error;
  while(true)
    {
      meanfile>>energy>>N>>BR;
      eff_errorfile>>eff>>error;
      if(meanfile.eof()||eff_errorfile.eof())break;
      output<<energy<<'\t'<<eff<<'\t'<<error<<endl;
      
    }
  cout<<"Successfully stored data in the file \"data_energy_eff_error.txt\""<<endl;
  return 0;
}
