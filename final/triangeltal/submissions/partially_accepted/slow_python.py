#!/usr/bin/python3
# based on joakim.cc
n = int(input())
a = list(map(int,input().split()))
order = [(a[i], i) for i in range(n)] 
order.sort()
a.sort()

mx1 = a[-1]
if mx1 >= n:
    print("NO")
else:
    ans = []
    mx2 = a[mx1-1]
    if mx1+mx2 < n:
        mx3 = a[mx1+mx2-1]
        if mx1+mx2+mx3 <= n:
            ans = ['?'] * n
            for i in range(0,n):
                o = order[i][1]
                if i < mx1:
                    ans[o] = '2'
                elif i < mx1+mx2:
                    ans[o] = '3'
                else:
                    ans[o] = '1'
    for mx3 in range(1,n):
        mx2 = n-mx3-mx1
        if mx2 > 0 and a[mx2-1] <= mx3 and a[mx1+mx2-1] <= mx2:
            ans = ['?'] * n
            for i in range(0,n):
                o = order[i][1]
                if i < mx2:
                    ans[o] = '3'
                elif i < mx1+mx2:
                    ans[o] = '2'
                else:
                    ans[o] = '1'
    if len(ans) == 0:
        print("NO")
    else:
        print("YES")
        print("".join(ans))
            
                
