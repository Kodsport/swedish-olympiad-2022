#!/usr/bin/python3
import sys
sys.setrecursionlimit(10**4)
def distance(x1, y1, x2, y2):
  return abs(x1 - x2) + abs(y1 - y2)
n = int(input())
l = []
for _ in range(n):
  t, s, x, y = map(int, input().split())
  l.append([t, s, x, y])
l.sort()

from collections import defaultdict
ans = [[-1]*(n + 2) for i in range(n + 2)]

def dp(prev, i):
  if ans[prev][i] != -1: return ans[prev][i]
  if i >= n:
    r =  ans[prev][i] = 0
  elif prev == -1:
    r =  ans[prev][i] = max(dp(-1, i+1), dp(i, i+1) + l[i][1])
  else:
    dist = distance(l[prev][2], l[prev][3], l[i][2], l[i][3])
    start = l[prev][0]
    if start + dist > l[i][0]:
      r = ans[prev][i] = dp(prev, i+1)
    else:
      r = ans[prev][i] = max(dp(i, i+1) + l[i][1], dp(prev, i+1))
  return r
res = dp(-1, 0)
print(res)
