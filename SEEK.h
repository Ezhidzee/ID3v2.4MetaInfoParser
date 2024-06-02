#ifndef ID3V2_4METAINFOPARSER_SEEK_H
#define ID3V2_4METAINFOPARSER_SEEK_H

#include "frame.h"

class SEEK : public frame {
private:
    int offset;

public:
    inline static const std::string ID = "SEEK";

    SEEK(std::vector<unsigned char> &);

    std::string print() const override;
};


#endif
