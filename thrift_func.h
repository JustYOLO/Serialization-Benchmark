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
        tStruct.itpfypwk = data.itpfypwk;
        tStruct.rwmdhsqd = data.rwmdhsqd;
        tStruct.trtzcnjk = data.trtzcnjk;
        tStruct.zifozeef = data.zifozeef;
        tStruct.jrssogei = data.jrssogei;
        tStruct.qzagtdun = data.qzagtdun;
        tStruct.sgcokhhb = data.sgcokhhb;
        tStruct.bwmmqqsh = data.bwmmqqsh;

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
        data.itpfypwk = tStruct.itpfypwk;
        data.rwmdhsqd = tStruct.rwmdhsqd;
        data.trtzcnjk = tStruct.trtzcnjk;
        data.zifozeef = tStruct.zifozeef;
        data.jrssogei = tStruct.jrssogei;
        data.qzagtdun = tStruct.qzagtdun;
        data.sgcokhhb = tStruct.sgcokhhb;
        data.bwmmqqsh = tStruct.bwmmqqsh;
    }
}
