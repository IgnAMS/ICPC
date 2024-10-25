DP = dict()
k = 2
def dp(i, j, t):
    if i == j and t != 0:
        return 0
    if (i, j) in DP.keys():
        return DP[i, j]
    
    DP[i, j] = 1
    for a in range(1, 7): 
        DP[i, j] += dp((i + a) % k, j, t + 1) * 1 / 6
    print(f"DP[{i}, {j}] = {DP[i, j]}")
    return DP[i, j]

print(dp(0, 0, 0))

# Puedo hacerlo en k pasos sumando 1 a uno con probabilidad (1/6)^k
# Puedo hacerlo en k-1 pasos suamndo 1 a uno con un +2 con probabilidad (1/6)^{} + (1/6)^{}
# 


