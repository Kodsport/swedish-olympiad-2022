#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh


use_solution abdullah.cpp

compile gen.cpp

mx=1000000000


#################################################################################
samplegroup
limits max_value=$mx doable=0
sample 1
sample 2
sample 3

#################################################################################
group group1 30 # doable
limits max_value=$mx doable=1
tc 1
tc 2
tc doable-1 gen seed=1 max_value=$mx type=3
tc doable-2 gen seed=2 max_value=$mx type=3
tc doable-3 gen seed=3 max_value=$mx type=3
tc doable-4 gen seed=4 max_value=$mx type=3
tc doable-5 gen seed=5 max_value=$mx type=3
tc doable-6 gen seed=6 max_value=$mx type=3
tc doable-7 gen seed=5 max_value=$mx type=1

group group2 20 # max_value=5
limits max_value=5
tc 3
tc small-1 gen seed=1 max_value=5 type=1
tc small-2 gen seed=2 max_value=5 type=4
tc small-3 gen seed=3 max_value=5 type=4
tc small-4 gen seed=4 max_value=5 type=4
tc small-5 gen seed=5 max_value=5 type=4
tc small-6 gen seed=6 max_value=5 type=2
tc small-7 gen seed=7 max_value=5 type=2
tc small-8 gen seed=8 max_value=5 type=2
tc small-9 gen seed=9 max_value=5 type=3
tc small-10 gen seed=10 max_value=5 type=3
tc small-11 gen seed=11 max_value=5 type=3

group group3 50
limits max_value=$mx
include_group group1
include_group group2
include_group sample
tc large-1 gen seed=1 max_value=$mx type=3
tc large-2 gen seed=2 max_value=$mx type=3
tc large-3 gen seed=3 max_value=$mx type=4
tc large-4 gen seed=4 max_value=$mx type=4
tc large-5 gen seed=5 max_value=$mx type=4
tc large-6 gen seed=6 max_value=$mx type=2
tc large-7 gen seed=7 max_value=$mx type=2
tc large-8 gen seed=8 max_value=$mx type=2
tc large-9 gen seed=9 max_value=$mx type=3



