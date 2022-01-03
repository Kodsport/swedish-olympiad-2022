#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh


use_solution abdullah.cpp

compile gen.cpp

MAX_N=200000
MAX_K=1000000000

#################################################################################
samplegroup
limits max_k=$MAX_K  max_n=10
sample 1
sample 2
sample 3

#################################################################################


group group1 50 # max_n=2000
limits max_k=$MAX_K max_n=2000 
include_group sample
tc medium-1 gen seed=1 max_k=10 max_n=2000 
tc medium-2 gen seed=2 max_k=10 max_n=2000 
tc medium-3 gen seed=3 max_k=10 max_n=2000 
tc medium-4 gen seed=4 max_k=10 max_n=2000 
tc medium-5 gen seed=5 max_k=10 max_n=2000 
tc medium-6 gen seed=6 max_k=10 max_n=2000 
tc medium-7 gen seed=7 max_k=10 max_n=2000 
tc medium-8 gen seed=8 max_k=10 max_n=2000 
tc medium-9 gen seed=9 max_k=10 max_n=2000 
tc medium-10 gen seed=10 max_k=100 max_n=2000 
tc medium-11 gen seed=11 max_k=100 max_n=2000 
tc medium-12 gen seed=12 max_k=100 max_n=2000 
tc medium-13 gen seed=13 max_k=100 max_n=2000 
tc medium-14 gen seed=14 max_k=100 max_n=2000 
tc medium-15 gen seed=15 max_k=1000 max_n=2000 
tc medium-16 gen seed=16 max_k=1000 max_n=2000 
tc medium-17 gen seed=17 max_k=1000 max_n=2000 
tc medium-18 gen seed=18 max_k=1000 max_n=2000 
tc medium-19 gen seed=19 max_k=10000 max_n=2000 
tc medium-20 gen seed=20 max_k=10000 max_n=2000 
tc medium-21 gen seed=21 max_k=10000 max_n=2000 
tc medium-22 gen seed=22 max_k=10000 max_n=2000 
tc medium-23 gen seed=23 max_k=10000 max_n=2000 
tc medium-24 gen seed=24 max_k=$MAX_K max_n=2000 
tc medium-25 gen seed=25 max_k=$MAX_K max_n=2000 
tc medium-26 gen seed=26 max_k=$MAX_K max_n=2000 
tc medium-27 gen seed=27 max_k=$MAX_K max_n=2000 
tc medium-28 gen seed=28 max_k=$MAX_K max_n=2000 
tc medium-29 gen seed=29 max_k=$MAX_K max_n=2000 
tc medium-30 gen seed=30 max_k=$MAX_K max_n=2000
tc medium-31 gen seed=31 max_k=1000 max_n=15 
tc medium-32 gen seed=32 max_k=1000 max_n=15 
tc medium-33 gen seed=33 max_k=1000 max_n=15 
tc medium-34 gen seed=34 max_k=1000 max_n=15 
tc medium-35 gen seed=35 max_k=1000 max_n=15 
tc medium-36 gen seed=36 max_k=1000 max_n=15 
tc medium-37 gen seed=37 max_k=1000 max_n=15 
tc medium-38 gen seed=38 max_k=1000 max_n=15 
tc medium-39 gen seed=39 max_k=1000 max_n=15 
tc medium-40 gen seed=40 max_k=1000 max_n=15 
tc medium-41 gen seed=41 max_k=300 max_n=15 
tc medium-42 gen seed=42 max_k=300 max_n=15
tc medium-43 gen seed=43 max_k=300 max_n=15 
tc medium-44 gen seed=44 max_k=300 max_n=15 
tc medium-45 gen seed=45 max_k=300 max_n=15 
tc medium-46 gen seed=46 max_k=300 max_n=15 
tc medium-47 gen seed=47 max_k=10 max_n=15 
tc medium-48 gen seed=48 max_k=10 max_n=15 
tc medium-49 gen seed=49 max_k=0 max_n=15 
tc medium-50 gen seed=50 max_k=0 max_n=15 



#################################################################################

group group2 50 
limits max_k=$MAX_K max_n=$MAX_N 
include_group sample
include_group group1

tc large-1 gen seed=1 max_k=$MAX_K max_n=$MAX_N 
tc large-2 gen seed=2 max_k=$MAX_K max_n=$MAX_N 
tc large-3 gen seed=3 max_k=$MAX_K max_n=$MAX_N 
tc large-4 gen seed=4 max_k=$MAX_K max_n=$MAX_N 
tc large-5 gen seed=5 max_k=$MAX_K max_n=$MAX_N 
tc large-6 gen seed=6 max_k=$MAX_K max_n=$MAX_N 
tc large-7 gen seed=7 max_k=$MAX_K max_n=$MAX_N 
tc large-8 gen seed=8 max_k=$MAX_K max_n=$MAX_N 
tc large-9 gen seed=9 max_k=$MAX_K max_n=$MAX_N 
tc large-10 gen seed=10 max_k=10000 max_n=$MAX_N 
tc large-11 gen seed=11 max_k=10000 max_n=$MAX_N 
tc large-12 gen seed=12 max_k=10000 max_n=$MAX_N 
tc large-13 gen seed=13 max_k=10000 max_n=$MAX_N 
tc large-14 gen seed=14 max_k=10000 max_n=$MAX_N 
tc large-15 gen seed=15 max_k=10000 max_n=$MAX_N 
tc large-16 gen seed=16 max_k=10000 max_n=$MAX_N 
tc large-17 gen seed=17 max_k=10000 max_n=$MAX_N 
tc large-18 gen seed=18 max_k=1000 max_n=$MAX_N 
tc large-19 gen seed=19 max_k=1000 max_n=$MAX_N 
tc large-20 gen seed=20 max_k=1000 max_n=$MAX_N 
tc large-21 gen seed=21 max_k=1000 max_n=$MAX_N 
tc large-22 gen seed=22 max_k=1000 max_n=$MAX_N
tc large-23 gen seed=23 max_k=0 max_n=$MAX_N
