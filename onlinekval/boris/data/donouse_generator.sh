#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution joakim.cc

compile gen.cc

MAX_N=2000
MAX_T=500000000
MAX_S=500000
MAX_XY=500000000


#################################################################################
samplegroup
limits max_n=$MAX_N max_t=$MAX_T max_s=$MAX_S max_xy=$MAX_XY
sample 1
sample 2
sample 3

#################################################################################
group group1 8 # n <= 2
limits max_n=2 max_t=$MAX_T max_s=$MAX_S max_xy=$MAX_XY

tc 1
tc 2
tc g1-rand-1  gen -type=random -n=1 -max_t=1      -max_s=1      -max_xy=1
tc g1-rand-2  gen -type=random -n=1 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY
tc g1-rand-3  gen -type=random -n=2 -max_t=1      -max_s=1      -max_xy=1
tc g1-rand-4  gen -type=random -n=2 -max_t=2      -max_s=1      -max_xy=2
tc g1-rand-5  gen -type=random -n=2 -max_t=2      -max_s=$MAX_S -max_xy=2
tc g1-rand-6  gen -type=random -n=2 -max_t=10     -max_s=1      -max_xy=2
tc g1-rand-7  gen -type=random -n=2 -max_t=25     -max_s=1      -max_xy=25
tc g1-rand-8  gen -type=random -n=2 -max_t=50     -max_s=1      -max_xy=25
tc g1-rand-9  gen -type=random -n=2 -max_t=25     -max_s=5      -max_xy=2
tc g1-rand-10 gen -type=random -n=2 -max_t=25     -max_s=5      -max_xy=25
tc g1-rand-11 gen -type=random -n=2 -max_t=50     -max_s=5      -max_xy=25
tc g1-rand-12 gen -type=random -n=2 -max_t=50     -max_s=$MAX_S -max_xy=$MAX_XY
tc g1-rand-13 gen -type=random -n=2 -max_t=$MAX_T -max_s=$MAX_S -max_xy=50
tc g1-rand-14 gen -type=random -n=2 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY


#################################################################################
group group2 31 # n <= 16
limits max_n=16 max_t=$MAX_T max_s=$MAX_S max_xy=$MAX_XY

include_group sample
tc g2-rand-1  gen -type=random -n=3  -max_t=50     -max_s=1      -max_xy=50
tc g2-rand-2  gen -type=random -n=3  -max_t=50     -max_s=5      -max_xy=$MAX_XY
tc g2-rand-3  gen -type=random -n=3  -max_t=$MAX_T -max_s=5      -max_xy=50
tc g2-rand-4  gen -type=random -n=3  -max_t=$MAX_T -max_s=5      -max_xy=$MAX_XY
tc g2-rand-5  gen -type=random -n=6  -max_t=50     -max_s=1      -max_xy=50
tc g2-rand-6  gen -type=random -n=6  -max_t=50     -max_s=5      -max_xy=$MAX_XY
tc g2-rand-7  gen -type=random -n=6  -max_t=$MAX_T -max_s=5      -max_xy=50
tc g2-rand-8  gen -type=random -n=6  -max_t=$MAX_T -max_s=5      -max_xy=$MAX_XY
tc g2-rand-9  gen -type=random -n=16 -max_t=50     -max_s=1      -max_xy=50
tc g2-rand-10 gen -type=random -n=16 -max_t=50     -max_s=5      -max_xy=$MAX_XY
tc g2-rand-11 gen -type=random -n=16 -max_t=$MAX_T -max_s=5      -max_xy=50
tc g2-rand-12 gen -type=random -n=16 -max_t=$MAX_T -max_s=5      -max_xy=$MAX_XY
tc g2-rand-13 gen -type=random -n=16 -max_t=20     -max_s=1      -max_xy=50
tc g2-rand-14 gen -type=random -n=16 -max_t=50     -max_s=1      -max_xy=20
tc g2-rand-15 gen -type=random -n=16 -max_t=20     -max_s=5      -max_xy=50
tc g2-rand-16 gen -type=random -n=16 -max_t=50     -max_s=5      -max_xy=20
tc g2-rand-17 gen -type=random -n=16 -max_t=20     -max_s=$MAX_S -max_xy=50
tc g2-rand-18 gen -type=random -n=16 -max_t=50     -max_s=$MAX_S -max_xy=20
tc g2-rand-19 gen -type=random -n=16 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY

