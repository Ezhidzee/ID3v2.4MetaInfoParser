#include "SYLT.h"

SYLT::SYLT(std::vector<unsigned char> &data) : frame(data), encLenFrame(data) {
    size -= 4;

    if (data[0] == 1) {
        timeStampFormat = "Absolute time, 32 bit sized, using MPEG [MPEG] frames as unit";
    } else timeStampFormat = "Absolute time, 32 bit sized, using milliseconds as unit";
    data.erase(data.begin());
    size--;

    std::string contentTypes[] = {"is other",
                                  "is lyrics",
                                  "is text transcription",
                                  "is movement/part name (e.g. \"Adagio\")",
                                  "is events (e.g. \"Don Quijote enters the stage\")",
                                  "is chord (e.g. \"Bb F Fsus\")",
                                  "is trivia/'pop up' information",
                                  "is URs to webpages",
                                  "is URs to images"};
    contentType = contentTypes[data[0]];
    data.erase(data.begin());
    size--;

    while (size != 0) {
        readToZeroByte(data, contentDescriptor, ID, size);
        if (data[0] == 0) {
            data.erase(data.begin());
            size--;
        }
        contentDescriptor += ' ';
    }
}

std::string SYLT::print() const {
    std::string frameString = "<Synchronised lyrics/text>\n"
                              "Time stamp format: " + timeStampFormat + '\n'
                              + "Content type: " + contentType + '\n'
                              + "Content descriptor: " + contentDescriptor + '\n';
    return frameString;
}
