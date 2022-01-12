from collections import deque
import random

def solvable(g, r,c,ar,ac):
    q = deque([(ar,ac)])
    seen = [[False]*c for i in range(r)]
    while len(q)>0:
        x,y = q.popleft()
        if seen[x][y]:
            continue
        seen[x][y] = True
        if g[x][y]=='K':
            return True
            
        for dir in [[0,1],[0,-1],[1,0],[-1,0]]:
            xi = x
            yi = y
            while True:
                xi += dir[0]
                yi += dir[1]
                if xi<0 or xi>=r or yi<0 or yi>=c:
                    break
                if g[xi][yi]=='R':
                    break
                if g[xi][yi]=='o' or g[xi][yi]=='K':
                    if not seen[xi][yi]:
                        q.append((xi,yi))
                    break
    return False

import copy 

def add_mirrors(g,mirrors):
    new_g = copy.deepcopy(g)
    for x,y in mirrors:
        if new_g[x][y] not in ['K','A']:
            new_g[x][y] = 'o'
    return new_g

def make_solvable(g,r,c,ar,ac):
    if solvable(g,r,c,ar,ac):
        return g
    all_pos = [(i,j) for i in range(r) for j in range(c)]
    random.shuffle(all_pos)

    extra_mirrors = 0
    for p in range(20,-1,-1):
        extra_mirrors += 2**p
        if solvable(add_mirrors(g,all_pos[:extra_mirrors]),r,c,ar,ac):
            extra_mirrors -= 2**p
    return add_mirrors(g,all_pos[:extra_mirrors+1])
