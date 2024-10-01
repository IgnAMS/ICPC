cont=0
for i in range(1,10):
    for j in range(1,i+1):
        for z in range(1,min(i,j)+1):
            print(i,j,z)
            cont+=1

print(cont)