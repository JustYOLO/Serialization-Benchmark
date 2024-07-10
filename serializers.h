#pragma once
#include "benchmark_struct.h"
#include <vector>
#include <msgpack.hpp>
#include <fstream>
#include "testData.pb.h"

// Include headers for other serialization libraries here

namespace serializers {

// MessagePack
size_t serializeMsgPack(const testData& data, const std::string& filename);
testData deserializeMsgPack(const std::string& filename);

size_t serializeProtoBuf(const testData& data, const std::string& filename);
testData deserializeProtoBuf(const std::string& filename);

size_t serializeJson(const testData& data, const std::string& filename);
testData deserializeJson(const std::string& filename);

}  // namespace serializers