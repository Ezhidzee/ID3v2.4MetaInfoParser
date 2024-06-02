#ifndef ID3V2_4METAINFOPARSER_EQU2_H
#define ID3V2_4METAINFOPARSER_EQU2_H

#include "frame.h"

class EQU2 : public frame {
private:
    std::string interpolationMethod;

    std::string identification;

    std::string adjustmentPoints;

public:
    inline static const std::string ID = "EQU2";

    EQU2(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif
