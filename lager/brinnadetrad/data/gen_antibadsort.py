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
n = int(cmdlinearg('n', 100))
maxd = int(cmdlinearg('maxd', 10**9))


D = []
A = []
I = []

sum = 0
for i in range(0,n):
    a = 1+i%2
    x = sum+1
    if i%2 == 1:
        x = D[i-1]-A[i-1]
    d = a+x
    if d > maxd:
        break
    sum += a
    A.append(a)
    D.append(d)
    I.append(i)

print(len(I))
random.shuffle(I)
print(*[D[i] for i in I])
print(*[A[i] for i in I])


