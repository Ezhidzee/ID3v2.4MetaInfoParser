#ifndef ID3V2_4METAINFOPARSER_POSS_H
#define ID3V2_4METAINFOPARSER_POSS_H

#include "frame.h"

class POSS : public frame {
private:
    std::string format;

    long long position;
public:
    inline static const std::string ID = "POSS";

    POSS(std::vector<unsigned char> &);

    std::string print() const override;
};


#endif
