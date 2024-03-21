
#include <iostream>
#include <iomanip>

#include "Pythia8/Pythia.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TFitResultPtr.h"
#include "TFitResult.h"
#include "TLatex.h"
#include "TString.h"

using namespace Pythia8;

float calc_mass(float E, float px, float py, float pz) {
    return sqrt(E*E - px*px - py*py - pz*pz);
}

int main() {

    const float Higgs_mass = 125;
    const int event_count = 1000;

    TH1F* histo = new TH1F("h1", "Higgs boson mass distribution;M_{H} (GeV);events / 1 MeV", 100, 124.95, 125.05);

    Pythia pythia;

    pythia.readString("PDF:pSet=LHAPDF6:cteq6l1");

    pythia.readString("25:m0 = " + to_string(Higgs_mass));
    pythia.readString("HiggsSM:all = on");
    pythia.readString("Beams:eCM = 8000.");
    pythia.init();

    float event_H_mass;
    for (int iEvent = 0; iEvent < event_count; ++iEvent) {
        pythia.next();
        for (int i=0; i<pythia.event.size(); ++i) {
            
            if (pythia.event[i].id() == 25) {
                event_H_mass = calc_mass(pythia.event[i].p()[0], pythia.event[i].p()[1], pythia.event[i].p()[2], pythia.event[i].p()[3]);
            }
        }
        //cout << "Higgs mass: " << event_H_mass << endl;
        histo->Fill(event_H_mass);
    }

    pythia.stat();

    cout << endl << endl << endl;

    auto histo_canvas = new TCanvas();

    histo->DrawClone();

    TF1 BreitWigner_fit("BreitWigner_fit", "[0]*TMath::BreitWigner(x,[1],[2])", 124.95, 125.05);
    BreitWigner_fit.SetParameters(9.820e-01, 1.250e+02, 3.804e-03);

    auto fit_result = histo->Fit(&BreitWigner_fit, "S","",124.95,125.05);

    TString width_string = to_string(BreitWigner_fit.GetParameters()[2]*1000);
    width_string = string(width_string, 0, 3);

    TString width_error_string = to_string(fit_result->ParError(2)*1000);
    width_error_string = string(width_error_string, 0, 3);

    TString latex_text = "\\Gamma = (" + width_string + "\\pm" + width_error_string + ") MeV";
    TLatex text1(125.01, 100, latex_text);
    text1.DrawClone();

    cout << endl << endl;
    cout << "The Breit-Wigner width is: (" << to_string(BreitWigner_fit.GetParameters()[2]*1000) << "±" << to_string(fit_result->ParError(2)*1000) << ") MeV" << endl << endl;

    histo_canvas->Print("Higgs_width_fit.pdf");

    return 0;
}