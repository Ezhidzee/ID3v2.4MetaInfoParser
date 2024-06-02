#ifndef ID3V2_4METAINFOPARSER_URLFRAME_H
#define ID3V2_4METAINFOPARSER_URLFRAME_H

#include "frame.h"

class urlFrame : public frame {
private:
    std::string url;

public:
    std::string ID;

    urlFrame(std::vector<unsigned char> &, std::string);

    std::string print() const override;
};

#endif
