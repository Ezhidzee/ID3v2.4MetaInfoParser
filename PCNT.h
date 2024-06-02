#ifndef ID3V2_4METAINFOPARSER_PCNT_H
#define ID3V2_4METAINFOPARSER_PCNT_H

#include "frame.h"

class PCNT : public frame {
private:
    long long counter;

public:
    inline static const std::string ID = "PCNT";

    PCNT(std::vector<unsigned char> &);

    std::string print() const override;
};


#endif
