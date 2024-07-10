#include "serializers.h"

namespace serializers {

size_t serializeMsgPack(const testData& data, const std::string& filename) {
    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, data);
    std::ofstream file(filename, std::ios::binary);
    if(!file) {
        throw std::runtime_error("Unable to open/create file for writing");
    }
    
    file.write(sbuf.data(), sbuf.size());
    file.close();

    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

testData deserializeMsgPack(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) {
        throw std::runtime_error("Unable to open file for reading");
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read the entire file into a vector
    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size)) {
        throw std::runtime_error("Unable to read file");
    }

    // Deserialize the data
    msgpack::object_handle oh = msgpack::unpack(buffer.data(), buffer.size());
    testData result;
    oh.get().convert(result);

    return result;
}

size_t serializeProtoBuf(const testData& data, const std::string& filename) {
    // TODO: Implement this function
}
testData deserializeProtoBuf(const std::string& filename) {
    // TODO: Implement this function
}

size_t serializeJson(const testData& data, const std::string& filename) {
    // TODO: how about using std::map (?)
}

testData deserializeJson(const std::string& filename) {

}


}  // namespace serializers