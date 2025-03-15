linea = input().split()
n = int(linea[0])
m = int(linea[1])
mat = []
source = [0, 0]
dir_s = ""
target = [0, 0]
dir_t = ""

for i in range(n):
    s = "".join(input().split(' '))
    mat.append(s)

for i in range(n):
    for j in range(m):
        # Vertical
        if i + 1 < n and mat[i][j] == 'S' and mat[i + 1][j] == 'S':
            target = [i, j]
            dir_t = "down"
        if i + 1 < n and mat[i][j] == 's' and mat[i + 1][j] == 's':
            source = [i, j]
            dir_s = 'down'
            
        # Horizontal
        if j + 1 < m and mat[i][j] == 'S' and mat[i][j + 1] == 'S':
            target = [i, j]
            dir_t = "right"
        if j + 1 < m and mat[i][j] == 's' and mat[i][j + 1] == 's':
            source = [i, j]
            dir_s = "right"
            
# direction can be right or down
def rotable(i, j, direction):
    possibilities = [] 
    if direction == 'down':
        if j + 1 < m and mat[i][j + 1] != 'H' and mat[i + 1][j + 1] != 'H':
            possibilities.append((i,     j, 'right'))
            possibilities.append((i + 1, j, 'right'))
        if j > 0 and mat[i][j - 1] != 'H' and mat[i + 1][j - 1] != 'H':
            possibilities.append((i,     j - 1, 'right'))
            possibilities.append((i + 1, j - 1, 'right'))
    else:
        if i + 1 < n and mat[i + 1][j] != 'H' and mat[i + 1][j + 1] != 'H':
            possibilities.append((i, j, 'down'))
            possibilities.append((i, j + 1, 'down'))
        if i > 0 and mat[i - 1][j] != 'H' and mat[i - 1][j + 1] != 'H':
            possibilities.append((i - 1, j, 'down'))
            possibilities.append((i - 1, j + 1, 'down'))
            
    return possibilities

# BFS
from collections import deque
q = deque()

D = {
    (i, j, direction): 1e7
    for i in range(n)
    for j in range(m)
    for direction in ["right", "down"] 
}

q.append((source[0], source[1], dir_s))
D[source[0], source[1], dir_s] = 0
while q:
    curr = q.popleft()
    i, j, direction = curr
    # print(curr, D[curr])
    # print("holi woli :)")
    for pos in rotable(i, j, direction):
        if D[pos] > D[curr] + 1:
            D[pos] = D[curr] + 1
            q.append(pos)
            
    if direction == 'right':
        if j > 0 and mat[i][j - 1] != 'H' and D[i, j - 1, direction] > D[curr] + 1:
            D[i, j - 1, direction] = D[curr] + 1
            q.append((i, j - 1, direction))
        if j + 2 < m and mat[i][j + 2] != 'H' and D[i, j + 1, direction] > D[curr] + 1:
            D[i, j + 1, direction] = D[curr] + 1
            q.append((i, j + 1, direction))
        
        if i + 1 < n and mat[i + 1][j] != 'H' and mat[i + 1][j + 1] != 'H' and D[i + 1, j, direction] > D[curr] + 1:
            D[i + 1, j, direction] = D[curr] + 1
            q.append((i + 1, j, direction))
        if i > 0 and mat[i - 1][j] != 'H' and mat[i - 1][j + 1] != 'H' and D[i - 1, j, direction] > D[curr] + 1:
            D[i - 1, j, direction] = D[curr] + 1
            q.append((i - 1, j, direction))
            
        
    else:
        if i > 0 and mat[i - 1][j] != 'H' and D[i - 1, j, direction] > D[curr] + 1:
            D[i - 1, j, direction] = D[curr] + 1
            q.append((i - 1, j, direction))
        if i + 2 < n and mat[i + 2][j] != 'H' and D[i + 1, j, direction] > D[curr] + 1:
            D[i + 1, j, direction] = D[curr] + 1
            q.append((i + 1, j, direction))
            
        if j + 1 < m and mat[i][j + 1] != 'H' and mat[i + 1][j + 1] != 'H' and D[i, j + 1, direction] > D[curr] + 1:
            D[i, j + 1, direction] = D[curr] + 1
            q.append((i, j + 1, direction))
        
        if j > 0 and mat[i][j - 1] != 'H' and mat[i + 1][j - 1] != 'H' and D[i, j - 1, direction] > D[curr] + 1:
            D[i, j - 1, direction] = D[curr] + 1
            q.append((i, j - 1, direction))
            
if D[target[0], target[1], dir_t] == 1e7:
    print("Impossible")
else:
    print(D[target[0], target[1], dir_t])