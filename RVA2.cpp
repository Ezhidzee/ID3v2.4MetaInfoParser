#include "RVA2.h"

struct RVA2::channel {
    std::string typeOfChannel;

    int volumeAdjustment;

    int peakBits;

    int peakVolume;

    std::string print() const {
        std::string frameString = "Type of channel:\n" + typeOfChannel + '\n'
                                  + "Volume adjustment:\n" + std::to_string(volumeAdjustment) + '\n'
                                  + "Bits representing peak:\n" + std::to_string(peakBits) + '\n'
                                  + "Peak volume:\n" + std::to_string(peakVolume) + '\n';
        return frameString;
    }
};

RVA2::RVA2(std::vector<unsigned char> &data) : frame(data) {
    readToZeroByte(data, identification, ID, size);

    std::string channelTypes[] = {"Other", "Master volume", "Front right", "Front left", "Back right", "Back left",
                                  "Front centre", "Back centre", "Subwoofer"};
    std::vector<channel> channels;
    while (size >= 5) {
        channel ch;
        ch.typeOfChannel = channelTypes[data[0]];
        data.erase(data.begin());
        size--;

        for (int i = 0; i < 2; i++) ch.volumeAdjustment += int(data[1 - i]) << (7 * i);
        data.erase(data.begin(), data.begin() + 2);
        size -= 2;

        ch.peakBits = data[0];
        data.erase(data.begin());
        size--;

        ch.peakVolume = data[0];
        data.erase(data.begin());
        size--;
        channels.push_back(ch);
    }

    for (const channel &ch: channels) channelsString += ch.print();
}

std::string RVA2::print() const {
    std::string frameString = "<Relative volume adjustment (2)>\n"
                              "Identification: " + identification + '\n';
    frameString += channelsString;
    return frameString;
}
