x = input()
n = len(x)
n2 = n // 2
j = n
palindromo = True
for i in range(n2):
    n -= 1
    if x[i] != x[i + n]:
        palindromo = False
        # print("no es palindromo :c")
    n -= 1
# print("es palindromo")
if palindromo:
    print("Es palindromo :)")
else:
    print("No es palindromo u.u")

# MOD = 
# ceros = sum(x[i] == 0 for i in range(n))
# unos = n - ceros
# for i in range((k + 1) // 2, k + 1):
#     if i >= unos:
#         ans += choose(n, unos)
#         ans %= MOD
# print(ans)
# 
# 
# 
# 