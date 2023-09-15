#!/usr/bin/python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

consonants = list("bcdfghjklmnpqrstvwxz")
vowels = list("aeiouy")

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n', random.randint(1, 50)))
mode = cmdlinearg('mode', 'random')

ans = []

if mode == "random" or mode == "sorted":
    for i in range(n):
        if random.randint(0, 1) == 0:
            ans.append(random.choice(vowels))
        else:
            ans.append(random.choice(consonants))
    if mode == "sorted":
        ans.sort()
elif mode == "same":
    if n%2 == 1:
        ans = ['a'] * n
    else:
        ans = ['z'] * n
elif mode == "ab":
    for i in range(n):
        if random.randint(0, 1) == 0:
            ans.append('a')
        else:
            ans.append('b')
    ans.sort()
elif mode == "ab2":
    for _ in range(n-2):
        ans.append('a')
    ans += ['bb']
elif mode == "ab3":
    for i in range(n):
        if i%3 == 0:
            ans.append('a')
        else:
            ans.append('b')

print("".join(ans))
