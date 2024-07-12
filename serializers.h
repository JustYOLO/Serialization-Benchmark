#pragma once
#include "benchmark_struct.h"
#include <vector>
#include <msgpack.hpp>
#include <fstream>

// Include headers for other serialization libraries here

namespace serializers {

// MessagePack
size_t serializeMsgPack(const testData& data, const std::string& filename);
testData deserializeMsgPack(const std::string& filename);

// TODO: add more serialization functions here

// Protobuf
size_t serializeProtoBuf(const testData& data, const std::string& filename);
testData deserializeProtoBuf(const std::string& filename);

// JSON
// size_t serializeJson(const testData& data, const std::string& filename);
// testData deserializeJson(const std::string& filename);

// FlexBuffers
size_t serializeFlexBuffers(const testData& data, const std::string& filename);
testData deserializeFlexBuffers(const std::string& filename);

// Apache Thrift

size_t serializeApacheThrift(const testData& data, const std::string& filename);
testData deserializeApacheThrift(const std::string& filename);

}  // namespace serializers