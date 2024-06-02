#include "textFrame.h"

textFrame::textFrame(std::vector<unsigned char> &data, std::string _ID) : frame(data) {
    ID = _ID;

    encoding = data[0];
    data.erase(data.begin());
    size--;

    text = std::string(data.begin(), data.begin() + size);
    data.erase(data.begin(), data.begin() + size);
}

std::string textFrame::print() const {
    std::string frameString = "<" + ID + ">\n"
                                         "Text: " + text + '\n';
    return frameString;
}
