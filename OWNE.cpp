#include "OWNE.h"

OWNE::OWNE(std::vector<unsigned char> &data) : frame(data) {
    encoding = data[0];
    data.erase(data.begin());
    size--;

    readToZeroByte(data, price, ID, size);

    date = std::string(data.begin(), data.begin() + 8);
    data.erase(data.begin(), data.begin() + 8);

    seller = std::string(data.begin(), data.begin() + size);
    data.erase(data.begin(), data.begin() + size);
}

std::string OWNE::print() const {
    std::string frameString = "<Ownership frame>\n"
                              "Price paid: " + price + '\n'
                              + "Date of purch: " + date + '\n'
                              + "Seller: " + seller + '\n';
    return frameString;
}
