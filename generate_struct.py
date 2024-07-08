'''
    Improvements:
        1. error handling
        2. tkey type checking
'''

import random
import string

def generate_struct(nkey, tkey, skey):
    struct_content = f"""// Automatically generated struct by generate_struct.py
// Number of keys: {nkey}
// Key type: {tkey}
// Key size: {skey}
// Value size: {sval}

struct testData {{
"""
    if(tkey != "string"):
        for i in range(nkey):
            struct_content += f"    {tkey} {''.join(random.SystemRandom().choice(string.ascii_uppercase + string.ascii_lowercase) for _ in range(skey))};\n"
    else:
        for i in range(nkey):
            struct_content += f"    char {''.join(random.SystemRandom().choice(string.ascii_uppercase + string.ascii_lowercase) for _ in range(skey))} [{sval + 1}];\n"
    
    struct_content += "};\n\n"
    return struct_content

def generate_header_file(nkey, tkey, skey):
    header_content = """#pragma once
#include <cstdint>
#include <string>

"""
    header_content += generate_struct(nkey, tkey, skey)
    
    return header_content

with open("config.txt", "r") as f:
    nkey, tkey, skey, sval = f.readline().split(", ")
nkey, skey, sval = map(int, (nkey, skey, sval))

# Generate the header file content
header_content = generate_header_file(nkey, tkey, skey)

# Write to file
with open("benchmark_struct.h", "w") as f:
    f.write(header_content)

print("benchmark_struct.h has been generated.")