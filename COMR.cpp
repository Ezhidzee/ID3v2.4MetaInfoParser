#include "COMR.h"

COMR::COMR(std::vector<unsigned char> &data) : frame(data) {
    encoding = data[0];
    data.erase(data.begin());
    size--;

    readToZeroByte(data, price, ID, size);

    for (int j = 0; j < 8; ++j) date += data[j];
    data.erase(data.begin(), data.begin() + 8);
    size -= 8;

    readToZeroByte(data, url, ID, size);

    std::string receivedAsFieldDescriptions[] = {"Other",
                                                 "Standard CD album with other songs",
                                                 "Compressed audio on CD",
                                                 "File over the Internet",
                                                 "Stream over the Internet",
                                                 "As note sheets",
                                                 "As note sheets in a book with other sheets",
                                                 "Music on other media",
                                                 "Non-musical merchandise"};
    receivedAs = receivedAsFieldDescriptions[data[0]];
    data.erase(data.begin());
    size--;

    readToZeroByte(data, seller, ID, size);

    readToZeroByte(data, description, ID, size);

    if (size != 0) data.erase(data.begin(), data.begin() + size);
}

std::string COMR::print() const {
    std::string frameString = "<Commercial frame>\n"
                              "Price: " + price + '\n'
                              + "Valid until: " + date + '\n'
                              + "Contact UR: " + url + '\n'
                              + "Received as: " + receivedAs + '\n'
                              + "Name of seller: " + seller + '\n'
                              + "Description: " + description + '\n';
    return frameString;
}
