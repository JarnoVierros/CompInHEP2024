
import os

def set_higgs_mass(mass: int):

    with open("./hdecay/hdecay.in", "r") as file:
        lines = file.readlines()
    lines[11] = f"MABEG    = {mass}.D0\n"
    lines[12] = f"MAEND    = {mass}.D0\n"

    with open("./hdecay/hdecay.in", "w") as file:
        file.writelines(lines)

def run_hdecay():
    os.system("cd hdecay/; ./run")

def calc_Higgs_width(mass: int):
    set_higgs_mass(mass)
    run_hdecay()

    with open("./hdecay/br.sm2", "r") as file:
        lines = file.readlines()
        line = lines[3].strip()
        values = line.split(" ")
        width = float(values[-1].strip())
        return width

Higgs_widths = []
for mass in range(10, 161):
    width = calc_Higgs_width(mass)
    Higgs_widths.append((mass, width))

with open("hdecay_Higgs_masses.txt", "w") as file:
    file.write("mass: width\n")
    for item in Higgs_widths:
        file.write(f"{item[0]}: {item[1]}\n")


