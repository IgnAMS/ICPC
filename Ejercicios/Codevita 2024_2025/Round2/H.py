lista = input().split(' ')
d = int(input())
S = []

mp1 = {'Q': 0, 'B': 1, 'R': 2}
mp2 = {'A': 0, 'B': 1, 'C': 2, 'D': 3, 'E': 4, 'F': 5, 'G': 6, 'H': 7}
inicial = []
for element in lista:
    inicial.append(mp1[element[0]] + mp2[element[1]] * 3 + (int(element[2]) - 1) * 3 * 8)
inicial.sort()
S.append(inicial)

rango = list(range(-7, 8))
rango.remove(0)

def possible(tipo, di, dj, mapa):
    opcion = mapa.copy()
    opcion.remove(elemento)
    if di not in range(8) or dj not in range(8):
        return False
    for x in mapa:
        xi = (x // 3) % 8
        xj = (x // 24) % 8
        if xi == di and xj == dj:
            return False
    opcion.append(tipo + di * 3 + dj * 24)
    opcion.sort()
    return opcion

def movimientos(elemento, mapa):
    "recibe: [q, i, j]"
    vecinos = []
    tipo = elemento % 3
    xi = (elemento // 3) % 8
    xj = (elemento // 24) % 8
    if tipo in [0, 1]: # reina o arfil
        for i in range(-1, -8, -1):
            di = i + xi
            dj = i + xj
            val = possible(tipo, di, dj, mapa)
            if val == False:
                break
            if val not in vecinos:
                vecinos.append(val)
        
        for i in range(1, 8):
            di = i + xi
            dj = i + xj
            val = possible(tipo, di, dj, mapa)
            if val == False:
                break
            if val not in vecinos:
                vecinos.append(val)
                
        for i in range(-1, -8, -1):
            di = i + xi
            dj = -i + xj
            val = possible(tipo, di, dj, mapa)
            if val == False:
                break
            if val not in vecinos:
                vecinos.append(val)
                
        for i in range(1, 8):
            di = i + xi
            dj = -i + xj
            val = possible(tipo, di, dj, mapa)
            if val == False:
                break
            if val not in vecinos:
                vecinos.append(val)
                    
    if tipo in [0, 2]:
        for i in range(-1, -8, -1):
            di = i + xi
            dj = xj
            val = possible(tipo, di, dj, mapa)
            if val == False:
                break
            if val not in vecinos:
                vecinos.append(val)
        
        for i in range(1, 8):
            di = i + xi
            dj = xj
            val = possible(tipo, di, dj, mapa)
            if val == False:
                break
            if val not in vecinos:
                vecinos.append(val)
                
        for i in range(-1, -8, -1):
            di = xi
            dj = i + xj
            val = possible(tipo, di, dj, mapa)
            if val == False:
                break
            if val not in vecinos:
                vecinos.append(val)
        for i in range(1, 8):
            di = xi
            dj = i + xj
            val = possible(tipo, di, dj, mapa)
            if val == False:
                break
            if val not in vecinos:
                vecinos.append(val)                
    return vecinos

newS = []
for _ in range(d):
    newS.clear()
    for mapa in S:
        for elemento in mapa:
            contador = 0
            for movimiento in movimientos(elemento, mapa):
                if movimiento not in newS:
                    newS.append(movimiento)
                    contador += 1
    S.clear()
    S = newS.copy()
print(len(S))

