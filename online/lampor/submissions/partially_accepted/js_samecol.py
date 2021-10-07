#!/usr/bin/env python3

input()
U, R, B, L = input(), input(), input(), input()
if {U[0], R[0], B[0], L[0]} == {'R', 'G', 'B'}:
    print(len(U) * len(R))
else:
    print(0)
