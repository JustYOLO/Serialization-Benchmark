#include "benchmark_struct.h"
#include "ProtoData.pb.h"

namespace proto {
    size_t Serialize(const testData& data, const std::string& filename) {
        GOOGLE_PROTOBUF_VERIFY_VERSION; // is it necessary?
        ProtoData protoData;
        protoData.set_itpfypwk(data.itpfypwk);
        protoData.set_rwmdhsqd(data.rwmdhsqd);
        protoData.set_trtzcnjk(data.trtzcnjk);
        protoData.set_zifozeef(data.zifozeef);
        protoData.set_jrssogei(data.jrssogei);
        protoData.set_qzagtdun(data.qzagtdun);
        protoData.set_sgcokhhb(data.sgcokhhb);
        protoData.set_bwmmqqsh(data.bwmmqqsh);
        std::ofstream output(filename, std::ios::out | std::ios::binary);
        if (!protoData.SerializeToOstream(&output)) {
            std::cerr << "protobuf: Failed to write data to file." << std::endl;
        }
        return protoData.ByteSizeLong();
    }
    void Deserialize(testData& data, const std::string& filename) {
        std::ifstream input(filename, std::ios::in | std::ios::binary);
        ProtoData protoData;
        if (!protoData.ParseFromIstream(&input)) {
            std::cerr << "protobuf: Failed to read data from file." << std::endl;
        }
        data.itpfypwk = protoData.itpfypwk();
        data.rwmdhsqd = protoData.rwmdhsqd();
        data.trtzcnjk = protoData.trtzcnjk();
        data.zifozeef = protoData.zifozeef();
        data.jrssogei = protoData.jrssogei();
        data.qzagtdun = protoData.qzagtdun();
        data.sgcokhhb = protoData.sgcokhhb();
        data.bwmmqqsh = protoData.bwmmqqsh();
    }
}
