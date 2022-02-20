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

tc smallest-1 gen_unique n=1 q=3 maxv=0
tc smallest-2 gen_unique n=8 q=8 maxv=10 mode=random
tc smallest-3 gen_unique n=40 q=200 maxv=200 mode=random
tc smallest-4 gen_unique n=200 q=200 maxv=200 mode=random
tc smallest-5 gen_unique n=200 q=200 maxv=200 mode=01_edge
tc smallest-6 gen_unique n=200 q=200 maxv=200 mode=increasing
tc smallest-7 gen_unique n=200 q=200 maxv=200 mode=unimodal
tc smallest-8 gen max_n=200 max_q=200 max_value=5 seed=8 type=1 
tc smallest-9 gen max_n=200 max_q=200 max_value=20 seed=9 type=1 
tc smallest-10 gen max_n=200 max_q=200 max_value=20 seed=10 type=1 
tc smallest-11 gen max_n=200 max_q=200 max_value=20 seed=11 type=1 
tc smallest-12 gen max_n=200 max_q=200 max_value=20 seed=12 type=1 
tc smallest-13 gen max_n=200 max_q=200 max_value=20 seed=13 type=1 
tc smallest-14 gen max_n=200 max_q=200 max_value=20 seed=14 type=2 
tc smallest-15 gen max_n=200 max_q=200 max_value=20 seed=15 type=3 
tc smallest-16 gen max_n=200 max_q=200 max_value=20 seed=16 type=3 
tc smallest-17 gen max_n=200 max_q=200 max_value=20 seed=17 type=3 
tc smallest-18 gen max_n=200 max_q=200 max_value=200 seed=18 type=1 
tc smallest-19 gen max_n=200 max_q=200 max_value=200 seed=19 type=1 
tc smallest-20 gen max_n=200 max_q=200 max_value=200 seed=20 type=1 
tc smallest-21 gen max_n=200 max_q=200 max_value=200 seed=21 type=1 
tc smallest-22 gen max_n=200 max_q=200 max_value=200 seed=22 type=1 
tc smallest-23 gen max_n=200 max_q=200 max_value=200 seed=23 type=1 
tc smallest-24 gen max_n=200 max_q=200 max_value=200 seed=24 type=1 
tc smallest-25 gen max_n=200 max_q=200 max_value=200 seed=25 type=1 
tc smallest-26 gen max_n=200 max_q=200 max_value=200 seed=26 type=1 
tc smallest-27 gen max_n=200 max_q=200 max_value=200 seed=27 type=1 slump=1
tc smallest-28 gen max_n=200 max_q=200 max_value=200 seed=28 type=1 slump=1
tc smallest-29 gen max_n=200 max_q=200 max_value=200 seed=29 type=2 slump=1
tc smallest-30 gen max_n=200 max_q=200 max_value=200 seed=30 type=3 slump=1


#################################################################################

group group2 7
limits max_n=200
include_group group1
include_group sample
tc small-1 gen_unique n=200 q=200 maxv=$MAX_VAL mode=random
tc small-2 gen_unique n=200 q=$MAX_N maxv=$MAX_VAL mode=random
tc small-3 gen_unique n=200 q=$MAX_N maxv=30 mode=random
tc small-4 gen_unique n=200 q=$MAX_N maxv=30 mode=increasing
tc small-5 gen max_n=200 max_q=$MAX_N max_value=30 seed=5 type=1
tc small-6 gen max_n=200 max_q=$MAX_N max_value=30 seed=6 type=2 
tc small-7 gen max_n=200 max_q=$MAX_N max_value=30 seed=7 type=3 
tc small-8 gen max_n=200 max_q=$MAX_N max_value=30 seed=8 type=1 
tc small-9 gen max_n=200 max_q=$MAX_N max_value=30 seed=9 type=1 
tc small-10 gen max_n=200 max_q=$MAX_N max_value=$MAX_VAL seed=10 type=1 
tc small-11 gen max_n=200 max_q=$MAX_N max_value=$MAX_VAL seed=11 type=1 
tc small-12 gen max_n=200 max_q=$MAX_N max_value=$MAX_VAL seed=12 type=1 slump=1
tc small-13 gen max_n=200 max_q=$MAX_N max_value=$MAX_VAL seed=13 type=2
tc small-14 gen max_n=200 max_q=$MAX_N max_value=$MAX_VAL seed=14 type=3 



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
tc queryone-11 gen max_n=$MAX_N max_q=1 seed=11 type=2 max_value=50 queryone=1
tc queryone-12 gen max_n=$MAX_N max_q=1 seed=12 type=2 max_value=1000 queryone=1


#################################################################################

group group4 12
limits unique=1
tc unique-1 gen_unique n=1 q=1 maxv=0
tc unique-2 gen_unique n=10 q=200 maxv=10
tc unique-3 gen_unique n=20000 q=20000 maxv=10
tc unique-4 gen_unique n=$MAX_N q=$MAX_N
tc unique-5 gen_unique n=$MAX_N q=$MAX_N mode=increasing
tc unique-6 gen_unique n=$MAX_N q=$MAX_N mode=01_edge
tc unique-7 gen_unique n=$MAX_N q=$MAX_N mode=unimodal


