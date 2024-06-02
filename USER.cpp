#include "USER.h"

USER::USER(std::vector<unsigned char> &data) : frame(data), encLenFrame(data) {
    size -= 4;

    text = std::string(data.begin(), data.begin() + size);
    data.erase(data.begin(), data.begin() + size);
}

std::string USER::print() const {
    std::string frameString = "<Terms of use>\n"
                              "The actual text: " + text + '\n';
    return frameString;
}
