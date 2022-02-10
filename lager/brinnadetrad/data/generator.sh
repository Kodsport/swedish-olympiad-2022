#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution nils.cpp

compile gen_random.py

MAXN=400000
MAXA=1000000000

samplegroup
limits maxn=$MAXN
sample_manual 1
sample_manual 2

group group1 10
limits maxn=$MAXN same_a=1
tc same_a-1 gen_random n=1
tc same_a-2 gen_random n=10 mina=2 maxa=2 maxx=10
tc same_a-3 gen_random n=$MAXN mina=1 maxa=1
tc same_a-4 gen_random n=$MAXN mina=100 maxa=100
tc same_a-5 gen_random n=$MAXN mina=10000 maxa=10000
tc same_a-6 gen_random n=$MAXN mina=$MAXA maxa=$MAXA


group group2 18
limits maxn=$MAXN same_x=1
tc same_x-1 gen_random n=1 minx=$MAXA maxx=$MAXA
tc same_x-2 gen_random n=10 minx=20 maxx=20 maxa=5
tc same_x-3 gen_random n=$MAXN minx=0 maxx=0
tc same_x-4 gen_random n=$MAXN minx=$MAXN maxx=$MAXN maxa=1000
tc same_x-5 gen_random n=$MAXN minx=$MAXA maxx=$MAXA
tc same_x-6 gen_random n=$MAXN minx=$MAXA maxx=$MAXA maxa=100000
tc same_x-7 gen_random n=$MAXN minx=$MAXA maxx=$MAXA maxa=500000 a_order=increasing
tc same_x-8 gen_random n=$MAXN minx=$MAXA maxx=$MAXA maxa=500000 a_order=decreasing

group group3 15
limits maxn=100 maxa=100 maxx=100
tc small-1 gen_random n=1 maxa=1 maxx=0
tc small-2 gen_random n=10 maxa=10 maxx=10
tc small-3 gen_random n=100 maxa=100 maxx=100
tc small-4 gen_random n=100 maxa=60 maxx=100
tc small-5 gen_random n=100 maxa=30 maxx=100
tc small-6 gen_random n=100 maxa=7 maxx=100
tc small-7 gen_random n=100 maxa=100 maxx=100 a_order=increasing
tc small-8 gen_random n=100 maxa=100 maxx=100 a_order=decreasing
tc small-9 gen_random n=100 maxa=100 maxx=100 distinct_x=2
tc small-10 gen_random n=100 maxa=100 maxx=100 distinct_x=7
tc small-11 gen_random n=100 maxa=100 maxx=100 distinct_x=20
tc 1
tc 2


group group4 22
limits maxn=2000
include_group group3
tc medium-1 gen_random n=100
tc medium-2 gen_random n=2000 maxa=50 maxx=100000
tc medium-3 gen_random n=2000
tc medium-4 gen_random n=2000 maxa=100000000
tc medium-5 gen_random n=2000 maxa=1000000
tc medium-6 gen_random n=2000 maxa=10000
tc medium-7 gen_random n=2000 maxa=10
tc medium-8 gen_random n=2000 maxa=10000000 a_order=increasing
tc medium-9 gen_random n=2000 maxa=10000000 a_order=decreasing
tc medium-10 gen_random n=2000 maxx=1000000 a_order=decreasing
tc medium-11 gen_random n=2000 maxx=0
tc medium-12 gen_random n=2000 maxx=1
tc medium-13 gen_random n=2000 maxa=10000000 distinct_x=100
tc medium-14 gen_random n=2000 maxa=10 maxx=10000


group group5 35
limits maxn=$MAXN
include_group group1
include_group group2
include_group group4
tc large-1 gen_random n=$MAXN maxa=$MAXN maxx=$MAXN
tc large-2 gen_random n=$MAXN maxa=$MAXA maxx=$MAXN
tc large-3 gen_random n=$MAXN maxa=$MAXN maxx=$MAXA
tc large-4 gen_random n=$MAXN
tc large-5 gen_random n=$MAXN maxa=10000000
tc large-6 gen_random n=$MAXN maxa=1000000
tc large-7 gen_random n=$MAXN maxa=30000
tc large-8 gen_random n=$MAXN maxa=1000
tc large-9 gen_random n=$MAXN maxa=100
tc large-10 gen_random n=$MAXN maxa=7
tc large-11 gen_random n=$MAXN maxa=30000 a_order=increasing
tc large-12 gen_random n=$MAXN maxa=30000 a_order=decreasing
tc large-13 gen_random n=$MAXN maxx=10000000 a_order=decreasing
tc large-14 gen_random n=$MAXN maxa=30 maxx=30
tc large-15 gen_random n=$MAXN maxa=10 maxx=1000000
tc large-16 gen_random n=$MAXN maxa=30000 distinct_x=10
tc large-17 gen_random n=$MAXN maxa=30000 distinct_x=1000
tc large-18 gen_random n=$MAXN maxa=30000 distinct_x=30000
