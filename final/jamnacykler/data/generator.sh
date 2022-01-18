#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution joakim_bcc.cc

compile gen.cc

N=100000
M=200000

samplegroup
limits maxn=$N maxm=$M
sample 1
sample 2
sample 3


# only placeholder below
# TODO: actually generate testdata

##################### GROUP 1: n <= 10 #######################
group group1 18
limits maxn=10 maxm=$M
tc 1
tc 2
tc 3
tc_manual ../manual_tests/manual-1.in
tc_manual ../manual_tests/manual-2.in
tc_manual ../manual_tests/manual-3.in
tc_manual ../manual_tests/manual-4.in
tc_manual ../manual_tests/manual-5.in
tc_manual ../manual_tests/manual-6.in

tc g1-empty gen -type=empty -n=10

tc g1-tree-1 gen -type=star -n=10
tc g1-tree-2 gen -type=bamboo -n=10

tc g1-bipartite-1  gen -type=bipartite -n=6 -m=9
tc g1-bipartite-2  gen -type=bipartite -n=9 -m=9

tc g1-wheel-1  gen -type=wheel -n=9
tc g1-wheel-2  gen -type=wheel2 -n=9
tc g1-wheel-3  gen -type=wheel2 -n=6

tc g1-cycle-1  gen -type=cycle -n=10
tc g1-cycle-2  gen -type=cycle -n=9

tc g1-paths-1  gen -type=paths -n1=3 -n2=1 -n3=3 -n=10
tc g1-paths-2  gen -type=paths -n1=3 -n2=2 -n3=3 -n=10
tc g1-paths-3  gen -type=paths -n1=2 -n2=1 -n3=3 -n=10
tc g1-paths-4  gen -type=paths -n1=3 -n2=1 -n3=4 -n=10
tc g1-paths-5  gen -type=paths -n1=4 -n2=2 -n3=1 -n=10
tc g1-paths-6  gen -type=paths -n1=3 -n2=2 -n3=2 -n=10
tc g1-paths-7  gen -type=paths -n1=2 -n2=2 -n3=2 -n=10
tc g1-paths-8  gen -type=paths -n1=2 -n2=3 -n3=2 -n=10

tc g1-cactus-1  gen -type=cactus -n=10 -siz=4
tc g1-cactus-2  gen -type=cactus -n=10 -siz=10
tc g1-cactus-3  gen -type=cactus -n=10 -siz=4 -extra_random_edges=1
tc g1-cactus-4  gen -type=cactus -n=10 -siz=10 -extra_random_edges=1

tc g1-random-1  gen -type=random -n=10 -m=4
tc g1-random-2  gen -type=random -n=10 -m=20

##################### GROUP 2: n <= 100, m <= 200 #######################
group group2 16
limits maxn=100 maxm=200
include_group group1
#TODO some tests here

tc g2-tree-1 gen -type=star -n=100
tc g2-tree-2 gen -type=bamboo -n=100

tc g2-bipartite-1  gen -type=bipartite -n=60 -m=190
tc g2-bipartite-2  gen -type=bipartite -n=98 -m=190

tc g2-wheel-1  gen -type=wheel -n=90
tc g2-wheel-2  gen -type=wheel2 -n=90
tc g2-wheel-3  gen -type=wheel2 -n=60

tc g2-cycle-1  gen -type=cycle -n=100
tc g2-cycle-2  gen -type=cycle -n=99

tc g2-paths-1  gen -type=paths -n1=33 -n2=11 -n3=33 -n=100
tc g2-paths-2  gen -type=paths -n1=33 -n2=22 -n3=33 -n=100
tc g2-paths-3  gen -type=paths -n1=22 -n2=11 -n3=33 -n=100
tc g2-paths-4  gen -type=paths -n1=33 -n2=11 -n3=44 -n=100
tc g2-paths-5  gen -type=paths -n1=44 -n2=22 -n3=13 -n=100
tc g2-paths-6  gen -type=paths -n1=33 -n2=22 -n3=22 -n=100
tc g2-paths-7  gen -type=paths -n1=22 -n2=22 -n3=22 -n=100
tc g2-paths-8  gen -type=paths -n1=22 -n2=33 -n3=22 -n=100