#################################################################################
group group5 16
limits max_n=2000
include_group group1
include_group group2

tc medium-1 gen_unique n=2000 q=2000 maxv=$MAX_VAL mode=random
tc medium-2 gen_unique n=2000 q=$MAX_N maxv=$MAX_VAL mode=random
tc medium-3 gen_unique n=2000 q=$MAX_N maxv=300 mode=random
tc medium-4 gen_unique n=2000 q=$MAX_N maxv=2000 mode=increasing
tc medium-5 gen_unique n=2000 q=$MAX_N maxv=2000 mode=01_edge
tc medium-6 gen_unique n=2000 q=$MAX_N maxv=2000
tc medium-7 gen_unique n=2000 q=$MAX_N maxv=2000 mode=unimodal
tc medium-8 gen max_n=2000 max_q=$MAX_N max_value=$MAX_VAL seed=8 type=1
tc medium-9 gen max_n=2000 max_q=$MAX_N max_value=$MAX_VAL seed=9 type=1
tc medium-10 gen max_n=2000 max_q=$MAX_N max_value=$MAX_VAL seed=10 type=1
tc medium-11 gen max_n=2000 max_q=$MAX_N max_value=$MAX_VAL seed=11 type=1 slump=1
tc medium-12 gen max_n=2000 max_q=$MAX_N max_value=$MAX_VAL seed=12 type=2

#################################################################################

group group6 18
limits max_q=1
include_group group3
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
tc onequery-15 gen max_n=$MAX_N max_q=1 max_value=$MAX_VAL seed=15 type=1
tc onequery-16 gen max_n=$MAX_N max_q=1 max_value=$MAX_VAL seed=16 type=1
tc onequery-17 gen max_n=$MAX_N max_q=1 max_value=$MAX_VAL seed=17 type=1
tc onequery-18 gen max_n=$MAX_N max_q=1 max_value=$MAX_VAL seed=18 type=1
tc onequery-19 gen max_n=$MAX_N max_q=1 max_value=$MAX_VAL seed=19 type=1
tc onequery-20 gen max_n=$MAX_N max_q=1 max_value=$MAX_VAL seed=20 type=2
tc onequery-21 gen max_n=$MAX_N max_q=1 max_value=$MAX_VAL seed=21 type=3

#################################################################################


group group7 33
include_group sample
include_group group1
include_group group2
include_group group3
include_group group4
include_group group5
include_group group6

tc large-1 gen_unique n=$MAX_N q=$MAX_N maxv=0 mode=random
tc large-2 gen_unique n=$MAX_N q=$MAX_N maxv=1 mode=random
tc large-3 gen_unique n=$MAX_N q=$MAX_N maxv=10 mode=random
tc large-4 gen_unique n=$MAX_N q=$MAX_N maxv=1000 mode=random
tc large-5 gen_unique n=$MAX_N q=$MAX_N mode=random
tc large-6 gen max_n=$MAX_N max_q=$MAX_N max_value=10 type=1 seed=6
tc large-7 gen max_n=$MAX_N max_q=$MAX_N max_value=10 type=1 seed=7
tc large-8 gen max_n=$MAX_N max_q=$MAX_N max_value=100 type=1 seed=8
tc large-9 gen max_n=$MAX_N max_q=$MAX_N max_value=1000 type=1 seed=9
tc large-10 gen max_n=$MAX_N max_q=$MAX_N max_value=1000 type=1 seed=10
tc large-11 gen max_n=$MAX_N max_q=$MAX_N max_value=$MAX_VAL type=1 seed=11
tc large-12 gen max_n=$MAX_N max_q=$MAX_N max_value=$MAX_VAL type=1 seed=12
tc large-13 gen max_n=$MAX_N max_q=$MAX_N max_value=$MAX_VAL type=1 seed=13
tc large-14 gen max_n=$MAX_N max_q=$MAX_N max_value=$MAX_VAL type=1 seed=14 slump=1 
tc large-15 gen max_n=$MAX_N max_q=$MAX_N max_value=$MAX_VAL type=1 seed=15 slump=1
tc large-16 gen max_n=$MAX_N max_q=$MAX_N max_value=$MAX_VAL type=2 seed=16 slump=1
tc large-17 gen max_n=$MAX_N max_q=$MAX_N max_value=$MAX_VAL type=2 seed=17 slump=1
tc large-18 gen max_n=$MAX_N max_q=$MAX_N max_value=$MAX_VAL type=2 seed=18 
tc large-19 gen max_n=$MAX_N max_q=$MAX_N max_value=$MAX_VAL type=2 seed=19
tc large-20 gen max_n=$MAX_N max_q=$MAX_N max_value=$MAX_VAL type=3 seed=20

