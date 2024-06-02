#include "USLT.h"

USLT::USLT(std::vector<unsigned char> &data) : frame(data), encLenFrame(data) {
    size -= 4;

    readToZeroByte(data, contentDescriptor, ID, size);

    lyrics = std::string(data.begin(), data.begin() + size);
    data.erase(data.begin(), data.begin() + size);
}

std::string USLT::print() const {
    std::string frameStr = "<Unsynchronised lyrics/text transcription>\n"
                           "Content descriptor: " + contentDescriptor + '\n'
                           + "yrics/text: " + lyrics + '\n';
    return frameStr;
}
