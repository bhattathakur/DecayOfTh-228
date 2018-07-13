#include <iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    string line;
    ifstream myfile("th228_03.chn.dat");
    ofstream outputfile("out2.txt");
    int count=0;
    if(myfile.is_open()&& outputfile.is_open()){
        while(getline(myfile,line)){
           if(count<6 || count>8197) line.clear();
            cout<<line<<'\n';
            if(line.size()>0)outputfile<<line<<'\n';
            count++;
        }
       myfile.close();
       outputfile.close();
    }
    else cout<<"Unable to open file";

return 0;
}
