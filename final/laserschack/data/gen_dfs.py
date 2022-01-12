#!/usr/bin/env python3
# First, paths in the grid is drawn by dfs, avoiding to pass within 'radius' of itself.
# Then, smoke machines are placed at distance at least `ans` from the path.

import sys
import random
from helpers import make_solvable

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
r = int(cmdlinearg('r'))
c = int(cmdlinearg('c'))
ans = int(cmdlinearg('ans'))
radius = int(cmdlinearg('radius')) # Minimum distance between two paths
mirror_ratio = float(cmdlinearg('mirror_ratio',0.75))
smoke_ratio = float(cmdlinearg('smoke_ratio',0.5))


grid = [['R'] * c for j in range(r)]

A_pos = (random.randint(0,r-1),random.randint(0,c-1))
q = [(*A_pos,random.randint(0,3))]

# Queue for second bfs
q2 = []
while len(q)>0:
    x=0
    y=0
    d=0
    (x,y,d) = q[-1]
    q.pop()

    if x<0 or y<0 or x>=r or y>=c:
        continue
    if grid[x][y] == 'o':
        continue

    numClose = 0

    x1 = max(0,x-radius)
    x2 = min(r,x+radius+1)
    y1 = max(0,y-radius)
    y2 = min(c,y+radius+1)
    if d==0:
        y2 = y+1
    if d==1:
        x1 = x
    if d==2:
        y1 = y    
    if d==3:
        x2 = x+1
        
    for i in range(x1,x2):
        for j in range(y1,y2):
            if grid[i][j] == 'o':
                numClose += 1

    if numClose>0:
        continue

    toPush = [(x,y+1,2),(x+1,y,1),(x,y-1,0),(x-1,y,3)]
    random.shuffle(toPush)

    for t in toPush:
        q.append(t)
        q2.append((t[0],t[1],1))

    grid[x][y] = 'o'

grid[A_pos[0]][A_pos[1]] = 'A'
while True:
    K_pos = (random.randint(0,r-1),random.randint(0,c-1))
    if grid[K_pos[0]][K_pos[1]]=='o':
        break
grid[K_pos[0]][K_pos[1]] = 'K'

while len(q2)>0:
    x,y,dist = q2.pop()
    if dist>ans or x<0 or y<0 or x>=r or y>=c or grid[x][y] in ['o','A','K']:
        continue
    grid[x][y] = 'o'
    for x1,y1 in [(x,y+1),(x+1,y),(x,y-1),(x-1,y)]:
        q2.append((x1,y1,dist+1))

grid = make_solvable(grid,r,c,*A_pos)

print(r, c)
for row in grid:
    for c in row:
        # Increase irregularity by randomly adding empty cells
        if c == 'o' and random.uniform(0,1)>=mirror_ratio:
            print(".",end="")
        elif c == 'R' and random.uniform(0,1)>=smoke_ratio:
            print(".",end="")
        else:
            print(c,end="")
    print()
