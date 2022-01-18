#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh


use_solution abdullah.cpp

compile gen.cpp

MAX_N=200000
MAX_VAL=1000000000

#################################################################################
samplegroup
limits max_value=$MAX_VAL plus_one=1 max_n=10
sample 1
sample 2
sample 3
sample 4

#################################################################################

group group1 15 # max_n=8
limits max_value=$MAX_VAL plus_one=1 max_n=8
include_group sample
tc small-1 gen seed=1 max_value=10 max_n=8 plus_one=1
tc small-2 gen seed=2 max_value=10 max_n=8 plus_one=1
tc small-3 gen seed=3 max_value=10 max_n=8 plus_one=1
tc small-4 gen seed=4 max_value=10 max_n=8 plus_one=1
tc small-5 gen seed=5 max_value=10 max_n=8 plus_one=1
tc small-6 gen seed=6 max_value=10 max_n=8 plus_one=1
tc small-7 gen seed=7 max_value=10 max_n=8 plus_one=1
tc small-8 gen seed=8 max_value=10 max_n=8 plus_one=1
tc small-9 gen seed=9 max_value=10 max_n=8 plus_one=1
tc small-10 gen seed=10 max_value=10 max_n=8 plus_one=1
tc small-11 gen seed=11 max_value=2 max_n=4 plus_one=1
tc small-12 gen seed=12 max_value=2 max_n=4 plus_one=1
tc small-13 gen seed=13 max_value=2 max_n=4 plus_one=1
tc small-14 gen seed=14 max_value=2 max_n=4 plus_one=1
tc small-15 gen seed=15 max_value=$MAX_VAL max_n=4 plus_one=1
tc small-16 gen seed=16 max_value=$MAX_VAL max_n=4 plus_one=1
tc small-17 gen seed=17 max_value=$MAX_VAL max_n=4 plus_one=1
tc small-18 gen seed=18 max_value=$MAX_VAL max_n=4 plus_one=1
tc small-19 gen seed=19 max_value=$MAX_VAL max_n=4 plus_one=1
tc small-20 gen seed=20 max_value=$MAX_VAL max_n=4 plus_one=1
tc small-21 gen seed=21 max_value=$MAX_VAL max_n=8 plus_one=0
tc small-22 gen seed=22 max_value=$MAX_VAL max_n=8 plus_one=0
tc small-23 gen seed=23 max_value=$MAX_VAL max_n=8 plus_one=0
tc small-24 gen seed=24 max_value=$MAX_VAL max_n=8 plus_one=0
tc small-25 gen seed=25 max_value=$MAX_VAL max_n=8 plus_one=1
tc small-26 gen seed=26 max_value=$MAX_VAL max_n=8 plus_one=1
tc small-27 gen seed=27 max_value=$MAX_VAL max_n=8 plus_one=1
tc small-28 gen seed=28 max_value=$MAX_VAL max_n=8 plus_one=1
tc small-29 gen seed=29 max_value=$MAX_VAL max_n=8 plus_one=1
tc small-30 gen seed=30 max_value=$MAX_VAL max_n=8 plus_one=1
tc small-31 gen seed=31 max_value=2 max_n=4 plus_one=1
tc small-32 gen seed=32 max_value=2 max_n=4 plus_one=1
tc small-33 gen seed=33 max_value=2 max_n=4 plus_one=1
tc small-34 gen seed=34 max_value=2 max_n=4 plus_one=1
tc small-35 gen seed=35 max_value=2 max_n=4 plus_one=1

#################################################################################

