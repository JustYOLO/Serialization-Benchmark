'''
    Improvements:
        1. error handling
        2. tkey type checking
'''

import random
import string
import numpy
import math

CPP_Header = """
#include "data_generator.h"
// this may only used by msgPack
void DataGenerator::fillString(testData& data, size_t nkeys, size_t svalMin, size_t svalMax, const std::vector<std::string> &values) {
    
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
                tmp = ''.join(random.SystemRandom().choice(string.ascii_uppercase + string.ascii_lowercase) for _ in range(random.randint(skeyMin, skeyMax)))
                if tmp not in key_value_pair.keys():
                    struct_content += f"    {tkey} {tmp};\n" # TODO: set key name based on zipfian
                    key_value_pair[tmp] = 1 # value is used only in string type
                    break
    else: # in case of string
        for i in range(nkey): 
            while True:
                tmp = ''.join(random.SystemRandom().choice(string.ascii_uppercase + string.ascii_lowercase) for _ in range(random.randint(skeyMin, skeyMax)))
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
        with open("data_generator_string.cpp", "w") as f:
            f.write(CPP_Header)
            strBuf = ""
            for idx, name in enumerate(key_value_pair.keys()):
                strBuf += f"    data.{name} = values[{idx}];\n"
            f.write(strBuf)
            # this line is for debugging
            # f.write(f"    std::cout << values[0] << \", \" << values[{testSize - 1}] << std::endl;\n")
            f.write("}\n")
    else:
        with open("data_generator_string.cpp", "w") as f:
            f.write(CPP_Header)
            f.write("}\n")

def generate_protoBuf_struct():
    header_content = """

"""

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
if(tkey == "string"):
    generate_values_file() # make values file

print("benchmark_struct.h and data_generator_string.cpp have been generated.")