#include "urlFrame.h"

urlFrame::urlFrame(std::vector<unsigned char> &data, std::string _ID) : frame(data) {
    ID = _ID;

    url = std::string(data.begin(), data.begin() + size);
    data.erase(data.begin(), data.begin() + size);
}

std::string urlFrame::print() const {
    std::string frameStr = "<" + ID + ">\n"
                                      "UR: " + url + '\n';
    return frameStr;
}
