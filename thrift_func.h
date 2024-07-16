#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <vector>
#include "gen-cpp/struct_types.h"
#include "benchmark_struct.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

namespace thrift {
    void Serialize(const testData& data, std::string& serialized_str) {
        TStruct tStruct;
        tStruct.nscpwcmu = data.nscpwcmu;
        tStruct.nwvrdaek = data.nwvrdaek;
        tStruct.fuzvztzr = data.fuzvztzr;
        tStruct.uykpiqcm = data.uykpiqcm;
        tStruct.ygxdpvnv = data.ygxdpvnv;
        tStruct.muzxzgja = data.muzxzgja;
        tStruct.sweazing = data.sweazing;
        tStruct.sutsmvdd = data.sutsmvdd;

        std::shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
        std::shared_ptr<TBinaryProtocol> protocol(new TBinaryProtocol(buffer));

        tStruct.write(protocol.get());

        // uint8_t* serializedData;
        // buffer->getBuffer(&serializedData, &dataSize);
        serialized_str = buffer->getBufferAsString();
    }

    void Deserialize(testData& data, std::vector<uint8_t>& inBuffer) {
        std::shared_ptr<TMemoryBuffer> bufferIn(new TMemoryBuffer());
        bufferIn->resetBuffer(inBuffer.data(), inBuffer.size());
        std::shared_ptr<TBinaryProtocol> protocolIn(new TBinaryProtocol(bufferIn));

        TStruct tStruct;
        tStruct.read(protocolIn.get());
        data.nscpwcmu = tStruct.nscpwcmu;
        data.nwvrdaek = tStruct.nwvrdaek;
        data.fuzvztzr = tStruct.fuzvztzr;
        data.uykpiqcm = tStruct.uykpiqcm;
        data.ygxdpvnv = tStruct.ygxdpvnv;
        data.muzxzgja = tStruct.muzxzgja;
        data.sweazing = tStruct.sweazing;
        data.sutsmvdd = tStruct.sutsmvdd;
    }
}
