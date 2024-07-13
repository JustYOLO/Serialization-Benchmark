# Serialization Benchmark

## Requirements

1. [Google Benchmark](https://github.com/google/benchmark) as a global library
2. [Protocol Buffers](https://protobuf.dev/)
3. [JSON library for C++](https://github.com/nlohmann/json) by Niels Lohmann (used 3.10.5-2)
4. [flexbuffers/flatbuffers](https://github.com/google/flatbuffers)
5. [Apache Thrift](https://thrift.apache.org/): followed [this](https://thrift.apache.org/docs/BuildingFromSource)
6. [MessagePack](https://github.com/msgpack/msgpack-c)

## How to use

1. edit the config.txt or test.sh as you want
2. mkdir: ./tmp and ./results (tmp directory is for serialized data, result directory is for output results)
3. use:
```bash
$ ./run.sh # runs single settings (reads config.txt)
# or
$ ./mtest.sh # runs multiple settings (modifies config.txt and runs ./run.sh script)
```

./run.sh script run all 6 serialization with same key-value test data.
**If config.txt is changed, you need to compile the whole program -> running ./run.sh script will do the job.**

**WARNING: ./run.sh script runs "make clean" and "make"**
**./test.sh script deletes ./tmp folder**

## config.txt
In order:
nkey, tkey, skeyMin, skeyMax, svalMin, svalMax, testSize
nkey: number of keys | tkey: type of keys | skey: size of keys (min, max) | sval: size of values

supported types(tkey): int32_t, double, string

sval used only when the type(tkey) is string
~~string means: char {variable length = skey} [{sval + 1}]~~
~~adding 1 in sval means it needs a space for null character~~

now uses std::string instead of char array

serialization_function names:
    JSON, MP (MessagePack), FX (FlexBuffers), PB (Protocol Buffers), TH (Apache Thrift), FB (FlatBuffers)