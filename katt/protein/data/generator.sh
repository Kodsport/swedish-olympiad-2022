#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution sol_nb_nlogn.cpp

samplegroup
sample 1
sample 2

group group1 15
limits maxn=20
tc 1
tc 2
tc_manual ../manual_tests/03.in
tc_manual ../manual_tests/04.in
tc_manual ../manual_tests/05.in
tc_manual ../manual_tests/06.in
tc_manual ../manual_tests/07.in
tc_manual ../manual_tests/08.in
tc_manual ../manual_tests/09.in
tc_manual ../manual_tests/10.in
tc_manual ../manual_tests/11.in
tc_manual ../manual_tests/12.in
tc_manual ../manual_tests/13.in
tc_manual ../manual_tests/14.in
tc_manual ../manual_tests/15.in
tc_manual ../manual_tests/16.in
tc_manual ../manual_tests/17.in
tc_manual ../manual_tests/18.in
tc_manual ../manual_tests/19.in
tc_manual ../manual_tests/20.in
tc_manual ../manual_tests/21.in
tc_manual ../manual_tests/22.in
tc_manual ../manual_tests/23.in
tc_manual ../manual_tests/24.in
tc_manual ../manual_tests/25.in
tc_manual ../manual_tests/26.in
tc_manual ../manual_tests/27.in
tc_manual ../manual_tests/28.in
tc_manual ../manual_tests/29.in
tc_manual ../manual_tests/30.in

group group2 10
limits maxn=300 maxk=5

tc_manual ../manual_tests/31.in
tc_manual ../manual_tests/32.in
tc_manual ../manual_tests/33.in
tc_manual ../manual_tests/34.in
tc_manual ../manual_tests/35.in
tc_manual ../manual_tests/36.in
tc_manual ../manual_tests/37.in
tc_manual ../manual_tests/38.in
tc_manual ../manual_tests/39.in
tc_manual ../manual_tests/40.in
tc_manual ../manual_tests/41.in
tc_manual ../manual_tests/42.in
tc_manual ../manual_tests/43.in
tc_manual ../manual_tests/44.in
tc_manual ../manual_tests/45.in
tc_manual ../manual_tests/46.in
tc_manual ../manual_tests/47.in
tc_manual ../manual_tests/48.in
tc_manual ../manual_tests/49.in
tc_manual ../manual_tests/50.in
tc_manual ../manual_tests/51.in
tc_manual ../manual_tests/52.in
tc_manual ../manual_tests/53.in
tc_manual ../manual_tests/54.in
tc_manual ../manual_tests/55.in
tc_manual ../manual_tests/56.in
tc_manual ../manual_tests/57.in
tc_manual ../manual_tests/58.in
tc_manual ../manual_tests/59.in
tc_manual ../manual_tests/60.in

group group3 20
limits maxn=500
include_group group1
include_group group2

tc_manual ../manual_tests/61.in
tc_manual ../manual_tests/62.in
tc_manual ../manual_tests/63.in
tc_manual ../manual_tests/64.in
tc_manual ../manual_tests/65.in
tc_manual ../manual_tests/66.in
tc_manual ../manual_tests/67.in
tc_manual ../manual_tests/68.in
tc_manual ../manual_tests/69.in
tc_manual ../manual_tests/70.in
tc_manual ../manual_tests/71.in
tc_manual ../manual_tests/72.in
tc_manual ../manual_tests/73.in
tc_manual ../manual_tests/74.in
tc_manual ../manual_tests/75.in
tc_manual ../manual_tests/76.in
tc_manual ../manual_tests/77.in
tc_manual ../manual_tests/78.in
tc_manual ../manual_tests/79.in

group group4 10
limits maxn=2000
include_group group3

tc_manual ../manual_tests/80.in
tc_manual ../manual_tests/81.in
tc_manual ../manual_tests/82.in
tc_manual ../manual_tests/83.in
tc_manual ../manual_tests/84.in
tc_manual ../manual_tests/85.in
tc_manual ../manual_tests/86.in
tc_manual ../manual_tests/87.in
tc_manual ../manual_tests/88.in
tc_manual ../manual_tests/89.in
tc_manual ../manual_tests/90.in
tc_manual ../manual_tests/91.in
tc_manual ../manual_tests/92.in
tc_manual ../manual_tests/93.in
tc_manual ../manual_tests/94.in
tc_manual ../manual_tests/95.in
tc_manual ../manual_tests/96.in
tc_manual ../manual_tests/97.in
tc_manual ../manual_tests/98.in
tc_manual ../manual_tests/99.in
tc_manual ../manual_tests/100.in

