#include "SEEK.h"

SEEK::SEEK(std::vector<unsigned char> &data) : frame(data) {
    for (int i = 0; i < 4; i++) offset += int(data[3 - i]) << (7 * i);
    data.erase(data.begin(), data.begin() + 4);
}

std::string SEEK::print() const {
    std::string frameString = "<Seek frame>\n"
                              "Minimum offset to next tag: " + std::to_string(offset) + '\n';
    return frameString;
}
