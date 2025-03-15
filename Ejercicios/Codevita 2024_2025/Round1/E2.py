# Cada hora tiene 30 grados
# Cada minuto tiene 6 grados

linea = input().split(':')
HORA = (int(linea[0]) * 30) % 360
MINUTO = (int(linea[1]) * 6) % 360

q = int(input())

costs = input().split()
A = int(costs[0])
B = int(costs[1])
X = int(costs[2])
Y = int(costs[3])


# Mover la hora en direccion horaria
# Mover el minuto anti horario
def M1(hora, minuto, angle):
    possibilities = []
    for i in range(12):
        new_hora = (hora + i * 30) % 360
        
        # Intersecciones con el minutero
        if hora > new_hora:
            if hora <= minuto or minuto <= new_hora:
                break
        else:
            if hora <= minuto and minuto <= new_hora:
                break
        
        new_minuto = minuto
        j = 0
        while new_minuto != new_hora:
            ang1 = abs(new_minuto - new_hora)
            ang2 = 360 - ang1
            if ang1 == angle or ang2 == angle:
                possibilities.append(
                    (new_hora, new_minuto, (i * 30) * X * A + j * Y * B)
                )
            j += 1
            new_minuto = (new_minuto - 1 + 360) % 360
    return possibilities


# Mover la hora en direccion anti horaria
# Mover el minuto horaria
def M2(hora, minuto, angle):
    possibilities = []
    for i in range(12):
        new_hora = (hora - i * 30 + 360) % 360
        if hora < new_hora:
            if hora >= minuto or minuto >= new_hora:
                break
        else:
            if new_hora <= minuto and minuto <= hora:
                break
        
        new_minuto = minuto
        j = 0
        while new_minuto != new_hora:
            ang1 = abs(new_minuto - new_hora)
            ang2 = 360 - ang1
            if ang1 == angle or ang2 == angle:
                possibilities.append(
                    (new_hora, new_minuto, (i * 30) * X * B + j * Y * A)
                )
            # if new_minuto == new_hora:
            #     break
            j += 1
            new_minuto = (new_minuto + 1) % 360            
    return possibilities

# DP[i, hora, minuto] = min(DP[i + 1, hora2, minuto2])

Queries = []
for i in range(q):
    Queries.append(int(input()))

# 20 * 12 * 360
DP = {
    (i, hora * 30, minuto): -1
    for i in range(q)
    for hora in range(12)
    for minuto in range(360)
}

# 20 * 12 * 360 * 12 
def dp(i, hora, minuto):
    if i == q:
        return 0
    if DP[i, hora, minuto] != -1:
        return DP[i, hora, minuto]
    
    DP[i, hora, minuto] = 1000000000
    
    for (hora2, minuto2, cost) in M1(hora, minuto, Queries[i]):
        DP[i, hora, minuto] = min(
            DP[i, hora, minuto],
            dp(i + 1, hora2, minuto2) + cost
        )
    for (hora2, minuto2, cost) in M2(hora, minuto, Queries[i]):
        DP[i, hora, minuto] = min(
            DP[i, hora, minuto],
            dp(i + 1, hora2, minuto2) + cost
        )
    return DP[i, hora, minuto]

print(dp(0, HORA, MINUTO))