#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution joakim.cc

compile gen.cpp

# Commented some testcases out because they were identical to other ones
MAX_RC=200000

samplegroup
limits maxRC=$MAX_RC
sample 1
sample 2
sample 3
sample 4
sample 5

group group1 9
limits empty=1 maxRC=$MAX_RC
tc empty-1 gen seed=1 type=1 mode=1 probability=0 maxRC=$MAX_RC
tc empty-2 gen seed=2 type=1 mode=2 probability=0 maxRC=$MAX_RC
tc empty-3 gen seed=3 type=1 mode=3 probability=0 maxRC=$MAX_RC
tc empty-4 gen seed=4 type=1 mode=4 probability=0 maxRC=$MAX_RC


group group2 10
limits maxRC=10
tc 1
tc 2
tc small-RC-1 gen seed=1 type=1 mode=1 probability=30 maxRC=10
tc small-RC-2 gen seed=2 type=1 mode=2 probability=30 maxRC=10
tc small-RC-4 gen seed=4 type=1 mode=2 probability=30 maxRC=10
tc small-RC-5 gen seed=5 type=1 mode=2 probability=30 maxRC=10
tc small-RC-6 gen seed=6 type=1 mode=4 probability=30 maxRC=10
tc small-RC-7 gen seed=7 type=1 mode=4 probability=30 maxRC=10
tc small-RC-8 gen seed=8 type=1 mode=4 probability=100 maxRC=10
tc small-RC-9 gen seed=9 type=4 mode=4 probability=75 maxRC=10
# tc small-RC-10 gen seed=10 type=4 mode=4 probability=75 maxRC=10
tc small-RC-11 gen seed=11 type=4 mode=4 probability=75 maxRC=10
# tc small-RC-12 gen seed=12 type=4 mode=2 probability=75 maxRC=10
tc small-RC-13 gen seed=13 type=4 mode=2 probability=75 maxRC=10
# tc small-RC-14 gen seed=14 type=4 mode=2 probability=75 maxRC=10
# tc small-RC-15 gen seed=15 type=4 mode=2 probability=75 maxRC=10
# tc small-RC-16 gen seed=16 type=4 mode=2 probability=75 maxRC=10
tc small-RC-17 gen seed=17 type=4 mode=2 probability=30 maxRC=10






group group3 20
limits maxRC=$MAX_RC three=1
tc empty-3
tc three-1 gen type=1 mode=3 seed=1 probability=100 maxRC=$MAX_RC
tc three-2 gen type=1 mode=3 seed=2 probability=1 maxRC=$MAX_RC
tc three-3 gen type=1 mode=3 seed=3 probability=10 maxRC=$MAX_RC
tc three-4 gen type=1 mode=3 seed=4 probability=10 maxRC=$MAX_RC
tc three-5 gen type=1 mode=3 seed=5 probability=30 maxRC=$MAX_RC
tc three-6 gen type=1 mode=3 seed=6 probability=30 maxRC=$MAX_RC
tc three-7 gen type=1 mode=3 seed=7 probability=50 maxRC=$MAX_RC
tc three-8 gen type=1 mode=3 seed=8 probability=30 maxRC=$MAX_RC
tc three-9 gen type=1 mode=3 seed=9 probability=50 maxRC=$MAX_RC
tc three-10 gen type=1 mode=3 seed=10 probability=75 maxRC=$MAX_RC
tc three-11 gen type=1 mode=3 seed=11 probability=75 maxRC=$MAX_RC
# tc three-12 gen type=2 mode=3 seed=101 probability=100 maxRC=$MAX_RC
tc three-13 gen type=2 mode=3 seed=13 probability=100 maxRC=$MAX_RC #counter heuristic
tc three-14 gen type=4 mode=3 seed=14 probability=10 maxRC=$MAX_RC
tc three-15 gen type=4 mode=3 seed=15 probability=10 maxRC=$MAX_RC
tc three-16 gen type=4 mode=3 seed=16 probability=10 maxRC=$MAX_RC
tc three-17 gen type=4 mode=3 seed=17 probability=30 maxRC=$MAX_RC
tc three-18 gen type=4 mode=3 seed=18 probability=30 maxRC=$MAX_RC
tc three-19 gen type=4 mode=3 seed=19 probability=30 maxRC=$MAX_RC
tc three-20 gen type=4 mode=3 seed=20 probability=50 maxRC=$MAX_RC
tc three-21 gen type=4 mode=3 seed=21 probability=75 maxRC=$MAX_RC
tc three-22 gen type=4 mode=3 seed=22 probability=75 maxRC=$MAX_RC
tc three-23 gen type=4 mode=3 seed=23 probability=75 maxRC=$MAX_RC
tc three-24 gen type=4 mode=3 seed=24 probability=75 maxRC=$MAX_RC


