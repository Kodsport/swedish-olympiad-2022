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
q = int(cmdlinearg('q', 10))
maxv = int(cmdlinearg('maxv', 10**9))
mode = cmdlinearg('mode', 'unimodal')

if mode == 'unimodal':
    A = []
    B = []
    for i in range(min(n, maxv)):
        if random.randint(0,1) == 0:
            A.append(i)
        else:
            B.append(i)
    while len(A) + len(B) < n:
        x = random.randint(0,maxv)
        if random.randint(0,1) == 0:
            A.append(x)
        else:
            B.append(x)
    A.sort()
    B.sort()
    B.reverse()
    A = B + A
if mode == 'uneven':
    A = []
    for i in range(min(n, maxv)):
        A.append(i)
    while len(A) < n:
        x = random.random()**2
        x *= maxv
        x = round(x)
        A.append(x)
    random.shuffle(A)

print(n,q)
print(*A)
Q = [i for i in range(min(n, maxv))]
random.shuffle(Q)
for i in range(q):
    if i >= len(Q):
        print(random.randint(0, maxv))
    else:
        print(Q[i])
    

