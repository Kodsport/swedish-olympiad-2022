#!/usr/bin/env python3
import random
T, N = map(int, input().split())
for _ in range(0,T):
    print("!",random.randint(1,N))
