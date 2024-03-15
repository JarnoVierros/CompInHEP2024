According to HDECAY, the Higgs boson width for m=125 GeV is 0.4077E-02 GeV.

feynhiggs_data_generator.py and hdecay_data_generator.py use FeynHiggs and hdecay repsectively to create feynhiggs_Higgs_masses.txt and hdecay_Higgs_masses.txt, which contain the decay widths of the Higgs boson for masses from 10 GeV to 160 GeV.

Higgs_width_distribution.cpp and Higgs_width_comparison.cpp are then used to draw the required figures from the data files.

I have excluded the program files of FeynHiggs and hdecay from the github upload.
