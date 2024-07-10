#include <benchmark/benchmark.h>
#include <msgpack.hpp>
#include "serializers.h"
#include "benchmark_struct.h"

static void BM_MsgPackSerialization(benchmark::State& state, testData data, const std::string& filename) {
    size_t dataSize = sizeof(data);
    size_t serializedSize = 0;
    for (auto _ : state) {
        auto serialized = serializers::serializeMsgPack(data, filename);
        benchmark::DoNotOptimize(serialized);
        serializedSize = serialized;
    }
    state.SetLabel(std::to_string(dataSize) + " " + std::to_string(serializedSize));
}

static void BM_MsgPackDeserialization(benchmark::State& state, const std::string& filename) {
    for (auto _ : state) {
        auto deserialized = serializers::deserializeMsgPack(filename);
        benchmark::DoNotOptimize(deserialized);
    }
}

static void BM_ProtoBufSerialization(benchmark::State& state, testData data, const std::string& filename) {
    size_t dataSize = sizeof(data);
    size_t serializedSize = 0;
    for (auto _ : state) {
        auto serialized = serializers::serializeProtoBuf(data, filename);
        benchmark::DoNotOptimize(serialized);
        serializedSize = serialized;
    }
    state.SetLabel("DataSize: " + std::to_string(dataSize) + ", SerializedSize: " + std::to_string(serializedSize));

}

static void BM_ProtoBufDeserialization(benchmark::State& state, const std::string& filename) {
    for (auto _ : state) {
        auto deserialized = serializers::deserializeProtoBuf(filename);
        benchmark::DoNotOptimize(deserialized);
    }
}
