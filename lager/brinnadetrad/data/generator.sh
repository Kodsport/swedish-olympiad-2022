#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution nils.cpp

compile gen_random.py
compile gen_samex.py
compile gen_antibadsort.py

MAXN=400000
MAXA=1000000000

samplegroup
limits maxn=$MAXN
sample_manual 1
sample_manual 2

group group1 14
limits maxn=$MAXN same_a=1
tc same_a-1 gen_random n=1
tc same_a-2 gen_random n=10 mina=3 maxa=3 maxd=20
tc same_a-3 gen_random n=$MAXN mina=1 maxa=1
tc same_a-4 gen_random n=$MAXN mina=10000 maxa=10000
tc same_a-5 gen_random n=$MAXN mina=$MAXA maxa=$MAXA


group group2 16
limits maxn=$MAXN same_d=1
tc same_d-1 gen_random n=1
tc same_d-2 gen_random n=10 maxa=20 mind=10 maxd=10
tc same_d-3 gen_random n=$MAXN mind=1 maxd=1
tc same_d-4 gen_random n=$MAXN mind=10000000 maxd=10000000
tc same_d-5 gen_random n=$MAXN mind=$MAXA maxd=$MAXA


group group3 11
limits maxn=100 maxa=100 maxd=100
tc small-1 gen_random n=1 maxa=1 maxd=1
tc small-2 gen_random n=2 maxa=3 maxd=3
tc small-3 gen_random n=3 maxa=5 maxd=5
tc small-4 gen_random n=5 maxa=20 maxd=20
tc small-5 gen_random n=17 maxa=50 maxd=50
tc small-6 gen_random n=100 maxa=100 maxd=100
tc small-7 gen_random n=100 maxa=100 maxd=100
tc small-8 gen_random n=100 maxa=100 maxd=100
tc small-9 gen_samex n=100 maxa=99 x=1
tc small-10 gen_samex n=100 maxa=97 x=3
tc small-11 gen_samex n=100 maxa=90 x=9
tc small-12 gen_samex n=100 maxa=77 x=17
tc small-13 gen_samex n=100 maxa=70 x=30
tc small-14 gen_samex n=100 maxa=50 x=50
tc small-15 gen_antibadsort n=100 maxd=100
tc 1
tc 2


group group4 23
limits maxn=2000
include_group group3
tc medium-1 gen_random n=100
tc medium-2 gen_random n=400
tc medium-3 gen_random n=2000 maxa=2000 maxd=2000
tc medium-4 gen_random n=2000 maxa=2000 maxd=2000
tc medium-5 gen_random n=2000
tc medium-6 gen_random n=2000
tc medium-7 gen_random n=2000 maxa=20000
tc medium-8 gen_samex n=2000 maxa=300000 x=100000
tc medium-9 gen_antibadsort n=2000


group group5 36
limits maxn=$MAXN
include_group group1
include_group group2
include_group group4
tc large-1 gen_random n=$MAXN maxa=$MAXN maxd=$MAXN
tc large-2 gen_random n=$MAXN maxa=$MAXN maxd=$MAXA
tc large-3 gen_random n=$MAXN maxa=$MAXA maxd=$MAXN
tc large-4 gen_random n=$MAXN maxa=$MAXA maxd=$MAXA
tc large-5 gen_random n=$MAXN maxa=$MAXA maxd=$MAXA
tc large-6 gen_random n=$MAXN maxa=$MAXA maxd=$MAXA
tc large-7 gen_random n=$MAXN maxa=100 maxd=$MAXA
tc large-8 gen_antibadsort n=$MAXN
