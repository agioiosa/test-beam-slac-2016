#include <iostream>
#include <fstream>
#include <string>
#include "TString.h"
#include <TCanvas.h>
#include <cstdlib>

#include "SLAC2016Cruncher.h"

int main (int argc, char **argv) {

    TCanvas *mydummycanvas = new TCanvas(); 

    string temp[100];
    cout << "###############################################################" << endl;
    cout << "#####      Welcome to SLAC 2016 Crunching framework!      #####" << endl;
    cout << "###############################################################" << endl;
    cout << " " << endl;
    cout << "## Reading rootfiles to be crunched........." << endl;
    cout << " " << endl;

    unsigned int size=0; 
    string line;
    ifstream inData (argv[1]); 

    while ( !inData.eof() )
    {
        getline (inData, line); //get contents of infile 
        cout << line << endl; //output contents of infile   
        size++;
    } 


    for(unsigned int j=1;j<size;j++){
         TString fname;
        if (argc > 1)
        {
            ifstream fin (argv[1]);
            if (!fin.is_open ())
            {
                cerr << "file open error:" << argv[1] << endl;
                exit (1);
            }
            unsigned int i = 0;
            while (fin >> fname)
            {
                i++;
                if(i==j){
                    temp[i] = fname;
                    int n = temp[i].rfind ("/"); // find the position in string of the last "/"
                    temp[i].erase (0, n + 1);	// erase substring in front of it including itself
                    // cout << temp[i] << endl; // print the input rootfile name
                }
            }
        }
        else
        {
            cerr << "no input file" << endl;
            exit (1);
        }
        SLAC2016Cruncher crunch(temp[j]);

        cout <<"###################################################################"<< endl;
        cout <<"##    Current file is : "<< temp[j] << "   ##"<<endl; // print the input rootfile name
        cout <<"###################################################################"<< endl;

        crunch.Loop();
        crunch.~SLAC2016Cruncher();
    }

    return 0;
}
