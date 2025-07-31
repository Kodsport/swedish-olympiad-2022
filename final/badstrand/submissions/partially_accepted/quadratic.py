#!/usr/bin/python3
n, b = input().split()
n = int(n)
b = int(b)
a = [int(x) for x in input().split()]
print(max([j-i for j in range(n+1) for i in range(n) if sum(a[i:j])<=b]))
