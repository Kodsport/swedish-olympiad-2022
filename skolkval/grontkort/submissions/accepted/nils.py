n = int(input())
m = int(input())
ans = 0
if n%2 == 0:
    ans = (m+n-1) // n + 2
else:
    m -= n
    if m <= 0:
        ans = 3
    else:
        ans = (m+n-1) // n + 3
print(10*ans)
