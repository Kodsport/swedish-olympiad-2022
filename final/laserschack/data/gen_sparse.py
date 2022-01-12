#!/usr/bin/env python3
# Place mirrors by dfs, taking straight axis aligned jump of arbitrary length in each step,
# with maximum number of mirrors per row/column.
# Then place smoke machines randomly.



import sys
import random

from helpers import make_solvable, solvable

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
r = int(cmdlinearg('r'))
c = int(cmdlinearg('c'))
max_mirrors_per_row = int(cmdlinearg('mirrors_per_row',3))
smoke_machines = int(cmdlinearg('numR',5))


grid = [['.'] * c for j in range(r)]

A_pos = (random.randint(0,r-1),random.randint(0,c-1))
q = [A_pos]

mirrors_per_row = [0]*r
mirrors_per_col = [0]*c

while len(q)>0:
    x,y = q.pop()
    if grid[x][y]=='o' or mirrors_per_col[y]>=max_mirrors_per_row or mirrors_per_row[x]>=max_mirrors_per_row:
        continue
    grid[x][y] = 'o'
    mirrors_per_col[y] += 1
    mirrors_per_row[x] += 1

    for _ in range(10):
        q.append((x,random.randint(0,c-1)))
    for _ in range(10):
        q.append((random.randint(0,r-1),y))

grid[A_pos[0]][A_pos[1]] = 'A'
while True:
    K_pos = (random.randint(0,r-1),random.randint(0,c-1))
    if grid[K_pos[0]][K_pos[1]]=='o' or max_mirrors_per_row==0:
        break
grid[K_pos[0]][K_pos[1]] = 'K'

while True:
    grid = make_solvable(grid,r,c,*A_pos)
    num_smokes = sum([sum([x=='R' for x in row]) for row in grid])
    for i in range(smoke_machines-num_smokes):
        while True:
            x = random.randint(0,r-1)
            y = random.randint(0,c-1)
            if grid[x][y] not in ['A','K','R']:
                break
        grid[x][y] = 'R'
    if solvable(grid,r,c,*A_pos):
        break

print(r, c)
for row in grid:
    for c in row:
        print(c,end="")
    print()
