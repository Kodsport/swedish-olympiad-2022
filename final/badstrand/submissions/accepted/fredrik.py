#!/usr/bin/python3
n, b = input().split()
n = int(n)
b = int(b)

a = [int(x) for x in input().split()]
l = 0
r = 0
s = 0
best = 0 
while l<n:
    while r<n and s+a[r]<=b:
        s += a[r]
        r += 1
    best = max(best,r-l)
    s-=a[l]
    l+=1
print(best)
