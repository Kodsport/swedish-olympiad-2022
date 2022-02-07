#!/usr/bin/env python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n', 10))
maxa = int(cmdlinearg('maxa', 10**9))
maxd = int(cmdlinearg('maxd', 10**9))
mina = int(cmdlinearg('mina', 1))
mind = int(cmdlinearg('mind', 1))

print(n)

D = [random.randint(mind, maxd) for _ in range(n)]
X = [random.randint(mind-maxa, maxd-mina) for _ in range(n)]
X.sort()
D.sort()
A = []
I = []
for i in range(n):
    a = D[i] - X[i]
    a = max(a, mina)
    a = min(a, maxa)
    A.append(a)
    I.append(i)

random.shuffle(I)
print(*[D[i] for i in I])
print(*[A[i] for i in I])


