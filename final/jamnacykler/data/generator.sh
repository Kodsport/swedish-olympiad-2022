#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution joakim.cc

#compile gen.cc

N=100000
M=200000

samplegroup
limits maxn=$N maxm=$M
sample 1
sample 2
sample 3


# only placeholder below
# TODO: actually generate testdata

group group1 100
limits maxn=$N maxm=$M
tc 1
tc 2
tc 3
