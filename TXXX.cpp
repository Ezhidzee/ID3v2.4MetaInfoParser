#include "TXXX.h"

TXXX::TXXX(std::vector<unsigned char> &data) : frame(data) {
    encoding = data[0];
    data.erase(data.begin());
    size--;

    readToZeroByte(data, description, ID, size);

    value = std::string(data.begin(), data.begin() + size);
    data.erase(data.begin(), data.begin() + size);
}

std::string TXXX::print() const {
    std::string frameString = "<User defined text information frame>\n"
                              "Description: " + description + '\n'
                              + "Value: " + value + '\n';
    return frameString;
}
