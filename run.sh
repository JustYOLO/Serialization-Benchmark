#!/bin/sh
python3 generate_struct.py
protoc --cpp_out=./ ./ProtoData.proto # for making protobuf struct
thrift --gen cpp struct.thrift # for making thrift struct
flatc --cpp struct.fbs # for making flatbuffers struct``

make clean
make

./benchmark_test
