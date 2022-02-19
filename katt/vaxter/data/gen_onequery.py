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
k = int(cmdlinearg('k', 10))
mode = cmdlinearg('mode', 'random')

if mode == 'random':
    A = [random.randint(0,k) for _ in range(n)]
if mode == 'rare_zero':
    A = []
    for i in range(0, n):
        if random.randint(0, n//20) == 0:
            A.append(0)
        else:
            A.append(random.randint(1,k))
if mode == 'big_numbers':
    A = [i for i in range(0,k+1)]
    while len(A) < n:
        A.append(random.randint(0, 10**9))
    random.shuffle(A)

print(n,1)
print(*A)
print(k)

    