group group4 25
limits maxRC=1000 down_and_right=1
tc down-and-right-1 gen type=3 mode=2 seed=1 probability=1 maxRC=1000 
tc down-and-right-2 gen type=3 mode=2 seed=2 probability=10 maxRC=1000 
tc down-and-right-3 gen type=3 mode=2 seed=3 probability=10 maxRC=1000 
tc down-and-right-4 gen type=3 mode=2 seed=4 probability=10 maxRC=1000 
tc down-and-right-5 gen type=3 mode=2 seed=5 probability=30 maxRC=1000 
tc down-and-right-6 gen type=3 mode=2 seed=6 probability=30 maxRC=1000 
tc down-and-right-7 gen type=3 mode=2 seed=7 probability=50 maxRC=1000 
tc down-and-right-8 gen type=3 mode=2 seed=8 probability=50 maxRC=1000 
tc down-and-right-9 gen type=3 mode=2 seed=9 probability=75 maxRC=1000 
tc down-and-right-10 gen type=3 mode=2 seed=10 probability=75 maxRC=1000 
tc down-and-right-11 gen type=3 mode=2 seed=11 probability=100 maxRC=1000 
# tc down-and-right-12 gen type=3 mode=2 seed=12 probability=100 maxRC=1000 
tc down-and-right-13 gen type=3 mode=2 seed=13 probability=100 maxRC=1000 
tc down-and-right-14 gen type=3 mode=2 seed=14 probability=100 maxRC=1000 
tc down-and-right-15 gen type=3 mode=4 seed=15 probability=1 maxRC=1000 
tc down-and-right-16 gen type=3 mode=4 seed=16 probability=10 maxRC=1000 
tc down-and-right-17 gen type=3 mode=4 seed=17 probability=10 maxRC=1000 
tc down-and-right-18 gen type=3 mode=4 seed=18 probability=30 maxRC=1000 
tc down-and-right-19 gen type=3 mode=4 seed=19 probability=30 maxRC=1000 
tc down-and-right-20 gen type=3 mode=4 seed=20 probability=30 maxRC=1000 
tc down-and-right-21 gen type=3 mode=4 seed=21 probability=50 maxRC=1000 
tc down-and-right-22 gen type=3 mode=4 seed=22 probability=50 maxRC=1000 
tc down-and-right-23 gen type=3 mode=4 seed=23 probability=50 maxRC=1000 
tc down-and-right-24 gen type=3 mode=4 seed=24 probability=75 maxRC=1000 
tc down-and-right-25 gen type=3 mode=4 seed=25 probability=75 maxRC=1000 
tc down-and-right-26 gen type=3 mode=4 seed=26 probability=75 maxRC=1000 
tc down-and-right-27 gen type=3 mode=4 seed=27 probability=100 maxRC=1000 
tc down-and-right-28 gen type=3 mode=4 seed=28 probability=100 maxRC=1000 
tc down-and-right-29 gen type=3 mode=4 seed=29 probability=100 maxRC=1000 
tc down-and-right-30 gen type=3 mode=4 seed=30 probability=100 maxRC=1000 


group group5 36
limits maxRC=$MAX_RC
include_group sample
include_group group1
include_group group2
include_group group3
include_group group4
tc_manual ../manual_tests/spiral2.in
tc_manual ../manual_tests/maze1.in
tc_manual ../manual_tests/small.in
tc_manual ../manual_tests/diagonal_maxcase.in
tc no-restrictions-1 gen type=1 mode=2 seed=1 probability=100 maxRC=$MAX_RC
tc no-restrictions-2 gen type=1 mode=2 seed=2 probability=1 maxRC=$MAX_RC
tc no-restrictions-3 gen type=1 mode=2 seed=3 probability=10 maxRC=$MAX_RC
tc no-restrictions-4 gen type=1 mode=2 seed=4 probability=10 maxRC=$MAX_RC
tc no-restrictions-5 gen type=1 mode=2 seed=5 probability=30 maxRC=$MAX_RC
tc no-restrictions-6 gen type=1 mode=2 seed=6 probability=30 maxRC=$MAX_RC
tc no-restrictions-7 gen type=1 mode=2 seed=7 probability=50 maxRC=$MAX_RC
tc no-restrictions-8 gen type=1 mode=2 seed=8 probability=30 maxRC=$MAX_RC
tc no-restrictions-9 gen type=1 mode=2 seed=9 probability=50 maxRC=$MAX_RC
tc no-restrictions-10 gen type=1 mode=2 seed=10 probability=75 maxRC=$MAX_RC
tc no-restrictions-11 gen type=1 mode=2 seed=11 probability=75 maxRC=$MAX_RC
# tc no-restrictions-12 gen type=2 mode=2 seed=100 probability=100 maxRC=$MAX_RC
tc no-restrictions-13 gen type=2 mode=2 seed=13 probability=100 maxRC=$MAX_RC #counter heuristic
tc no-restrictions-14 gen type=4 mode=2 seed=14 probability=10 maxRC=$MAX_RC
tc no-restrictions-15 gen type=4 mode=4 seed=15 probability=10 maxRC=$MAX_RC
tc no-restrictions-16 gen type=4 mode=4 seed=16 probability=10 maxRC=$MAX_RC
tc no-restrictions-17 gen type=4 mode=4 seed=17 probability=30 maxRC=$MAX_RC
tc no-restrictions-18 gen type=4 mode=4 seed=18 probability=30 maxRC=$MAX_RC
tc no-restrictions-19 gen type=4 mode=4 seed=19 probability=30 maxRC=$MAX_RC
tc no-restrictions-20 gen type=4 mode=4 seed=20 probability=50 maxRC=$MAX_RC
tc no-restrictions-21 gen type=4 mode=4 seed=21 probability=75 maxRC=$MAX_RC
tc no-restrictions-22 gen type=4 mode=4 seed=22 probability=75 maxRC=$MAX_RC
tc no-restrictions-23 gen type=4 mode=4 seed=23 probability=75 maxRC=$MAX_RC
tc no-restrictions-24 gen type=4 mode=4 seed=24 probability=75 maxRC=$MAX_RC
tc no-restrictions-25 gen type=4 mode=4 seed=25 probability=100 maxRC=$MAX_RC
tc no-restrictions-26 gen type=4 mode=4 seed=26 probability=100 maxRC=$MAX_RC
tc no-restrictions-27 gen type=4 mode=4 seed=27 probability=100 maxRC=$MAX_RC
tc no-restrictions-28 gen type=4 mode=4 seed=28 probability=1 maxRC=$MAX_RC
tc no-restrictions-29 gen type=2 mode=4 seed=101 probability=100 maxRC=$MAX_RC #counter heuristic
