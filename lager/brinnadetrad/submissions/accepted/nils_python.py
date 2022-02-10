#!/usr/bin/env python3
from heapq import *
n = int(input())
X = list(map(int, input().split()))
A = list(map(int, input().split()))
pq = []
tot = 0
for i in range(n):
    heappush(pq, -A[i])
    tot += A[i]
    if tot-A[i] > X[i]:
        tot += heappop(pq)
print(len(pq))
