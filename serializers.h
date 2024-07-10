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

// Add function declarations for other serialization methods here
// For example:
// std::vector<char> serializeProtobuf(const testData& data);
// testData deserializeProtobuf(const std::vector<char>& buffer);

// ... (other serialization methods)

}  // namespace serializers