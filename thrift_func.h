#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <vector>
#include "gen-cpp/struct_types.h"
#include "benchmark_struct.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

namespace thrift {
    void Serialize(const testData& data, std::string& serialized_str) {
        TStruct tStruct;
        tStruct.kzgiwgrw = data.kzgiwgrw;
        tStruct.dezjobnz = data.dezjobnz;
        tStruct.ieremuco = data.ieremuco;
        tStruct.uesgdftd = data.uesgdftd;
        tStruct.dmstvxix = data.dmstvxix;
        tStruct.pyonuzzg = data.pyonuzzg;
        tStruct.tilpdtek = data.tilpdtek;
        tStruct.qswdlcdc = data.qswdlcdc;
        tStruct.xljaldlb = data.xljaldlb;
        tStruct.sfjsktjp = data.sfjsktjp;
        tStruct.knapjxna = data.knapjxna;
        tStruct.anlawttq = data.anlawttq;
        tStruct.nllzxvpp = data.nllzxvpp;
        tStruct.tyfotgbe = data.tyfotgbe;
        tStruct.flnkscdj = data.flnkscdj;
        tStruct.mukwbnfx = data.mukwbnfx;
        tStruct.laxqtwmt = data.laxqtwmt;
        tStruct.hcperyup = data.hcperyup;
        tStruct.qdplqouo = data.qdplqouo;
        tStruct.oogbawct = data.oogbawct;
        tStruct.nnwgvima = data.nnwgvima;
        tStruct.nwuzhpdb = data.nwuzhpdb;
        tStruct.tmzovmhd = data.tmzovmhd;
        tStruct.rsnrnizf = data.rsnrnizf;
        tStruct.ivjhkfwa = data.ivjhkfwa;
        tStruct.eymlquhq = data.eymlquhq;
        tStruct.lhfqsqrf = data.lhfqsqrf;
        tStruct.rrzickmr = data.rrzickmr;
        tStruct.esdkloyo = data.esdkloyo;
        tStruct.khbvphfk = data.khbvphfk;
        tStruct.xvfeefth = data.xvfeefth;
        tStruct.iflmxuur = data.iflmxuur;
        tStruct.zmbwqjnz = data.zmbwqjnz;
        tStruct.ikulmxip = data.ikulmxip;
        tStruct.uscevqrf = data.uscevqrf;
        tStruct.ocvwicgv = data.ocvwicgv;
        tStruct.lcdsulto = data.lcdsulto;
        tStruct.pumpatfl = data.pumpatfl;
        tStruct.lwclnihb = data.lwclnihb;
        tStruct.errgsaoi = data.errgsaoi;
        tStruct.gyhlnjwh = data.gyhlnjwh;
        tStruct.ehkcedtv = data.ehkcedtv;
        tStruct.vdfhhycn = data.vdfhhycn;
        tStruct.ozhwdmpw = data.ozhwdmpw;
        tStruct.ykdhluxn = data.ykdhluxn;
        tStruct.ihnwjuhw = data.ihnwjuhw;
        tStruct.umpbntqn = data.umpbntqn;
        tStruct.oaizyhlt = data.oaizyhlt;
        tStruct.yyzmaoxe = data.yyzmaoxe;
        tStruct.ewkwedkd = data.ewkwedkd;
        tStruct.nexgmjdm = data.nexgmjdm;
        tStruct.wwlqjcvq = data.wwlqjcvq;
        tStruct.zppxtpkk = data.zppxtpkk;
        tStruct.iaodurzp = data.iaodurzp;
        tStruct.ifcvayzb = data.ifcvayzb;
        tStruct.cfzsnfwn = data.cfzsnfwn;
        tStruct.uhzxtshi = data.uhzxtshi;
        tStruct.osyexwsp = data.osyexwsp;
        tStruct.ojmmuukk = data.ojmmuukk;
        tStruct.hadshozy = data.hadshozy;
        tStruct.wtjmxxrx = data.wtjmxxrx;
        tStruct.zrsytazc = data.zrsytazc;
        tStruct.oxbqbuvz = data.oxbqbuvz;
        tStruct.khodeqzz = data.khodeqzz;

        std::shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
        std::shared_ptr<TBinaryProtocol> protocol(new TBinaryProtocol(buffer));

        tStruct.write(protocol.get());

        // uint8_t* serializedData;
        // buffer->getBuffer(&serializedData, &dataSize);
        serialized_str = buffer->getBufferAsString();
    }

