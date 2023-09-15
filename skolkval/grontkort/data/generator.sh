#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../../testdata_tools/gen.sh

use_solution joakim.cc

compile gen_random.py

samplegroup
sample_manual 1
sample_manual 2
sample_manual 3

group g1 20
limits max_m=0
tc 1
tc_manual g1

tc m0-1 gen_random m0=1
tc m0-2 gen_random m0=1
tc m0-3 gen_random m0=1
tc m0-4 gen_random m0=1
tc m0-5 gen_random m0=1
tc m0-6 gen_random m0=1
tc m0-7 gen_random m0=1
tc m0-8 gen_random m0=1

group g2 20
limits max_n=2
tc 1
tc 2
tc_manual g2

tc n2-1 gen_random n2=1
tc n2-2 gen_random n2=1
tc n2-3 gen_random n2=1
tc n2-4 gen_random n2=1
tc n2-5 gen_random n2=1
tc n2-6 gen_random n2=1
tc n2-7 gen_random n2=1
tc n2-8 gen_random n2=1

group g3 40
tc 1
tc 2
tc 3
limits max_n=100 max_m=100
tc_manual g3
tc_manual g4

tc small-1 gen_random max100=1
tc small-2 gen_random max100=1
tc small-3 gen_random max100=1
tc small-4 gen_random max100=1
tc small-5 gen_random max100=1
tc small-6 gen_random max100=1
tc small-7 gen_random max100=1
tc small-8 gen_random max100=1

group g4 20
include_group g1
include_group g2
include_group g3
tc_manual g5
tc big-1 gen_random
tc big-2 gen_random
tc big-3 gen_random
tc big-4 gen_random
tc big-5 gen_random
tc big-6 gen_random
tc big-7 gen_random
tc big-8 gen_random
