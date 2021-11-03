#!/usr/bin/env python3
s = input()
vowels = "aeiouy"
dp = [[1, 0] for _ in range(len(s))]
ans = 0
for i in range(len(s)):
    if s[i] in vowels:
        dp[i][0] += sum(dp[j][0] + dp[j][1] for j in range(i))
    else:
        for j in range(i):
            if s[j] in vowels:
                dp[i][1] += dp[j][0]
            else:
                dp[i][0] += dp[j][0]
    ans += dp[i][0] + dp[i][1]
print(ans)
