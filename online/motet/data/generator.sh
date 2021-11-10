#!/bin/bash
. ../../../testdata_tools/gen.sh




use_solution abdullah.cpp            

compile gen_all_length.cpp opt          
compile gen_disjoint.cpp opt          
compile gen_no_restrictions.cpp opt          
compile gen_short_intervals.cpp opt
compile gen_slow_update.cpp opt
compile gen_all_length_disjoint.cpp opt          

# Generate answers to sample cases
samplegroup
limits sum_m=200000 max_coordinate=1000000000
sample 1
sample 2
sample 3


group group1 10                       
limits sum_m=100 max_coordinate=100                          
tc 1
tc 2
tc 3                                
tc small-all-length1 gen_all_length seed=1 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=5
tc small-all-length2 gen_all_length seed=2 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=5
tc small-all-length3 gen_all_length seed=3 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=3
tc small-all-length4 gen_all_length seed=4 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=2
tc small-all-length5 gen_all_length seed=5 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=1
tc small-no-restrictions1 gen_no_restrictions seed=6 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=1
tc small-no-restrictions2 gen_no_restrictions seed=7 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=2
tc small-no-restrictions3 gen_no_restrictions seed=8 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=2
tc small-no-restrictions4 gen_no_restrictions seed=9 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=2
tc small-no-restrictions5 gen_no_restrictions seed=10 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=3
tc small-no-restrictions6 gen_no_restrictions seed=11 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=3
tc small-no-restrictions7 gen_no_restrictions seed=12 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=5
tc small-no-restrictions8 gen_no_restrictions seed=13 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=5
tc small-no-restrictions9 gen_no_restrictions seed=14 sum_m=100 max_m=100 min_m=20 max_coordinate=100 type_of_n=5
tc tiny-no-restrictions1 gen_no_restrictions seed=15 sum_m=20 max_m=20 min_m=1 max_coordinate=50 type_of_n=5
tc tiny-no-restrictions2 gen_no_restrictions seed=16 sum_m=20 max_m=20 min_m=1 max_coordinate=50 type_of_n=5
tc tiny-no-restrictions3 gen_no_restrictions seed=17 sum_m=20 max_m=20 min_m=1 max_coordinate=50 type_of_n=5
tc small-gen_short-intervals1 gen_short_intervals seed=18 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=5
tc small-gen_short-intervals2 gen_short_intervals seed=19 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=5
tc small-gen_short-intervals3 gen_short_intervals seed=20 sum_m=100 max_m=100 min_m=1 max_coordinate=100 type_of_n=5



group group2 15
limits sum_m=1000 max_coordinate=4000 disjoint=1
tc medium-all-length-disjoint1 gen_all_length_disjoint seed=1 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-all-length-disjoint2 gen_all_length_disjoint seed=2 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-all-length-disjoint3 gen_all_length_disjoint seed=3 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-all-length-disjoint4 gen_all_length_disjoint seed=4 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-all-length-disjoint5 gen_all_length_disjoint seed=5 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=1
tc medium-disjoint1 gen_disjoint seed=6 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-disjoint2 gen_disjoint seed=7 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-disjoint3 gen_disjoint seed=8 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-disjoint4 gen_disjoint seed=9 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-disjoint5 gen_disjoint seed=10 sum_m=1000 max_m=100 min_m=50 max_coordinate=4000 type_of_n=5
tc medium-disjoint6 gen_disjoint seed=11 sum_m=1000 max_m=100 min_m=50 max_coordinate=4000 type_of_n=5
tc medium-disjoint7 gen_disjoint seed=12 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=1
tc medium-disjoint8 gen_disjoint seed=13 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=3
tc medium-disjoint9 gen_disjoint seed=14 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=2
tc medium-disjoint10 gen_disjoint seed=15 sum_m=1000 max_m=35 min_m=30 max_coordinate=4000 type_of_n=2
tc medium-disjoint11 gen_disjoint seed=16 sum_m=1000 max_m=35 min_m=30 max_coordinate=4000 type_of_n=2
tc tiny-disjoint1 gen_disjoint seed=17 sum_m=20 max_m=20 min_m=1 max_coordinate=4000 type_of_n=5
tc tiny-disjoint2 gen_disjoint seed=18 sum_m=20 max_m=20 min_m=1 max_coordinate=4000 type_of_n=5
tc tiny-disjoint3 gen_disjoint seed=19 sum_m=20 max_m=20 min_m=1 max_coordinate=4000 type_of_n=5
tc tiny-disjoint4 gen_disjoint seed=20 sum_m=20 max_m=6 min_m=4 max_coordinate=50 type_of_n=5
tc tiny-disjoint5 gen_disjoint seed=21 sum_m=20 max_m=6 min_m=4 max_coordinate=50 type_of_n=5
tc tiny-disjoint6 gen_disjoint seed=22 sum_m=20 max_m=6 min_m=4 max_coordinate=50 type_of_n=5
tc tiny-disjoint7 gen_disjoint seed=23 sum_m=20 max_m=20 min_m=1 max_coordinate=50 type_of_n=5
tc tiny-disjoint8 gen_disjoint seed=24 sum_m=20 max_m=20 min_m=1 max_coordinate=50 type_of_n=5
tc tiny-disjoint9 gen_disjoint seed=25 sum_m=20 max_m=20 min_m=1 max_coordinate=50 type_of_n=5







