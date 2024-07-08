'''
    Improvements:
        1. error handling
        2. tkey type checking
'''

import random
import string

key_list = [] # for checking duplicate keys

def generate_struct(nkey, tkey, skeyMin, skeyMax):
    struct_content = f"""// Automatically generated struct by generate_struct.py
// Number of keys: {nkey}
// Key type: {tkey}
// Key size bound: [{skeyMin}, {skeyMax}]
// Value size: {sval}

struct testData {{
""" 
    if(tkey != "string"): 
        for i in range(nkey):
            while True:
                tmp = ''.join(random.SystemRandom().choice(string.ascii_uppercase + string.ascii_lowercase) for _ in range(random.randint(skeyMin, skeyMax)))
                if tmp not in key_list:
                    struct_content += f"    {tkey} {tmp};\n"
                    key_list.append(tmp)
                    break
    else:
        for i in range(nkey): 
            while True:
                tmp = ''.join(random.SystemRandom().choice(string.ascii_uppercase + string.ascii_lowercase) for _ in range(random.randint(skeyMin, skeyMax)))
                if tmp not in key_list:
                    struct_content += f"    char {tmp} [{sval}];\n"
                    key_list.append(tmp)
                    break

    
    struct_content += "};\n\n"
    return struct_content

def generate_header_file(nkey, tkey, skeyMin, skeyMax):
    header_content = """#pragma once
#include <cstdint>
#include <string>

"""
    header_content += generate_struct(nkey, tkey, skeyMin, skeyMax)
    
    return header_content

with open("config.txt", "r") as f:
    nkey, tkey, skeyMin, skeyMax, sval = f.readline().split(", ")
nkey, skeyMin, skeyMax, sval = map(int, (nkey, skeyMin, skeyMax, sval))

# Generate the header file content
header_content = generate_header_file(nkey, tkey, skeyMin, skeyMax)

# Write to file
with open("benchmark_struct.h", "w") as f:
    f.write(header_content)

print("benchmark_struct.h has been generated.")