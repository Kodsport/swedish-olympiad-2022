#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh


use_solution joakim.cc

compile gen.cpp
compile gen_unique.py
compile gen_onequery.py

MAX_N=200000
MAX_VAL=1000000000

#################################################################################

samplegroup
limits max_value=$MAX_VAL max_n=10 
sample 1
sample 2

#################################################################################

group group1 5
limits max_n=200 max_value=200 max_q=200
include_group sample

tc smallest-1 gen_unique n=1 q=3 maxv=0
tc smallest-2 gen_unique n=8 q=8 maxv=10 mode=random
tc smallest-3 gen_unique n=40 q=200 maxv=200 mode=random
tc smallest-4 gen_unique n=200 q=200 maxv=200 mode=random
tc smallest-5 gen_unique n=200 q=200 maxv=200 mode=01_edge
tc smallest-6 gen_unique n=200 q=200 maxv=200 mode=increasing
tc smallest-7 gen_unique n=200 q=200 maxv=200 mode=unimodal
tc smallest-8 gen max_n=200 max_q=200 max_value=200 seed=8 type=1 
#################################################################################

group group2 7
limits max_n=200
include_group group1
tc small-1 gen_unique n=200 q=200 maxv=$MAX_VAL mode=random
tc small-2 gen_unique n=200 q=$MAX_N maxv=$MAX_VAL mode=random
tc small-3 gen_unique n=200 q=$MAX_N maxv=30 mode=random
tc small-4 gen_unique n=200 q=$MAX_N maxv=30 mode=increasing

#################################################################################
group group3 9
limits max_q=1 queryone=1
tc queryone-1 gen max_n=$MAX_N max_q=1 seed=1 type=1 max_value=$MAX_VAL queryone=1
tc queryone-2 gen max_n=$MAX_N max_q=1 seed=2 type=1 max_value=$MAX_VAL queryone=1
tc queryone-3 gen max_n=$MAX_N max_q=1 seed=3 type=1 max_value=$MAX_VAL queryone=1
tc queryone-4 gen max_n=$MAX_N max_q=1 seed=4 type=1 max_value=100 queryone=1
tc queryone-5 gen max_n=$MAX_N max_q=1 seed=5 type=1 max_value=100 queryone=1
tc queryone-6 gen max_n=$MAX_N max_q=1 seed=6 type=1 max_value=100 queryone=1
tc queryone-7 gen max_n=$MAX_N max_q=1 seed=7 type=3 max_value=$MAX_VAL queryone=1
tc queryone-8 gen max_n=$MAX_N max_q=1 seed=8 type=3 max_value=$MAX_VAL queryone=1
tc queryone-9 gen max_n=$MAX_N max_q=1 seed=9 type=3 max_value=100 queryone=1
tc queryone-10 gen max_n=$MAX_N max_q=1 seed=10 type=3 max_value=1000 queryone=1
tc queryone-11 gen max_n=$MAX_N max_q=1 seed=11 type=2 max_value=1000 queryone=1
tc queryone-12 gen max_n=$MAX_N max_q=1 seed=12 type=2 max_value=1000 queryone=1

#################################################################################
group group4 12
limits max_n=2000
include_group group2
tc medium-1 gen_unique n=2000 q=2000 maxv=$MAX_VAL mode=random
tc medium-2 gen_unique n=2000 q=$MAX_N maxv=$MAX_VAL mode=random
tc medium-3 gen_unique n=2000 q=$MAX_N maxv=300 mode=random
tc medium-4 gen_unique n=2000 q=$MAX_N maxv=2000 mode=increasing
tc medium-5 gen_unique n=2000 q=$MAX_N maxv=2000 mode=01_edge
tc medium-6 gen_unique n=2000 q=$MAX_N maxv=2000
tc medium-7 gen_unique n=2000 q=$MAX_N maxv=2000 mode=unimodal


#################################################################################

group group5 16
limits unique=1
tc unique-1 gen_unique n=1 q=1 maxv=0
tc unique-2 gen_unique n=10 q=200 maxv=10
tc unique-3 gen_unique n=20000 q=20000 maxv=10
tc unique-4 gen_unique n=$MAX_N q=$MAX_N
tc unique-5 gen_unique n=$MAX_N q=$MAX_N mode=increasing
tc unique-6 gen_unique n=$MAX_N q=$MAX_N mode=01_edge
tc unique-7 gen_unique n=$MAX_N q=$MAX_N mode=unimodal

#################################################################################

group group6 18
limits max_q=1
tc onequery-1 gen_unique n=1 q=1 maxv=0
tc onequery-2 gen_onequery n=20 k=5
tc onequery-3 gen_unique n=$MAX_N q=1 maxv=0 mode=random
tc onequery-4 gen_unique n=$MAX_N q=1 mode=random
tc onequery-5 gen_unique n=$MAX_N q=1 maxv=10000 mode=random
tc onequery-6 gen_unique n=$MAX_N q=1 maxv=1000 mode=random
tc onequery-7 gen_unique n=$MAX_N q=1 maxv=100 mode=random
tc onequery-8 gen_unique n=$MAX_N q=1 maxv=100 mode=01_edge
tc onequery-9 gen_onequery n=$MAX_N k=10
tc onequery-10 gen_onequery n=$MAX_N k=100
tc onequery-11 gen_onequery n=$MAX_N k=1000
tc onequery-12 gen_onequery n=$MAX_N k=10000
tc onequery-13 gen_onequery n=$MAX_N k=100 mode=rare_zero
tc onequery-14 gen_onequery n=$MAX_N k=10000 mode=big_numbers

#################################################################################


group group7 33

include_group group3
include_group group4
include_group group5

tc large-1 gen_unique n=$MAX_N q=$MAX_N maxv=0 mode=random
tc large-2 gen_unique n=$MAX_N q=$MAX_N maxv=1 mode=random
tc large-3 gen_unique n=$MAX_N q=$MAX_N maxv=10 mode=random
tc large-4 gen_unique n=$MAX_N q=$MAX_N maxv=1000 mode=random
tc large-5 gen_unique n=$MAX_N q=$MAX_N mode=random
