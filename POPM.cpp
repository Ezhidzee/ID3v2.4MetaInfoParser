#include "POPM.h"

POPM::POPM(std::vector<unsigned char> &data) : frame(data) {
    readToZeroByte(data, email, ID, size);

    rating = int(data[0]);
    data.erase(data.begin());
    size--;

    for (int i = 0; i < size; i++) counter += int(data[size - i - 1]) << (7 * i);
    data.erase(data.begin(), data.begin() + size);
}

std::string POPM::print() const {
    std::string frameString = "<Popularimeter>\n"
                              "Email to user: " + email + '\n'
                              + "Rating: " + std::to_string(rating) + '\n'
                              + "Counter: " + std::to_string(counter) + '\n';
    return frameString;
}
