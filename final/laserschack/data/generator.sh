#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fredrik.cpp

compile gen_dfs.py
compile gen_sparse.py

samplegroup
limits mode=none maxRC=1000000 r=-1
sample 1
sample 2
sample 3

group group1 10
limits mode=none maxRC=250000 r=1
tc r1-sparse-1 gen_sparse r=1 c=100 numR=1 mirrors_per_row=1000000
tc r1-sparse-2 gen_sparse r=1 c=1000 numR=1 mirrors_per_row=1000000
tc r1-sparse-3 gen_sparse r=1 c=250000 numR=1 mirrors_per_row=0
tc r1-sparse-4 gen_sparse r=1 c=250000 numR=1 mirrors_per_row=10
tc r1-sparse-5 gen_sparse r=1 c=250000 numR=1 mirrors_per_row=100
tc r1-sparse-6 gen_sparse r=1 c=250000 numR=1 mirrors_per_row=1000000
tc r1-sparse-7 gen_sparse r=1 c=250000 numR=1 mirrors_per_row=1000000
tc r1-sparse-8 gen_sparse r=1 c=250000 numR=1 mirrors_per_row=1000000



group group2 20
limits mode=singleR maxRC=250000 r=-1
tc singleR-small-1 gen_sparse r=4 c=4 numR=1 mirrors_per_row=2
tc singleR-small-2 gen_sparse r=4 c=4 numR=1 mirrors_per_row=2
tc singleR-small-3 gen_sparse r=4 c=4 numR=1 mirrors_per_row=2
tc singleR-sparse-1 gen_sparse r=500 c=500 numR=1 mirrors_per_row=2
tc singleR-sparse-2 gen_sparse r=500 c=500 numR=1 mirrors_per_row=3
tc singleR-sparse-3 gen_sparse r=500 c=500 numR=1 mirrors_per_row=3
tc singleR-sparse-4 gen_sparse r=500 c=500 numR=1 mirrors_per_row=4
tc singleR-sparse-5 gen_sparse r=500 c=500 numR=1 mirrors_per_row=10
tc singleR-sparse-6 gen_sparse r=500 c=500 numR=1 mirrors_per_row=100
tc singleR-sparse-7 gen_sparse r=500 c=500 numR=1 mirrors_per_row=1000000
tc singleR-sparse-8 gen_sparse r=10 c=25000 numR=1 mirrors_per_row=2
tc singleR-sparse-9 gen_sparse r=50000 c=5 numR=1 mirrors_per_row=4
tc singleR-sparse-10 gen_sparse r=2 c=125000 numR=1 mirrors_per_row=100
tc singleR-sparse-11 gen_sparse r=250000 c=1 numR=1 mirrors_per_row=5 seed=42
tc singleR-sparse-12 gen_sparse r=1 c=250000 numR=1 mirrors_per_row=1000000 seed=42

group group3 20
limits mode=noair maxRC=250000 r=-1

tc noair-dfs-1 gen_dfs r=500 c=500 ans=0 radius=1 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-2 gen_dfs r=500 c=500 ans=1 radius=1 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-3 gen_dfs r=500 c=500 ans=1 radius=3 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-4 gen_dfs r=500 c=500 ans=4 radius=3 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-5 gen_dfs r=453 c=505 ans=10 radius=10 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-6 gen_dfs r=507 c=462 ans=20 radius=10 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-7 gen_dfs r=500 c=500 ans=35 radius=10 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-8 gen_dfs r=500 c=500 ans=100 radius=100 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-9 gen_dfs r=500 c=500 ans=200 radius=100 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-10 gen_dfs r=500 c=500 ans=350 radius=100 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-11 gen_dfs r=10 c=25000 ans=4 radius=4 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-12 gen_dfs r=25000 c=10 ans=6 radius=5 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-13 gen_dfs r=5 c=50000 ans=2 radius=2 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-14 gen_dfs r=50000 c=5 ans=4 radius=3 mirror_ratio=1 smoke_ratio=1


group group4 20
limits mode=none maxRC=2500 r=-1

tc small-dfs-1 gen_dfs r=50 c=50 ans=0 radius=1 seed=42
tc small-dfs-2 gen_dfs r=50 c=50 ans=1 radius=1
tc small-dfs-3 gen_dfs r=50 c=50 ans=1 radius=3
tc small-dfs-4 gen_dfs r=50 c=50 ans=4 radius=3
tc small-dfs-5 gen_dfs r=40 c=55 ans=10 radius=20
tc small-dfs-6 gen_dfs r=57 c=42 ans=20 radius=20
tc small-dfs-7 gen_dfs r=51 c=49 ans=35 radius=20
tc small-dfs-8 gen_dfs r=54 c=43 ans=50 radius=50
tc small-dfs-10 gen_dfs r=10 c=250 ans=4 radius=4
tc small-dfs-11 gen_dfs r=250 c=10 ans=6 radius=5
tc small-dfs-12 gen_dfs r=5 c=500 ans=2 radius=2
tc small-dfs-13 gen_dfs r=500 c=5 ans=4 radius=3
tc small-sparse-1 gen_sparse r=1 c=2500 numR=1 mirrors_per_row=1000000
tc small-sparse-2 gen_sparse r=1 c=2500 numR=1 mirrors_per_row=1000000
tc small-sparse-3 gen_sparse r=50 c=50 numR=4 mirrors_per_row=3


group group5 30
limits mode=none maxRC=250000 r=-1
include_group sample
include_group group1
include_group group2
include_group group3
include_group group4

tc full-dfs-1 gen_dfs r=500 c=500 ans=0 radius=1
tc full-dfs-2 gen_dfs r=500 c=500 ans=1 radius=1
tc full-dfs-3 gen_dfs r=500 c=500 ans=1 radius=3
tc full-dfs-4 gen_dfs r=500 c=500 ans=4 radius=3
tc full-dfs-5 gen_dfs r=453 c=505 ans=10 radius=10
tc full-dfs-6 gen_dfs r=507 c=462 ans=20 radius=10
tc full-dfs-7 gen_dfs r=500 c=500 ans=35 radius=10
tc full-dfs-8 gen_dfs r=500 c=500 ans=100 radius=100
tc full-dfs-9 gen_dfs r=500 c=500 ans=200 radius=100
tc full-dfs-10 gen_dfs r=500 c=500 ans=350 radius=100
tc full-dfs-11 gen_dfs r=10 c=25000 ans=4 radius=4
tc full-dfs-12 gen_dfs r=25000 c=10 ans=6 radius=5
tc full-dfs-13 gen_dfs r=5 c=50000 ans=2 radius=2
tc full-dfs-14 gen_dfs r=50000 c=5 ans=4 radius=3
tc full-sparse-1 gen_sparse r=500 c=500 numR=4 mirrors_per_row=3
tc full-sparse-2 gen_sparse r=500 c=500 numR=100 mirrors_per_row=3
tc full-sparse-3 gen_sparse r=500 c=500 numR=4 mirrors_per_row=10
tc full-sparse-4 gen_sparse r=500 c=500 numR=100 mirrors_per_row=10