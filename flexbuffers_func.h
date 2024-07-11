#include <flatbuffers/flexbuffers.h>
#include "benchmark_struct.h"

namespace flex {
    void Serialize(const testData& data, std::vector<uint8_t> &outBuffer) {
        flexbuffers::Builder builder;

        builder.Map([&]() {
            builder.Int("rxpBVKZm", data.rxpBVKZm);
            builder.Int("IBGMyqVi", data.IBGMyqVi);
            builder.Int("zzGMxurm", data.zzGMxurm);
            builder.Int("FLJfpQwW", data.FLJfpQwW);
            builder.Int("kcgzfQYK", data.kcgzfQYK);
            builder.Int("WCqGIdaV", data.WCqGIdaV);
            builder.Int("kNagacUI", data.kNagacUI);
            builder.Int("BrOHaYcB", data.BrOHaYcB);

        });

        builder.Finish();
        outBuffer = builder.GetBuffer();
    }
    void Deserialize(testData& data, const std::vector<uint8_t> &inBuffer) {
        auto root = flexbuffers::GetRoot(inBuffer).AsMap();
        
        data.rxpBVKZm = root["rxpBVKZm"].AsInt32();
        data.IBGMyqVi = root["IBGMyqVi"].AsInt32();
        data.zzGMxurm = root["zzGMxurm"].AsInt32();
        data.FLJfpQwW = root["FLJfpQwW"].AsInt32();
        data.kcgzfQYK = root["kcgzfQYK"].AsInt32();
        data.WCqGIdaV = root["WCqGIdaV"].AsInt32();
        data.kNagacUI = root["kNagacUI"].AsInt32();
        data.BrOHaYcB = root["BrOHaYcB"].AsInt32();
    }
}
