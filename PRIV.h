#ifndef ID3V2_4METAINFOPARSER_PRIV_H
#define ID3V2_4METAINFOPARSER_PRIV_H

#include "frame.h"

class PRIV : public frame {
private:
    std::string owner;

    std::string binData;

public:
    inline static const std::string ID = "PRIV";

    PRIV(std::vector<unsigned char> &);

    std::string print() const override;
};


#endif