group group5 25
limits maxn=100000
include_group group4

tc_manual ../manual_tests/101.in
tc_manual ../manual_tests/102.in
tc_manual ../manual_tests/103.in
tc_manual ../manual_tests/104.in
tc_manual ../manual_tests/105.in
tc_manual ../manual_tests/106.in
tc_manual ../manual_tests/107.in
tc_manual ../manual_tests/108.in
tc_manual ../manual_tests/109.in
tc_manual ../manual_tests/110.in
tc_manual ../manual_tests/111.in
tc_manual ../manual_tests/112.in
tc_manual ../manual_tests/113.in
tc_manual ../manual_tests/114.in
tc_manual ../manual_tests/115.in
tc_manual ../manual_tests/116.in
tc_manual ../manual_tests/117.in
tc_manual ../manual_tests/118.in
tc_manual ../manual_tests/119.in
tc_manual ../manual_tests/120.in
tc_manual ../manual_tests/121.in
tc_manual ../manual_tests/122.in
tc_manual ../manual_tests/123.in
tc_manual ../manual_tests/124.in
tc_manual ../manual_tests/125.in
tc_manual ../manual_tests/126.in
tc_manual ../manual_tests/127.in
tc_manual ../manual_tests/128.in
tc_manual ../manual_tests/129.in
tc_manual ../manual_tests/130.in
tc_manual ../manual_tests/131.in
tc_manual ../manual_tests/132.in
tc_manual ../manual_tests/133.in
tc_manual ../manual_tests/134.in
tc_manual ../manual_tests/135.in
tc_manual ../manual_tests/136.in
tc_manual ../manual_tests/137.in
tc_manual ../manual_tests/138.in
tc_manual ../manual_tests/139.in
tc_manual ../manual_tests/140.in
tc_manual ../manual_tests/141.in
tc_manual ../manual_tests/142.in
tc_manual ../manual_tests/143.in
tc_manual ../manual_tests/144.in
tc_manual ../manual_tests/145.in
tc_manual ../manual_tests/146.in
tc_manual ../manual_tests/147.in
tc_manual ../manual_tests/148.in

group group6 10
limits maxk=2

tc_manual ../manual_tests/149.in
tc_manual ../manual_tests/150.in
tc_manual ../manual_tests/151.in
tc_manual ../manual_tests/152.in
tc_manual ../manual_tests/153.in
tc_manual ../manual_tests/154.in
tc_manual ../manual_tests/155.in
tc_manual ../manual_tests/156.in
tc_manual ../manual_tests/157.in
tc_manual ../manual_tests/158.in
tc_manual ../manual_tests/159.in
tc_manual ../manual_tests/160.in
tc_manual ../manual_tests/161.in
tc_manual ../manual_tests/162.in
tc_manual ../manual_tests/163.in
tc_manual ../manual_tests/164.in
tc_manual ../manual_tests/165.in
tc_manual ../manual_tests/166.in
tc_manual ../manual_tests/167.in
tc_manual ../manual_tests/168.in

group group7 10 
include_group group5
include_group group6

tc_manual ../manual_tests/169.in
tc_manual ../manual_tests/170.in
tc_manual ../manual_tests/171.in
tc_manual ../manual_tests/172.in
tc_manual ../manual_tests/173.in
tc_manual ../manual_tests/174.in
tc_manual ../manual_tests/175.in
tc_manual ../manual_tests/176.in
tc_manual ../manual_tests/177.in
tc_manual ../manual_tests/178.in
tc_manual ../manual_tests/179.in
tc_manual ../manual_tests/180.in
tc_manual ../manual_tests/181.in
tc_manual ../manual_tests/182.in
tc_manual ../manual_tests/183.in
tc_manual ../manual_tests/184.in
tc_manual ../manual_tests/185.in
tc_manual ../manual_tests/186.in
tc_manual ../manual_tests/187.in
tc_manual ../manual_tests/188.in
tc_manual ../manual_tests/189.in
tc_manual ../manual_tests/190.in
tc_manual ../manual_tests/191.in
tc_manual ../manual_tests/192.in
tc_manual ../manual_tests/193.in
