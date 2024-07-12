#include "benchmark_struct.h"
#include "ProtoData.pb.h"

namespace proto {
    size_t Serialize(const testData& data, const std::string& filename) {
        GOOGLE_PROTOBUF_VERIFY_VERSION; // is it necessary?
        ProtoData protoData;
        protoData.set_pphtemzf(data.pphtemzf);
        protoData.set_gterefev(data.gterefev);
        protoData.set_hqixjbhi(data.hqixjbhi);
        protoData.set_ygjaoemn(data.ygjaoemn);
        protoData.set_tulheqjt(data.tulheqjt);
        protoData.set_wkaobqib(data.wkaobqib);
        protoData.set_nmjjnyom(data.nmjjnyom);
        protoData.set_dgfaaijx(data.dgfaaijx);
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
        data.pphtemzf = protoData.pphtemzf();
        data.gterefev = protoData.gterefev();
        data.hqixjbhi = protoData.hqixjbhi();
        data.ygjaoemn = protoData.ygjaoemn();
        data.tulheqjt = protoData.tulheqjt();
        data.wkaobqib = protoData.wkaobqib();
        data.nmjjnyom = protoData.nmjjnyom();
        data.dgfaaijx = protoData.dgfaaijx();
    }
}
