#ifndef ID3V2_4METAINFOPARSER_GRID_H
#define ID3V2_4METAINFOPARSER_GRID_H

#include "frame.h"

class GRID : public frame {
private:
    std::string owner;

    std::string groupSymbol;

    std::string groupData;

public:
    inline static const std::string ID = "GRID";

    GRID(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif