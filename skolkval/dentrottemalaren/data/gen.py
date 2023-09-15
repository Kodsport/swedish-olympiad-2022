#!/usr/bin/python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n', random.randint(1, 9)))
safe = int(cmdlinearg('safe', 0))
paints = int(cmdlinearg('paints', 100))
mode = cmdlinearg('mode', 'random')

all_cells = []
is_safe = []
grid = []
for i in range(n):
    is_safe.append([0] * n)
    grid.append(['.'] * n)
    for j in range(n):
        all_cells.append((i, j))
safe_cells = []

if safe > 0:
    safe_cells = random.sample(all_cells, safe)

for (i, j) in safe_cells:
    is_safe[i][j] = 1

vs = "VS"


for _ in range(paints):
    i = random.randrange(0, n)
    dim = random.randint(0, 1)
    col = random.randint(0, 1)
    if mode == 'nocross':
        col = paints%2
        dim = paints%2
    if dim == 0:
        bad = 0
        for j in range(n):
            if is_safe[i][j] == 1:
                bad = 1
        if bad == 0:
            for j in range(n):
                grid[i][j] = vs[col]
    else:
        bad = 0
        for j in range(n):
            if is_safe[j][i] == 1:
                bad = 1
        if bad == 0:
            for j in range(n):
                grid[j][i] = vs[col]

print(n)
for i in range(n):
    print("".join(grid[i]))
