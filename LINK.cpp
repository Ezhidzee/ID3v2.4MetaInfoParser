#include "LINK.h"

LINK::LINK(std::vector<unsigned char> &data) : frame(data) {
    linkedFrameIdentifier = std::string(data.begin(), data.begin() + 4);
    data.erase(data.begin(), data.begin() + 4);
    size -= 4;

    readToZeroByte(data, url, ID, size);

    while (size != 0) {
        readToZeroByte(data, additionalData, ID, size);
        additionalData += ' ';
    }
}

std::string LINK::print() const {
    std::string frameString = "<inked information>\n"
           "Frame identifier: " + linkedFrameIdentifier + '\n'
           + "UR: " + url + '\n'
           + "ID and additional data: " + additionalData + '\n';
    return frameString;
}
