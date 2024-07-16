#pragma once
#include "benchmark_struct.h"
#include <vector>
#include <msgpack.hpp>
#include <fstream>

// Include headers for other serialization libraries here

namespace serializers {

// MessagePack
size_t serializeMsgPack(const testData& data, const std::string& filename, benchmark::State& state);
testData deserializeMsgPack(const std::string& filename, benchmark::State& state);

// futher improvements add more serialization functions here

// Protobuf
size_t serializeProtoBuf(const testData& data, const std::string& filename, benchmark::State& state);
testData deserializeProtoBuf(const std::string& filename, benchmark::State& state);

// JSON
size_t serializeJson(const testData& data, const std::string& filename, benchmark::State& state);
testData deserializeJson(const std::string& filename, benchmark::State& state);

// FlexBuffers
size_t serializeFlexBuffers(const testData& data, const std::string& filename, benchmark::State& state);
testData deserializeFlexBuffers(const std::string& filename, benchmark::State& state);

// Apache Thrift

size_t serializeApacheThrift(const testData& data, const std::string& filename, benchmark::State& state);
testData deserializeApacheThrift(const std::string& filename, benchmark::State& state);

// FlatBuffers
size_t serializeFlatBuffers(const testData& data, const std::string& filename, benchmark::State& state);
testData deserializeFlatBuffers(const std::string& filename, benchmark::State& state);

}  // namespace serializers