#include "GRID.h"

GRID::GRID(std::vector<unsigned char> &data) : frame(data) {
    readToZeroByte(data, owner, ID, size);

    groupSymbol += data[0];
    data.erase(data.begin());
    size--;

    if (size != 0) {
        groupData = std::string(data.begin(), data.begin() + size);
        data.erase(data.begin(), data.begin() + size);
    }
}

std::string GRID::print() const {
    std::string frameString = "<Group ID registration>\n"
                              "Owner identifier: " + owner + '\n'
                              + "Group symbol: " + groupSymbol + '\n'
                              + "Group dependent data: " + groupData + '\n';
    return frameString;
}