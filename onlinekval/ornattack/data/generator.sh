#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution gustav.cpp

compile gen_random.py

samplegroup
limits max_n=10 max_k=10 line=0
sample_manual 1
sample_manual 2

group group1 15
limits max_n=100000 max_k=100000 line=1
tc g1-1 gen_random n=2 k=50000 mode=line shuffle_nodes=false min_power=900000000 max_power=1000000000 plane_distribution=0.9
tc g1-2 gen_random n=60000 k=60000 mode=line shuffle_nodes=false min_power=1000 max_power=1000000000 plane_distribution=0.9
tc g1-3 gen_random n=70000 k=70000 mode=line shuffle_nodes=false min_power=1000000 max_power=1000000000 plane_distribution=0.8
tc g1-4 gen_random n=80000 k=80000 mode=line shuffle_nodes=false min_power=1000000 max_power=1000000000 plane_distribution=0.7
tc g1-5 gen_random n=90000 k=90000 mode=line shuffle_nodes=false min_power=123456 max_power=123456789 plane_distribution=0.31415
tc g1-6 gen_random n=100000 k=100000 mode=line shuffle_nodes=false min_power=133769 max_power=420691337 plane_distribution=0.420133769
tc g1-7 gen_random n=99999 k=99999 mode=line shuffle_nodes=false min_power=1 max_power=1 plane_distribution=0.1
tc g1-8 gen_random n=99999 k=99999 mode=line shuffle_nodes=false min_power=1000000000 max_power=1000000000 plane_distribution=0.5
tc g1-9 gen_random n=100 k=100000 mode=line shuffle_nodes=false min_power=10000 max_power=1000000000 plane_distribution=0.45
tc g1-10 gen_random n=100000 k=100 mode=line shuffle_nodes=false min_power=10000 max_power=1000000000 plane_distribution=-1
tc g1-11 gen_random n=10 k=10 mode=line shuffle_nodes=false min_power=1 max_power=100 plane_distribution=1.0

group group2 30
include_group sample
limits max_n=2000 max_k=2000 line=0
tc g2-1 gen_random n=1 k=1 mode=random shuffle_nodes=false min_power=1 max_power=10 plane_distribution=1.0
tc g2-2 gen_random n=2 k=1 mode=random shuffle_nodes=true min_power=1 max_power=100 plane_distribution=0.5
tc g2-3 gen_random n=10 k=6 mode=random shuffle_nodes=false min_power=1 max_power=200 plane_distribution=0.8
tc g2-4 gen_random n=15 k=15 mode=random shuffle_nodes=false min_power=1 max_power=1000 plane_distribution=0.3
tc g2-5 gen_random n=1000 k=501 mode=random shuffle_nodes=false min_power=1 max_power=10000 plane_distribution=0.25
tc g2-6 gen_random n=1500 k=1732 mode=random shuffle_nodes=false min_power=1 max_power=100000 plane_distribution=0.2
tc g2-7 gen_random n=1600 k=1900 mode=deep shuffle_nodes=true min_power=1 max_power=1000000 plane_distribution=0.6
tc g2-8 gen_random n=1700 k=2000 mode=random shuffle_nodes=true min_power=500000000 max_power=1000000000 plane_distribution=0.1
tc g2-9 gen_random n=1800 k=1905 mode=starline shuffle_nodes=true min_power=800000000 max_power=1000000000 plane_distribution=-1
tc g2-10 gen_random n=1900 k=1957 mode=star shuffle_nodes=true min_power=800000000 max_power=1000000000 plane_distribution=0.7
tc g2-11 gen_random n=1950 k=2000 mode=star shuffle_nodes=false min_power=800000000 max_power=1000000000 plane_distribution=0.7
tc g2-12 gen_random n=2000 k=1 mode=deeper shuffle_nodes=true min_power=1 max_power=1 plane_distribution=0.7


group group3 5
include_group sample
include_group group2
limits max_n=2000 max_k=100000 line=0
tc g3-1 gen_random n=1000 k=50000 mode=random shuffle_nodes=false min_power=1000 max_power=10000 plane_distribution=0.22
tc g3-2 gen_random n=1500 k=60000 mode=random shuffle_nodes=false min_power=10000 max_power=100000 plane_distribution=0.8
tc g3-3 gen_random n=1900 k=70000 mode=random shuffle_nodes=true min_power=100000 max_power=1000000 plane_distribution=0.2
tc g3-4 gen_random n=1950 k=90000 mode=starline shuffle_nodes=true min_power=10000000 max_power=100000000 plane_distribution=0.54
tc g3-5 gen_random n=1990 k=100000 mode=deeper shuffle_nodes=true min_power=133742069 max_power=1000000000 plane_distribution=-1
tc g3-6 gen_random n=1999 k=95000 mode=degtwo shuffle_nodes=true min_power=123456789 max_power=987654321 plane_distribution=1
tc g3-7 gen_random n=2000 k=99000 mode=random shuffle_nodes=true min_power=123454321 max_power=800000000 plane_distribution=0.7
tc g3-8 gen_random n=2000 k=99900 mode=shallow shuffle_nodes=true min_power=1000000000 max_power=1000000000 plane_distribution=0.67
tc g3-9 gen_random n=2000 k=99000 mode=random shuffle_nodes=true min_power=123454321 max_power=1000000000 plane_distribution=0.32
tc g3-10 gen_random n=2000 k=99000 mode=random shuffle_nodes=true min_power=12354321 max_power=70000000 plane_distribution=0.45


group group4 50
include_group group1
include_group group3
limits max_n=100000 max_k=100000 line=0
tc g4-1 gen_random n=90000 k=90000 mode=random shuffle_nodes=false min_power=100000 max_power=1000000 plane_distribution=0.5
tc g4-2 gen_random n=90000 k=90000 mode=starline shuffle_nodes=true min_power=1000000000 max_power=1000000000 plane_distribution=1
tc g4-3 gen_random n=90000 k=90000 mode=random shuffle_nodes=false min_power=1000000000 max_power=1000000000 plane_distribution=-1
tc g4-4 gen_random n=95000 k=100000 mode=deep shuffle_nodes=true min_power=700000000 max_power=999999999 plane_distribution=0.32
tc g4-5 gen_random n=99000 k=70000 mode=random shuffle_nodes=false min_power=800000000 max_power=899999999 plane_distribution=0.48
tc g4-6 gen_random n=99900 k=99900 mode=random shuffle_nodes=true min_power=1 max_power=899999999 plane_distribution=0.56
tc g4-7 gen_random n=90000 k=99990 mode=degtwo shuffle_nodes=true min_power=100000000 max_power=899999999 plane_distribution=0.67
tc g4-8 gen_random n=99990 k=99999 mode=star shuffle_nodes=false min_power=500000000 max_power=899999999 plane_distribution=0.78
tc g4-9 gen_random n=99999 k=99990 mode=shallow shuffle_nodes=true min_power=500000000 max_power=899999999 plane_distribution=0.14
tc g4-10 gen_random n=100000 k=100000 mode=deeper shuffle_nodes=true min_power=70000000 max_power=89699999 plane_distribution=0.25
