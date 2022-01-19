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
n = int(float(cmdlinearg('n')))
a = int(float(cmdlinearg('a', n)))
b = int(float(cmdlinearg('b', n)))
m = int(float(cmdlinearg('m', n)))
xlim = int(float(cmdlinearg('x')))
hlim = int(float(cmdlinearg('h')))

mode = cmdlinearg('mode', '')

xhi_ab = xlim
xlo_m = 1
if mode == 'separated':
    xhi_ab = xlim // 2
    xlo_m = xlim // 2 + 1

xs = set()
towers = []
uncovered = []
for i in range(a + b):
    while True:
        x = random.randint(1, xhi_ab)
        f = random.randint(1, 10**2)
        h = random.randint(1, hlim)
        if x in xs:
            continue
        xs.add(x)
        towers.append((x, f, h))
        uncovered.append((x, h))
        break

random.shuffle(uncovered)

xs = set()
masts = []
for i in range(m):
    while True:
        if m == 1:
            x = random.randint(xlo_m, xlim)
            h = 10**4
        elif uncovered:
            x1,h1 = uncovered[0]
            h = random.randint(h1, min(int(hlim * 1.1), 10**4))
            hdif = h - h1
            if x1 + hdif < xlo_m:
                delta = xlo_m - (x1 + hdif)
                h += delta
                assert h <= 10**4
                h += int(delta * 0.1)
                h = min(h, 10**4)
                hdif = h - h1
                assert x1 + hdif >= xlo_m
            x = random.randint(max(x1 - hdif, xlo_m), x1 + hdif)
        else:
            x = random.randint(xlo_m, xlim)
            h = random.randint(1, hlim)
        if x in xs:
            continue
        if uncovered:
            uncovered = [(x2,h2) for (x2,h2) in uncovered if h2 > h - abs(x - x2)]
        xs.add(x)
        masts.append((x, h))
        break
assert not uncovered

print(a, b, m)

# negate x's to fix the order of the "separated" inequality in a lazy fashion
random.shuffle(towers)
for (x,f,h) in towers:
    print(10**6+1 - x,f,h)

random.shuffle(masts)
for (x,h) in masts:
    print(10**6+1 - x,h)
