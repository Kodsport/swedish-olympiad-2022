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
x = int(cmdlinearg('x', 3))
y = int(cmdlinearg('y', 5))
z = int(cmdlinearg('z', 2))
noise = int(cmdlinearg('noise', 0))

assert(n == x+y+z)

print(n)
p_sorted = [x, y, z]
p_sorted.sort()
A = [p_sorted[0]] * x + [p_sorted[1]] * y + [p_sorted[2]] * z

for _ in range(abs(noise)):
    diff = 1
    if noise < 0:
        diff = -1
    i = random.randrange(0, n)
    A[i] += diff

random.shuffle(A)

print(*A)
