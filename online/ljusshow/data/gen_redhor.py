#!/usr/bin/env python3
# Grid where all lamps on left and right sides are red.

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
R = int(cmdlinearg('R'))
C = int(cmdlinearg('C'))
print(R, C)

print(''.join(random.choice('BG') for _ in range(C)))
print('R' * R)
print(''.join(random.choice('BG') for _ in range(C)))
print('R' * R)
