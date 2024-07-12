#include <nlohmann/json.hpp>
#include "benchmark_struct.h"
using jsonStruct = nlohmann::json;

namespace json {
    void Serialize(const testData& data, std::string& buf) {
    jsonStruct j = {
        // {"{key}", data.{key}},
        {"kzgiwgrw", data.kzgiwgrw},
        {"dezjobnz", data.dezjobnz},
        {"ieremuco", data.ieremuco},
        {"uesgdftd", data.uesgdftd},
        {"dmstvxix", data.dmstvxix},
        {"pyonuzzg", data.pyonuzzg},
        {"tilpdtek", data.tilpdtek},
        {"qswdlcdc", data.qswdlcdc},
        {"xljaldlb", data.xljaldlb},
        {"sfjsktjp", data.sfjsktjp},
        {"knapjxna", data.knapjxna},
        {"anlawttq", data.anlawttq},
        {"nllzxvpp", data.nllzxvpp},
        {"tyfotgbe", data.tyfotgbe},
        {"flnkscdj", data.flnkscdj},
        {"mukwbnfx", data.mukwbnfx},
        {"laxqtwmt", data.laxqtwmt},
        {"hcperyup", data.hcperyup},
        {"qdplqouo", data.qdplqouo},
        {"oogbawct", data.oogbawct},
        {"nnwgvima", data.nnwgvima},
        {"nwuzhpdb", data.nwuzhpdb},
        {"tmzovmhd", data.tmzovmhd},
        {"rsnrnizf", data.rsnrnizf},
        {"ivjhkfwa", data.ivjhkfwa},
        {"eymlquhq", data.eymlquhq},
        {"lhfqsqrf", data.lhfqsqrf},
        {"rrzickmr", data.rrzickmr},
        {"esdkloyo", data.esdkloyo},
        {"khbvphfk", data.khbvphfk},
        {"xvfeefth", data.xvfeefth},
        {"iflmxuur", data.iflmxuur},
        {"zmbwqjnz", data.zmbwqjnz},
        {"ikulmxip", data.ikulmxip},
        {"uscevqrf", data.uscevqrf},
        {"ocvwicgv", data.ocvwicgv},
        {"lcdsulto", data.lcdsulto},
        {"pumpatfl", data.pumpatfl},
        {"lwclnihb", data.lwclnihb},
        {"errgsaoi", data.errgsaoi},
        {"gyhlnjwh", data.gyhlnjwh},
        {"ehkcedtv", data.ehkcedtv},
        {"vdfhhycn", data.vdfhhycn},
        {"ozhwdmpw", data.ozhwdmpw},
        {"ykdhluxn", data.ykdhluxn},
        {"ihnwjuhw", data.ihnwjuhw},
        {"umpbntqn", data.umpbntqn},
        {"oaizyhlt", data.oaizyhlt},
        {"yyzmaoxe", data.yyzmaoxe},
        {"ewkwedkd", data.ewkwedkd},
        {"nexgmjdm", data.nexgmjdm},
        {"wwlqjcvq", data.wwlqjcvq},
        {"zppxtpkk", data.zppxtpkk},
        {"iaodurzp", data.iaodurzp},
        {"ifcvayzb", data.ifcvayzb},
        {"cfzsnfwn", data.cfzsnfwn},
        {"uhzxtshi", data.uhzxtshi},
        {"osyexwsp", data.osyexwsp},
        {"ojmmuukk", data.ojmmuukk},
        {"hadshozy", data.hadshozy},
        {"wtjmxxrx", data.wtjmxxrx},
        {"zrsytazc", data.zrsytazc},
        {"oxbqbuvz", data.oxbqbuvz},
        {"khodeqzz", data.khodeqzz},
        };
        buf =  j.dump(4); // The '4' argument adds indentation for pretty-printing
    }

    void Deserialize(testData& data, const std::string& buf) {
        jsonStruct j = jsonStruct::parse(buf);

        // data.{key} = j["{key}"];
        data.kzgiwgrw = j["kzgiwgrw"];
        data.dezjobnz = j["dezjobnz"];
        data.ieremuco = j["ieremuco"];
        data.uesgdftd = j["uesgdftd"];
        data.dmstvxix = j["dmstvxix"];
        data.pyonuzzg = j["pyonuzzg"];
        data.tilpdtek = j["tilpdtek"];
        data.qswdlcdc = j["qswdlcdc"];
        data.xljaldlb = j["xljaldlb"];
        data.sfjsktjp = j["sfjsktjp"];
        data.knapjxna = j["knapjxna"];
        data.anlawttq = j["anlawttq"];
        data.nllzxvpp = j["nllzxvpp"];
        data.tyfotgbe = j["tyfotgbe"];
        data.flnkscdj = j["flnkscdj"];
        data.mukwbnfx = j["mukwbnfx"];
        data.laxqtwmt = j["laxqtwmt"];
        data.hcperyup = j["hcperyup"];
        data.qdplqouo = j["qdplqouo"];
        data.oogbawct = j["oogbawct"];
        data.nnwgvima = j["nnwgvima"];
        data.nwuzhpdb = j["nwuzhpdb"];
        data.tmzovmhd = j["tmzovmhd"];
        data.rsnrnizf = j["rsnrnizf"];
        data.ivjhkfwa = j["ivjhkfwa"];
        data.eymlquhq = j["eymlquhq"];
        data.lhfqsqrf = j["lhfqsqrf"];
        data.rrzickmr = j["rrzickmr"];
        data.esdkloyo = j["esdkloyo"];
        data.khbvphfk = j["khbvphfk"];
        data.xvfeefth = j["xvfeefth"];
        data.iflmxuur = j["iflmxuur"];
        data.zmbwqjnz = j["zmbwqjnz"];
        data.ikulmxip = j["ikulmxip"];
        data.uscevqrf = j["uscevqrf"];
        data.ocvwicgv = j["ocvwicgv"];
        data.lcdsulto = j["lcdsulto"];
        data.pumpatfl = j["pumpatfl"];
        data.lwclnihb = j["lwclnihb"];
        data.errgsaoi = j["errgsaoi"];
        data.gyhlnjwh = j["gyhlnjwh"];
        data.ehkcedtv = j["ehkcedtv"];
        data.vdfhhycn = j["vdfhhycn"];
        data.ozhwdmpw = j["ozhwdmpw"];
        data.ykdhluxn = j["ykdhluxn"];
        data.ihnwjuhw = j["ihnwjuhw"];
        data.umpbntqn = j["umpbntqn"];
        data.oaizyhlt = j["oaizyhlt"];
        data.yyzmaoxe = j["yyzmaoxe"];
        data.ewkwedkd = j["ewkwedkd"];
        data.nexgmjdm = j["nexgmjdm"];
        data.wwlqjcvq = j["wwlqjcvq"];
        data.zppxtpkk = j["zppxtpkk"];
        data.iaodurzp = j["iaodurzp"];
        data.ifcvayzb = j["ifcvayzb"];
        data.cfzsnfwn = j["cfzsnfwn"];
        data.uhzxtshi = j["uhzxtshi"];
        data.osyexwsp = j["osyexwsp"];
        data.ojmmuukk = j["ojmmuukk"];
        data.hadshozy = j["hadshozy"];
        data.wtjmxxrx = j["wtjmxxrx"];
        data.zrsytazc = j["zrsytazc"];
        data.oxbqbuvz = j["oxbqbuvz"];
        data.khodeqzz = j["khodeqzz"];
    }
}
