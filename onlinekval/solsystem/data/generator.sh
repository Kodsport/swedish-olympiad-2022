#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh


use_solution abdullah.cpp

compile gen_no_restrictions.cpp 
compile gen_all_length.cpp 

max_n=100000
max_q=100000
max_r=1000000000

#################################################################################
samplegroup
limits max_n=$max_n max_q=$max_q max_r=$max_r
sample 1
sample 2
sample 3
sample 4

#################################################################################
group group1 15 # q=1
limits max_n=$max_n max_q=1 max_r=$max_r

tc 1
tc few-queries-all-length1 gen_all_length max_n=$max_n max_q=1 max_r=$max_r seed=1
tc few-queries-all-length2 gen_all_length max_n=$max_n max_q=1 max_r=$max_r seed=2
tc few-queries-all-length3 gen_all_length max_n=$max_n max_q=1 max_r=$max_r seed=3
tc few-queries-all-length4 gen_all_length max_n=$max_n max_q=1 max_r=$max_r seed=4
tc few-queries-all-length5 gen_all_length max_n=$max_n max_q=1 max_r=$max_r seed=5

tc few-queries-no-restrictions1 gen_no_restrictions max_n=$max_n max_q=1 max_r=$max_r seed=6
tc few-queries-no-restrictions2 gen_no_restrictions max_n=$max_n max_q=1 max_r=$max_r seed=7
tc few-queries-no-restrictions3 gen_no_restrictions max_n=$max_n max_q=1 max_r=$max_r seed=8
tc few-queries-no-restrictions4 gen_no_restrictions max_n=$max_n max_q=1 max_r=$max_r seed=9
tc few-queries-no-restrictions5 gen_no_restrictions max_n=$max_n max_q=1 max_r=$max_r seed=10
tc few-queries-no-restrictions6 gen_no_restrictions max_n=$max_n max_q=1 max_r=$max_r seed=11

tc few-queries-tiny1 gen_no_restrictions max_n=20 max_q=1 max_r=20 seed=12
tc few-queries-tiny2 gen_no_restrictions max_n=20 max_q=1 max_r=20 seed=13
tc few-queries-tiny3 gen_no_restrictions max_n=20 max_q=1 max_r=20 seed=14
tc few-queries-tiny4 gen_no_restrictions max_n=20 max_q=1 max_r=20 seed=15
tc few-queries-tiny5 gen_no_restrictions max_n=20 max_q=1 max_r=20 seed=16

tc few-queries-tiny6 gen_no_restrictions max_n=5 max_q=1 max_r=10 seed=18
tc few-queries-tiny7 gen_no_restrictions max_n=5 max_q=1 max_r=10 seed=19
tc few-queries-tiny8 gen_no_restrictions max_n=5 max_q=1 max_r=10 seed=20
tc few-queries-tiny9 gen_no_restrictions max_n=5 max_q=1 max_r=10 seed=21

tc few-queries-tiny10 gen_no_restrictions max_n=5 max_q=1 max_r=5 seed=22
tc few-queries-tiny11 gen_no_restrictions max_n=5 max_q=1 max_r=5 seed=23
tc few-queries-tiny12 gen_no_restrictions max_n=5 max_q=1 max_r=5 seed=24
tc few-queries-tiny13 gen_no_restrictions max_n=5 max_q=1 max_r=5 seed=25



#################################################################################
group group2 35 # l_i and r_i are increasing
limits max_n=$max_n max_q=$max_q max_r=$max_r increasing=1

tc 3
tc increasing-all-length1 gen_all_length max_n=$max_n max_q=$max_q max_r=$max_r seed=1 increasing=1
tc increasing-all-length2 gen_all_length max_n=$max_n max_q=$max_q max_r=$max_r seed=2 increasing=1
tc increasing-all-length3 gen_all_length max_n=$max_n max_q=$max_q max_r=$max_r seed=3 increasing=1
tc increasing-all-length4 gen_all_length max_n=$max_n max_q=$max_q max_r=$max_r seed=4 increasing=1

tc increasing-no-restrictions1 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=5 increasing=1
tc increasing-no-restrictions2 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=6 increasing=1
tc increasing-no-restrictions3 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=7 increasing=1
tc increasing-no-restrictions4 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=8 increasing=1
tc increasing-no-restrictions5 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=9 increasing=1
tc increasing-no-restrictions6 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=10 increasing=1
tc increasing-no-restrictions7 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=11 increasing=1

tc inreasing-tiny1 gen_no_restrictions max_n=20 max_q=20 max_r=100 seed=12 increasing=1
tc inreasing-tiny2 gen_no_restrictions max_n=20 max_q=20 max_r=100 seed=13 increasing=1
tc inreasing-tiny3 gen_no_restrictions max_n=20 max_q=20 max_r=100 seed=14 increasing=1
tc inreasing-tiny4 gen_no_restrictions max_n=20 max_q=20 max_r=100 seed=15 increasing=1
tc inreasing-tiny5 gen_no_restrictions max_n=20 max_q=20 max_r=100 seed=16 increasing=1

