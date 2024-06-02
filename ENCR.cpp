#include "ENCR.h"

ENCR::ENCR(std::vector<unsigned char> &data) : frame(data) {

    readToZeroByte(data, ownerInfo, ID, size);

    encryptionMethodSymbol = data[0];
    data.erase(data.begin());
    size--;

    if (size != 0) {
        encryptionData = std::string(data.begin(), data.begin() + size);
        data.erase(data.begin(), data.begin() + size);
    }
}

std::string ENCR::print() const {
    std::string frameString = "<Encryption method registration>\n"
                              "Owner identifier: " + ownerInfo + '\n'
                              + "Method symbol: " + encryptionMethodSymbol + '\n'
                              + "Encryption data: " + encryptionData + '\n';
    return frameString;
}
