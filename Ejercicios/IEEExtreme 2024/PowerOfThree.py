import math
import random

def power(a, b):
    result = 1
    while b:
        if b & 1:
            result = result * a
        a = a * a
        b >>= 1
    return result

N = input()
sz = len(N)

x = math.ceil(sz / math.log10(3))
c = power(3, x)

done = False
for t in range(3):
    c //= 3
    if c < 1:
        break

    # print(f"trying {c}")
    x -= 1
    cc = c
    good = True

    idxs = random.sample(range(1, sz + 1), min(10000, sz))
    idxs.sort()
    prev = 0
    for idx in idxs:
        cc //= power(10, idx - prev - 1)
        prev = idx - 1
        if int(N[-idx]) != cc % 10:
            good = False
            break

    if good:
        print(x)
        done = True
        break

if not done:
    print(-1)