group group3 30
limits sum_m=200000 disjoint=1 max_coordinate=1000000000
include_group group2

tc large-all-length-disjoint1 gen_all_length_disjoint seed=1 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-all-length-disjoint2 gen_all_length_disjoint seed=2 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-all-length-disjoint3 gen_all_length_disjoint seed=3 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-all-length-disjoint4 gen_all_length_disjoint seed=4 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-all-length-disjoint5 gen_all_length_disjoint seed=5 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=1
tc large-disjoint1 gen_disjoint seed=10 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-disjoint2 gen_disjoint seed=11 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-disjoint3 gen_disjoint seed=12 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-disjoint4 gen_disjoint seed=13 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000 type_of_n=5
tc large-disjoint5 gen_disjoint seed=14 sum_m=200000 max_m=10000 min_m=5000 max_coordinate=1000000 type_of_n=5
tc large-disjoint6 gen_disjoint seed=15 sum_m=200000 max_m=10000 min_m=5000 max_coordinate=1000000000 type_of_n=5
tc large-disjoint7 gen_disjoint seed=16 sum_m=200000 max_m=10000 min_m=5000 max_coordinate=1000000000 type_of_n=5
tc large-disjoint8 gen_disjoint seed=17 sum_m=200000 max_m=10 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-disjoint9 gen_disjoint seed=18 sum_m=200000 max_m=10 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-disjoint10 gen_disjoint seed=19 sum_m=200000 max_m=500 min_m=400 max_coordinate=1000000000 type_of_n=2
tc large-disjoint11 gen_disjoint seed=20 sum_m=200000 max_m=500 min_m=400 max_coordinate=1000000000 type_of_n=2
tc large-disjoint12 gen_disjoint seed=13 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=1


group group4 15
limits sum_m=1000 max_coordinate=4000
include_group group1
include_group group2
tc medium-all-length1 gen_all_length seed=1 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-all-length2 gen_all_length seed=2 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-all-length3 gen_all_length seed=3 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=3
tc medium-all-length4 gen_all_length seed=4 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=2
tc medium-all-length5 gen_all_length seed=5 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=1
tc medium-no-restrictions1 gen_no_restrictions seed=6 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=1
tc medium-no-restrictions2 gen_no_restrictions seed=7 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=2
tc medium-no-restrictions3 gen_no_restrictions seed=8 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=2
tc medium-no-restrictions4 gen_no_restrictions seed=9 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=2
tc medium-no-restrictions5 gen_no_restrictions seed=10 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=3
tc medium-no-restrictions6 gen_no_restrictions seed=11 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=3
tc medium-no-restrictions7 gen_no_restrictions seed=12 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-no-restrictions8 gen_no_restrictions seed=13 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-no-restrictions9 gen_no_restrictions seed=14 sum_m=1000 max_m=100 min_m=50 max_coordinate=4000 type_of_n=5
tc medium-no-restrictions10 gen_no_restrictions seed=15 sum_m=1000 max_m=100 min_m=50 max_coordinate=110 type_of_n=5
tc medium-no-restrictions11 gen_no_restrictions seed=16 sum_m=1000 max_m=35 min_m=30 max_coordinate=70 type_of_n=2
tc medium-no-restrictions12 gen_no_restrictions seed=17 sum_m=1000 max_m=35 min_m=30 max_coordinate=70 type_of_n=2
tc medium-gen_short-intervals1 gen_short_intervals seed=18 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-gen_short-intervals2 gen_short_intervals seed=19 sum_m=1000 max_m=1000 min_m=1 max_coordinate=4000 type_of_n=5
tc medium-gen_short-intervals3 gen_short_intervals seed=20 sum_m=1000 max_m=100 min_m=50 max_coordinate=4000 type_of_n=5
tc medium-gen_short-intervals4 gen_short_intervals seed=21 sum_m=1000 max_m=100 min_m=50 max_coordinate=4000 type_of_n=5
tc medium-gen_short-intervals5 gen_short_intervals seed=22 sum_m=1000 max_m=100 min_m=50 max_coordinate=4000 type_of_n=5

group group5 30
limits sum_m=200000 max_coordinate=1000000000

include_group group1
include_group group2
include_group group3
include_group group4

tc large-all-length1 gen_all_length seed=1 sum_m=200000 max_m=1000 min_m=1 max_coordinate=1000000000 type_of_n=2
tc large-all-length2 gen_all_length seed=2 sum_m=200000 max_m=1000 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-no-restrictions1 gen_no_restrictions seed=3 sum_m=200000 max_m=450 min_m=400 max_coordinate=1000000000 type_of_n=2
tc large-no-restrictions2 gen_no_restrictions seed=4 sum_m=200000 max_m=450 min_m=400 max_coordinate=1000000000 type_of_n=2
tc large-no-restrictions3 gen_no_restrictions seed=5 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=2
tc large-no-restrictions4 gen_no_restrictions seed=6 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-no-restrictions5 gen_no_restrictions seed=7 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-no-restrictions6 gen_no_restrictions seed=8 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=5
tc large-slow-update gen_slow_update seed=4 sum_m=200000 max_m=200000 min_m=1 max_coordinate=1000000000 type_of_n=5
