linea = input().split()
n = int(linea[0])
m = int(linea[1])
matrix = []
for i in range(n):
    s = "".join(input().split(' '))
    matrix.append(s)

# for i in range(n):
#     print(matrix)
    

Dirs = ["up", "left", "right", "down"]

    

def next_move(direction, i, j):
    if direction == 'up':
        return i - 1, j
    if direction == "down":
        return i + 1, j
    if direction == "right":
        return i, j + 1
    if direction == "left":
        return i, j - 1

def next_dir(direction, i, j):
    di, dj = next_move(direction, i, j)
    if matrix[di][dj] == '0':
        return direction
    if matrix[di][dj] == '/':
        if direction == 'up':
            return 'right'
        if direction == 'down':
            return 'left'
        if direction == 'left':
            return 'down'
        if direction == 'right':
            return 'up'
    if matrix[di][dj] == '\\':
        if direction == 'up':
            return 'left'
        if direction == 'down':
            return 'right'
        if direction == 'left':
            return 'up'
        if direction == 'right':
            return 'down'
    
V = {
    (direction, i, j): 0
    for direction in Dirs
    for i in range(n)
    for j in range(m)
}

P = {
    (direction, i, j): (-1, -1, -1)
    for direction in Dirs
    for i in range(n)
    for j in range(m)
}

mp_dir = {'up': 0, 'left': 1, 'right': 2, 'down': 3}

Cycles = []
curr = set()
def dfs(direction, i, j):
    if matrix[i][j] != '0':
        curr.add(i * 4 * n + j * 4 + mp_dir[direction])
    V[direction, i, j] = 1
    di, dj = next_move(direction, i, j)
    if di == -1 or dj == -1 or di == n or dj == m:
        return
    next_direction = next_dir(direction, i, j)
    value = di * 4 * n + dj * 4 + mp_dir[next_direction]
    if V[next_direction, di, dj] and value in curr:
        new_cycle = [[di, dj]]
        while P[direction, i, j][0] != -1:
            new_cycle.append([i, j])
            direction, i, j = P[direction, i, j]
        Cycles.append(new_cycle)
    else:
        P[next_direction, di, dj] = (direction, i, j)
        dfs(next_direction, di, dj)

for direction in Dirs:
    for i in range(n):
        for j in range(m):
            if V[direction, i, j] == 0 and matrix[i][j] != '0':
                curr = set()
                dfs(direction, i, j)
                
ans = 0
for cycle in Cycles:
    ans = max(ans, len(cycle))
print(ans)