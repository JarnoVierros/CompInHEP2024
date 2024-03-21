pythia_path := /home/jarno/pythia8311

all: 
	make Higgs_width_calculation
	make Higgs_width

Higgs_width_calculation: Higgs_width_calculation.cpp
	$(CXX) Higgs_width_calculation.cpp -L $(pythia_path)/lib/ -l pythia8 -o Higgs_width_calculation
	
Higgs_width: Higgs_width_fit.cpp
	$(CXX) Higgs_width_fit.cpp $$(root-config --glibs --cflags --libs) -L $(pythia_path)/lib/ -l pythia8 -o Higgs_width_fit
