#!/usr/bin/env python3
T = int(input())
n, m = map(int, input().split())
a1 = ["R"] * m
a2 = ["R"] * n
a3 = ["G"] * m
a4 = []
for _ in range(n):
    s = input()
    if s.count('0') > m//2:
        a4.append("G")
    else:
        a4.append("B")
print("".join(a1))
print("".join(a2))
print("".join(a3))
print("".join(a4))
