#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

compile gen.py

use_solution joakim.cc

samplegroup
sample 1
sample 2

group g1 20
limits maxn=1
tc_manual g1
tc random-row-1 gen n=1 m=1
tc random-row-2 gen n=1 m=2
tc random-row-3 gen n=1 m=4
tc random-row-4 gen n=1 m=8
tc random-row-5 gen n=1 m=8
tc chess-row gen n=1 m=8 mode=chess
tc snake-row gen n=1 m=8 mode=snake2
tc slope-row gen n=1 m=8 mode=slope

group g2 20
limits maxn=3 maxm=3 eq=1
tc_manual g2
tc random-small-1 gen n=2 m=2
tc random-small-2 gen n=3 m=3
tc chess-small gen n=3 m=3 mode=chess
tc snake-small gen n=3 m=3 mode=snake
tc slope-small gen n=3 m=3 mode=slope

group g3 20
limits maxn=4 maxm=4 eq=1
include_group g2
tc_manual g3
tc random-medium-1 gen n=4 m=4
tc random-medium-2 gen n=4 m=4
tc chess-medium gen n=4 m=4 mode=chess
tc snake-medium gen n=4 m=4 mode=snake2
tc slope-medium gen n=4 m=4 mode=slope

group g4 40
#limits maxn=$MAXN maxm=$MAXM
include_group g3
include_group g1
tc_manual g4
tc_manual g5

tc random-large-1 gen n=4 m=8
tc random-large-2 gen n=8 m=4
tc random-large-3 gen n=8 m=8
tc random-large-4 gen n=8 m=8
tc chess-large-1 gen n=7 m=8 mode=chess
tc chess-large-2 gen n=8 m=8 mode=chess
tc snake-large-1 gen n=8 m=7 mode=snake
tc snake-large-2 gen n=8 m=8 mode=snake2
tc snake-large-3 gen n=7 m=3 mode=snake2
tc slope-large-1 gen n=8 m=8 mode=slope
tc slope-large-2 gen n=7 m=8 mode=slope
