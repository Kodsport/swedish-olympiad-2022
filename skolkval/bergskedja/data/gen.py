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

dx = [0,1,0,-1]
dy = [1,0,-1,0]

def inbounds(i, j):
    return i >= 0 and j >= 0 and i < n and j < m

def smaller(i, j):
    res = 0
    for k in range(4):
        i2 = i + dx[k]
        j2 = j + dy[k]
        if inbounds(i2,j2) and grid[i2][j2] < grid[i][j]:
            res += 1
    return res

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n', random.randint(1, 8)))
m = int(cmdlinearg('m', random.randint(1, 8)))
mode = cmdlinearg('mode', 'random')

print(n,m)

grid = []
for _ in range(n):
    grid.append([-1] * m)

if mode == "random":
    inds = list(range(n*m))
    random.shuffle(inds)
    for i in range(n):
        for j in range(m):
            grid[i][j] = inds[i*m+j]

elif mode == "snake" or mode == "snake2":
    for i in range(n):
        for j2 in range(m):
            j = j2
            if i%2 == 1:
                j = m-j-1
            if mode == "snake2":
                grid[n-i-1][j] = i*m+j2
            else:
                grid[i][j] = i*m+j2

elif mode == "chess":
    cells = []
    for i in range(n):
        for j in range(m):
            r = random.randint(0, 1000) + 2000*((i+j)%2)
            cells.append((r,i,j))
    cells.sort()
    for k in range(n*m):
        _,i,j = cells[k]
        grid[i][j] = k

elif mode == "slope":
    for k in range(n*m):
        best = -10**10
        i_best = random.randrange(0,n)
        j_best = random.randrange(0,m)
        for i in range(n):
            for j in range(m):
                if grid[i][j] == -1:
                    res = 0
                    for d in range(4):
                        i2 = i + dx[d]
                        j2 = j + dy[d]
                        if inbounds(i2,j2) and grid[i2][j2] != -1:
                            res += 1
                    if res != 0:
                        temp = random.randint(0, 10000)
                        if temp > best:
                            best = temp
                            i_best = i
                            j_best = j
        grid[i_best][j_best] = k

for i in range(n):
    row = []
    for j in range(m):
        row.append(str(smaller(i, j)))
    print("".join(row))
