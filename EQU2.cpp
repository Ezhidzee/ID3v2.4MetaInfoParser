#include "EQU2.h"

EQU2::EQU2(std::vector<unsigned char> &data) : frame(data) {
    if (data[0] == 0) {
        interpolationMethod = "Band\n"
                              "No interpolation is made. A jump from one adjustment level to\n"
                              "another occurs in the middle between two adjustment points.";
    } else {
        interpolationMethod = "inear\n"
                              "Interpolation between adjustment points is linear.";
    }
    data.erase(data.begin());
    size--;

    readToZeroByte(data, identification, ID, size);

    while (size > 0) {
        adjustmentPoints += "Frequency " + data[0] + ' ' + data[1] + '\n';
        adjustmentPoints += "Volume adjustment " + data[2] + ' ' + data[3] + '\n';
        data.erase(data.begin(), data.begin() + 4);
        size -= 4;
    }
}

std::string EQU2::print() const {
    std::string frameString = "<Equalisation (2)>\n"
                              "Interpolation method: " + interpolationMethod + '\n'
                              + "Identification: " + identification + '\n'
                              + adjustmentPoints + '\n';
    return frameString;
}
