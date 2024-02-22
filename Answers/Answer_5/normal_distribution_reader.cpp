
#include <iostream>
#include "TF1.h"
#include "TH1F.h"
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
using namespace std;

void normal_distribution_reader() {

    TFile in_file("normal_distribution.root");

    TTree* tree;
    in_file.GetObject("t1", tree);

    float normal_value;
    tree->SetBranchAddress("normal_value", &normal_value);

    TH1F histo("histo","Normal distribution;x;y",100,-5,5);

    for (int i;i<tree->GetEntries();i++) {
        tree->GetEntry(i);
        histo.Fill(normal_value);
    }

    auto histo_canvas = new TCanvas();

    histo.SetLineColor(1);
    histo.SetLineWidth(5);
    histo.SetFillColor(5);
    histo.DrawClone();

    histo.Fit("gaus");

    histo_canvas->Print("normal_distribution.pdf");
    histo_canvas->Print("normal_distribution.png");

}
