#!/usr/bin/env python3

input()
U, R, B, L = input(), input(), input(), input()

rows = len(R)

ans = 0

for i in range(len(U)):
    cols = set()
    cols.add(U[i])
    cols.add(B[i])
    if cols == {'G', 'B'}:
        ans += rows

print(ans)
