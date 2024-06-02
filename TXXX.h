#ifndef ID3V2_4METAINFOPARSER_TXXX_H
#define ID3V2_4METAINFOPARSER_TXXX_H

#include "frame.h"

class TXXX : public frame {
private:
    char encoding;

    std::string description;

    std::string value;

public:
    inline static const std::string ID = "TXXX";

    TXXX(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif
