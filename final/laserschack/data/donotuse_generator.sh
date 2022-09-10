#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fredrik.cpp

compile gen_dfs.py
compile gen_worstcase.py
compile gen_sparse.py
compile gen_manual.py

samplegroup
limits mode=none maxRC=40000 r=-1
sample 1
sample 2
sample 3

group group1 10
limits mode=none maxRC=40000 r=1
tc r1-sparse-1 gen_sparse r=1 c=100 numR=1 mirrors_per_row=1000000
tc r1-sparse-2 gen_sparse r=1 c=1000 numR=1 mirrors_per_row=1000000
tc r1-sparse-3 gen_sparse r=1 c=40000 numR=1 mirrors_per_row=0
tc r1-sparse-4 gen_sparse r=1 c=40000 numR=1 mirrors_per_row=10
tc r1-sparse-5 gen_sparse r=1 c=40000 numR=1 mirrors_per_row=100
tc r1-sparse-6 gen_sparse r=1 c=40000 numR=1 mirrors_per_row=1000000
tc r1-sparse-7 gen_sparse r=1 c=40000 numR=1 mirrors_per_row=1000000
tc r1-sparse-8 gen_sparse r=1 c=40000 numR=1 mirrors_per_row=1000000
tc extreme-1 gen_manual r=1 c=40000 fill=. ky=0 ay=19999 ry=39999
tc extreme-2 gen_manual r=1 c=40000 fill=o ky=0 ay=19999 ry=39999
tc extreme-3 gen_manual r=1 c=40000 fill=R ky=20000 ay=19999



group group2 20
limits mode=singleR maxRC=40000 r=-1
tc singleR-small-1 gen_sparse r=4 c=4 numR=1 mirrors_per_row=2
tc singleR-small-2 gen_sparse r=4 c=4 numR=1 mirrors_per_row=2
tc singleR-small-3 gen_sparse r=4 c=4 numR=1 mirrors_per_row=2
tc singleR-sparse-1 gen_sparse r=200 c=200 numR=1 mirrors_per_row=2
tc singleR-sparse-2 gen_sparse r=200 c=200 numR=1 mirrors_per_row=3
tc singleR-sparse-3 gen_sparse r=200 c=200 numR=1 mirrors_per_row=3
tc singleR-sparse-4 gen_sparse r=200 c=200 numR=1 mirrors_per_row=4
tc singleR-sparse-5 gen_sparse r=200 c=200 numR=1 mirrors_per_row=10
tc singleR-sparse-6 gen_sparse r=200 c=200 numR=1 mirrors_per_row=100
tc singleR-sparse-7 gen_sparse r=200 c=200 numR=1 mirrors_per_row=1000000
tc singleR-sparse-8 gen_sparse r=10 c=4000 numR=1 mirrors_per_row=2
tc singleR-sparse-9 gen_sparse r=8000 c=5 numR=1 mirrors_per_row=4 seed=42
tc singleR-sparse-10 gen_sparse r=2 c=20000 numR=1 mirrors_per_row=100
tc singleR-sparse-11 gen_sparse r=40000 c=1 numR=1 mirrors_per_row=5 seed=42
tc singleR-worstcase-1 gen_worstcase c=40000
tc extreme-1
tc extreme-2
tc extreme-4 gen_manual c=1 r=40000 fill=. kx=0 ax=19999 rx=39999
tc extreme-5 gen_manual c=1 r=40000 fill=o kx=0 ax=19999 rx=39999
tc extreme-6 gen_manual c=2 r=20000 fill=o kx=0 ax=9999 rx=19999

group group3 20
limits mode=noair maxRC=40000 r=-1

tc noair-dfs-1 gen_dfs r=200 c=200 ans=0 radius=1 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-2 gen_dfs r=200 c=200 ans=1 radius=1 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-3 gen_dfs r=200 c=200 ans=1 radius=3 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-4 gen_dfs r=200 c=200 ans=4 radius=3 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-5 gen_dfs r=200 c=200 ans=10 radius=10 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-6 gen_dfs r=200 c=200 ans=20 radius=10 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-7 gen_dfs r=200 c=200 ans=35 radius=10 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-8 gen_dfs r=200 c=200 ans=100 radius=100 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-9 gen_dfs r=200 c=200 ans=200 radius=100 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-10 gen_dfs r=200 c=200 ans=350 radius=100 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-11 gen_dfs r=10 c=4000 ans=4 radius=4 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-12 gen_dfs r=4000 c=10 ans=6 radius=5 mirror_ratio=1 smoke_ratio=1
tc noair-dfs-13 gen_dfs r=5 c=8000 ans=2 radius=2 mirror_ratio=1 smoke_ratio=1
tc singleR-worstcase-1
tc extreme-2
tc extreme-3
tc extreme-5


group group4 20
limits mode=none maxRC=400 r=-1

tc small-dfs-1 gen_dfs r=20 c=20 ans=0 radius=1 seed=42
tc small-dfs-2 gen_dfs r=20 c=20 ans=1 radius=1
tc small-dfs-3 gen_dfs r=20 c=20 ans=1 radius=3
tc small-dfs-4 gen_dfs r=20 c=20 ans=4 radius=3
tc small-dfs-5 gen_dfs r=20 c=20 ans=10 radius=20
tc small-dfs-6 gen_dfs r=20 c=20 ans=20 radius=20
tc small-dfs-7 gen_dfs r=20 c=20 ans=35 radius=20
tc small-dfs-8 gen_dfs r=20 c=20 ans=50 radius=50
tc small-dfs-10 gen_dfs r=10 c=40 ans=4 radius=4
tc small-dfs-11 gen_dfs r=40 c=10 ans=6 radius=5
tc small-dfs-12 gen_dfs r=4 c=100 ans=2 radius=2
tc small-dfs-13 gen_dfs r=100 c=4 ans=2 radius=3
tc small-sparse-1 gen_sparse r=1 c=400 numR=1 mirrors_per_row=1000000
tc small-sparse-2 gen_sparse r=1 c=400 numR=1 mirrors_per_row=1000000
tc small-sparse-3 gen_sparse r=20 c=20 numR=4 mirrors_per_row=3


group group5 30
limits mode=none maxRC=40000 r=-1
include_group sample
include_group group1
include_group group2
include_group group3
include_group group4

tc full-dfs-1 gen_dfs r=200 c=200 ans=0 radius=1
tc full-dfs-2 gen_dfs r=200 c=200 ans=1 radius=1
tc full-dfs-3 gen_dfs r=200 c=200 ans=1 radius=3
tc full-dfs-4 gen_dfs r=200 c=200 ans=4 radius=3
tc full-dfs-5 gen_dfs r=200 c=200 ans=10 radius=10
tc full-dfs-6 gen_dfs r=200 c=200 ans=20 radius=10
tc full-dfs-7 gen_dfs r=200 c=200 ans=35 radius=10
tc full-dfs-8 gen_dfs r=200 c=200 ans=100 radius=100
tc full-dfs-9 gen_dfs r=200 c=200 ans=200 radius=100
tc full-dfs-10 gen_dfs r=200 c=200 ans=350 radius=100
tc full-dfs-11 gen_dfs r=10 c=4000 ans=4 radius=4
tc full-dfs-12 gen_dfs r=4000 c=10 ans=6 radius=5
tc full-dfs-13 gen_dfs r=5 c=8000 ans=2 radius=2
tc full-dfs-14 gen_dfs r=8000 c=5 ans=4 radius=3
tc full-sparse-1 gen_sparse r=200 c=200 numR=4 mirrors_per_row=3
tc full-sparse-2 gen_sparse r=200 c=200 numR=100 mirrors_per_row=3
tc full-sparse-3 gen_sparse r=200 c=200 numR=4 mirrors_per_row=10
tc full-sparse-4 gen_sparse r=200 c=200 numR=100 mirrors_per_row=10
