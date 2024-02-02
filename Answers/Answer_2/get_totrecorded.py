import re

totrecorded = None

with open("brilcalc.log", "r") as file:
    text = file.read()
    numbers = re.findall("[0123456789.]+", text)
    totrecorded = float(numbers[-1]) #the desired value is the last number in the file

totrecorded = totrecorded/1000 #unit conversion

print(f"Summary luminosity: {totrecorded:.1f} (fb)^(-1)")