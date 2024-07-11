#include "benchmark_struct.h"
#include "ProtoData.pb.h"

namespace proto {
    size_t Serialize(const testData& data, const std::string& filename) {
        GOOGLE_PROTOBUF_VERIFY_VERSION; // is it necessary?
        ProtoData protoData;
        protoData.set_qieezdij(data.qieezdij);
        protoData.set_rbqjhkqq(data.rbqjhkqq);
        protoData.set_tnxueiff(data.tnxueiff);
        protoData.set_wfzxitxa(data.wfzxitxa);
        protoData.set_wjhiporp(data.wjhiporp);
        protoData.set_bntuygoi(data.bntuygoi);
        protoData.set_smxkhuxz(data.smxkhuxz);
        protoData.set_jjomypit(data.jjomypit);
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
        data.qieezdij = protoData.qieezdij();
        data.rbqjhkqq = protoData.rbqjhkqq();
        data.tnxueiff = protoData.tnxueiff();
        data.wfzxitxa = protoData.wfzxitxa();
        data.wjhiporp = protoData.wjhiporp();
        data.bntuygoi = protoData.bntuygoi();
        data.smxkhuxz = protoData.smxkhuxz();
        data.jjomypit = protoData.jjomypit();
    }
}
