#include <benchmark/benchmark.h>
#include "serializers.h"
#include "flexbuffers_func.h"
#include "protobuf_func.h"
#include "thrift_func.h"
#include "flatbuffers_func.h"
#include "json_func.h"

// TODO: make a uniform read/write and error handling method for all serializers

namespace serializers {

    size_t serializeMsgPack(const testData& data, const std::string& filename, benchmark::State& state) {
        msgpack::sbuffer sbuf;
        msgpack::pack(sbuf, data);
        state.PauseTiming();
        std::ofstream file(filename, std::ios::binary);
        if(!file) {
            throw std::runtime_error("Unable to open/create file for writing");
        }
        
        file.write(sbuf.data(), sbuf.size());
        file.close();

        std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
        state.ResumeTiming();
        return in.tellg();
    }

    testData deserializeMsgPack(const std::string& filename, benchmark::State& state) {
        state.PauseTiming();
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
        state.ResumeTiming();
        msgpack::object_handle oh = msgpack::unpack(buffer.data(), buffer.size());
        testData result;
        oh.get().convert(result);

        return result;
    }

    size_t serializeProtoBuf(const testData& data, const std::string& filename, benchmark::State& state) {
        std::vector<uint8_t> buffer;
        proto::Serialize(data, buffer);
        state.PauseTiming();
        std::ofstream outFile(filename, std::ios::binary);
        if (!outFile) {
            std::cout << "Failed to open file for writing: " << filename << std::endl;
        }
        outFile.write(reinterpret_cast<const char *>(buffer.data()), buffer.size());
        outFile.close();
        state.ResumeTiming();
        return buffer.size();
    }
    testData deserializeProtoBuf(const std::string& filename, benchmark::State& state) {
        state.PauseTiming();
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

        state.ResumeTiming();
        testData data;
        proto::Deserialize(data, buffer);
        return data;
    }

    size_t serializeJson(const testData& data, const std::string& filename, benchmark::State& state) {
        std::string buf;
        json::Serialize(data, buf);
        state.PauseTiming();
        std::ofstream outFile(filename, std::ios::binary);
        outFile.write(reinterpret_cast<const char *>(buf.data()), buf.size());
        state.ResumeTiming();
        return buf.size();
    }

    testData deserializeJson(const std::string& filename, benchmark::State& state) {
        state.PauseTiming();
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

        state.ResumeTiming();
        testData result;
        json::Deserialize(result, buffer);

        return result;

    }

    size_t serializeFlexBuffers(const testData& data, const std::string& filename, benchmark::State& state) {
        std::vector<uint8_t> outBuffer;
        flex::Serialize(data, outBuffer);
        state.PauseTiming();
        std::ofstream outFile(filename, std::ios::binary);
        if (outFile) {
            outFile.write(reinterpret_cast<const char *>(outBuffer.data()), outBuffer.size());
        } else {
            std::cerr << "Failed to open file for writing: " << filename << std::endl;
        }
        state.ResumeTiming();
        return outBuffer.size();
    }

    testData deserializeFlexBuffers(const std::string& filename, benchmark::State& state) {
        state.PauseTiming();
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
        state.ResumeTiming();

        testData result;
        flex::Deserialize(result, buffer);

        return result;
    }

    size_t serializeApacheThrift(const testData& data, const std::string& filename, benchmark::State& state) {
        std::string serialized_str;
        thrift::Serialize(data, serialized_str);
        state.PauseTiming();
        std::ofstream outFile(filename, std::ios::binary);
        outFile.write(serialized_str.c_str(), serialized_str.length());
        outFile.close();
        state.ResumeTiming();
        return serialized_str.length();
    }

    testData deserializeApacheThrift(const std::string& filename, benchmark::State& state) {
        testData data;
        state.PauseTiming();
        std::ifstream inFile(filename, std::ios::binary);
        std::vector<uint8_t> serialData((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        inFile.close();
        state.ResumeTiming();
        thrift::Deserialize(data, serialData);

        return data;
    }

    size_t serializeFlatBuffers(const testData& data, const std::string& filename, benchmark::State& state) {
        std::vector<uint8_t> buf;
        flat::Serialize(data, buf);

        state.PauseTiming();
        std::ofstream file(filename, std::ios::binary);

        file.write(reinterpret_cast<const char*>(buf.data()), buf.size());
        file.close();
        state.ResumeTiming();
        return buf.size();
    }

    testData deserializeFlatBuffers(const std::string& filename, benchmark::State& state) {
        state.PauseTiming();
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
        state.ResumeTiming();
        testData data;
        flat::Deserialize(data, buffer);

        return data;

    }


}  // namespace serializers