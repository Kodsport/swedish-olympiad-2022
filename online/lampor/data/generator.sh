#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution js_dedup.cpp

compile poster.py
compile gen_sameside.py
compile gen_rand.py
compile gen_redhor.py

samplegroup
limits task=0
sample 1
sample 2
sample 3
sample 4


# Gruppen består av ett enda testfall, det som finns på vår affisch (\url{https://www.progolymp.se/2022/affisch.pdf}).
group group1 20
limits task=1
tc poster poster

# Alla lampor på samma sida har samma färg.
group group2 15
limits task=2
tc 2
tc 3
tc rc1-RGGG gen_sameside sides=RGGG R=1 C=1
tc rc1-RGBG gen_sameside sides=RGBG R=1 C=1
tc rc1-BGRR gen_sameside sides=BGRR R=1 C=1
tc rc1-BBGB gen_sameside sides=BBGB R=1 C=1
tc sameside-RRRR gen_sameside sides=RRRR R=1000000 C=1000000
tc sameside-RRBR gen_sameside sides=RRBR R=1000000 C=1000000
tc sameside-GRBR gen_sameside sides=GRBR R=1000000 C=1000000
tc sameside-GGBB gen_sameside sides=GGBB R=1000000 C=1000000
tc sameside-GRBB gen_sameside sides=GRBB R=1000000 C=1000000
tc sameside-GRGR gen_sameside sides=GRGR R=1000000 C=1000000
tc sameside-BGGR gen_sameside sides=BGGR R=1000000 C=1000000

# R,C
group group3 25
limits task=3
include_group group1
tc 1
tc 2
tc 3
tc 4
tc rand-1e3-1 gen_rand R=1000 C=1000
tc rand-1e3-2 gen_rand R=1000 C=1000
tc rand-1e3-3 gen_rand R=1000 C=1000

# Alla lampor till höger eller vänster om rutnätet lyser rött, och alla lampor över och under rutnätet lyser grönt eller blått.
group group4 25
limits task=4
tc 1
tc sameside-GRBR
tc sameside-GRGR
tc rand-redhor-1 gen_redhor R=1000000 C=1000000
tc rand-redhor-2 gen_redhor R=1000000 C=1000000
tc rand-redhor-3 gen_redhor R=1000000 C=1000000

# Inga ytterligare begränsningar
group group5 15
limits task=5
include_group group1
include_group group2
include_group group3
include_group group4

tc rand-1e6-1 gen_rand R=1000000 C=1000000
tc rand-1e6-2 gen_rand R=1000000 C=1000000
tc rand-1e6-3 gen_rand R=1000000 C=1000000
