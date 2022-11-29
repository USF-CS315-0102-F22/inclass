import sys

print("v2.0 raw")

for line in sys.stdin:
    hexvals = [hex(ord(line[i]))[2:] for i in range(4)]
    hexstr = '0x' + ''.join(hexvals)
    print(hexstr)

    #for i in range(4):
    #    v = ord(line[i])
    #    
    #    print(hex(v))

    #binstr = line.strip()[2:]
    #if binstr == "":
    #    continue
    #ivalue = int(binstr, 2)
    #hexstr = hex(ivalue)
    #print(hexstr)
