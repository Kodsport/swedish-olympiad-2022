#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution nils.cpp

compile gen_random.py
compile gen_partition.py

MAXN=500000

samplegroup
limits maxn=$MAXN
sample_manual 1
sample_manual 2

group group1 14
limits maxn=$MAXN same=1
tc same-1 gen_random n=3 maxa=1 same=1
tc same-2 gen_random n=3 maxa=2 same=1
tc same-3 gen_random n=10 maxa=1 same=1
tc same-4 gen_random n=10 maxa=3 same=1
tc same-5 gen_random n=10 maxa=4 same=1
tc same-6 gen_random n=99999 maxa=33333 same=1
tc same-7 gen_random n=$MAXN maxa=1 same=1
tc same-8 gen_random n=$MAXN maxa=$(($MAXN / 3)) same=1
tc same-9 gen_random n=$MAXN maxa=$(($MAXN / 3 + 1)) same=1
tc same-10 gen_random n=$MAXN maxa=$MAXN same=1

group group2 16
limits maxn=10
tc small-1 gen_random n=3 maxa=1
tc small-2 gen_random n=3 maxa=2
tc small-3 gen_random n=9 maxa=3 same=1
tc small-4 gen_random n=10 maxa=4
tc small-5 gen_random n=10
tc small-6 gen_partition n=10 x=3 y=5 z=2
tc small-7 gen_partition n=10 x=5 y=1 z=4
tc small-8 gen_partition n=10 x=7 y=1 z=2
tc small-9 gen_partition n=10 x=3 y=5 z=2 noise=-1
tc small-10 gen_partition n=10 x=3 y=5 z=2 noise=1
tc small-11 gen_partition n=10 x=7 y=1 z=2 noise=1
tc 1
tc 2

group group3 11
limits maxn=$MAXN maxa=3
tc a-small-1 gen_random n=4 maxa=1
tc a-small-2 gen_random n=5 maxa=2
tc a-small-3 gen_random n=3 maxa=3
tc a-small-4 gen_random n=$MAXN maxa=3
tc a-small-5 gen_random n=9 maxa=3 same=1
tc a-small-6 gen_random n=$MAXN maxa=1
tc a-small-7 gen_random n=8 maxa=3 same=1
tc a-small-8 gen_random n=8 maxa=3
tc a-small-9 gen_partition n=6 x=2 y=3 z=1
tc a-small-10 gen_partition n=6 x=3 y=1 z=2
tc a-small-11 gen_partition n=6 x=3 y=1 z=2 noise=1

group group4 23
limits maxn=3000
include_group group2
tc medium-1 gen_random n=3000 maxa=1500
tc medium-2 gen_random n=3000 maxa=1100
tc medium-3 gen_random n=3000
tc medium-4 gen_random n=3000 maxa=1000 same=1
tc medium-5 gen_partition n=3000 x=1000 y=1500 z=500
tc medium-6 gen_partition n=3000 x=1500 y=500 z=1000
tc medium-7 gen_partition n=3000 x=1500 y=500 z=1000 noise=1
tc medium-8 gen_partition n=3000 x=2 y=2997 z=1
tc medium-9 gen_partition n=3000 x=1001 y=999 z=1000
tc medium-10 gen_partition n=3000 x=1001 y=999 z=1000 noise=1
tc medium-11 gen_partition n=3000 x=1500 y=500 z=1000 noise=-100


group group5 36
limits maxn=$MAXN
include_group group1
include_group group3
include_group group4
tc large-1 gen_random n=$MAXN maxa=$(($MAXN / 2))
tc large-2 gen_random n=$MAXN
tc large-3 gen_partition n=300000 x=100000 y=150000 z=50000
tc large-4 gen_partition n=300000 x=150000 y=50000 z=100000
tc large-5 gen_partition n=300000 x=150000 y=50000 z=100000 noise=1
tc large-6 gen_partition n=$MAXN x=$(($MAXN - 3)) y=1 z=2
tc large-7 gen_partition n=$MAXN x=$(($MAXN - 3)) y=1 z=2 noise=1
tc large-8 gen_partition n=$MAXN x=3 y=$(($MAXN - 5)) z=2 noise=-1000
tc large-9 gen_partition n=$MAXN x=200000 y=210000 z=90000 noise=-1000000
tc large-10 gen_partition n=$MAXN x=166668 y=166665 z=166667 noise=-1000000
tc large-11 gen_partition n=$MAXN x=166668 y=166665 z=166667 noise=1
tc large-12 gen_partition n=$MAXN x=1 y=$(($MAXN - 2)) z=1
tc large-13 gen_random n=$MAXN maxa=$(($MAXN / 3))
