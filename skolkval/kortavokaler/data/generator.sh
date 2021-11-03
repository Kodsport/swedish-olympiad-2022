#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution nils.py

samplegroup
sample 1
sample 2

group g1 20
limits eq=1
tc_manual g1

group g2 20
limits maxlen=10
tc_manual g2

group g3 20
limits maxlen=10
tc_manual g3

group g4 20
tc_manual g4

group g5 20
tc_manual g5
