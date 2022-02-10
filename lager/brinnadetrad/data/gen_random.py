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
maxx = int(cmdlinearg('maxx', 10**9))
mina = int(cmdlinearg('mina', 1))
minx = int(cmdlinearg('minx', 0))
a_order = cmdlinearg('a_order', "none")
distinct_x = int(cmdlinearg('distinct_x', 10**9))

print(n)

A = [random.randint(mina, maxa) for _ in range(n)]
X = [random.randint(minx, maxx) for _ in range(n)]

if distinct_x < n:
    DX = [random.randint(minx, maxx) for _ in range(distinct_x)]
    for i in range(n):
        X[i] = DX[random.randrange(0, distinct_x)-1]

X.sort()
if a_order == "increasing":
    A.sort()
if a_order == "decreasing":
    A.sort()
    A.reverse()
print(*X)
print(*A)
