#include "benchmark_struct.h"
#include "ProtoData.pb.h"

namespace proto {
    size_t Serialize(const testData& data, std::vector<uint8_t>& buffer) {
        GOOGLE_PROTOBUF_VERIFY_VERSION; // is it necessary?
        ProtoData protoData;
        protoData.set_nscpwcmu(data.nscpwcmu);
        protoData.set_nwvrdaek(data.nwvrdaek);
        protoData.set_fuzvztzr(data.fuzvztzr);
        protoData.set_uykpiqcm(data.uykpiqcm);
        protoData.set_ygxdpvnv(data.ygxdpvnv);
        protoData.set_muzxzgja(data.muzxzgja);
        protoData.set_sweazing(data.sweazing);
        protoData.set_sutsmvdd(data.sutsmvdd);
        size_t size = protoData.ByteSizeLong();
        buffer.resize(size);
        protoData.SerializeToArray(buffer.data(), static_cast<int>(size));
        // std::ofstream output(filename, std::ios::out | std::ios::binary);
        // if (!protoData.SerializeToOstream(&output)) {
        //     std::cerr << "protobuf: Failed to write data to file." << std::endl;
        // }
        return size;
    }
    void Deserialize(testData& data, const std::vector<uint8_t>& buffer) {
        ProtoData protoData;
        protoData.ParseFromArray(buffer.data(), static_cast<int>(buffer.size()));
        data.nscpwcmu = protoData.nscpwcmu();
        data.nwvrdaek = protoData.nwvrdaek();
        data.fuzvztzr = protoData.fuzvztzr();
        data.uykpiqcm = protoData.uykpiqcm();
        data.ygxdpvnv = protoData.ygxdpvnv();
        data.muzxzgja = protoData.muzxzgja();
        data.sweazing = protoData.sweazing();
        data.sutsmvdd = protoData.sutsmvdd();
    }
}