group group2 25 # max_n=2000
limits max_value=$MAX_VAL max_n=2000 plus_one=1
include_group sample
include_group group1
tc medium-1 gen seed=1 max_value=10 max_n=2000 plus_one=1
tc medium-2 gen seed=2 max_value=10 max_n=2000 plus_one=1
tc medium-3 gen seed=3 max_value=10 max_n=2000 plus_one=1
tc medium-4 gen seed=4 max_value=10 max_n=2000 plus_one=1
tc medium-5 gen seed=5 max_value=10 max_n=2000 plus_one=1
tc medium-6 gen seed=6 max_value=10 max_n=2000 plus_one=1
tc medium-7 gen seed=7 max_value=10 max_n=2000 plus_one=1
tc medium-8 gen seed=8 max_value=10 max_n=2000 plus_one=1
tc medium-9 gen seed=9 max_value=10 max_n=2000 plus_one=1
tc medium-10 gen seed=10 max_value=100 max_n=2000 plus_one=1
tc medium-11 gen seed=11 max_value=100 max_n=2000 plus_one=1
tc medium-12 gen seed=12 max_value=100 max_n=2000 plus_one=1
tc medium-13 gen seed=13 max_value=100 max_n=2000 plus_one=1
tc medium-14 gen seed=14 max_value=100 max_n=2000 plus_one=1
tc medium-15 gen seed=15 max_value=$MAX_VAL max_n=2000 plus_one=1
tc medium-16 gen seed=16 max_value=$MAX_VAL max_n=2000 plus_one=1
tc medium-17 gen seed=17 max_value=$MAX_VAL max_n=2000 plus_one=1
tc medium-18 gen seed=18 max_value=$MAX_VAL max_n=2000 plus_one=1
tc medium-19 gen seed=19 max_value=$MAX_VAL max_n=2000 plus_one=1
tc medium-20 gen seed=20 max_value=$MAX_VAL max_n=2000 plus_one=1
tc medium-21 gen seed=21 max_value=$MAX_VAL max_n=2000 plus_one=1
tc medium-22 gen seed=22 max_value=$MAX_VAL max_n=2000 plus_one=1
tc medium-23 gen seed=23 max_value=$MAX_VAL max_n=2000 plus_one=1
tc medium-24 gen seed=24 max_value=$MAX_VAL max_n=2000 plus_one=1
tc medium-25 gen seed=25 max_value=$MAX_VAL max_n=2000 plus_one=0
tc medium-26 gen seed=26 max_value=$MAX_VAL max_n=2000 plus_one=0
tc medium-27 gen seed=27 max_value=$MAX_VAL max_n=2000 plus_one=0
tc medium-28 gen seed=28 max_value=$MAX_VAL max_n=2000 plus_one=0
tc medium-29 gen seed=29 max_value=$MAX_VAL max_n=2000 plus_one=0
tc medium-30 gen seed=30 max_value=$MAX_VAL max_n=2000 plus_one=0

#################################################################################

group group3 20 #plus_one=0
limits max_value=$MAX_VAL max_n=$MAX_N plus_one=0

tc large-equal-1 gen seed=1 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-2 gen seed=2 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-3 gen seed=3 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-4 gen seed=4 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-5 gen seed=5 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-6 gen seed=6 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-7 gen seed=7 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-8 gen seed=8 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-9 gen seed=9 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-10 gen seed=10 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-11 gen seed=11 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-12 gen seed=12 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-13 gen seed=13 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-14 gen seed=14 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-15 gen seed=15 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-16 gen seed=16 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-17 gen seed=17 max_value=$MAX_VAL max_n=$MAX_N plus_one=0
tc large-equal-18 gen seed=18 max_value=100 max_n=$MAX_N plus_one=0
tc large-equal-19 gen seed=19 max_value=100 max_n=$MAX_N plus_one=0
tc large-equal-20 gen seed=20 max_value=100 max_n=$MAX_N plus_one=0
tc large-equal-21 gen seed=21 max_value=100 max_n=$MAX_N plus_one=0
tc large-equal-22 gen seed=22 max_value=100 max_n=$MAX_N plus_one=0

#################################################################################

group group4 40
limits max_value=$MAX_VAL max_n=$MAX_N plus_one=1
include_group sample
include_group group1
include_group group2
include_group group3

tc large-1 gen seed=1 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-2 gen seed=2 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-3 gen seed=3 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-4 gen seed=4 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-5 gen seed=5 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-6 gen seed=6 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-7 gen seed=7 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-8 gen seed=8 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-9 gen seed=9 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-10 gen seed=10 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-11 gen seed=11 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-12 gen seed=12 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-13 gen seed=13 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-14 gen seed=14 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-15 gen seed=15 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-16 gen seed=16 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-17 gen seed=17 max_value=$MAX_VAL max_n=$MAX_N plus_one=1
tc large-18 gen seed=18 max_value=100 max_n=$MAX_N plus_one=1
tc large-19 gen seed=19 max_value=100 max_n=$MAX_N plus_one=1
tc large-20 gen seed=20 max_value=100 max_n=$MAX_N plus_one=1
tc large-21 gen seed=21 max_value=100 max_n=$MAX_N plus_one=1
tc large-22 gen seed=22 max_value=100 max_n=$MAX_N plus_one=1
