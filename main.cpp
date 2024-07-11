#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm> // for std::remove_if
#include <cctype>    // for std::isspace
#include <benchmark/benchmark.h>
#include "benchmark_struct.h"
#include "data_generator.h"
#include "serializers.h"
#include "benchmark_func.h"

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
    
    if (tokens.size() < 6) {
        std::cerr << "Error: Not enough parameters in config file" << std::endl;
        exit(1);
    }
}
void getValues(std::vector<std::string> *values, size_t testSize) {
    std::ifstream config_file("values.txt");
    std::string line;
    for(size_t i = 0; i < testSize; ++i) {
        line.clear();
        std::getline(config_file, line);
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream iss(line);
        for (std::string s; iss >> s;) 
            values[i].push_back(s);
    }
}



class CustomReporter : public benchmark::BenchmarkReporter {
public:
    CustomReporter(const std::string& latencyFileName, const std::string& sizeFileName) : latencyFile(latencyFileName), sizeFile(sizeFileName), consoleReporter() {
        if (!latencyFile.is_open() || !sizeFile.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
    }

    bool ReportContext(const Context& context) override {
        consoleReporter.ReportContext(context);
        return true;
    }

    void ReportRuns(const std::vector<Run>& report) override {
        for (const auto& run : report) {
            double time_ns = (run.real_accumulated_time * 1e9) / run.iterations;
            latencyBuf += std::to_string(time_ns) + "\n"; // output unit is nano seconds
            if(run.report_label != "")
                sizeBuf += run.report_label + "\n"; 
        }
        consoleReporter.ReportRuns(report);
    }

    void Finalize() override {
        latencyFile << latencyBuf; // TODO: seperate serialize and deserialize latency output file
        sizeFile << sizeBuf;
        latencyFile.close();
        sizeFile.close();
        consoleReporter.Finalize();
    }

private:
    std::string latencyBuf;
    std::string sizeBuf;
    std::ofstream latencyFile;
    std::ofstream sizeFile;
    benchmark::ConsoleReporter consoleReporter;
};


int main(int argc, char** argv) {
    std::vector<std::string> tokens;    
    getTokens(tokens);

    size_t nkeys = std::stoi(tokens[0]);
    size_t svalMin = std::stoi(tokens[4]);
    size_t svalMax = std::stoi(tokens[5]);
    size_t testSize = std::stoi(tokens[6]);
    std::string type = tokens[1];

    std::vector<std::string> values [testSize];
    getValues(values, testSize); // values contains random generated values from python

    for(size_t i = 0; i < testSize; i++) {
        for(size_t j = 0; j < nkeys; j++)
            std::cout << values[i].at(j) << " ";
        std::cout << std::endl;
    }

    benchmark::Initialize(&argc, argv);
    DataGenerator generator;

    std::vector<testData> testDataVector (testSize);
    for (size_t i = 0; i < testSize; ++i) {
        generator.fillStruct(testDataVector[i], nkeys, svalMin, svalMax, type, values[i]);
        benchmark::RegisterBenchmark(
            ("BM_MsgPackSerialization_" + std::to_string(i)).c_str(),
            BM_MsgPackSerialization, testDataVector[i], "tmp/" + std::to_string(i) + ".msgpack");

        benchmark::RegisterBenchmark(
            ("BM_MsgPackDeserialization_" + std::to_string(i)).c_str(),
            BM_MsgPackDeserialization, "tmp/" + std::to_string(i) + ".msgpack");
    }

    CustomReporter reporter("MP-16-string-16-16-16-latency.txt", "MP-16-string-16-16-16-size.txt");
    auto start_time = std::chrono::high_resolution_clock::now();
    benchmark::RunSpecifiedBenchmarks(&reporter);
    benchmark::Shutdown();
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "Total elapsed time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
