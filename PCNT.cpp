#include "PCNT.h"

PCNT::PCNT(std::vector<unsigned char> &data) : frame(data) {
    for (int i = 0; i < size; i++) counter += int(data[size - i - 1]) << (7 * i);
    data.erase(data.begin(), data.begin() + size);
}

std::string PCNT::print() const {
    std::string frameString = "<Play counter>\n"
                              "Counter: " + std::to_string(counter) + '\n';
    return frameString;
}
