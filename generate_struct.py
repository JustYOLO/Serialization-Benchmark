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
    size_t Serialize(const testData& data, const std::string& filename) {
        GOOGLE_PROTOBUF_VERIFY_VERSION; // is it necessary?
        ProtoData protoData;
"""
    for key in key_value_pair.keys():
        func_content += f"        protoData.set_{key}(data.{key});\n"

    func_content += """        std::ofstream output(filename, std::ios::out | std::ios::binary);
        if (!protoData.SerializeToOstream(&output)) {
            std::cerr << "protobuf: Failed to write data to file." << std::endl;
        }
        return protoData.ByteSizeLong();
    }
    void Deserialize(testData& data, const std::string& filename) {
        std::ifstream input(filename, std::ios::in | std::ios::binary);
        ProtoData protoData;
        if (!protoData.ParseFromIstream(&input)) {
            std::cerr << "protobuf: Failed to read data from file." << std::endl;
        }
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
    void Serialize(const testData& data, std::vector<uint8_t> &outBuffer) {
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

    header_content += """
        });

        builder.Finish();
        outBuffer = builder.GetBuffer();
    }
    void Deserialize(testData& data, const std::vector<uint8_t> &inBuffer) {
        auto root = flexbuffers::GetRoot(inBuffer).AsMap();
        
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
            header_content += f"        data.{key} = root[\"{key}\"].AdDouble();\n"


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
    void Serialize(const testData& data, std::string& serialized_str) {
        TStruct tStruct;
"""
    for key in key_value_pair.keys():
        struct_content += f"        tStruct.{key} = data.{key};\n"
    struct_content += """
        std::shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
        std::shared_ptr<TBinaryProtocol> protocol(new TBinaryProtocol(buffer));

        tStruct.write(protocol.get());

        // uint8_t* serializedData;
        // buffer->getBuffer(&serializedData, &dataSize);
        serialized_str = buffer->getBufferAsString();
    }

    void Deserialize(testData& data, std::vector<uint8_t>& inBuffer) {
        std::shared_ptr<TMemoryBuffer> bufferIn(new TMemoryBuffer());
        bufferIn->resetBuffer(inBuffer.data(), inBuffer.size());
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
if(tkey == "string"):
    generate_values_file() # make values file

print("structures have been generated.")
