#!/usr/bin/env python3
def fix_stats(r, m, s):
    if s == 0:
        return (0, 0, 0)
    if [r, m, s].count(-1) == 1:
        if r == -1:
            return (s-m, m, s)
        if m == -1:
            return (r, s-r, s)
        if s == -1:
            return (r, m, m+r)
    return (r, m, s)
r1, m1, s1 = map(int, input().split())
r2, m2, s2 = map(int, input().split())
(r1, m2, s2) = fix_stats(r1, m2, s2)
(r2, m1, s1) = fix_stats(r2, m1, s1)
print(r1, m1, s1)
print(r2, m2, s2)
