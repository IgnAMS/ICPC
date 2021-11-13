lista = [1, 2, 3, 2, 1, 4, 5, 6, 7, 10]
lista.reverse()
ans = 0
mul = 365
for x in lista:
    ans = (ans + x * mul) % 1000000007
    mul = (mul * 365) % 1000000007
print(ans)