#!/usr/bin/env python3

from collections import deque
import heapq


r,c = input().split()
r = int(r)
c = int(c)

g = [list(input()) for i in range(r)]

q = deque()
ar = 0
ac = 0
for i in range(r):
    for j in range(c):
        if g[i][j] == 'R':
            q.append((i,j,0))
        if g[i][j] == 'A':
            ar = i
            ac = j

dist = [[-1]*c for i in range(r)]
cnt = 0 
while len(q)>0:
    x,y,d = q.popleft()
    cnt += 1
    if x<0 or x>=r or y<0 or y>=c or dist[x][y]!=-1:
        continue
    dist[x][y] = d
    for dx,dy in [[0,1],[0,-1],[1,0],[-1,0]]:
        x1 = x+dx
        y1 = y+dy
        if x1<0 or x1>=r or y1<0 or y1>=c or dist[x1][y1]!=-1:
            continue
        q.append((x1,y1,d+1))
    
q2 = [(-dist[ar][ac],ar,ac)]
cnt = 0
seen = [[False]*c for i in range(r)]
while len(q2)>0:
    mn,x,y = heapq.heappop(q2)
    mn = -mn
    if seen[x][y]:
        continue
    seen[x][y] = True
    if g[x][y]=='K':
        print(mn)
        exit(0)
        
    for dir in [[0,1],[0,-1],[1,0],[-1,0]]:
        xi = x
        yi = y
        mni = mn
        while True:
            cnt += 1
            xi += dir[0]
            yi += dir[1]
            if xi<0 or xi>=r or yi<0 or yi>=c:
                break
            mni = min(mni, dist[xi][yi])
            if g[xi][yi]=='o' or g[xi][yi]=='K':
                if not seen[xi][yi]:
                    heapq.heappush(q2,(-mni,xi,yi))
                break
