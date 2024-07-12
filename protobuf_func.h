#include "benchmark_struct.h"
#include "ProtoData.pb.h"

namespace proto {
    size_t Serialize(const testData& data, const std::string& filename) {
        GOOGLE_PROTOBUF_VERIFY_VERSION; // is it necessary?
        ProtoData protoData;
        protoData.set_kzgiwgrw(data.kzgiwgrw);
        protoData.set_dezjobnz(data.dezjobnz);
        protoData.set_ieremuco(data.ieremuco);
        protoData.set_uesgdftd(data.uesgdftd);
        protoData.set_dmstvxix(data.dmstvxix);
        protoData.set_pyonuzzg(data.pyonuzzg);
        protoData.set_tilpdtek(data.tilpdtek);
        protoData.set_qswdlcdc(data.qswdlcdc);
        protoData.set_xljaldlb(data.xljaldlb);
        protoData.set_sfjsktjp(data.sfjsktjp);
        protoData.set_knapjxna(data.knapjxna);
        protoData.set_anlawttq(data.anlawttq);
        protoData.set_nllzxvpp(data.nllzxvpp);
        protoData.set_tyfotgbe(data.tyfotgbe);
        protoData.set_flnkscdj(data.flnkscdj);
        protoData.set_mukwbnfx(data.mukwbnfx);
        protoData.set_laxqtwmt(data.laxqtwmt);
        protoData.set_hcperyup(data.hcperyup);
        protoData.set_qdplqouo(data.qdplqouo);
        protoData.set_oogbawct(data.oogbawct);
        protoData.set_nnwgvima(data.nnwgvima);
        protoData.set_nwuzhpdb(data.nwuzhpdb);
        protoData.set_tmzovmhd(data.tmzovmhd);
        protoData.set_rsnrnizf(data.rsnrnizf);
        protoData.set_ivjhkfwa(data.ivjhkfwa);
        protoData.set_eymlquhq(data.eymlquhq);
        protoData.set_lhfqsqrf(data.lhfqsqrf);
        protoData.set_rrzickmr(data.rrzickmr);
        protoData.set_esdkloyo(data.esdkloyo);
        protoData.set_khbvphfk(data.khbvphfk);
        protoData.set_xvfeefth(data.xvfeefth);
        protoData.set_iflmxuur(data.iflmxuur);
        protoData.set_zmbwqjnz(data.zmbwqjnz);
        protoData.set_ikulmxip(data.ikulmxip);
        protoData.set_uscevqrf(data.uscevqrf);
        protoData.set_ocvwicgv(data.ocvwicgv);
        protoData.set_lcdsulto(data.lcdsulto);
        protoData.set_pumpatfl(data.pumpatfl);
        protoData.set_lwclnihb(data.lwclnihb);
        protoData.set_errgsaoi(data.errgsaoi);
        protoData.set_gyhlnjwh(data.gyhlnjwh);
        protoData.set_ehkcedtv(data.ehkcedtv);
        protoData.set_vdfhhycn(data.vdfhhycn);
        protoData.set_ozhwdmpw(data.ozhwdmpw);
        protoData.set_ykdhluxn(data.ykdhluxn);
        protoData.set_ihnwjuhw(data.ihnwjuhw);
        protoData.set_umpbntqn(data.umpbntqn);
        protoData.set_oaizyhlt(data.oaizyhlt);
        protoData.set_yyzmaoxe(data.yyzmaoxe);
        protoData.set_ewkwedkd(data.ewkwedkd);
        protoData.set_nexgmjdm(data.nexgmjdm);
        protoData.set_wwlqjcvq(data.wwlqjcvq);
        protoData.set_zppxtpkk(data.zppxtpkk);
        protoData.set_iaodurzp(data.iaodurzp);
        protoData.set_ifcvayzb(data.ifcvayzb);
        protoData.set_cfzsnfwn(data.cfzsnfwn);
        protoData.set_uhzxtshi(data.uhzxtshi);
        protoData.set_osyexwsp(data.osyexwsp);
        protoData.set_ojmmuukk(data.ojmmuukk);
        protoData.set_hadshozy(data.hadshozy);
        protoData.set_wtjmxxrx(data.wtjmxxrx);
        protoData.set_zrsytazc(data.zrsytazc);
        protoData.set_oxbqbuvz(data.oxbqbuvz);
        protoData.set_khodeqzz(data.khodeqzz);
        std::ofstream output(filename, std::ios::out | std::ios::binary);
        if (!protoData.SerializeToOstream(&output)) {
            std::cerr << "protobuf: Failed to write data to file." << std::endl;
        }
        return protoData.ByteSizeLong();
    }
    void Deserialize(testData& data, const std::string& filename) {
        std::ifstream input(filename, std::ios::in | std::ios::binary);
        ProtoData protoData;
        if (!protoData.ParseFromIstream(&input)) {
            std::cerr << "protobuf: Failed to read data from file." << std::endl;
        }
        data.kzgiwgrw = protoData.kzgiwgrw();
        data.dezjobnz = protoData.dezjobnz();
        data.ieremuco = protoData.ieremuco();
        data.uesgdftd = protoData.uesgdftd();
        data.dmstvxix = protoData.dmstvxix();
        data.pyonuzzg = protoData.pyonuzzg();
        data.tilpdtek = protoData.tilpdtek();
        data.qswdlcdc = protoData.qswdlcdc();
        data.xljaldlb = protoData.xljaldlb();
        data.sfjsktjp = protoData.sfjsktjp();
        data.knapjxna = protoData.knapjxna();
        data.anlawttq = protoData.anlawttq();
        data.nllzxvpp = protoData.nllzxvpp();
        data.tyfotgbe = protoData.tyfotgbe();
        data.flnkscdj = protoData.flnkscdj();
        data.mukwbnfx = protoData.mukwbnfx();
        data.laxqtwmt = protoData.laxqtwmt();
        data.hcperyup = protoData.hcperyup();
        data.qdplqouo = protoData.qdplqouo();
        data.oogbawct = protoData.oogbawct();
        data.nnwgvima = protoData.nnwgvima();
        data.nwuzhpdb = protoData.nwuzhpdb();
        data.tmzovmhd = protoData.tmzovmhd();
        data.rsnrnizf = protoData.rsnrnizf();
        data.ivjhkfwa = protoData.ivjhkfwa();
        data.eymlquhq = protoData.eymlquhq();
        data.lhfqsqrf = protoData.lhfqsqrf();
        data.rrzickmr = protoData.rrzickmr();
        data.esdkloyo = protoData.esdkloyo();
        data.khbvphfk = protoData.khbvphfk();
        data.xvfeefth = protoData.xvfeefth();
        data.iflmxuur = protoData.iflmxuur();
        data.zmbwqjnz = protoData.zmbwqjnz();
        data.ikulmxip = protoData.ikulmxip();
        data.uscevqrf = protoData.uscevqrf();
        data.ocvwicgv = protoData.ocvwicgv();
        data.lcdsulto = protoData.lcdsulto();
        data.pumpatfl = protoData.pumpatfl();
        data.lwclnihb = protoData.lwclnihb();
        data.errgsaoi = protoData.errgsaoi();
        data.gyhlnjwh = protoData.gyhlnjwh();
        data.ehkcedtv = protoData.ehkcedtv();
        data.vdfhhycn = protoData.vdfhhycn();
        data.ozhwdmpw = protoData.ozhwdmpw();
        data.ykdhluxn = protoData.ykdhluxn();
        data.ihnwjuhw = protoData.ihnwjuhw();
        data.umpbntqn = protoData.umpbntqn();
        data.oaizyhlt = protoData.oaizyhlt();
        data.yyzmaoxe = protoData.yyzmaoxe();
        data.ewkwedkd = protoData.ewkwedkd();
        data.nexgmjdm = protoData.nexgmjdm();
        data.wwlqjcvq = protoData.wwlqjcvq();
        data.zppxtpkk = protoData.zppxtpkk();
        data.iaodurzp = protoData.iaodurzp();
        data.ifcvayzb = protoData.ifcvayzb();
        data.cfzsnfwn = protoData.cfzsnfwn();
        data.uhzxtshi = protoData.uhzxtshi();
        data.osyexwsp = protoData.osyexwsp();
        data.ojmmuukk = protoData.ojmmuukk();
        data.hadshozy = protoData.hadshozy();
        data.wtjmxxrx = protoData.wtjmxxrx();
        data.zrsytazc = protoData.zrsytazc();
        data.oxbqbuvz = protoData.oxbqbuvz();
        data.khodeqzz = protoData.khodeqzz();
    }
}
