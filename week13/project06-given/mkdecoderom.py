import sys

print("v2.0 raw")

for line in sys.stdin:
    binstr = line.strip()[2:]
    if binstr == "":
        continue
    ivalue = int(binstr, 2)
    hexstr = hex(ivalue)
    print(hexstr)
