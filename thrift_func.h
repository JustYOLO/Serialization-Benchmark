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
        tStruct.pphtemzf = data.pphtemzf;
        tStruct.gterefev = data.gterefev;
        tStruct.hqixjbhi = data.hqixjbhi;
        tStruct.ygjaoemn = data.ygjaoemn;
        tStruct.tulheqjt = data.tulheqjt;
        tStruct.wkaobqib = data.wkaobqib;
        tStruct.nmjjnyom = data.nmjjnyom;
        tStruct.dgfaaijx = data.dgfaaijx;

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
        data.pphtemzf = tStruct.pphtemzf;
        data.gterefev = tStruct.gterefev;
        data.hqixjbhi = tStruct.hqixjbhi;
        data.ygjaoemn = tStruct.ygjaoemn;
        data.tulheqjt = tStruct.tulheqjt;
        data.wkaobqib = tStruct.wkaobqib;
        data.nmjjnyom = tStruct.nmjjnyom;
        data.dgfaaijx = tStruct.dgfaaijx;
    }
}
