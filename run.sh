#!/bin/sh
python3 generate_struct.py

make clean
make

./benchmark_test
