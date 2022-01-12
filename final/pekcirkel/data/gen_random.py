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
maxa = int(cmdlinearg('maxa', n))
same = int(cmdlinearg('same', 0))

print(n)
A = [random.randint(1, maxa) for _ in range(n)]
if same == 1:
    A = [maxa] * n
print(*A)
