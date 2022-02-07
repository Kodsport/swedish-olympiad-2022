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
mina = int(cmdlinearg('mina', 1))
x = int(cmdlinearg('x', 0))

maxa = min(maxa, 10**9-x)

print(n)

D = []
A = []
I = []
for i in range(n):
    a = random.randint(mina, maxa)
    d = a+x
    A.append(a)
    D.append(d)
    I.append(i)

random.shuffle(I)
print(*[D[i] for i in I])
print(*[A[i] for i in I])


