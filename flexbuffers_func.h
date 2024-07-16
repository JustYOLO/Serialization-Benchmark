#include <flatbuffers/flexbuffers.h>
#include "benchmark_struct.h"

namespace flex {
    size_t Serialize(const testData& data, std::vector<char> &serializedData) {
        flexbuffers::Builder builder;

        builder.Map([&]() {
            builder.String("uztrathh", data.uztrathh);
            builder.String("xlcdrebd", data.xlcdrebd);
            builder.String("svblwglq", data.svblwglq);
            builder.String("gkesoazh", data.gkesoazh);
            builder.String("gdnajler", data.gdnajler);
            builder.String("yzjgzcpl", data.yzjgzcpl);
            builder.String("ucfkmhfi", data.ucfkmhfi);
            builder.String("hcfkimtf", data.hcfkimtf);
        });
        builder.Finish();
        std::vector<uint8_t> outBuffer;
        outBuffer = builder.GetBuffer();
        serializedData.resize(outBuffer.size());
        std::memcpy(serializedData.data(), outBuffer.data(), outBuffer.size());
        return outBuffer.size();
    }
    void Deserialize(testData& data, std::vector<char> &serializedData, const size_t size) {
        auto root = flexbuffers::GetRoot(reinterpret_cast<const uint8_t*>(serializedData.data()), size).AsMap();

        data.uztrathh = root["uztrathh"].AsString().str();
        data.xlcdrebd = root["xlcdrebd"].AsString().str();
        data.svblwglq = root["svblwglq"].AsString().str();
        data.gkesoazh = root["gkesoazh"].AsString().str();
        data.gdnajler = root["gdnajler"].AsString().str();
        data.yzjgzcpl = root["yzjgzcpl"].AsString().str();
        data.ucfkmhfi = root["ucfkmhfi"].AsString().str();
        data.hcfkimtf = root["hcfkimtf"].AsString().str();
    }
}
