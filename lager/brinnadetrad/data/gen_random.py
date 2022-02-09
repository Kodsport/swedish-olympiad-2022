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

print(n)

A = [random.randint(mina, maxa) for _ in range(n)]
X = [random.randint(minx, maxx) for _ in range(n)]
X.sort()
print(*X)
print(*A)
