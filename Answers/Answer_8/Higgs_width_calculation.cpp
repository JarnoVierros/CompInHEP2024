
#include "Pythia8/Pythia.h"

using namespace Pythia8;

int main() {

    const float Higgs_mass = 125;

    Pythia pythia;

    pythia.readString("25:m0 = " + to_string(Higgs_mass));
    pythia.init();

    cout << "Mass: " << pythia.particleData.m0(25) << ", Width: " << pythia.particleData.mWidth(25)*1000 << " MeV" << endl;

    return 0;
    
}