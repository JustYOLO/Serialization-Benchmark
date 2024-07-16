#include "benchmark_struct.h"
#include "ProtoData.pb.h"

namespace proto {
    size_t Serialize(const testData& data, std::vector<char> &serializedData) {
        GOOGLE_PROTOBUF_VERIFY_VERSION; // is it necessary?
        ProtoData protoData;
        protoData.set_uztrathh(data.uztrathh);
        protoData.set_xlcdrebd(data.xlcdrebd);
        protoData.set_svblwglq(data.svblwglq);
        protoData.set_gkesoazh(data.gkesoazh);
        protoData.set_gdnajler(data.gdnajler);
        protoData.set_yzjgzcpl(data.yzjgzcpl);
        protoData.set_ucfkmhfi(data.ucfkmhfi);
        protoData.set_hcfkimtf(data.hcfkimtf);
        size_t size = protoData.ByteSizeLong();
        serializedData.resize(size);
        protoData.SerializeToArray(serializedData.data(), static_cast<int>(size));
        // protoData.SerializeToArray(buffer.data(), static_cast<int>(size));
        // std::ofstream output(filename, std::ios::out | std::ios::binary);
        // if (!protoData.SerializeToOstream(&output)) {
        //     std::cerr << "protobuf: Failed to write data to file." << std::endl;
        // }
        return size;
    }
    void Deserialize(testData& data, std::vector<char> &serializedData, const size_t size) {
        ProtoData protoData;
        protoData.ParseFromArray(serializedData.data(), static_cast<int>(size));
        data.uztrathh = protoData.uztrathh();
        data.xlcdrebd = protoData.xlcdrebd();
        data.svblwglq = protoData.svblwglq();
        data.gkesoazh = protoData.gkesoazh();
        data.gdnajler = protoData.gdnajler();
        data.yzjgzcpl = protoData.yzjgzcpl();
        data.ucfkmhfi = protoData.ucfkmhfi();
        data.hcfkimtf = protoData.hcfkimtf();
    }
}

