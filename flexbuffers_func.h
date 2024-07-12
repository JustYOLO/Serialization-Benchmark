#include <flatbuffers/flexbuffers.h>
#include "benchmark_struct.h"

namespace flex {
    void Serialize(const testData& data, std::vector<uint8_t> &outBuffer) {
        flexbuffers::Builder builder;

        builder.Map([&]() {
            builder.Int("itpfypwk", data.itpfypwk);
            builder.Int("rwmdhsqd", data.rwmdhsqd);
            builder.Int("trtzcnjk", data.trtzcnjk);
            builder.Int("zifozeef", data.zifozeef);
            builder.Int("jrssogei", data.jrssogei);
            builder.Int("qzagtdun", data.qzagtdun);
            builder.Int("sgcokhhb", data.sgcokhhb);
            builder.Int("bwmmqqsh", data.bwmmqqsh);

        });

        builder.Finish();
        outBuffer = builder.GetBuffer();
    }
    void Deserialize(testData& data, const std::vector<uint8_t> &inBuffer) {
        auto root = flexbuffers::GetRoot(inBuffer).AsMap();
        
        data.itpfypwk = root["itpfypwk"].AsInt32();
        data.rwmdhsqd = root["rwmdhsqd"].AsInt32();
        data.trtzcnjk = root["trtzcnjk"].AsInt32();
        data.zifozeef = root["zifozeef"].AsInt32();
        data.jrssogei = root["jrssogei"].AsInt32();
        data.qzagtdun = root["qzagtdun"].AsInt32();
        data.sgcokhhb = root["sgcokhhb"].AsInt32();
        data.bwmmqqsh = root["bwmmqqsh"].AsInt32();
    }
}
