#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution sl.cpp

compile gen_random.py

samplegroup
limits abm=2000
sample 1
sample 2
sample 3

group group1 23
limits abm=2000 separated=1
tc sepsmall-1 gen_random n=8 x=3e2 h=1e3 mode=separated
tc sepsmall-2 gen_random n=8 x=1e3 h=1e3 mode=separated
tc sepsmall-3 gen_random n=8 x=1e3 h=1e3 mode=separated
tc sepsmall-4 gen_random n=8 x=2e3 h=1e3 mode=separated
tc sep-1 gen_random n=500 x=3e3 h=1e3 mode=separated
tc sep-2 gen_random n=500 x=3e3 h=5e3 mode=separated
tc sep-3 gen_random n=2000 x=10000 h=1e3 mode=separated
tc sep-4 gen_random n=2000 x=10000 h=2e3 mode=separated

group group2 10
limits abm=8
tc 1
tc 2
tc 3
tc sepsmall-1
tc sepsmall-2
tc sepsmall-3
tc sepsmall-4
tc small-1 gen_random n=8 x=2e4 h=1e4
tc small-2 gen_random n=8 x=1e4 h=1e4
tc small-3 gen_random n=8 x=1e4 h=1e4
tc small-4 gen_random n=8 x=1e3 h=1e4
tc small-5 gen_random n=8 x=1e4 h=1e4 a=1
tc small-6 gen_random n=8 x=1e4 h=1e4 b=1
tc small-7 gen_random n=8 x=1e3 h=1e3 m=1

group group3 22
limits abm=100
include_group group2
tc med-1 gen_random n=100 x=1e5 h=1e4
tc med-2 gen_random n=100 x=1e5 h=2e3
tc med-3 gen_random n=100 x=1e4 h=1e4
tc med-4 gen_random n=100 x=3e3 h=1e4

group group4 45
limits abm=2000
include_group group1
include_group group3
tc large-1 gen_random n=2000 x=1e6 h=1e4
tc large-2 gen_random n=2000 x=1e6 h=1e3  # h ~ x / n means points are very separated
tc large-3 gen_random n=2000 x=1e5 h=1e4
tc large-4 gen_random n=2000 x=1e4 h=1e4  # h ~ x means points are not very separated
tc large-5 gen_random n=2000 x=1e4 h=1e4
tc large-6 gen_random n=2000 x=1e5 h=1e4 a=1
tc large-7 gen_random n=2000 x=1e5 h=1e4 b=1
tc large-8 gen_random n=2000 x=6e3 h=3e3 m=1 seed=43
