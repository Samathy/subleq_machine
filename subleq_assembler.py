#!/usr/bin/python3
asm_values = open("subleq.asm").read().split() 
print("Generated tokens")
print (asm_values)


with open('subleq.bin', 'wb') as f: #TODO Add check for succesful open
    for items in asm_values:
        f.write(int(items).to_bytes(1,byteorder='big',signed=True))

print("Wrote file")
f.close()
