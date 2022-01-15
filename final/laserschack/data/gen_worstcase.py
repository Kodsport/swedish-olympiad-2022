#! /usr/bin/env python3
import random
import sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
c = int(cmdlinearg('c'))

print("1 40000")
print("A" + "o"*(c-3)+"KR")