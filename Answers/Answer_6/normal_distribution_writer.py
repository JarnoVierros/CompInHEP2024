
import ROOT
from array import array

N = 1000

out_file = ROOT.TFile.Open("normal_distribution.root", "RECREATE")

normal_distribution = ROOT.TF1("normal_distribution", "[0]*exp(-0.5*((x-[1])/[2])**2)", -100, 100)
normal_distribution.SetParameter(0, 200)
normal_distribution.SetParameter(1, 0)
normal_distribution.SetParameter(2, 1)

t1 = ROOT.TTree("t1", "normal distribution")
normal_value = array("f", [0.0])
t1.Branch("normal_value", normal_value, "normal_value/F")

for i in range(N):
    normal_value[0] = normal_distribution.GetRandom()
    t1.Fill()

t1.Write()
out_file.Close()

print("\"normal_distribution.root\" successfully written.")
