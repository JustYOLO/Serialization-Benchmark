#include "data_generator.h"
#include <algorithm>
#include <cstring>
#include <stdexcept>

DataGenerator::DataGenerator(unsigned seed) : gen(seed) {}

void DataGenerator::fillStruct(testData& data, size_t value_size, const std::string& type) {
    if (type == "int32_t") {
        fillInt32(data);
    } else if (type == "double") {
        fillDouble(data);
    } else if (type == "string") {
        fillChar(data, value_size);
    } else {
        throw std::runtime_error("Unsupported type");
    }
}

void DataGenerator::fillInt32(testData& data) {
    int32_t* ptr = reinterpret_cast<int32_t*>(&data); // Is it ok to use reinterpret_cast? Is there any better method?
    size_t num_members = sizeof(testData) / sizeof(int32_t);
    for (size_t i = 0; i < num_members; ++i) {
        ptr[i] = generateRandomValue<int32_t>();
    }
}

void DataGenerator::fillDouble(testData& data) {
    double* ptr = reinterpret_cast<double*>(&data);
    size_t num_members = sizeof(testData) / sizeof(double);
    for (size_t i = 0; i < num_members; ++i) {
        ptr[i] = generateRandomValue<double>();
    }
}

void DataGenerator::fillChar(testData& data, size_t value_size) {
    char* ptr = reinterpret_cast<char*>(&data);
    size_t num_members = sizeof(testData) / (value_size + 1);
    for (size_t i = 0; i < num_members; ++i) {
        generateRandomString(ptr + i * (value_size + 1), value_size);
    }
}

template<>
int32_t DataGenerator::generateRandomValue<int32_t>() {
    return std::uniform_int_distribution<int32_t>{}(gen);
}

template<>
double DataGenerator::generateRandomValue<double>() {
    return std::uniform_real_distribution<double>{}(gen);
}

void DataGenerator::generateRandomString(char* str, size_t size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const size_t charset_size = sizeof(charset) - 1;

    for (size_t i = 0; i < size; ++i) {
        str[i] = charset[std::uniform_int_distribution<>(0, charset_size - 1)(gen)];
    }
    str[size] = '\0';  // Null-terminate the string
}