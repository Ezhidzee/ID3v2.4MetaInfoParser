#ifndef ID3V2_4METAINFOPARSER_RVA2_H
#define ID3V2_4METAINFOPARSER_RVA2_H

#include "frame.h"

class RVA2 : public frame {
private:
    std::string identification;

    struct channel;

    std::string channelsString;
public:
    inline static const std::string ID = "RVA2";

    RVA2(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif
