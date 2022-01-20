#!/usr/dev/env python3

a,b,m = list(map(int, input().split()))

ev = [] #(x,type,f)

tot_score = 0

for i in range(a):
    x,f,h = list(map(int, input().split()))
    ev.append((x+h+1, "HE", f))
    ev.append((x+1, "HS", f))

for i in range(b):
    x,f,h = list(map(int, input().split()))
    ev.append((x+h+1, "HE", -f))
    ev.append((x+1, "HS", -f))
    
for i in range(m):
    x,h = list(map(int, input().split()))
    ev.append((x+h+1, "AM", 0))

ev.sort()

diff = 0
lastp = int(1e18)
ans = 0
for p,t,f in ev:
    tot_score += diff*(p-lastp)
    if t=="AM":
        ans = max(ans,tot_score)
    if t=="HS":
        diff += f
    if t=="HE":
        diff -= f
    lastp = p

print(ans)



