#ifndef ID3V2_4METAINFOPARSER_ID3V2_H
#define ID3V2_4METAINFOPARSER_ID3V2_H

#include <vector>
#include <fstream>
#include <cstdint>

class id3v2 {
private:
    std::vector<unsigned char> data;

    FILE *file;

    struct header {
        unsigned char identifier[3];
        unsigned char version[2];
        unsigned char flags[1];
        unsigned char size[4];
    };

    header header;

    bool flags[4];

    uint32_t size = 0;

    bool findFrame(std::vector<unsigned char> &);

public:
    id3v2(const char *);

};


#endif
