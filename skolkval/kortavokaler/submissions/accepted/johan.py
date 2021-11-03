#!/usr/bin/env python3
S = reversed(input())

k0 = 1
k1 = 0
k2 = 0
for k in S:
    if k in "aeiouy":
        k0 += k0 + k1
    else:
        k2 += k2
        k2 += k1
        k1 += k0
print(k0 + k1 + k2 - 1)
