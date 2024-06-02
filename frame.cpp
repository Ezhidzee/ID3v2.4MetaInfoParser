#include "frame.h"

#include <cstring>
#include <locale>
#include <codecvt>

frame::frame(std::vector<unsigned char> &data) {
    memcpy(&header, &data[0], 10);
    data.erase(data.begin(), data.begin() + 10);

    for (int i = 0; i < 4; i++) size += int(header.size[3 - i]) << (7 * i);
}

void frame::readToZeroByte(std::vector<unsigned char> &data, std::string &line, const std::string &tagId, int tagSize) {
    int i = 0;
    while (data[i] != 0 && i < size) {
        line += data[i];
        i++;
        if (i > tagSize) throw tagReadingException(tagId);
    }
    data.erase(data.begin(), data.begin() + i);
    size -= i;
}

frame::tagReadingException::tagReadingException(const std::string _tagId) {
    tagId = _tagId;
}
