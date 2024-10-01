ans=[]
while True:
    linea=input()
    if linea=='-1':
        break
    lista = linea.split('\t')
    #print(lista)
    ans.append(lista[2])

print(ans)
for i in ans:
    print(i)
