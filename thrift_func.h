#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <vector>
#include "gen-cpp/struct_types.h"
#include "benchmark_struct.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

namespace thrift {
    size_t Serialize(const testData& data, std::vector<char> &serializedData) {
        TStruct tStruct;
        tStruct.uztrathh = data.uztrathh;
        tStruct.xlcdrebd = data.xlcdrebd;
        tStruct.svblwglq = data.svblwglq;
        tStruct.gkesoazh = data.gkesoazh;
        tStruct.gdnajler = data.gdnajler;
        tStruct.yzjgzcpl = data.yzjgzcpl;
        tStruct.ucfkmhfi = data.ucfkmhfi;
        tStruct.hcfkimtf = data.hcfkimtf;


        std::shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
        std::shared_ptr<TBinaryProtocol> protocol(new TBinaryProtocol(buffer));

        tStruct.write(protocol.get());
        size_t size = buffer->getBufferSize();

        serializedData.resize(size);
        std::memcpy(serializedData.data(), buffer->getBufferAsString().c_str(), size);
        return size;
    }

    void Deserialize(testData& data, std::vector<char> &serializedData, const size_t size) {
        std::shared_ptr<TMemoryBuffer> bufferIn(new TMemoryBuffer());
        bufferIn->write((uint8_t*)(serializedData.data()), size);
        std::shared_ptr<TBinaryProtocol> protocolIn(new TBinaryProtocol(bufferIn));

        TStruct tStruct;
        tStruct.read(protocolIn.get());
        data.uztrathh = tStruct.uztrathh;
        data.xlcdrebd = tStruct.xlcdrebd;
        data.svblwglq = tStruct.svblwglq;
        data.gkesoazh = tStruct.gkesoazh;
        data.gdnajler = tStruct.gdnajler;
        data.yzjgzcpl = tStruct.yzjgzcpl;
        data.ucfkmhfi = tStruct.ucfkmhfi;
        data.hcfkimtf = tStruct.hcfkimtf;
    }
}
