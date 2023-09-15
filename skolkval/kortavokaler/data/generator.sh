#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution nils.py
compile gen.py

samplegroup
sample 1
sample 2

group g1 20
limits eq=1
tc_manual g1
tc same-1 gen n=49 mode=same
tc same-2 gen n=50 mode=same

group g2 40
limits maxlen=10
tc_manual g2
tc_manual g3
tc random-small-1 gen n=5
tc random-small-2 gen n=10
tc random-small-3 gen n=10
tc sorted-small gen n=10 mode=sorted
tc ab-small gen n=10 mode=ab
tc ab2-small gen n=10 mode=ab2
tc ab3-small gen n=10 mode=ab3

group g3 40
limits maxlen=50
include_group g1
include_group g2
tc_manual g4
tc_manual g5
tc random-large-1 gen n=20
tc random-large-2 gen n=50
tc random-large-3 gen n=50
tc sorted-large gen n=50 mode=sorted
tc ab-large gen n=50 mode=ab
tc ab2-large gen n=50 mode=ab2
tc ab3-large gen n=50 mode=ab3