tc g2-path-1 gen -type=path -n=16 -max_t=50     -max_s=1      -max_xy=50      -path_len=10
tc g2-path-2 gen -type=path -n=16 -max_t=13     -max_s=1      -max_xy=50      -path_len=12
tc g2-path-3 gen -type=path -n=16 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY -path_len=16
tc g2-path-4 gen -type=path -n=16 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY -path_len=15
tc g2-path-5 gen -type=path -n=16 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY -path_len=12
tc g2-path-6 gen -type=path -n=16 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY -path_len=8
tc g2-path-7 gen -type=path -n=16 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY -path_len=5


#################################################################################
group group3 33 # t,x,y <= 50, s = 1
limits max_n=$MAX_N max_t=50 max_s=1 max_xy=50

tc 1
tc 2
tc g1-rand-1
tc g1-rand-3
tc g1-rand-4
tc g1-rand-6
tc g1-rand-7
tc g1-rand-8
tc g2-rand-1
tc g2-rand-5
tc g2-rand-9
tc g2-rand-13
tc g2-rand-14
tc g2-path-1
tc g2-path-2

tc g3-rand-1 gen -type=random -n=49   -max_t=50 -max_s=1 -max_xy=50
tc g3-rand-2 gen -type=random -n=99   -max_t=50 -max_s=1 -max_xy=50
tc g3-rand-3 gen -type=random -n=399  -max_t=50 -max_s=1 -max_xy=50
tc g3-rand-4 gen -type=random -n=1000 -max_t=50 -max_s=1 -max_xy=50
tc g3-rand-5 gen -type=random -n=1500 -max_t=50 -max_s=1 -max_xy=50
tc g3-rand-6 gen -type=random -n=1999 -max_t=50 -max_s=1 -max_xy=50
tc g3-rand-7 gen -type=random -n=2000 -max_t=50 -max_s=1 -max_xy=50

tc g3-path-1 gen -type=path -n=100  -max_t=50 -max_s=1 -max_xy=50 -path_len=45
tc g3-path-2 gen -type=path -n=100  -max_t=50 -max_s=1 -max_xy=50 -path_len=20
tc g3-path-3 gen -type=path -n=2000 -max_t=50 -max_s=1 -max_xy=50 -path_len=45
tc g3-path-4 gen -type=path -n=2000 -max_t=50 -max_s=1 -max_xy=50 -path_len=20


#################################################################################
group group4 28 # no additional constraints
limits max_n=$MAX_N max_t=$MAX_T max_s=$MAX_S max_xy=$MAX_XY
include_group sample
include_group group1
include_group group2
include_group group3

tc g4-rand-1 gen -type=random -n=49   -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY
tc g4-rand-2 gen -type=random -n=99   -max_t=$MAX_T -max_s=5      -max_xy=$MAX_XY
tc g4-rand-3 gen -type=random -n=399  -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY
tc g4-rand-4 gen -type=random -n=1000 -max_t=$MAX_T -max_s=$MAX_S -max_xy=500000
tc g4-rand-5 gen -type=random -n=1500 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY
tc g4-rand-6 gen -type=random -n=1999 -max_t=$MAX_T -max_s=100    -max_xy=$MAX_XY
tc g4-rand-7 gen -type=random -n=2000 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY

tc g4-path-1 gen -type=path -n=2000 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY -path_len=100
tc g4-path-2 gen -type=path -n=2000 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY -path_len=1000
tc g4-path-3 gen -type=path -n=2000 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY -path_len=1678
tc g4-path-4 gen -type=path -n=2000 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY -path_len=1967
tc g4-path-5 gen -type=path -n=2000 -max_t=$MAX_T -max_s=$MAX_S -max_xy=$MAX_XY -path_len=2000
