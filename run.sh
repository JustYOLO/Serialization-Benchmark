#!/bin/sh
python3 generate_struct.py
protoc --cpp_out=./ ./testData.proto # for making protobuf struct

make clean
make

./benchmark_test
