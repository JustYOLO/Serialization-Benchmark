#pragma once
#include "benchmark_struct.h"
#include <random>
#include <type_traits>

class DataGenerator {
public:
    DataGenerator(unsigned seed = std::random_device{}());

    void fillStruct(testData& data, size_t value_size, const std::string& type);

private:
    std::mt19937 gen;

    template<typename T>
    T generateRandomValue();

    void generateRandomString(char* str, size_t size);
    void fillInt32(testData& data);
    void fillDouble(testData& data);
    void fillChar(testData& data, size_t value_size);
};

// Template specializations for different types
template<>
int32_t DataGenerator::generateRandomValue<int32_t>();

template<>
double DataGenerator::generateRandomValue<double>();