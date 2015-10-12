

asm_values = open("subleq.asm").read().split() 
print (asm_values)


with open('subleq.bin', 'wb') as f:
    for items in asm_values:
        print("writing "+str(int(items)))
        f.write(int(items).to_bytes(1,byteorder='big',signed=True))
f.close()
