#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../../testdata_tools/gen.sh

use_solution js.py

samplegroup
sample 1
sample 2

group g1 100
include_group sample
tc_manual g1
tc_manual g2
tc_manual g3
tc_manual g4
tc_manual g5
