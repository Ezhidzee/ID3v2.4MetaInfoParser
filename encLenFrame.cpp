#include "encLenFrame.h"

#include <cstring>

encLenFrame::encLenFrame(std::vector<unsigned char> &data) {
    memcpy(&textInfo, &data[0], 4);
    data.erase(data.begin(), data.begin() + 4);
}
