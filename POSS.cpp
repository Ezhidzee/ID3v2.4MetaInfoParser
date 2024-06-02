#include "POSS.h"

POSS::POSS(std::vector<unsigned char> &data) : frame(data) {
    if (data[0] == 1) {
        format = "Absolute time, 32 bit sized, using MPEG frames as unit";
    } else format = "Absolute time, 32 bit sized, using milliseconds as unit";
    data.erase(data.begin());
    size--;

    for (int i = 0; i < size; i++) position += int(data[size - i - 1]) << (7 * i);
    data.erase(data.begin(), data.begin() + size);
}

std::string POSS::print() const {
    std::string frameString = "<Position synchronisation>\n"
                              "Time stamp format: " + format + '\n'
                              + "Position: " + std::to_string(position) + '\n';
    return frameString;
}
