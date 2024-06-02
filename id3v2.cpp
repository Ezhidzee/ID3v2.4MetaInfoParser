#include "id3v2.h"
#include "COMM.h"
#include "COMR.h"
#include "ENCR.h"
#include "EQU2.h"
#include "ETCO.h"
#include "GRID.h"
#include "LINK.h"
#include "OWNE.h"
#include "PRIV.h"
#include "PCNT.h"
#include "POPM.h"
#include "POSS.h"
#include "RBUF.h"
#include "RVA2.h"
#include "SEEK.h"
#include "SYLT.h"
#include "TXXX.h"
#include "UFID.h"
#include "USER.h"
#include "USLT.h"
#include "WXXX.h"
#include "textFrame.h"
#include "urlFrame.h"

#include <bitset>
#include <algorithm>

id3v2::id3v2(const char *filePath) {
    file = fopen(filePath, "r+");
    fseek(file, 0, SEEK_END);
    long int fileSize = ftell(file);
    fclose(file);
    file = fopen(filePath, "r+");
    data = std::vector<unsigned char>(fileSize);
    fread(&data[0], sizeof(unsigned char), fileSize, file);
    fclose(file);
    memcpy(&header, &data[0], 10);
    data.erase(data.begin(), data.begin() + 10);

    std::string flagsByte = std::bitset<8>(header.flags[0]).to_string();
    for (int i = 0; i < 4; ++i) flags[i] = flagsByte[i] - '0';

    for (int i = 0; i < 4; i++) size += int(header.size[3 - i]) << (7 * i);

    if (flags[1]) {
        unsigned char extendedHeaderSize[4];
        memcpy(&extendedHeaderSize, &data[0], 4);
        int extSize = 0;
        for (int i = 0; i < 4; ++i) extSize += int(extendedHeaderSize[3 - i]) << (7 * i);
        data.erase(data.begin(), data.begin() + extSize);
    }

    while (findFrame(data)) {
        std::string frame = std::string(data.begin(), data.begin() + 4);
        if (frame == "COMM") std::cout << COMM(data).print() << std::endl;
        else if (frame == "COMR") std::cout << COMR(data).print() << std::endl;
        else if (frame == "ENCR") std::cout << ENCR(data).print() << std::endl;
        else if (frame == "EQU2") std::cout << EQU2(data).print() << std::endl;
        else if (frame == "ETCO") std::cout << ETCO(data).print() << std::endl;
        else if (frame == "GRID") std::cout << GRID(data).print() << std::endl;
        else if (frame == "LINK") std::cout << LINK(data).print() << std::endl;
        else if (frame == "OWNE") std::cout << OWNE(data).print() << std::endl;
        else if (frame == "PRIV") std::cout << PRIV(data).print() << std::endl;
        else if (frame == "PCNT") std::cout << PCNT(data).print() << std::endl;
        else if (frame == "POPM") std::cout << POPM(data).print() << std::endl;
        else if (frame == "POSS") std::cout << POSS(data).print() << std::endl;
        else if (frame == "RBUF") std::cout << RBUF(data).print() << std::endl;
        else if (frame == "RVA2") std::cout << RVA2(data).print() << std::endl;
        else if (frame == "SEEK") std::cout << SEEK(data).print() << std::endl;
        else if (frame == "SYLT") std::cout << SYLT(data).print() << std::endl;
        else if (frame == "TXXX") std::cout << TXXX(data).print() << std::endl;
        else if (frame == "UFID") std::cout << UFID(data).print() << std::endl;
        else if (frame == "USER") std::cout << USER(data).print() << std::endl;
        else if (frame == "USLT") std::cout << USLT(data).print() << std::endl;
        else if (frame == "WXXX") std::cout << WXXX(data).print() << std::endl;
        else if (frame[0] == 'T') std::cout << textFrame(data, frame).print() << std::endl;
        else if (frame[0] == 'W') std::cout << urlFrame(data, frame).print() << std::endl;
    }
}

bool id3v2::findFrame(std::vector<unsigned char> &data) {
    std::vector<std::string> frameTags = {
            "COMM", "COMR", "ENCR", "EQU2", "ETCO", "GRID", "LINK", "OWNE", "PRIV", "PCNT", "POPM", "POSS", "RBUF",
            "RVA2", "SEEK", "SYLT", "TALB", "TBPM", "TCOM", "TCON", "TCOP", "TDEN", "TDLY", "TDOR", "TDRC", "TDRL",
            "TDTG", "TENC", "TEXT", "TIPL", "TIT1", "TIT2", "TIT3", "TKEY", "TLAN", "TLEN", "TMCL", "TMOO", "TOAL",
            "TOFN", "TOLY", "TOPE", "TOWN", "TPE1", "TPE2", "TPE3", "TPE4", "TPOS", "TPRO", "TPUB", "TRCK", "TRSN",
            "TRSO", "TSOA", "TSOP", "TSOT", "TSRC", "TSSE", "TSST", "TYER", "TXXX", "UFID", "USER", "USLT", "WCOM",
            "WCOP", "WOAF", "WOAR", "WOAS", "WORS", "WPAY", "WPUB", "WXXX"};

    for (int i = 0; i < data.size() - 4; ++i) {
        std::string frame = std::string(data.begin() + i, data.begin() + i + 4);
        if (std::find(frameTags.begin(), frameTags.end(), frame) != frameTags.end()) {
            data.erase(data.begin(), data.begin() + i);
            return true;
        }
    }

    return false;
}
