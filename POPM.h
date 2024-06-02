#ifndef ID3V2_4METAINFOPARSER_POPM_H
#define ID3V2_4METAINFOPARSER_POPM_H

#include "frame.h"

class POPM : public frame {
private:
    std::string email;

    int rating;

    long long counter;

public:
    inline static const std::string ID = "POPM";

    POPM(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif
