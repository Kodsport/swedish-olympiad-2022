#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution nils.cpp

compile gen.py

samplegroup
limits t=0
sample_manual 1

testcase() {
	NAME=$(printf "%02d" $1)
	group group$NAME 10
	limits t=$1
	tc "case$NAME" "${@:2}" tc=$1
}

testcase 1 gen n=10 m=10 kind=1
testcase 2 gen n=40 m=40 kind=1
testcase 3 gen n=150 m=150 kind=1
testcase 4 gen n=400 m=400 kind=1
testcase 5 gen n=1000 m=1000 kind=1
testcase 6 gen n=100 m=10 kind=1
testcase 7 gen n=1000 m=1 kind=1
testcase 8 gen n=10 m=10 kind=2
testcase 9 gen n=100 m=100 kind=2
testcase 10 gen n=1000 m=1000 kind=2


# Clamp final scores to 100
echo 'grading: custom' >> testdata.yaml
echo 'grading: default' >> secret/testdata.yaml
echo 'grading: default' >> sample/testdata.yaml