import random

t = 100

with open("test.txt", "w") as file:
    aux = str(t) + '\n'
    file.write(aux)
    
for _ in range(t):
    n = random.randint(4, 6)
    k = random.randint(0, n)
    s = ""
    for i in range(n):
        s += (str(random.randint(0, 1)))
    with open("test.txt", "a") as file:
        file.write(str(n) + " " + str(k) + '\n')
        file.write(s + '\n')
    