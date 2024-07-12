#include "serializers.h"
#include "flexbuffers_func.h"
#include "protobuf_func.h"
#include "thrift_func.h"
#include "flatbuffers_func.h"
#include "json_func.h"

// TODO: make a uniform read/write and error handling method for all serializers

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
    return proto::Serialize(data, filename);
}
testData deserializeProtoBuf(const std::string& filename) {
    testData data;
    proto::Deserialize(data, filename);
    return data;
}

size_t serializeJson(const testData& data, const std::string& filename) {
    std::string buf;
    json::Serialize(data, buf);
    std::ofstream outFile(filename, std::ios::binary);
    outFile.write(reinterpret_cast<const char *>(buf.data()), buf.size());
    return buf.size();
}

testData deserializeJson(const std::string& filename) {
    std::string buffer;
    std::ifstream inFile(filename, std::ios::binary | std::ios::ate);
    if (inFile) {
        std::streamsize size = inFile.tellg();
        inFile.seekg(0, std::ios::beg);

        buffer.resize(size);
        inFile.read(reinterpret_cast<char *>(buffer.data()), size);
    } else {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
    }

    testData result;
    json::Deserialize(result, buffer);

    return result;

}

    size_t serializeFlexBuffers(const testData& data, const std::string& filename) {
        std::vector<uint8_t> outBuffer;
        flex::Serialize(data, outBuffer);

        std::ofstream outFile(filename, std::ios::binary);
        if (outFile) {
            outFile.write(reinterpret_cast<const char *>(outBuffer.data()), outBuffer.size());
        } else {
            std::cerr << "Failed to open file for writing: " << filename << std::endl;
        }

        return outBuffer.size();
    }

    testData deserializeFlexBuffers(const std::string& filename) {
        std::vector<uint8_t> buffer;
        std::ifstream inFile(filename, std::ios::binary | std::ios::ate);
        if (inFile) {
            std::streamsize size = inFile.tellg();
            inFile.seekg(0, std::ios::beg);

            buffer.resize(size);
            inFile.read(reinterpret_cast<char *>(buffer.data()), size);
        } else {
            std::cerr << "Failed to open file for reading: " << filename << std::endl;
        }

        testData result;
        flex::Deserialize(result, buffer);

        return result;
    }

    size_t serializeApacheThrift(const testData& data, const std::string& filename) {
        std::string serialized_str;
        thrift::Serialize(data, serialized_str);

        std::ofstream outFile(filename, std::ios::binary);
        outFile.write(serialized_str.c_str(), serialized_str.length());
        outFile.close();
        return serialized_str.length();
    }

    testData deserializeApacheThrift(const std::string& filename) {
        testData data;
        std::ifstream inFile(filename, std::ios::binary);
        std::vector<uint8_t> serialData((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        inFile.close();

        thrift::Deserialize(data, serialData);

        return data;
    }
    size_t serializeFlatBuffers(const testData& data, const std::string& filename) {
        std::vector<uint8_t> buf;
        flat::Serialize(data, buf);

        std::ofstream file(filename, std::ios::binary);

        file.write(reinterpret_cast<const char*>(buf.data()), buf.size());
        file.close();
        return buf.size();
    }

    testData deserializeFlatBuffers(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary | std::ios::ate);
        if (!file) {
            throw std::runtime_error("Unable to open file for reading: " + filename);
        }

        std::streamsize size = file.tellg();
        file.seekg(0, std::ios::beg);

        std::vector<uint8_t> buffer(size);
        if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
            throw std::runtime_error("Failed to read file: " + filename);
        }

        testData data;
        flat::Deserialize(data, buffer);

        return data;

    }


}  // namespace serializers