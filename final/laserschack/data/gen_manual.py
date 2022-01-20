
#! /usr/bin/env python3
import random
import sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

r = int(cmdlinearg('r'))
c = int(cmdlinearg('c'))
fill = cmdlinearg('fill')

kx = int(cmdlinearg('kx',0))
ky = int(cmdlinearg('ky',0))
ax = int(cmdlinearg('ax',0))
ay = int(cmdlinearg('ay',0))
rx = int(cmdlinearg('rx',0))
ry = int(cmdlinearg('ry',0))

print(r,c)
for i in range(r):
    for j in range(c):
        if (i == kx and j == ky):
            print('K',end='')
        elif (i == ax and j == ay):
            print('A',end='')
        elif (i == rx and j == ry):
            print('R',end='')
        else:
            print(fill,end='')
    print('')
