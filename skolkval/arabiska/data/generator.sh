#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../../testdata_tools/gen.sh

use_solution abdullah.py

compile gen_random.py

samplegroup
sample 1
sample 2
sample 3

group g1 40
limits subtask=1
tc 1
tc_manual g1
tc_manual g2
tc rnd01 gen_random subtask=1
tc rnd02 gen_random subtask=1
tc rnd03 gen_random subtask=1
tc rnd04 gen_random subtask=1

group g2 60
tc 2
tc 3
tc_manual g3
tc_manual g4
tc_manual g5
tc rnd05 gen_random
tc rnd06 gen_random
tc rnd07 gen_random
tc rnd08 gen_random
