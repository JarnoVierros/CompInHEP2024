
#include <iostream>
#include "TF1.h"
#include "TTree.h"
#include "TFile.h"
using namespace std;

int main() {

    int N = 1000;

    TFile out_file("normal_distribution.root","RECREATE");

    auto normal_distribution = new TF1("normal_distribution", "[0]*exp(-0.5*((x-[1])/[2])**2)", -100, 100);
    normal_distribution->SetParameter(0, 200);
    normal_distribution->SetParameter(1, 0);
    normal_distribution->SetParameter(2, 1);
    
    TTree t1("t1", "normal distribution");
    float normal_value;
    t1.Branch("normal_value", &normal_value, "normal_value/F");

    for (int i=0;i<N;i++) {
        normal_value = normal_distribution->GetRandom();
        t1.Fill();
    }

    t1.Write();
    out_file.Close();

    cout << "\"normal_distribution.root\" successfully written." << endl;
    
    return 0;

}
