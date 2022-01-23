#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh


use_solution abdullah.cpp

compile gen.py

MAX_N=100000

#################################################################################
samplegroup
limits  max_n=$MAXN mode=none
sample 1
sample 2
sample 3

#################################################################################

group group1 20 # max_n=1000
limits max_n=500 mode=same_a
tc same_a-1 gen n=1 ans=1 mode=same_a 
tc same_a-2 gen n=2 ans=1 mode=same_a 
tc same_a-3 gen n=2 ans=2 mode=same_a 
tc same_a-4 gen n=5 ans=1 mode=same_a 
tc same_a-5 gen n=5 ans=2 mode=same_a 
tc same_a-6 gen n=5 ans=4 mode=same_a 
tc same_a-7 gen n=5 ans=5 mode=same_a 
tc same_a-8 gen n=100 ans=10 mode=same_a 
tc same_a-9 gen n=100 ans=50 mode=same_a 
tc same_a-10 gen n=500 ans=1 mode=same_a 
tc same_a-11 gen n=500 ans=2 mode=same_a 
tc same_a-12 gen n=500 ans=5 mode=same_a 
tc same_a-13 gen n=500 ans=50 mode=same_a 
tc same_a-14 gen n=500 ans=200 mode=same_a 
tc same_a-15 gen n=500 ans=500 mode=same_a 


group group2 30 # max_n=500
limits max_n=500 mode=none
include_group sample
tc small-1 gen n=1 ans=1 
tc small-2 gen n=2 ans=1 
tc small-3 gen n=2 ans=2 
tc small-4 gen n=5 ans=1 
tc small-5 gen n=5 ans=2 
tc small-6 gen n=5 ans=4 
tc small-7 gen n=5 ans=5 
tc small-8 gen n=100 ans=10 
tc small-9 gen n=100 ans=50 
tc small-10 gen n=500 ans=1 
tc small-11 gen n=500 ans=2 
tc small-12 gen n=500 ans=5 
tc small-13 gen n=500 ans=50 
tc small-14 gen n=500 ans=200 
tc small-15 gen n=500 ans=500 


#################################################################################

group group3 50 
limits max_n=$MAX_N mode=none
include_group sample
include_group group1
include_group group2

tc large-1 gen n=$MAX_N ans=1 
tc large-2 gen n=$MAX_N ans=2 
tc large-3 gen n=$MAX_N ans=5 
tc large-4 gen n=$MAX_N ans=50 
tc large-5 gen n=$MAX_N ans=200 
tc large-6 gen n=$MAX_N ans=1000 
tc large-7 gen n=$MAX_N ans=10000 
tc large-8 gen n=$MAX_N ans=$MAX_N 
