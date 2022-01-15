#!/usr/bin/env python3

import heapq
INF = 100000000
r, c = map(int, input().split())
m = [[i for i in input()] for _ in range(r)]

smoke_map = [[1]*c for _ in range(r)]
smoke_q = [(i, j, 0) for i in range(r) for j in range(c) if m[i][j] == "R"]


for i, j, n in smoke_q:
    if i<0 or i==r or j<0 or j==c:continue
    if smoke_map[i][j]!=1:continue
    smoke_map[i][j] = n
    smoke_q.append((i+1, j, n-1))
    smoke_q.append((i-1, j, n-1))
    smoke_q.append((i, j+1, n-1))
    smoke_q.append((i, j-1, n-1))
    
laser_pq = []
heapq.heapify(laser_pq)
for i in range(r):
    for j in range(c):
        if m[i][j] == "A":
            heapq.heappush(laser_pq, (-1*INF, 0, i, j))
            heapq.heappush(laser_pq, (-1*INF, 1, i, j))
            heapq.heappush(laser_pq, (-1*INF, 2, i, j))
            heapq.heappush(laser_pq, (-1*INF, 3, i, j))

seen = [[[1, 1, 1, 1] for _ in range(c)] for _ in range(r)]
best = None
while len(laser_pq):
    dist, dire, i, j = heapq.heappop(laser_pq)
    if i<0 or i==r or j<0 or j==c:continue
    if seen[i][j][dire] != 1:
        continue
    dist = max(dist, smoke_map[i][j])
    seen[i][j][dire] = dist
    if m[i][j] == "K":
        best = dist
        break
    if m[i][j] == "o":
        heapq.heappush(laser_pq, (dist, 0, i+1, j))
        heapq.heappush(laser_pq, (dist, 1, i, j+1))
        heapq.heappush(laser_pq, (dist, 2, i-1, j))
        heapq.heappush(laser_pq, (dist, 3, i, j-1))
    else:
        if dire == 0:
            heapq.heappush(laser_pq, (dist, 0, i+1, j))
        if dire == 1:
            heapq.heappush(laser_pq, (dist, 1, i, j+1))
        if dire == 2:
            heapq.heappush(laser_pq, (dist, 2, i-1, j))
        if dire == 3:
            heapq.heappush(laser_pq, (dist, 3, i, j-1))
print(-1*best)