#include "PRIV.h"

PRIV::PRIV(std::vector<unsigned char> &data) : frame(data) {
    readToZeroByte(data, owner, ID, size);

    binData = std::string(data.begin(), data.begin() + size);
    data.erase(data.begin(), data.begin() + size);
}

std::string PRIV::print() const {
    std::string frameString = "<Private frame>\n"
                              "Owner identifier: " + owner + '\n'
                              + "The private data: " + binData + '\n';
    return frameString;
}
