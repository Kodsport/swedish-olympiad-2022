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

print(cmdlinearg('tc'))

n = int(cmdlinearg('n'))
m = int(cmdlinearg('m'))
kind = cmdlinearg('kind')

if kind == '1':
    row_masks = [0] * n
    col_masks = [0] * m

    for i in range(0, n):
        c1 = random.randint(0,2)
        c2 = random.randint(0,2)
        row_masks[i] = (2**c1) | (2**c2)

    for i in range(0, m):
        c1 = random.randint(0,2)
        c2 = random.randint(0,2)
        col_masks[i] = (2**c1) | (2**c2)

    print(n, m)
    for i in range(0, n):
        row = []
        zo = "01"
        for j in range(0, m):
            row.append(zo[(row_masks[i] | col_masks[j]) == 7])
        print("".join(row))
else:
    print(n, m)
    for i in range(n):
        row = []
        for j in range(m):
            row.append(str(random.randint(0,1)))
        print("".join(row))
        
