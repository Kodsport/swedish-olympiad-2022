#!/usr/bin/python3


import sys
import random
import math


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
k = int(cmdlinearg('k'))
min_power = int(cmdlinearg('min_power'))
max_power = int(cmdlinearg('max_power'))
plane_distribution = float(cmdlinearg('plane_distribution'))
shuffle_nodes = cmdlinearg('shuffle_nodes',default="true")=="true"
mode = cmdlinearg('mode')

starline_last = 0

def gen_tree(n, mode):
    global starline_last
    
    eds = []
    assert mode in ['random', 'star','starline', 'line', 'shallow', 'deep', 'deeper', 'degtwo']
    depth = [0]
    deg = [0] * n
    for i in range(1, n):
        if mode == 'random':
            pred = random.randrange(i)
        elif mode == 'star':
            pred = 0
        elif mode == 'starline':
            if random.randint(0,1)==0 and i != 1:
                pred = 0
            else:
                pred = starline_last
                starline_last = i
        elif mode == 'line':
            pred = i-1
        elif mode == 'shallow':
            pred = int(random.uniform(0, i**0.2) ** 5)
        elif mode == 'deep':
            pred = i-1 - int(random.uniform(0, i**0.1) ** 10)
        elif mode == 'deeper':
            if i < 4:
                pred = random.randrange(i)
            else:
                hi = math.log2(math.log2(i))
                pred = i - int(2 ** 2 ** min(random.uniform(-3, hi), random.uniform(-3, hi), random.uniform(-3, hi)))
        elif mode == 'degtwo':
            while True:
                pred = random.randrange(i)
                if deg[pred] < 2:
                    break
        else:
            assert False
        assert 0 <= pred < i
        deg[pred] += 1
        eds.append((pred, i))
        depth.append(depth[pred] + 1)
    print('depth =', max(depth), file=sys.stderr)
    return eds

eds = gen_tree(n, mode)

p = list(range(n))
if shuffle_nodes:
    random.shuffle(p)
    if mode=="starline":
        p[p.index(0)] = p[starline_last]
        p[starline_last] = 0

if shuffle_nodes:
    random.shuffle(eds)

print(n)
for a, b in eds:
    e = [p[a]+1, p[b]+1]
    if shuffle_nodes:
        random.shuffle(e)
    print(e[0],e[1])

print(k)
not_hit = [int(i) for i in range(n)]
for i in range(k):
    power = random.randint(min_power,max_power)

    node = random.randrange(n)
    if (plane_distribution > random.random() or len(not_hit) == n) and len(not_hit) > 0:
        index = random.randrange(len(not_hit))
        node = not_hit[index]
        not_hit[index] = not_hit[-1]
        not_hit.pop()

    print(node + 1, power)