#include <flatbuffers/flatbuffers.h>
#include <vector>
#include "benchmark_struct.h"
#include "struct_generated.h"

namespace flat {
    void Serialize(const testData& data, std::vector<uint8_t>& buf) {
        flatbuffers::FlatBufferBuilder builder;
        auto serializedData = CreateflatData(builder, data.pphtemzf, data.gterefev, data.hqixjbhi, data.ygjaoemn, data.tulheqjt, data.wkaobqib, data.nmjjnyom, data.dgfaaijx);
        builder.Finish(serializedData);

        buf.assign(builder.GetBufferPointer(), builder.GetBufferPointer() + builder.GetSize());
    }
    
    void Deserialize(testData& data, const std::vector<uint8_t> &buffer) {
        auto flatData = GetflatData(buffer.data());
        data.pphtemzf = flatData->pphtemzf();
        data.gterefev = flatData->gterefev();
        data.hqixjbhi = flatData->hqixjbhi();
        data.ygjaoemn = flatData->ygjaoemn();
        data.tulheqjt = flatData->tulheqjt();
        data.wkaobqib = flatData->wkaobqib();
        data.nmjjnyom = flatData->nmjjnyom();
        data.dgfaaijx = flatData->dgfaaijx();
        // data.{keys} = flatData->{keys}()->c_str();
    }
}
