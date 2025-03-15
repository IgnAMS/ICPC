import sys

lista = []
while True:
    inp = sys.stdin.readline().strip()
    if inp == "exit":
        break
    if not inp:  
        break
    lista.append(inp)

n = len(lista)

G = {}
parent_name = {}


in_N = [1 for _ in range(n)]

for i, line in enumerate(lista):
    line = line.split(',')
    # print(line[2].strip('\"'))
    # print(line[1].strip('\"'))
    lista[i] = line

lista.sort(key=lambda x: x[2].strip('\"'))

eliminados = set()

for i, line in enumerate(lista):
    if line[2] == "":
        # Any record with no acronym is eliminated from the output. 
        in_N[i] = 0
        continue

    if line[5] == '"Parent Event"' and line[2] in eliminados:
        # All serialized sets that don't have a unique parent event should be eliminated from the output.         
        in_N[i] = 0
        continue
    
    if line[5] == '"Parent Event"' and line[2] in G.keys():
        # All serialized sets that don't have a unique parent event should be eliminated from the output. 
        eliminados.add(line[2])
        del G[line[2]]
        del parent_name[line[2]]    
        continue
    
    if line[5] == '"Parent Event"' and line[2] not in G.keys():
        G[line[2]] = []
        parent_name[line[2]] = line[0]
        
for i, line in enumerate(lista):
    if line[5] == '"Parent Event"' and line[2] in eliminados:
        in_N[i] = 0

for i, line in enumerate(lista):
    if line[2] == "":
        continue
    if line[5] == '"IEEE Event"':
        if line[2] not in G.keys():
            # Any child event without a parent should be eliminated from the output. 
            in_N[i] = 0
        else:
            G[line[2]].append(i)

for i, line in enumerate(lista):
    if in_N[i] == 0:
        continue
    
    if line[5] == '"Parent Event"':
        # Any parent event without children should be exclude from the output. 
        if len(G[line[2]]) == 0:
            in_N[i] = 0
            continue
        digit_project = lista[G[line[2]][0]][4]
        for v in G[line[2]]:
            if lista[v][4] != digit_project:
                digit_project = "???"

        line[4] = digit_project
        print(",".join(line))
        hijos = []
        for v in G[line[2]]:
            hijo = lista[v]
            hijo.append(line[0])
            hijos.append(hijo)

        hijos.sort(key=lambda x: (x[1].strip('\"'), x[0]))

        for hijo in hijos:
            print(",".join(hijo))
