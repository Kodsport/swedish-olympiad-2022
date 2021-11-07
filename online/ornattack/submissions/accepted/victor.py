#!env /bin/python3

import sys
sys.setrecursionlimit(200001)

n = int(input())
graph = [[] for i in range(n)]
ans = [0 for i in range(n)]
hit = [0 for i in range(n)]

for i in range(n - 1):
    u, v = [int(i) for i in input().split()]
    graph[u - 1].append(v - 1)
    graph[v - 1].append(u - 1)

k = int(input())
for i in range(k):
    u, p = [int(i) for i in input().split()]
    hit[u - 1] += p

def pull(u, p):
    for v in graph[u]:
        if v != p:
            ans[u] += pull(v, u)

    return hit[u] / max(1, len(graph[u])) + ans[u] / max(1, len(graph[u]) - 1)

def push(u, p, damage):
    ans[u] += damage
    for v in graph[u]:
        if v != p:
            amount_push = (ans[u] - (hit[v] / len(graph[v]) + ans[v] / max(1, len(graph[v]) - 1))) / max(1, len(graph[u]) - 1) + hit[u] / len(graph[u])
            push(v, u, amount_push)
    ans[u] += hit[u]

pull(0, 0)
push(0,0,0)
for i in ans:
    print("{:.20f}".format(i))