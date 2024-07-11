#include <flatbuffers/flexbuffers.h>
#include "benchmark_struct.h"

namespace flex {
    void Serialize(const testData& data, std::vector<uint8_t> &outBuffer) {
        flexbuffers::Builder builder;

        builder.Map([&]() {
            builder.String("qieezdij", data.qieezdij);
            builder.String("rbqjhkqq", data.rbqjhkqq);
            builder.String("tnxueiff", data.tnxueiff);
            builder.String("wfzxitxa", data.wfzxitxa);
            builder.String("wjhiporp", data.wjhiporp);
            builder.String("bntuygoi", data.bntuygoi);
            builder.String("smxkhuxz", data.smxkhuxz);
            builder.String("jjomypit", data.jjomypit);

        });

        builder.Finish();
        outBuffer = builder.GetBuffer();
    }
    void Deserialize(testData& data, const std::vector<uint8_t> &inBuffer) {
        auto root = flexbuffers::GetRoot(inBuffer).AsMap();
        
        data.qieezdij = root["qieezdij"].AsString().str();
        data.rbqjhkqq = root["rbqjhkqq"].AsString().str();
        data.tnxueiff = root["tnxueiff"].AsString().str();
        data.wfzxitxa = root["wfzxitxa"].AsString().str();
        data.wjhiporp = root["wjhiporp"].AsString().str();
        data.bntuygoi = root["bntuygoi"].AsString().str();
        data.smxkhuxz = root["smxkhuxz"].AsString().str();
        data.jjomypit = root["jjomypit"].AsString().str();
    }
}
