'''
    Improvements:
        1. error handling
        2. tkey type checking
'''

import random
import string
import numpy
import math

CPP_Header = """#include "data_generator.h"
// this may only used by msgPack

void DataGenerator::fillString(testData& data, const std::vector<std::string> &values) {
    
"""

CHARSET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

key_value_pair = {} # have key-value pair

def generate_struct(nkey, tkey, skeyMin, skeyMax):
    struct_content = f"""// Automatically generated struct by generate_struct.py
// Number of keys: {nkey}
// Key type: {tkey}
// Key size bound: [{skeyMin}, {skeyMax}]
// Value size bound: [{svalMin}, {svalMax}]

struct testData {{
""" 
    if(tkey != "string"): 
        for i in range(nkey):
            while True:
                tmp = ''.join(random.SystemRandom().choice(string.ascii_lowercase) for _ in range(random.randint(skeyMin, skeyMax)))
                if tmp not in key_value_pair.keys():
                    struct_content += f"    {tkey} {tmp};\n" # TODO: set key name based on zipfian
                    key_value_pair[tmp] = 1 # value is used only in string type
                    break
    else: # in case of string
        for i in range(nkey): 
            while True:
                tmp = ''.join(random.SystemRandom().choice(string.ascii_lowercase) for _ in range(random.randint(skeyMin, skeyMax)))
                if tmp not in key_value_pair.keys():
                    key_value_pair[tmp] = []
                    struct_content += f"    std::string {tmp};\n"
                    for _ in range(testSize):
                        key_value_pair[tmp].append(''.join(random.SystemRandom().choice(CHARSET) for _ in range(random.randint(svalMin, svalMax))))
                    break

    
    struct_content += "    MSGPACK_DEFINE_MAP("
    for idx, name in enumerate(key_value_pair.keys()):
        if idx == len(key_value_pair.keys()) - 1:
            struct_content += name
        else:
            struct_content += name + ", "
    struct_content += ");\n"
    
    struct_content += "};\n\n"
    return struct_content

def generate_header_file(nkey, tkey, skeyMin, skeyMax):
    header_content = """#pragma once
#include <cstdint>
#include <string>
#include <msgpack.hpp>

"""
    header_content += generate_struct(nkey, tkey, skeyMin, skeyMax)
    
    return header_content

def generate_string_struct():
    i = 0
    if tkey == "string":
        with open("data_generator_string.cc", "w") as f:
            f.write(CPP_Header)
            strBuf = ""
            for idx, name in enumerate(key_value_pair.keys()):
                strBuf += f"    data.{name} = values[{idx}];\n"
            f.write(strBuf)
            # this line is for debugging
            # f.write(f"    std::cout << values[0] << \", \" << values[{testSize - 1}] << std::endl;\n")
            f.write("}\n")
    else:
        with open("data_generator_string.cc", "w") as f:
            f.write(CPP_Header)
            f.write("}\n")

def generate_protoBuf_struct():
    # This function generates two files: the ProtoData.proto file and the protoBuf_func.h file
    header_content = """syntax = "proto3";

message ProtoData {
"""
    if tkey == "string":
        for idx, key in enumerate(key_value_pair.keys()):
            header_content += f"    string {key} = {idx + 1};\n"
    elif tkey == "int32_t":
        for idx, key in enumerate(key_value_pair.keys()):
            header_content += f"    int32 {key} = {idx + 1};\n"
    elif tkey == "double":
        for idx, key in enumerate(key_value_pair.keys()):
            header_content += f"    double {key} = {idx + 1};\n"
    header_content += "}\n"

    func_content = """#include "benchmark_struct.h"
#include "ProtoData.pb.h"

namespace proto {
    size_t Serialize(const testData& data, std::vector<char> &serializedData) {
        GOOGLE_PROTOBUF_VERIFY_VERSION; // is it necessary?
        ProtoData protoData;
"""
    for key in key_value_pair.keys():
        func_content += f"        protoData.set_{key}(data.{key});\n"

    func_content += """        size_t size = protoData.ByteSizeLong();
        serializedData.resize(size);
        protoData.SerializeToArray(serializedData.data(), static_cast<int>(size));
        // protoData.SerializeToArray(buffer.data(), static_cast<int>(size));
        // std::ofstream output(filename, std::ios::out | std::ios::binary);
        // if (!protoData.SerializeToOstream(&output)) {
        //     std::cerr << "protobuf: Failed to write data to file." << std::endl;
        // }
        return size;
    }
    void Deserialize(testData& data, std::vector<char> &serializedData, const size_t size) {
        ProtoData protoData;
        protoData.ParseFromArray(serializedData.data(), static_cast<int>(size));
"""
    for key in key_value_pair.keys():
        func_content += f"        data.{key} = protoData.{key}();\n"
    func_content += """    }
}

"""

    with open("ProtoData.proto", "w") as f:
        f.write(header_content)
    with open("protobuf_func.h", "w") as f:
        f.write(func_content)


