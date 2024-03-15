#include <iostream>
#include <fstream>
#include "TGraph.h"
#include "TCanvas.h"

using namespace std;

void Higgs_width_distribution() {

    cout << "start"  << endl;
    
    string data;
    ifstream ReadFile("hdecay_Higgs_masses.txt");

    float mass[150], width[150];
    int n = 150;
    int mass_start = 10;


    int i = -1;
    while (getline (ReadFile, data)) {
        if (i==-1) {
            i++;
            continue;
        } 
        string value = "";
        int j = 0;
        while (data[j]!=':') {
            j += 1;
        }
        j += 2;
        for (int k=0;k<data.length()-j;k++) {
            value += data[j+k];
        }
        mass[i] = mass_start + i;
        width[i] = stof(value);
        i++;
    }

    ReadFile.close();

    auto graph_canvas = new TCanvas();

    auto graph = new TGraph(n,mass,width);
    TString title = "Higgs boson width distribution;M_{H} (GeV);\\Gamma(H) (GeV)";
    graph->SetTitle(title);
    graph->SetLineWidth(2);
    graph->Draw("AC");

    graph_canvas->Print("Higgs_width_distribution.pdf");

    cout << "stop"  << endl;
    return;

}