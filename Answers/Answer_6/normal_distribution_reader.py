
import ROOT

in_file = ROOT.TFile.Open("normal_distribution.root", "READ")

tree = in_file.Get("t1")

histo = ROOT.TH1F("histo","Normal distribution;x;y",100,-5,5)

for entry in tree:
    histo.Fill(entry.normal_value)

histo_canvas = ROOT.TCanvas()

histo.SetLineColor(1)
histo.SetLineWidth(5)
histo.SetFillColor(5)
histo.DrawClone()

histo.Fit("gaus")

histo_canvas.Print("normal_distribution.pdf");
histo_canvas.Print("normal_distribution.png");
