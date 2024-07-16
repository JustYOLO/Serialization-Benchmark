#include <nlohmann/json.hpp>
#include "benchmark_struct.h"
using jsonStruct = nlohmann::json;

namespace json {
    void Serialize(const testData& data, std::string& buf) {
    jsonStruct j = {
        // {"{key}", data.{key}},
        {"nscpwcmu", data.nscpwcmu},
        {"nwvrdaek", data.nwvrdaek},
        {"fuzvztzr", data.fuzvztzr},
        {"uykpiqcm", data.uykpiqcm},
        {"ygxdpvnv", data.ygxdpvnv},
        {"muzxzgja", data.muzxzgja},
        {"sweazing", data.sweazing},
        {"sutsmvdd", data.sutsmvdd},
        };
        buf =  j.dump(4); // The '4' argument adds indentation for pretty-printing
    }

    void Deserialize(testData& data, const std::string& buf) {
        jsonStruct j = jsonStruct::parse(buf);

        // data.{key} = j["{key}"];
        data.nscpwcmu = j["nscpwcmu"];
        data.nwvrdaek = j["nwvrdaek"];
        data.fuzvztzr = j["fuzvztzr"];
        data.uykpiqcm = j["uykpiqcm"];
        data.ygxdpvnv = j["ygxdpvnv"];
        data.muzxzgja = j["muzxzgja"];
        data.sweazing = j["sweazing"];
        data.sutsmvdd = j["sutsmvdd"];
    }
}