tc g2-cactus-1  gen -type=cactus -n=100 -siz=6
tc g2-cactus-2  gen -type=cactus -n=100 -siz=100
tc g2-cactus-3  gen -type=cactus -n=100 -siz=6 -extra_random_edges=1
tc g2-cactus-4  gen -type=cactus -n=100 -siz=100 -extra_random_edges=1

tc g2-random-1  gen -type=random -n=100 -m=200
tc g2-random-2  gen -type=random -n=100 -m=100

##################### GROUP 3: bipartite ####################
group group3 17
limits maxn=$N maxm=$M bipartite=1
tc 3
tc g1-empty
tc g1-tree-1
tc g1-tree-2
tc g1-bipartite-1
tc g1-bipartite-2
tc g1-wheel-3
tc g1-cycle-1
tc g1-paths-1
tc g1-paths-7
tc g2-tree-1
tc g2-tree-2
tc g2-bipartite-1
tc g2-bipartite-2
tc g2-cycle-1
tc g2-paths-1
tc g2-paths-7

tc g3-paths-1 gen -type=paths -n=100000 -n1=11 -n2=13131 -n3=12311
tc g3-paths-2 gen -type=paths -n=100000 -n1=1222 -n2=22 -n3=12320

tc g3-cycle  gen -type=cycle -n=100000

tc g3-wheel-1  gen -type=wheel -n=99999 -gap=2
tc g3-wheel-2  gen -type=wheel -n=98999 -gap=2000
tc g3-wheel-3  gen -type=wheel2 -n=99998

tc g3-tree-1  gen -type=star -n=100000
tc g3-tree-2  gen -type=bamboo -n=100000
tc g3-tree-3  gen -type=caterpillar -n=100000
tc g3-tree-4  gen -type=binary -n=100000

tc g3-almosttree-1  gen -type=bamboo -n=100000 -extra_random_edges=1 -bipartite=1
tc g3-almosttree-2  gen -type=caterpillar -n=100000 -extra_random_edges=1 -bipartite=1
tc g3-almosttree-3  gen -type=binary -n=100000 -extra_random_edges=1 -bipartite=1
tc g3-almosttree-4  gen -type=bamboo -n=100000 -extra_random_edges=3 -bipartite=1
tc g3-almosttree-5  gen -type=caterpillar -n=100000 -extra_random_edges=3 -bipartite=1
tc g3-almosttree-6  gen -type=binary -n=100000 -extra_random_edges=3 -bipartite=1
tc g3-almosttree-7  gen -type=bamboo -n=100000 -extra_random_edges=300 -bipartite=1
tc g3-almosttree-8  gen -type=caterpillar -n=100000 -extra_random_edges=300 -bipartite=1
tc g3-almosttree-9  gen -type=binary -n=100000 -extra_random_edges=300 -bipartite=1

tc g3-bipartite-1  gen -type=bipartite -n=6 -m=9
tc g3-bipartite-2  gen -type=bipartite -n=10 -m=15
tc g3-bipartite-3  gen -type=bipartite -n=100 -m=300
tc g3-bipartite-4  gen -type=bipartite -n=100000 -m=200000
tc g3-bipartite-5  gen -type=bipartite -n=10000 -m=200000
tc g3-bipartite-6  gen -type=bipartite -n=100000 -m=100000
tc g3-bipartite-7  gen -type=bipartite -n=100000 -m=200000 -left=1000


##################### GROUP 4: degree <= 2 ####################
group group4 13
limits maxn=$N maxm=$M maxdeg=2

tc g1-empty
tc g1-cycle-1
tc g1-cycle-2
tc g1-tree-2
tc g2-cycle-1
tc g2-cycle-2
tc g2-tree-2
tc g3-cycle
tc g3-tree-2

tc g4-cycle  gen -type=cycle -n=99999

##################### GROUP 5: degree >= 3 ####################
group group5 20
limits maxn=$N maxm=$M mindeg=3

tc manual-4
tc manual-5
tc manual-6
tc g1-wheel-1
tc g1-wheel-2
tc g1-wheel-3
tc g1-bipartite-1
tc g2-wheel-1
tc g2-wheel-2
tc g2-wheel-3

