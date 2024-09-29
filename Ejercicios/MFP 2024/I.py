n = int(input())
versos = []
for i in range(n):
    versos.append(input())

m = int(input())
puntajes = dict()
for _ in range(m):
    palabra, puntaje = input().split()
    puntajes[palabra] = int(puntaje)
    
nota_total = 0
best_nota = 0
best_verso = 0

for i in range(n):
    curr_puntaje = 0
    for palabra in versos[i].split():
        if palabra in puntajes.keys():
            curr_puntaje += puntajes[palabra]
    if curr_puntaje >= best_nota:
        best_verso = i + 1
        best_nota = curr_puntaje
    nota_total += curr_puntaje
print(nota_total, best_verso)