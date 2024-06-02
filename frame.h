#ifndef ID3V2_4METAINFOPARSER_FRAME_H
#define ID3V2_4METAINFOPARSER_FRAME_H

#include <iostream>
#include <vector>
#include <string>

class frame {
protected:
    struct header {
        unsigned char frameId[4];
        unsigned char size[4];
        unsigned char flags[2];
    };

    header header;

    int size = 0;

    void readToZeroByte(std::vector<unsigned char> &data, std::string &line, const std::string &tagId, int tagSize);

public:
    frame(std::vector<unsigned char> &);

    class tagReadingException {
    public:
        std::string tagId;

        tagReadingException(const std::string);
    };

    virtual std::string print() const = 0;
};


#endif
