
import subprocess

#proc = subprocess.Popen(["./FeynHiggs-2.19.0/FeynHiggs2.18.0_Linux", "./FeynHiggs-2.19.0/var.in"], stdout=subprocess.PIPE, shell=True)
proc = subprocess.Popen(["./FeynHiggs-2.19.0/FeynHiggs2.18.0_Linux ./FeynHiggs-2.19.0/var.in"], stdout=subprocess.PIPE, shell=True)
(out, err) = proc.communicate()
output = str(out)
start = output.find("GammaTot-SMA0")
start = output[start:].find("=")+start+1
stop = output[start:].find("\\n") + start
value = output[start:stop]
width = float(value.strip())




def set_higgs_mass(mass: int):

    with open("./FeynHiggs-2.19.0/var.in", "r") as file:
        lines = file.readlines()
    
    lines[2] = f"MA0          {mass}\n"

    with open("./FeynHiggs-2.19.0/var.in", "w") as file:
        file.writelines(lines)

def calc_Higgs_width(mass: int):
    set_higgs_mass(mass)

    proc = subprocess.Popen(["./FeynHiggs-2.19.0/FeynHiggs2.18.0_Linux ./FeynHiggs-2.19.0/var.in"], stdout=subprocess.PIPE, shell=True)
    (out, err) = proc.communicate()
    output = str(out)

    start = output.find("GammaTot-SMA0")
    start = output[start:].find("=")+start+1
    stop = output[start:].find("\\n") + start
    value = output[start:stop]
    width = float(value.strip())
    return width

Higgs_widths = []
for mass in range(10, 161):
    width = calc_Higgs_width(mass)
    Higgs_widths.append((mass, width))

with open("feynhiggs_Higgs_masses.txt", "w") as file:
    file.write("mass: width\n")
    for item in Higgs_widths:
        file.write(f"{item[0]}: {item[1]}\n")


