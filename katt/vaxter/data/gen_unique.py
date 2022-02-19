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
mode = cmdlinearg('mode', 'unique')

if mode == 'random':
    A = []
    for i in range(min(n, maxv+1)):
        A.append(i)
    while len(A) < n:
        A.append(random.randint(0, maxv))
    random.shuffle(A)
if mode == 'unique':
    A = [i for i in range(n)]
    random.shuffle(A)
if mode == 'increasing':
    A = [i for i in range(n)]
if mode == '01_edge':
    B = [i for i in range(2,n)]
    random.shuffle(B)
    A = [0] + B + [1]
if mode == 'unimodal':
    A = []
    B = []
    for i in range(n):
        if random.randint(0,1) == 0:
            A.append(i)
        else:
            B.append(i)
    B.reverse()
    A = B+A

print(n,q)
print(*A)
Q = [i for i in range(n)]
random.shuffle(Q)
for i in range(q):
    if i >= len(Q):
        print(random.randint(0, maxv))
    else:
        print(Q[i])

    

