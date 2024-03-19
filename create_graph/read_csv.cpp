#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){

    ifstream myFile;
    myFile.open("test1.csv");
    string line1;
    getline(myFile, line1);
    string tempsym1, tempsym2, line, tempsym3, tempsym4;
    tempsym1 = '\\' ;
    tempsym2 = ",-,-,-" ;
    tempsym3 = '-';
    tempsym4 = "";
    
    if(myFile.is_open()){
        while(getline(myFile, line)){
            std::stringstream ss(line);
            while(getline(ss, line, ',')){
                
                if(line.compare(tempsym1) != 0 && line.compare(tempsym2) != 0 && line.compare(tempsym3) != 0 && line.compare(tempsym4) !=0)
                    {   
                        if(line.back() == '\\'){
                            line.erase(line.end());
                        }
                        cout<< line <<endl;
                    }
            }
        }
    }
 
}