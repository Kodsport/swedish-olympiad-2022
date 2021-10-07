#!/usr/bin/env python3

input()
U, R, B, L = input(), input(), input(), input()

ans = 0

for r in range(len(R)):
    for c in range(len(U)):
        has = set()
        has.add(U[c])
        has.add(B[c])
        has.add(L[r])
        has.add(R[r])
        if has == {'R', 'G', 'B'}:
            ans += 1

print(ans)
