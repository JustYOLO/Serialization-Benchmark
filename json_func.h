#include <nlohmann/json.hpp>
#include "benchmark_struct.h"
using jsonStruct = nlohmann::json;

namespace json {
    void Serialize(const testData& data, std::string& buf) {
    jsonStruct j = {
        // {"{key}", data.{key}},
        {"pphtemzf", data.pphtemzf},
        {"gterefev", data.gterefev},
        {"hqixjbhi", data.hqixjbhi},
        {"ygjaoemn", data.ygjaoemn},
        {"tulheqjt", data.tulheqjt},
        {"wkaobqib", data.wkaobqib},
        {"nmjjnyom", data.nmjjnyom},
        {"dgfaaijx", data.dgfaaijx},
        };
        buf =  j.dump(4); // The '4' argument adds indentation for pretty-printing
    }

    void Deserialize(testData& data, const std::string& buf) {
        jsonStruct j = jsonStruct::parse(buf);

        // data.{key} = j["{key}"];
        data.pphtemzf = j["pphtemzf"];
        data.gterefev = j["gterefev"];
        data.hqixjbhi = j["hqixjbhi"];
        data.ygjaoemn = j["ygjaoemn"];
        data.tulheqjt = j["tulheqjt"];
        data.wkaobqib = j["wkaobqib"];
        data.nmjjnyom = j["nmjjnyom"];
        data.dgfaaijx = j["dgfaaijx"];
    }
}
