import re

totrecorded = None

with open("brilcalc.log", "r") as file:
    text = file.read()
    numbers = re.findall("[0123456789.]+", text)
    totrecorded = float(numbers[-1]) #the desired value is the last number in the file

totrecorded = totrecorded/1000 #unit conversion

print(f"Summary luminosity: {totrecorded:.1f} (fb)^(-1)")

#Problem 3 here:

total = 0

with open("brilcalc.log", "r") as file:
    lines = file.readlines()
    for line in lines:
        line = line.strip()
        if line[0] == "|" and line[-1] == "|":
            if "totrecorded" in line: break
            if "recorded" in line: continue
            values = line[1:-1].split("|")
            total += float(values[-1])

total = total/1000

print(f"Summary luminosity confirmation: {total:.1f} (fb)^(-1)")
print(f"Difference from original: {totrecorded-total} (fb)^(-1)")
