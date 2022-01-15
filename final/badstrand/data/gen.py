import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
ans = int(cmdlinearg('ans'))
mode = cmdlinearg('mode',"none")

a = [random.randint(1,1000) for i in range(n)]

if mode=="same_a":
    for i in range(n):
        a[i] = a[0]

s = sum(a[:ans])
b = s
for i in range(n-ans):
    s += a[i+ans] - a[i]
    b = min(b,s)
print(n,b)
print(" ".join(str(x) for x in a))