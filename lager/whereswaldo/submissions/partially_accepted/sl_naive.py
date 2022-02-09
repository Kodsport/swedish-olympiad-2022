#!/usr/bin/env python3
T, N = map(int, input().split())

for _ in range(T):
    for i in range(N):
        print('?', i+1, i+1)
        x = int(input())
        if x == 1:
            print('!', i+1)
            break
