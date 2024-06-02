#ifndef ID3V2_4METAINFOPARSER_WXXX_H
#define ID3V2_4METAINFOPARSER_WXXX_H

#include "frame.h"

class WXXX : public frame {
private:
    char encoding;

    std::string description;

    std::string url;

public:
    inline static const std::string ID = "WXXX";

    WXXX(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif