#!/usr/bin/python3
import random
n = int(input())
print("YES")
print("".join([str(random.randint(1,3)) for i in range(n)]))
