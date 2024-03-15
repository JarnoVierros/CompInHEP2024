#include <iostream>
#include <fstream>
#include "TGraph.h"
#include "TCanvas.h"
#include "TLegend.h"

using namespace std;

void Higgs_width_comparison() {

    int n = 151;
    float mass[n], mass2[n], mass3[n], hdecay_width[n], feynhiggs_width[n];
    int mass_start = 10;

    for (int i=0;i<n;i++) {
        mass[i] = mass_start + i;
    }

    string hdecay_data;
    ifstream hdecay_ReadFile("hdecay_Higgs_masses.txt");

    int i = -1;
    while (getline (hdecay_ReadFile, hdecay_data)) {
        if (i==-1) {
            i++;
            continue;
        } 
        string value = "";
        int j = 0;
        while (hdecay_data[j]!=':') {
            j += 1;
        }
        j += 2;
        for (int k=0;k<hdecay_data.length()-j;k++) {
            value += hdecay_data[j+k];
        }
        hdecay_width[i] = stof(value);
        i++;
    }

    hdecay_ReadFile.close();

    string feynhiggs_data;
    ifstream feynhiggs_ReadFile("feynhiggs_Higgs_masses.txt");

    i = -1;
    while (getline (feynhiggs_ReadFile, feynhiggs_data)) {
        if (i==-1) {
            i++;
            continue;
        } 
        string value = "";
        int j = 0;
        while (feynhiggs_data[j]!=':') {
            j += 1;
        }
        j += 2;
        for (int k=0;k<feynhiggs_data.length()-j;k++) {
            value += feynhiggs_data[j+k];
        }
        feynhiggs_width[i] = stof(value);
        i++;
    }

    feynhiggs_ReadFile.close();

    auto graph_canvas = new TCanvas();
    graph_canvas->Divide(1, 2);
    graph_canvas->cd(1);
    
    auto hdecay_graph = new TGraph(n,mass,hdecay_width);
    TString title_1 = "Higgs boson width distribution;M_{H} (GeV);\\Gamma(H) (GeV)";
    hdecay_graph->SetTitle(title_1);
    hdecay_graph->SetLineWidth(1);
    hdecay_graph->Draw("AC");

    auto feynhiggs_graph = new TGraph(n,mass,feynhiggs_width);
    feynhiggs_graph->SetLineWidth(1);
    feynhiggs_graph->SetLineColor(2);
    feynhiggs_graph->Draw("C");

    auto legend = new TLegend(0.15, 0.8, 0.25, 0.9);
    legend->AddEntry(hdecay_graph, "hdecay");
    legend->AddEntry(feynhiggs_graph, "FeynHiggs");
    legend->Draw();

    float width_ratio[n];
    for (int i=0;i<n;i++) {
        width_ratio[i] = feynhiggs_width[i]/hdecay_width[i];
    }

    graph_canvas->cd(2);
    
    auto ratio_graph = new TGraph(n,mass,width_ratio);
    
    TString title_2 = "Higgs boson width ratio;M_{H} (GeV);FeynHiggs/hdecay";
    ratio_graph->SetTitle(title_2);
    ratio_graph->SetLineWidth(2);
    ratio_graph->Draw("AC");    


    graph_canvas->Print("Higgs_width_comparison.pdf");

}