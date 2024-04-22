#!/bin/bash

# `pip install gprof2dot` or use your package manager

gcc -Wall -pg -o test_gprof test_gprof.cpp
./test_gprof

gprof test_gprof gmon.out >gprof.txt

python3 -m gprof2dot <gprof.txt >gprof.dot
dot -Tpdf -o gprof.pdf gprof.dot