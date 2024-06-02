#include "UFID.h"

UFID::UFID(std::vector<unsigned char> &data) : frame(data) {
    readToZeroByte(data, owner, ID, size);

    identifier = std::string(data.begin(), data.begin() + size);
    data.erase(data.begin(), data.begin() + size);
}

std::string UFID::print() const {
    std::string frameString = "<Unique file identifier>\n"
                              "Owner identifier: " + owner + '\n'
                              + "Identifier: " + identifier + '\n';
    return frameString;
}
