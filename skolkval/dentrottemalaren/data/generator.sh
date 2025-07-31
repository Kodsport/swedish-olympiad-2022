#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../../testdata_tools/gen.sh

use_solution joakim.cc
compile gen.py

samplegroup
limits maxn=9
sample 1
sample 2
sample 3

group g1 40
limits maxn=4
tc 1
tc_manual g1
tc_manual g2
tc random-small-1 gen n=1
tc random-small-2 gen n=2
tc random-small-3 gen n=4 safe=1
tc random-small-4 gen n=4 paints=1
tc random-small-5 gen n=4 paints=4 safe=2
tc random-small-6 gen n=4 safe=3
tc random-small-7 gen n=4
tc uniform-small gen n=4 mode=nocross paints=200
tc stripe-small-1 gen n=4 mode=nocross paints=2
tc stripe-small-2 gen n=4 mode=nocross paints=3

group g2 60
limits maxn=9
include_group sample
include_group g1
tc_manual g3
tc_manual g4
tc_manual g5
tc random-large-1 gen n=5
tc random-large-2 gen n=9 safe=1
tc random-large-3 gen n=9 paints=1
tc random-large-4 gen n=9 paints=9
tc random-large-5 gen n=9 safe=8
tc random-large-6 gen n=9
tc random-large-7 gen n=9
tc uniform-large gen n=9 mode=nocross paints=200
tc stripe-large-1 gen n=9 mode=nocross paints=4
tc stripe-large-2 gen n=9 mode=nocross paints=5