tc inreasing-tiny6 gen_no_restrictions max_n=5 max_q=5 max_r=25 seed=18 increasing=1
tc inreasing-tiny7 gen_no_restrictions max_n=5 max_q=5 max_r=25 seed=19 increasing=1
tc inreasing-tiny8 gen_no_restrictions max_n=5 max_q=5 max_r=25 seed=20 increasing=1
tc inreasing-tiny9 gen_no_restrictions max_n=5 max_q=5 max_r=25 seed=21 increasing=1

tc inreasing-tiny10 gen_no_restrictions max_n=5 max_q=5 max_r=25 seed=22 increasing=1
tc inreasing-tiny11 gen_no_restrictions max_n=5 max_q=5 max_r=25 seed=23 increasing=1
tc inreasing-tiny12 gen_no_restrictions max_n=5 max_q=5 max_r=25 seed=24 increasing=1
tc inreasing-tiny13 gen_no_restrictions max_n=5 max_q=5 max_r=25 seed=25 increasing=1
#################################################################################
group group3 38 # A_i,B_i,r_i<=1e5
limits max_n=$max_n max_q=$max_q max_r=100000 

include_group sample
tc small-coordinates-all-length1 gen_all_length max_n=$max_n max_q=$max_q max_r=100000 seed=1
tc small-coordinates-all-length2 gen_all_length max_n=$max_n max_q=$max_q max_r=100000 seed=2
tc small-coordinates-all-length3 gen_all_length max_n=$max_n max_q=$max_q max_r=100000 seed=3
tc small-coordinates-all-length4 gen_all_length max_n=$max_n max_q=$max_q max_r=100000 seed=4

tc small-coordinates-no-restrictions1 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=5
tc small-coordinates-no-restrictions2 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=6
tc small-coordinates-no-restrictions3 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=7
tc small-coordinates-no-restrictions4 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=8
tc small-coordinates-no-restrictions5 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=9
tc small-coordinates-no-restrictions6 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=10
tc small-coordinates-no-restrictions7 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=11
tc small-coordinates-no-restrictions8 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=12
tc small-coordinates-no-restrictions9 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=13
tc small-coordinates-no-restrictions10 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=14
tc small-coordinates-no-restrictions11 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=15
tc small-coordinates-no-restrictions12 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=100000 seed=16

tc small-coordinates-tiny1 gen_no_restrictions max_n=20 max_q=20 max_r=20 seed=12
tc small-coordinates-tiny2 gen_no_restrictions max_n=20 max_q=20 max_r=20 seed=13
tc small-coordinates-tiny3 gen_no_restrictions max_n=20 max_q=20 max_r=20 seed=14
tc small-coordinates-tiny4 gen_no_restrictions max_n=20 max_q=20 max_r=20 seed=15
tc small-coordinates-tiny5 gen_no_restrictions max_n=20 max_q=20 max_r=20 seed=16

tc small-coordinates-tiny6 gen_no_restrictions max_n=5 max_q=100 max_r=10 seed=18
tc small-coordinates-tiny7 gen_no_restrictions max_n=5 max_q=100 max_r=10 seed=19
tc small-coordinates-tiny8 gen_no_restrictions max_n=5 max_q=10 max_r=10 seed=20
tc small-coordinates-tiny9 gen_no_restrictions max_n=5 max_q=10 max_r=10 seed=21

tc small-coordinates-tiny10 gen_no_restrictions max_n=5 max_q=5 max_r=5 seed=22
tc small-coordinates-tiny11 gen_no_restrictions max_n=5 max_q=5 max_r=5 seed=23
tc small-coordinates-tiny12 gen_no_restrictions max_n=5 max_q=5 max_r=5 seed=24
tc small-coordinates-tiny13 gen_no_restrictions max_n=5 max_q=5 max_r=5 seed=25

#################################################################################
group group4 12 # no additional constraints
limits max_n=$max_n max_q=$max_q max_r=$max_r 
include_group sample
include_group group1
include_group group2
include_group group3

tc large-coordinates-all-length1 gen_all_length max_n=$max_n max_q=$max_q max_r=$max_r seed=1
tc large-coordinates-all-length2 gen_all_length max_n=$max_n max_q=$max_q max_r=$max_r seed=2
tc large-coordinates-all-length3 gen_all_length max_n=$max_n max_q=$max_q max_r=$max_r seed=3
tc large-coordinates-all-length4 gen_all_length max_n=$max_n max_q=$max_q max_r=$max_r seed=4

tc large-coordinates-no-restrictions1 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=5
tc large-coordinates-no-restrictions2 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=6
tc large-coordinates-no-restrictions3 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=7
tc large-coordinates-no-restrictions4 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=8
tc large-coordinates-no-restrictions5 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=9
tc large-coordinates-no-restrictions6 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=10
tc large-coordinates-no-restrictions7 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=11
tc large-coordinates-no-restrictions8 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=12
tc large-coordinates-no-restrictions9 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=13
tc large-coordinates-no-restrictions10 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=14
tc large-coordinates-no-restrictions11 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=15
tc large-coordinates-no-restrictions12 gen_no_restrictions max_n=$max_n max_q=$max_q max_r=$max_r seed=16
