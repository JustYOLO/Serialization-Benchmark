#include <flatbuffers/flexbuffers.h>
#include "benchmark_struct.h"

namespace flex {
    void Serialize(const testData& data, std::vector<uint8_t> &outBuffer) {
        flexbuffers::Builder builder;

        builder.Map([&]() {
            builder.Int("pphtemzf", data.pphtemzf);
            builder.Int("gterefev", data.gterefev);
            builder.Int("hqixjbhi", data.hqixjbhi);
            builder.Int("ygjaoemn", data.ygjaoemn);
            builder.Int("tulheqjt", data.tulheqjt);
            builder.Int("wkaobqib", data.wkaobqib);
            builder.Int("nmjjnyom", data.nmjjnyom);
            builder.Int("dgfaaijx", data.dgfaaijx);

        });

        builder.Finish();
        outBuffer = builder.GetBuffer();
    }
    void Deserialize(testData& data, const std::vector<uint8_t> &inBuffer) {
        auto root = flexbuffers::GetRoot(inBuffer).AsMap();
        
        data.pphtemzf = root["pphtemzf"].AsInt32();
        data.gterefev = root["gterefev"].AsInt32();
        data.hqixjbhi = root["hqixjbhi"].AsInt32();
        data.ygjaoemn = root["ygjaoemn"].AsInt32();
        data.tulheqjt = root["tulheqjt"].AsInt32();
        data.wkaobqib = root["wkaobqib"].AsInt32();
        data.nmjjnyom = root["nmjjnyom"].AsInt32();
        data.dgfaaijx = root["dgfaaijx"].AsInt32();
    }
}
