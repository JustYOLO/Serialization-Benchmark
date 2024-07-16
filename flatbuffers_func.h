#include <flatbuffers/flatbuffers.h>
#include <vector>
#include "benchmark_struct.h"
#include "struct_generated.h"

namespace flat {
    size_t Serialize(const testData& data, std::vector<char> &serializedData) {
        flatbuffers::FlatBufferBuilder builder;
        std::vector<flatbuffers::Offset<flatbuffers::String>> keys;
        keys.push_back(builder.CreateString(data.uztrathh));
        keys.push_back(builder.CreateString(data.xlcdrebd));
        keys.push_back(builder.CreateString(data.svblwglq));
        keys.push_back(builder.CreateString(data.gkesoazh));
        keys.push_back(builder.CreateString(data.gdnajler));
        keys.push_back(builder.CreateString(data.yzjgzcpl));
        keys.push_back(builder.CreateString(data.ucfkmhfi));
        keys.push_back(builder.CreateString(data.hcfkimtf));
        auto result = CreateflatData(builder, keys[0], keys[1], keys[2], keys[3], keys[4], keys[5], keys[6], keys[7]);
        builder.Finish(result);
        serializedData.resize(builder.GetSize());
        std::memcpy(serializedData.data(), builder.GetBufferPointer(), builder.GetSize());
        return builder.GetSize();
    }
    
    void Deserialize(testData& data, std::vector<char> &serializedData, const size_t size) {
        auto flatData = GetflatData(serializedData.data());
        data.uztrathh = flatData->uztrathh()->str();
        data.xlcdrebd = flatData->xlcdrebd()->str();
        data.svblwglq = flatData->svblwglq()->str();
        data.gkesoazh = flatData->gkesoazh()->str();
        data.gdnajler = flatData->gdnajler()->str();
        data.yzjgzcpl = flatData->yzjgzcpl()->str();
        data.ucfkmhfi = flatData->ucfkmhfi()->str();
        data.hcfkimtf = flatData->hcfkimtf()->str();
        // data.{keys} = flatData->{keys}()->c_str();
    }
}
