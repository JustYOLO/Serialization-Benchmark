#include <flatbuffers/flexbuffers.h>
#include "benchmark_struct.h"

namespace flex {
    void Serialize(const testData& data, std::vector<uint8_t> &outBuffer) {
        flexbuffers::Builder builder;

        builder.Map([&]() {
            builder.String("nscpwcmu", data.nscpwcmu);
            builder.String("nwvrdaek", data.nwvrdaek);
            builder.String("fuzvztzr", data.fuzvztzr);
            builder.String("uykpiqcm", data.uykpiqcm);
            builder.String("ygxdpvnv", data.ygxdpvnv);
            builder.String("muzxzgja", data.muzxzgja);
            builder.String("sweazing", data.sweazing);
            builder.String("sutsmvdd", data.sutsmvdd);

        });

        builder.Finish();
        outBuffer = builder.GetBuffer();
    }
    void Deserialize(testData& data, const std::vector<uint8_t> &inBuffer) {
        auto root = flexbuffers::GetRoot(inBuffer).AsMap();
        
        data.nscpwcmu = root["nscpwcmu"].AsString().str();
        data.nwvrdaek = root["nwvrdaek"].AsString().str();
        data.fuzvztzr = root["fuzvztzr"].AsString().str();
        data.uykpiqcm = root["uykpiqcm"].AsString().str();
        data.ygxdpvnv = root["ygxdpvnv"].AsString().str();
        data.muzxzgja = root["muzxzgja"].AsString().str();
        data.sweazing = root["sweazing"].AsString().str();
        data.sutsmvdd = root["sutsmvdd"].AsString().str();
    }
}