def generate_flexBuf_struct():
    header_content = """#include <flatbuffers/flexbuffers.h>
#include "benchmark_struct.h"

namespace flex {
    size_t Serialize(const testData& data, std::vector<char> &serializedData) {
        flexbuffers::Builder builder;

        builder.Map([&]() {
"""
    # builder.String("key", "value");
    if tkey == "string":
        for key in key_value_pair.keys():
            header_content += f"            builder.String(\"{key}\", data.{key});\n"
    elif tkey == "int32_t":
        for key in key_value_pair.keys():
            header_content += f"            builder.Int(\"{key}\", data.{key});\n"
    elif tkey == "double":
        for key in key_value_pair.keys():
            header_content += f"            builder.Double(\"{key}\", data.{key});\n"

    header_content += """        });
        builder.Finish();
        std::vector<uint8_t> outBuffer;
        outBuffer = builder.GetBuffer();
        serializedData.resize(outBuffer.size());
        std::memcpy(serializedData.data(), outBuffer.data(), outBuffer.size());
        return outBuffer.size();
    }
    void Deserialize(testData& data, std::vector<char> &serializedData, const size_t size) {
        auto root = flexbuffers::GetRoot(reinterpret_cast<const uint8_t*>(serializedData.data()), size).AsMap();

"""
    # data.dngdRVLn = root["dngdRVLn"].AsString().str();
    if tkey == "string":
        for key in key_value_pair.keys():
            header_content += f"        data.{key} = root[\"{key}\"].AsString().str();\n"
    elif tkey == "int32_t":
        for key in key_value_pair.keys():
            header_content += f"        data.{key} = root[\"{key}\"].AsInt32();\n"
    elif tkey == "double":
        for key in key_value_pair.keys():
            header_content += f"        data.{key} = root[\"{key}\"].AsDouble();\n"


    header_content += """    }
}
"""
    with open("flexbuffers_func.h", "w") as f:
        f.write(header_content)

def generate_thrift_struct():
    # This function generates two files: the struct.thrift file and the thrift_func.h file
    struct_content = """#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <vector>
#include "gen-cpp/struct_types.h"
#include "benchmark_struct.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

namespace thrift {
    size_t Serialize(const testData& data, std::vector<char> &serializedData) {
        TStruct tStruct;
"""
    for key in key_value_pair.keys():
        struct_content += f"        tStruct.{key} = data.{key};\n"
    struct_content += """

        std::shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
        std::shared_ptr<TBinaryProtocol> protocol(new TBinaryProtocol(buffer));

        tStruct.write(protocol.get());
        size_t size = buffer->getBufferSize();

        serializedData.resize(size);
        std::memcpy(serializedData.data(), buffer->getBufferAsString().c_str(), size);
        return size;
    }

    void Deserialize(testData& data, std::vector<char> &serializedData, const size_t size) {
        std::shared_ptr<TMemoryBuffer> bufferIn(new TMemoryBuffer());
        bufferIn->write((uint8_t*)(serializedData.data()), size);
        std::shared_ptr<TBinaryProtocol> protocolIn(new TBinaryProtocol(bufferIn));

        TStruct tStruct;
        tStruct.read(protocolIn.get());
"""
    for key in key_value_pair.keys():
        struct_content += f"        data.{key} = tStruct.{key};\n"
    struct_content += """    }
}
"""
    thrift_content = """struct TStruct {
"""
    if tkey == "string":
        for idx, key in enumerate(key_value_pair.keys()):
            thrift_content += f" {idx+1}: string {key},\n"
    elif tkey == "int32_t":
        for idx, key in enumerate(key_value_pair.keys()):
            thrift_content += f" {idx+1}: i32 {key},\n"
    elif tkey == "double":
        for idx, key in enumerate(key_value_pair.keys()):
            thrift_content += f" {idx+1}: double {key},\n"
    thrift_content += "}\n"


    with open("thrift_func.h", "w") as f:
        f.write(struct_content)
    with open("struct.thrift", "w") as f:
        f.write(thrift_content)

