#ifndef ID3V2_4METAINFOPARSER_TEXTFRAME_H
#define ID3V2_4METAINFOPARSER_TEXTFRAME_H

#include "frame.h"

class textFrame : public frame {
private:
    char encoding;

    std::string text;

public:
    std::string ID;

    textFrame(std::vector<unsigned char> &, std::string);

    std::string print() const override;

};

#endif
