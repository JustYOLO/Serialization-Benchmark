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
    state.SetLabel(std::to_string(dataSize) + " " + std::to_string(serializedSize));
}

static void BM_ProtoBufDeserialization(benchmark::State& state, const std::string& filename) {
    for (auto _ : state) {
        auto deserialized = serializers::deserializeProtoBuf(filename);
        benchmark::DoNotOptimize(deserialized);
    }
}

static void BM_FlexBufSerialization(benchmark::State& state, testData data, const std::string& filename) {
    size_t dataSize = sizeof(data);
    size_t serializedSize = 0;
    for (auto _ : state) {
        auto serialized = serializers::serializeFlexBuffers(data, filename);
        benchmark::DoNotOptimize(serialized);
        serializedSize = serialized;
    }
    state.SetLabel(std::to_string(dataSize) + " " + std::to_string(serializedSize));

}
static void BM_FlexBufDeserialization(benchmark::State& state, const std::string& filename) {
    for (auto _ : state) {
        auto deserialized = serializers::deserializeFlexBuffers(filename);
        benchmark::DoNotOptimize(deserialized);
    }
}

static void BM_ThriftSerialization(benchmark::State& state, testData data, const std::string& filename) {
    size_t dataSize = sizeof(data);
    size_t serializedSize = 0;
    for (auto _ : state) {
        auto serialized = serializers::serializeApacheThrift(data, filename);
        benchmark::DoNotOptimize(serialized);
        serializedSize = serialized;
    }
    state.SetLabel(std::to_string(dataSize) + " " + std::to_string(serializedSize));

}
static void BM_ThriftDeserialization(benchmark::State& state, const std::string& filename) {
    for (auto _ : state) {
        auto deserialized = serializers::deserializeApacheThrift(filename);
        benchmark::DoNotOptimize(deserialized);
    }
}

static void BM_FlatBufSerialization(benchmark::State& state, testData data, const std::string& filename) {
    size_t dataSize = sizeof(data);
    size_t serializedSize = 0;
    for (auto _ : state) {
        auto serialized = serializers::serializeFlatBuffers(data, filename);
        benchmark::DoNotOptimize(serialized);
        serializedSize = serialized;
    }
    state.SetLabel(std::to_string(dataSize) + " " + std::to_string(serializedSize));
}

static void BM_FlatBufDeserialization(benchmark::State& state, const std::string& filename) {
    for (auto _ : state) {
        auto deserialized = serializers::deserializeFlatBuffers(filename);
        benchmark::DoNotOptimize(deserialized);
    }
}

static void BM_JsonSerialization(benchmark::State& state, testData data, const std::string& filename) {
    size_t dataSize = sizeof(data);
    size_t serializedSize = 0;
    for (auto _ : state) {
        auto serialized = serializers::serializeJson(data, filename);
        benchmark::DoNotOptimize(serialized);
        serializedSize = serialized;
    }
    state.SetLabel(std::to_string(dataSize) + " " + std::to_string(serializedSize));
}

static void BM_JsonDeserialization(benchmark::State& state, const std::string& filename) {
    for (auto _ : state) {
        auto deserialized = serializers::deserializeJson(filename);
        benchmark::DoNotOptimize(deserialized);
    }
}
