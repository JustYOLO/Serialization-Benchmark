#include <flatbuffers/flexbuffers.h>
#include "benchmark_struct.h"

namespace flex {
    void Serialize(const testData& data, std::vector<uint8_t> &outBuffer) {
        flexbuffers::Builder builder;

        builder.Map([&]() {
            builder.String("kzgiwgrw", data.kzgiwgrw);
            builder.String("dezjobnz", data.dezjobnz);
            builder.String("ieremuco", data.ieremuco);
            builder.String("uesgdftd", data.uesgdftd);
            builder.String("dmstvxix", data.dmstvxix);
            builder.String("pyonuzzg", data.pyonuzzg);
            builder.String("tilpdtek", data.tilpdtek);
            builder.String("qswdlcdc", data.qswdlcdc);
            builder.String("xljaldlb", data.xljaldlb);
            builder.String("sfjsktjp", data.sfjsktjp);
            builder.String("knapjxna", data.knapjxna);
            builder.String("anlawttq", data.anlawttq);
            builder.String("nllzxvpp", data.nllzxvpp);
            builder.String("tyfotgbe", data.tyfotgbe);
            builder.String("flnkscdj", data.flnkscdj);
            builder.String("mukwbnfx", data.mukwbnfx);
            builder.String("laxqtwmt", data.laxqtwmt);
            builder.String("hcperyup", data.hcperyup);
            builder.String("qdplqouo", data.qdplqouo);
            builder.String("oogbawct", data.oogbawct);
            builder.String("nnwgvima", data.nnwgvima);
            builder.String("nwuzhpdb", data.nwuzhpdb);
            builder.String("tmzovmhd", data.tmzovmhd);
            builder.String("rsnrnizf", data.rsnrnizf);
            builder.String("ivjhkfwa", data.ivjhkfwa);
            builder.String("eymlquhq", data.eymlquhq);
            builder.String("lhfqsqrf", data.lhfqsqrf);
            builder.String("rrzickmr", data.rrzickmr);
            builder.String("esdkloyo", data.esdkloyo);
            builder.String("khbvphfk", data.khbvphfk);
            builder.String("xvfeefth", data.xvfeefth);
            builder.String("iflmxuur", data.iflmxuur);
            builder.String("zmbwqjnz", data.zmbwqjnz);
            builder.String("ikulmxip", data.ikulmxip);
            builder.String("uscevqrf", data.uscevqrf);
            builder.String("ocvwicgv", data.ocvwicgv);
            builder.String("lcdsulto", data.lcdsulto);
            builder.String("pumpatfl", data.pumpatfl);
            builder.String("lwclnihb", data.lwclnihb);
            builder.String("errgsaoi", data.errgsaoi);
            builder.String("gyhlnjwh", data.gyhlnjwh);
            builder.String("ehkcedtv", data.ehkcedtv);
            builder.String("vdfhhycn", data.vdfhhycn);
            builder.String("ozhwdmpw", data.ozhwdmpw);
            builder.String("ykdhluxn", data.ykdhluxn);
            builder.String("ihnwjuhw", data.ihnwjuhw);
            builder.String("umpbntqn", data.umpbntqn);
            builder.String("oaizyhlt", data.oaizyhlt);
            builder.String("yyzmaoxe", data.yyzmaoxe);
            builder.String("ewkwedkd", data.ewkwedkd);
            builder.String("nexgmjdm", data.nexgmjdm);
            builder.String("wwlqjcvq", data.wwlqjcvq);
            builder.String("zppxtpkk", data.zppxtpkk);
            builder.String("iaodurzp", data.iaodurzp);
            builder.String("ifcvayzb", data.ifcvayzb);
            builder.String("cfzsnfwn", data.cfzsnfwn);
            builder.String("uhzxtshi", data.uhzxtshi);
            builder.String("osyexwsp", data.osyexwsp);
            builder.String("ojmmuukk", data.ojmmuukk);
            builder.String("hadshozy", data.hadshozy);
            builder.String("wtjmxxrx", data.wtjmxxrx);
            builder.String("zrsytazc", data.zrsytazc);
            builder.String("oxbqbuvz", data.oxbqbuvz);
            builder.String("khodeqzz", data.khodeqzz);

        });

        builder.Finish();
        outBuffer = builder.GetBuffer();
    }
    void Deserialize(testData& data, const std::vector<uint8_t> &inBuffer) {
        auto root = flexbuffers::GetRoot(inBuffer).AsMap();
        
        data.kzgiwgrw = root["kzgiwgrw"].AsString().str();
        data.dezjobnz = root["dezjobnz"].AsString().str();
        data.ieremuco = root["ieremuco"].AsString().str();
        data.uesgdftd = root["uesgdftd"].AsString().str();
        data.dmstvxix = root["dmstvxix"].AsString().str();
        data.pyonuzzg = root["pyonuzzg"].AsString().str();
        data.tilpdtek = root["tilpdtek"].AsString().str();
        data.qswdlcdc = root["qswdlcdc"].AsString().str();
        data.xljaldlb = root["xljaldlb"].AsString().str();
        data.sfjsktjp = root["sfjsktjp"].AsString().str();
        data.knapjxna = root["knapjxna"].AsString().str();
        data.anlawttq = root["anlawttq"].AsString().str();
        data.nllzxvpp = root["nllzxvpp"].AsString().str();
        data.tyfotgbe = root["tyfotgbe"].AsString().str();
        data.flnkscdj = root["flnkscdj"].AsString().str();
        data.mukwbnfx = root["mukwbnfx"].AsString().str();
        data.laxqtwmt = root["laxqtwmt"].AsString().str();
        data.hcperyup = root["hcperyup"].AsString().str();
        data.qdplqouo = root["qdplqouo"].AsString().str();
        data.oogbawct = root["oogbawct"].AsString().str();
        data.nnwgvima = root["nnwgvima"].AsString().str();
        data.nwuzhpdb = root["nwuzhpdb"].AsString().str();
        data.tmzovmhd = root["tmzovmhd"].AsString().str();
        data.rsnrnizf = root["rsnrnizf"].AsString().str();
        data.ivjhkfwa = root["ivjhkfwa"].AsString().str();
        data.eymlquhq = root["eymlquhq"].AsString().str();
        data.lhfqsqrf = root["lhfqsqrf"].AsString().str();
        data.rrzickmr = root["rrzickmr"].AsString().str();
        data.esdkloyo = root["esdkloyo"].AsString().str();
        data.khbvphfk = root["khbvphfk"].AsString().str();
        data.xvfeefth = root["xvfeefth"].AsString().str();
        data.iflmxuur = root["iflmxuur"].AsString().str();
        data.zmbwqjnz = root["zmbwqjnz"].AsString().str();
        data.ikulmxip = root["ikulmxip"].AsString().str();
        data.uscevqrf = root["uscevqrf"].AsString().str();
        data.ocvwicgv = root["ocvwicgv"].AsString().str();
        data.lcdsulto = root["lcdsulto"].AsString().str();
        data.pumpatfl = root["pumpatfl"].AsString().str();
        data.lwclnihb = root["lwclnihb"].AsString().str();
        data.errgsaoi = root["errgsaoi"].AsString().str();
        data.gyhlnjwh = root["gyhlnjwh"].AsString().str();
        data.ehkcedtv = root["ehkcedtv"].AsString().str();
        data.vdfhhycn = root["vdfhhycn"].AsString().str();
        data.ozhwdmpw = root["ozhwdmpw"].AsString().str();
        data.ykdhluxn = root["ykdhluxn"].AsString().str();
        data.ihnwjuhw = root["ihnwjuhw"].AsString().str();
        data.umpbntqn = root["umpbntqn"].AsString().str();
        data.oaizyhlt = root["oaizyhlt"].AsString().str();
        data.yyzmaoxe = root["yyzmaoxe"].AsString().str();
        data.ewkwedkd = root["ewkwedkd"].AsString().str();
        data.nexgmjdm = root["nexgmjdm"].AsString().str();
        data.wwlqjcvq = root["wwlqjcvq"].AsString().str();
        data.zppxtpkk = root["zppxtpkk"].AsString().str();
        data.iaodurzp = root["iaodurzp"].AsString().str();
        data.ifcvayzb = root["ifcvayzb"].AsString().str();
        data.cfzsnfwn = root["cfzsnfwn"].AsString().str();
        data.uhzxtshi = root["uhzxtshi"].AsString().str();
        data.osyexwsp = root["osyexwsp"].AsString().str();
        data.ojmmuukk = root["ojmmuukk"].AsString().str();
        data.hadshozy = root["hadshozy"].AsString().str();
        data.wtjmxxrx = root["wtjmxxrx"].AsString().str();
        data.zrsytazc = root["zrsytazc"].AsString().str();
        data.oxbqbuvz = root["oxbqbuvz"].AsString().str();
        data.khodeqzz = root["khodeqzz"].AsString().str();
    }
}