tc g5-wheel-1  gen -type=wheel -n=100 -forced_deg3=1
tc g5-wheel-2  gen -type=wheel -n=100000 -forced_deg3=1
tc g5-wheel-3  gen -type=wheel -n=99999 -forced_deg3=1
tc g5-wheel-4  gen -type=wheel -n=99997 -gap=100 -forced_deg3=1
tc g5-wheel-5  gen -type=wheel -n=99998 -gap=10000 -forced_deg3=1
tc g5-wheel-6  gen -type=wheel2 -n=100 -forced_deg3=1
tc g5-wheel-7  gen -type=wheel2 -n=100000 -forced_deg3=1
tc g5-wheel-8  gen -type=wheel2 -n=99999 -forced_deg3=1
tc g5-wheel-9  gen -type=wheel2 -n=99997 -gap=100 -forced_deg3=1
tc g5-wheel-10  gen -type=wheel2 -n=99998 -gap=10000 -forced_deg3=1
tc g5-wheel-11  gen -type=cycle -n=9 -forced_deg3=1
tc g5-wheel-12  gen -type=cycle -n=99995 -forced_deg3=1

tc g5-tree-1  gen -type=star -n=100000 -forced_deg3=1
tc g5-tree-2  gen -type=bamboo -n=90000 -forced_deg3=1
tc g5-tree-3  gen -type=caterpillar -n=100000 -forced_deg3=1
tc g5-tree-4  gen -type=binary -n=100000 -forced_deg3=1

tc g5-random-1  gen -type=random -n=100000 -m=150000 -forced_deg3=1
tc g5-random-2  gen -type=random -n=10000 -m=150000 -forced_deg3=1

tc g5-complete  gen -type=complete -n=630 -forced_deg3=1

tc g5-empty-1  gen -type=empty -n=10 -forced_deg3=1
tc g5-empty-2  gen -type=empty -n=100 -forced_deg3=1
tc g5-empty-3  gen -type=empty -n=1000 -forced_deg3=1
tc g5-empty-4  gen -type=empty -n=100000 -forced_deg3=1

##################### GROUP 6 ####################
group group6 16
limits maxn=$N maxm=$M
include_group group1
include_group group2
include_group group3
include_group group4
include_group group5

tc g6-bipartite-1  gen -type=bipartite -n=100000 -m=100000 -left=123 -extra_random_edges=10
tc g6-bipartite-2  gen -type=bipartite -n=100000 -m=199990 -extra_random_edges=10

tc g6-wheel-1  gen -type=wheel -n=100000 -gap=3
tc g6-wheel-2  gen -type=wheel2 -n=100000 -gap=3
tc g6-wheel-3  gen -type=wheel -n=99999 -gap=3
tc g6-wheel-4  gen -type=wheel2 -n=99999 -gap=3

tc g6-paths-1  gen -type=paths -n1=3333 -n2=1111 -n3=33333 -n=100000
tc g6-paths-2  gen -type=paths -n1=3333 -n2=2222 -n3=33333 -n=100000
tc g6-paths-3  gen -type=paths -n1=2222 -n2=11111 -n3=3333 -n=100000
tc g6-paths-4  gen -type=paths -n1=33333 -n2=1111 -n3=4444 -n=100000
tc g6-paths-5  gen -type=paths -n1=44444 -n2=2222 -n3=3333 -n=100000
tc g6-paths-6  gen -type=paths -n1=3333 -n2=22222 -n3=2222 -n=100000
tc g6-paths-7  gen -type=paths -n1=2222 -n2=22222 -n3=2222 -n=100000
tc g6-paths-8  gen -type=paths -n1=22222 -n2=3333 -n3=2222 -n=100000

tc g6-cactus-1  gen -type=cactus -n=100000 -siz=6
tc g6-cactus-2  gen -type=cactus -n=100000 -siz=100
tc g6-cactus-3  gen -type=cactus -n=100000 -siz=10000
tc g6-cactus-4  gen -type=cactus -n=100000 -siz=6 -extra_random_edges=1
tc g6-cactus-5  gen -type=cactus -n=100000 -siz=100 -extra_random_edges=1
tc g6-cactus-6  gen -type=cactus -n=100000 -siz=1000 -extra_random_edges=1

tc g6-random-1  gen -type=random -n=100000 -m=200000
tc g6-random-2  gen -type=random -n=100000 -m=100000
