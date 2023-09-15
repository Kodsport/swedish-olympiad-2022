#!/usr/bin/python3


import sys
import random
import math
import string


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
subtask = int(cmdlinearg('subtask', 0))

def word():
    return "".join(random.choice(string.ascii_lowercase) for _ in range(5))

def bad(w):
    vowels = "aieouyAIEOUY"
    consonants = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ"
    for i, letter in enumerate(w):
        if letter in vowels:
            if (
                i + 2 >= len(w)
                or w[i + 1] not in consonants
                or w[i + 2] not in consonants
            ):
                continue
        else:
            continue
        return True
    return False

print(5)
W = []
for x in range(5):
    w = word()
    if subtask:
        while bad(w): w = word()
    W.append(w)

print(' '.join(W))
