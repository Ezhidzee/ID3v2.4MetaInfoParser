#include "COMM.h"

COMM::COMM(std::vector<unsigned char> &data) : frame(data), encLenFrame(data) {
    size -= 4;

    readToZeroByte(data, text, ID, size);
    text += '\n';

    text += std::string(data.begin(), data.begin() + size);
    data.erase(data.begin(), data.begin() + size);
}

std::string COMM::print() const {
    std::string frameString = "<Comments>\n"
                              + text + '\n';
    return frameString;
}