#include "WXXX.h"

WXXX::WXXX(std::vector<unsigned char> &data) : frame(data) {
    encoding = data[0];

    readToZeroByte(data, description, ID, size);

    url = std::string(data.begin(), data.begin() + size);
    data.erase(data.begin(), data.begin() + size);
}

std::string WXXX::print() const {
    std::string frameStr = "<User defined UR link frame>\n"
                           "Description: " + description + '\n'
                           + "UR: " + url + '\n';
    return frameStr;
}
