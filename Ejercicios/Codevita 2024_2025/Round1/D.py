
def hour_to_int(hora):
	if "Am" in hora:
		hora = hora.split(':')
		hora = (int(hora[0])) * 60 + int(hora[1][:2])
	else:
		hora = hora.split(':')
		if hora[0] == "12":		
			hora = (int(hora[0])) * 60 + int(hora[1][:2])
		else:
			hora = (int(hora[0]) + 12) * 60 + int(hora[1][:2])
	return hora


n = int(input())
E = []
Cities = set()
H = set()


for i in range(n):
    linea = input()
    linea = linea.split(' ')
    Cities.add(linea[0])
    Cities.add(linea[1])
    inicio = hour_to_int(linea[2])
    final = hour_to_int(linea[3])
    H.add(inicio)
    H.add(final)
    costo = int(linea[4])
    E.append([linea[0], linea[1], inicio, final, costo])
    
linea = input().split()
source = linea[0]
target = linea[1]

Cities.add(source)
Cities.add(target)

linea = input().split(' ')
hora_inicio = hour_to_int(linea[0])
hora_fin = hour_to_int(linea[1])

H.add(hora_inicio)
H.add(hora_fin)

H = list(H)
H.sort()


Cities = list(Cities)
G = {(city, t): [] for t in H for city in Cities}
for e in E:
    G[e[0], e[2]].append([e[1], e[3], e[4]])

for t in range(len(H) - 1):
    for city in Cities:
        G[city, H[t]].append([city, H[t + 1], 0])


# Dijkstra
INF = 1e7
D = {(city, t): INF for city in Cities for t in H}
V = {(city, t): 0 for city in Cities for t in H}

D[source, hora_inicio] = 0

def minDist():
    mn = INF
    mn_ind = -1
    for city in Cities:
        for t in H:
            if D[city, t] < mn and V[city, t] == 0:
                mn = D[city, t]
                mn_ind = (city, t)
    return mn_ind

for t in range(len(Cities) * len(H)):
    u = minDist()
    if u == -1:
        break
    V[u] = 1
    for edge in G[u]:
        v = (edge[0], edge[1])
        cost = edge[2]
        if V[v] == 0 and D[v] > D[u] + cost:
            D[v] = D[u] + cost

# Obtener la respuesta
ans = INF
for t in H:
    if t <= hora_fin:
        ans = min(ans, D[target, t])

if ans == INF:
    print("Impossible")
else:
    print(ans)
    