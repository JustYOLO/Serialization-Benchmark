#include <flatbuffers/flatbuffers.h>
#include <vector>
#include "benchmark_struct.h"
#include "struct_generated.h"

namespace flat {
    void Serialize(const testData& data, std::vector<uint8_t>& buf) {
        flatbuffers::FlatBufferBuilder builder;
        std::vector<flatbuffers::Offset<flatbuffers::String>> keys;
        keys.push_back(builder.CreateString(data.nscpwcmu));
        keys.push_back(builder.CreateString(data.nwvrdaek));
        keys.push_back(builder.CreateString(data.fuzvztzr));
        keys.push_back(builder.CreateString(data.uykpiqcm));
        keys.push_back(builder.CreateString(data.ygxdpvnv));
        keys.push_back(builder.CreateString(data.muzxzgja));
        keys.push_back(builder.CreateString(data.sweazing));
        keys.push_back(builder.CreateString(data.sutsmvdd));
        auto serializedData = CreateflatData(builder, keys[0], keys[1], keys[2], keys[3], keys[4], keys[5], keys[6], keys[7]);
        builder.Finish(serializedData);

        buf.assign(builder.GetBufferPointer(), builder.GetBufferPointer() + builder.GetSize());
    }
    
    void Deserialize(testData& data, const std::vector<uint8_t> &buffer) {
        auto flatData = GetflatData(buffer.data());
        data.nscpwcmu = flatData->nscpwcmu()->str();
        data.nwvrdaek = flatData->nwvrdaek()->str();
        data.fuzvztzr = flatData->fuzvztzr()->str();
        data.uykpiqcm = flatData->uykpiqcm()->str();
        data.ygxdpvnv = flatData->ygxdpvnv()->str();
        data.muzxzgja = flatData->muzxzgja()->str();
        data.sweazing = flatData->sweazing()->str();
        data.sutsmvdd = flatData->sutsmvdd()->str();
        // data.{keys} = flatData->{keys}()->c_str();
    }
}
