#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm> // for std::remove_if
#include <cctype>    // for std::isspace
#include <benchmark/benchmark.h>
#include "benchmark_struct.h"
#include "data_generator.h"

// Read config.txt to get value size and type
void getTokens(std::vector<std::string> &tokens) {
    std::ifstream config_file("config.txt");
    std::string line;
    std::getline(config_file, line);
    std::replace(line.begin(), line.end(), ',', ' ');
    std::istringstream iss(line);
    std::string token;
    for (std::string s; iss >> s;) 
        tokens.push_back(s);
    
    if (tokens.size() < 5) {
        std::cerr << "Error: Not enough parameters in config file" << std::endl;
        exit(1);
    }
}

int main() {
    std::vector<std::string> tokens;
    getTokens(tokens);

    size_t value_size = std::stoi(tokens[4]);
    std::string type = tokens[1];

    testData data;
    DataGenerator generator;

    generator.fillStruct(data, value_size, type);

    // print test data
    if (type == "int32_t") {
        int32_t* ptr = reinterpret_cast<int32_t*>(&data);
        for (int i = 0; i < 3; ++i) {
            std::cout << "Value " << i + 1 << ": " << ptr[i] << std::endl;
        }
    } else if (type == "double") {
        double* ptr = reinterpret_cast<double*>(&data);
        for (int i = 0; i < 3; ++i) {
            std::cout << "Value " << i + 1 << ": " << ptr[i] << std::endl;
        }
    } else if (type == "string") {
        char* ptr = reinterpret_cast<char*>(&data);
        for (int i = 0; i < 3; ++i) {
            std::cout << "String " << i + 1 << ": " << (ptr + i * (value_size + 1)) << std::endl;
        }
    }



    return 0;
}