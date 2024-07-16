#include <nlohmann/json.hpp>
#include "benchmark_struct.h"
using jsonStruct = nlohmann::json;

namespace json {
    size_t Serialize(const testData& data, std::vector<char> &serializedData) {
    jsonStruct j = {
        // {"{key}", data.{key}},
        {"uztrathh", data.uztrathh},
        {"xlcdrebd", data.xlcdrebd},
        {"svblwglq", data.svblwglq},
        {"gkesoazh", data.gkesoazh},
        {"gdnajler", data.gdnajler},
        {"yzjgzcpl", data.yzjgzcpl},
        {"ucfkmhfi", data.ucfkmhfi},
        {"hcfkimtf", data.hcfkimtf},
        };
        std::string buf =  j.dump(4);
        serializedData.resize(buf.size());
        std::memcpy(serializedData.data(), buf.c_str(), buf.size());
        return buf.size();
    }

    void Deserialize(testData& data, std::vector<char> &serializedData, const size_t size) {
        jsonStruct j = jsonStruct::parse(serializedData);

        // data.{key} = j["{key}"];
        data.uztrathh = j["uztrathh"];
        data.xlcdrebd = j["xlcdrebd"];
        data.svblwglq = j["svblwglq"];
        data.gkesoazh = j["gkesoazh"];
        data.gdnajler = j["gdnajler"];
        data.yzjgzcpl = j["yzjgzcpl"];
        data.ucfkmhfi = j["ucfkmhfi"];
        data.hcfkimtf = j["hcfkimtf"];
    }
}
