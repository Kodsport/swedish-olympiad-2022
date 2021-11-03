#!/usr/bin/env python3
E = (229 / 1000) * (324 / 1000) * 2
P = (297 / 1000) * (420 / 1000) * 2
I = (210 / 1000) * (297 / 1000)

e, p, i = [int(x) for x in input().split()]
print("{:.6f}".format(E * e + P * p + I * i))
