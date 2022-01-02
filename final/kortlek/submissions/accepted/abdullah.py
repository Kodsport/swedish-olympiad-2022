#!/usr/bin/python3

n,m=[int(i) for i in input().split()]
rounds=[int(i) for i in input().split()]
cards=[int(i) for i in input().split()]

rounds.sort()
cards.sort()

def solve():
    ans=0
    if n==m:
        for i in range(n):
            ans+=abs(rounds[i]-cards[i])
        return ans
    for i in range(n):
        ans+=abs(rounds[i]-cards[i+1])
    cur=ans
    for i in range(n):
        cur-=abs(rounds[i]-cards[i+1])
        cur+=abs(rounds[i]-cards[i])
        ans=min(ans,cur)

print(solve())