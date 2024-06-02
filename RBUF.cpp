#include "RBUF.h"

RBUF::RBUF(std::vector<unsigned char> &data) : frame(data) {
    for (int i = 0; i < 3; i++) bufferSize += int(data[2 - i]) << (7 * i);
    data.erase(data.begin(), data.begin() + 3);
    size -= 3;

    flag = data[0];
    data.erase(data.begin());
    size--;

    if (size != 0) {
        for (int i = 0; i < 4; i++) bufferSize += int(data[3 - i]) << (7 * i);
        data.erase(data.begin(), data.begin() + 4);
    }
}

std::string RBUF::print() const {
    std::string frameString = "<Recommended buffer size>\n"
                              "Buffer size: " + std::to_string(bufferSize) + '\n'
                              + "Embedded info flag: " + std::to_string(flag) + '\n'
                              + "Offset to next tag: " + std::to_string(nextTagOffset) + '\n';
    return frameString;
}