def generate_flatBuf_struct():
    struct_content = """table flatData {
"""
    if tkey == "string":
        for key in key_value_pair.keys():
            struct_content += f"    {key}: string;\n"
    elif tkey == "int32_t":
        for key in key_value_pair.keys():
            struct_content += f"    {key}: int;\n"
    elif tkey == "double":
        for key in key_value_pair.keys():
            struct_content += f"    {key}: double;\n"

    struct_content += """}
root_type flatData;
"""
    func_content = """#include <flatbuffers/flatbuffers.h>
#include <vector>
#include "benchmark_struct.h"
#include "struct_generated.h"

namespace flat {
    size_t Serialize(const testData& data, std::vector<char> &serializedData) {
        flatbuffers::FlatBufferBuilder builder;
"""
    if tkey == "string":
        func_content += f"        std::vector<flatbuffers::Offset<flatbuffers::String>> keys;\n"
        for key in key_value_pair.keys():
            func_content += f"        keys.push_back(builder.CreateString(data.{key}));\n"
        func_content += f"        auto result = CreateflatData(builder, "
        for idx, key in enumerate(key_value_pair.keys()):
            if idx == len(key_value_pair.keys()) - 1:
                func_content += f"keys[{idx}]"
            else:
                func_content += f"keys[{idx}], "
        func_content += f");"
    else:
        func_content += f"        auto result = CreateflatData(builder, "
        for idx, key in enumerate(key_value_pair.keys()):
            if idx == len(key_value_pair.keys()) - 1:
                func_content += f"data.{key}"
            else:
                func_content += f"data.{key}, "
        func_content += f");"
    func_content += """
        builder.Finish(result);
        serializedData.resize(builder.GetSize());
        std::memcpy(serializedData.data(), builder.GetBufferPointer(), builder.GetSize());
        return builder.GetSize();
    }
    
    void Deserialize(testData& data, std::vector<char> &serializedData, const size_t size) {
        auto flatData = GetflatData(serializedData.data());
"""
    if tkey == "string":
        for key in key_value_pair.keys():
            func_content += f"        data.{key} = flatData->{key}()->str();\n"
    else:
        for key in key_value_pair.keys():
            func_content += f"        data.{key} = flatData->{key}();\n"
    func_content += """        // data.{keys} = flatData->{keys}()->c_str();
    }
}
"""
    
    with open("struct.fbs", "w") as f:
        f.write(struct_content)
    with open("flatbuffers_func.h", "w") as f:
        f.write(func_content)

def generate_json_func():
    func_content = """#include <nlohmann/json.hpp>
#include "benchmark_struct.h"
using jsonStruct = nlohmann::json;

namespace json {
    size_t Serialize(const testData& data, std::vector<char> &serializedData) {
    jsonStruct j = {
        // {"{key}", data.{key}},
"""
    for key in key_value_pair.keys():
        func_content += f"        {{\"{key}\", data.{key}}},\n"
    func_content += """        };
        std::string buf =  j.dump(4);
        serializedData.resize(buf.size());
        std::memcpy(serializedData.data(), buf.c_str(), buf.size());
        return buf.size();
    }

    void Deserialize(testData& data, std::vector<char> &serializedData, const size_t size) {
        jsonStruct j = jsonStruct::parse(serializedData);

        // data.{key} = j["{key}"];
"""
    for key in key_value_pair.keys():
        func_content += f"        data.{key} = j[\"{key}\"];\n"
    func_content += """    }
}
"""
    with open("json_func.h", "w") as f:
        f.write(func_content)

def generate_values_file():
    with open("values.txt", "w") as f:
        for i in range(testSize):
            for key in key_value_pair.keys():
                f.write(key_value_pair[key][i] + ", ")
            f.write("\n")


# starts here? 

with open("config.txt", "r") as f:
    nkey, tkey, skeyMin, skeyMax, svalMin, svalMax, testSize = f.readline().split(", ")
nkey, skeyMin, skeyMax, svalMin, svalMax, testSize = map(int, (nkey, skeyMin, skeyMax, svalMin, svalMax, testSize))

# Generate the header file content
header_content = generate_header_file(nkey, tkey, skeyMin, skeyMax)

# Write to file
with open("benchmark_struct.h", "w") as f:
    f.write(header_content)

generate_string_struct() # makes string struct for C++ (msgpack?)
generate_flexBuf_struct()
generate_protoBuf_struct()
generate_thrift_struct()
generate_json_func()
generate_flatBuf_struct()
if(tkey == "string"):
    generate_values_file() # make values file

print("structures have been generated.")