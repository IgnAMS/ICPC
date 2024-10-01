lista = [23.0, 24.3, 24.5, 25.1, 25.5, 26.9, 28.3, 30.0, 31.4, 32.0, 34.4, 34.8, 38.5, 39.4]
ans = 0
prom = sum(lista) / len(lista)
for el in lista:
    ans += (el - prom) ** 2
    
print(ans / (len(lista) - 1))
ans = 0
for el in lista:
    ans += el ** 2

print(ans)
print(sum(lista) / len(lista))