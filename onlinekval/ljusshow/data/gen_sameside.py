#!/usr/bin/env python3
# Grid where all lamps on each side have the same color.

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
cols = cmdlinearg('sides')
print(R, C)
print(cols[0] * C)
print(cols[1] * R)
print(cols[2] * C)
print(cols[3] * R)
