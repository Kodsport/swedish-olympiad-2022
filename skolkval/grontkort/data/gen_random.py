#!/usr/bin/python3

import sys
import random
import math
import string


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n2 = int(cmdlinearg('n2', 0))
m0 = int(cmdlinearg('m0', 0))
max100 = int(cmdlinearg('max100', 0))

N = random.randint(2, 4 * 10**8)
M = random.randint(0, 4 * 10**8)
if n2: N = 2
if m0: M = 0
if max100:
    N = random.randint(2, 100)
    M = random.randint(0, 100)

print(N)
print(M)