    void Deserialize(testData& data, std::vector<uint8_t>& inBuffer) {
        std::shared_ptr<TMemoryBuffer> bufferIn(new TMemoryBuffer());
        bufferIn->resetBuffer(inBuffer.data(), inBuffer.size());
        std::shared_ptr<TBinaryProtocol> protocolIn(new TBinaryProtocol(bufferIn));

        TStruct tStruct;
        tStruct.read(protocolIn.get());
        data.kzgiwgrw = tStruct.kzgiwgrw;
        data.dezjobnz = tStruct.dezjobnz;
        data.ieremuco = tStruct.ieremuco;
        data.uesgdftd = tStruct.uesgdftd;
        data.dmstvxix = tStruct.dmstvxix;
        data.pyonuzzg = tStruct.pyonuzzg;
        data.tilpdtek = tStruct.tilpdtek;
        data.qswdlcdc = tStruct.qswdlcdc;
        data.xljaldlb = tStruct.xljaldlb;
        data.sfjsktjp = tStruct.sfjsktjp;
        data.knapjxna = tStruct.knapjxna;
        data.anlawttq = tStruct.anlawttq;
        data.nllzxvpp = tStruct.nllzxvpp;
        data.tyfotgbe = tStruct.tyfotgbe;
        data.flnkscdj = tStruct.flnkscdj;
        data.mukwbnfx = tStruct.mukwbnfx;
        data.laxqtwmt = tStruct.laxqtwmt;
        data.hcperyup = tStruct.hcperyup;
        data.qdplqouo = tStruct.qdplqouo;
        data.oogbawct = tStruct.oogbawct;
        data.nnwgvima = tStruct.nnwgvima;
        data.nwuzhpdb = tStruct.nwuzhpdb;
        data.tmzovmhd = tStruct.tmzovmhd;
        data.rsnrnizf = tStruct.rsnrnizf;
        data.ivjhkfwa = tStruct.ivjhkfwa;
        data.eymlquhq = tStruct.eymlquhq;
        data.lhfqsqrf = tStruct.lhfqsqrf;
        data.rrzickmr = tStruct.rrzickmr;
        data.esdkloyo = tStruct.esdkloyo;
        data.khbvphfk = tStruct.khbvphfk;
        data.xvfeefth = tStruct.xvfeefth;
        data.iflmxuur = tStruct.iflmxuur;
        data.zmbwqjnz = tStruct.zmbwqjnz;
        data.ikulmxip = tStruct.ikulmxip;
        data.uscevqrf = tStruct.uscevqrf;
        data.ocvwicgv = tStruct.ocvwicgv;
        data.lcdsulto = tStruct.lcdsulto;
        data.pumpatfl = tStruct.pumpatfl;
        data.lwclnihb = tStruct.lwclnihb;
        data.errgsaoi = tStruct.errgsaoi;
        data.gyhlnjwh = tStruct.gyhlnjwh;
        data.ehkcedtv = tStruct.ehkcedtv;
        data.vdfhhycn = tStruct.vdfhhycn;
        data.ozhwdmpw = tStruct.ozhwdmpw;
        data.ykdhluxn = tStruct.ykdhluxn;
        data.ihnwjuhw = tStruct.ihnwjuhw;
        data.umpbntqn = tStruct.umpbntqn;
        data.oaizyhlt = tStruct.oaizyhlt;
        data.yyzmaoxe = tStruct.yyzmaoxe;
        data.ewkwedkd = tStruct.ewkwedkd;
        data.nexgmjdm = tStruct.nexgmjdm;
        data.wwlqjcvq = tStruct.wwlqjcvq;
        data.zppxtpkk = tStruct.zppxtpkk;
        data.iaodurzp = tStruct.iaodurzp;
        data.ifcvayzb = tStruct.ifcvayzb;
        data.cfzsnfwn = tStruct.cfzsnfwn;
        data.uhzxtshi = tStruct.uhzxtshi;
        data.osyexwsp = tStruct.osyexwsp;
        data.ojmmuukk = tStruct.ojmmuukk;
        data.hadshozy = tStruct.hadshozy;
        data.wtjmxxrx = tStruct.wtjmxxrx;
        data.zrsytazc = tStruct.zrsytazc;
        data.oxbqbuvz = tStruct.oxbqbuvz;
        data.khodeqzz = tStruct.khodeqzz;
    }
}
