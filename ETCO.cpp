#include "ETCO.h"

ETCO::ETCO(std::vector<unsigned char> &data) : frame(data) {
    if (data[0] == 0) {
        timeStampFormat = "Absolute time, 32 bit sized, using MPEG [MPEG] frames as unit";
    } else timeStampFormat = "Absolute time, 32 bit sized, using milliseconds as unit";
    data.erase(data.begin());
    size--;

    while (size != 0) {
        eventTypeDefinition(data);
        int timeStamp = 0;
        for (int i = 0; i < 4; i++) timeStamp += int(header.size[3 - i]) << (7 * i);
        events += std::to_string(timeStamp) + '\n';
        data.erase(data.begin(), data.begin() + 4);
        size -= 4;
    }
}

void ETCO::eventTypeDefinition(std::vector<unsigned char> &data) {
    std::string eventTypes[] = {"padding (has no meaning)", "end of initial silence", "intro start", "main part start",
                                "outro start", "outro end", "verse start", "refrain start", "interlude start",
                                "theme start", "variation start", "key change", "time change,"
                                                                                "momentary unwanted noise (Snap, Crackle & Pop)",
                                "sustained noise",
                                "sustained noise end", "intro end", "main part end", "verse end", "refrain end",
                                "theme end", "profanity", "profanity end"};
    int type = int(data[0]);
    if (type <= 22) {
        events += '<' + eventTypes[type] + "> ";
    } else if (type >= 23 && type <= 223) {
        events += "<reserved for future use> ";
    } else if (type >= 224 && type <= 239) {
        events += "<not predefined synch 0-F> ";
    } else if (type >= 240 && type <= 252) {
        events += "<reserved for future use> ";
    } else if (type == 253) {
        events += "<audio end (start of silence)> ";
    } else if (type == 254) {
        events += "<audio file ends> ";
    } else if (type == 255) {
        size--;
        data.erase(data.begin());
        eventTypeDefinition(data);
    }
    if (type != 255) {
        size--;
        data.erase(data.begin());
    }
}

std::string ETCO::print() const {
    std::string frameString = "<Event timing codes>\n"
                              "Time stamp format: " + timeStampFormat + '\n'
                              + "Events: " + events + '\n';
    return frameString;
}
