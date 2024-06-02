#ifndef ID3V2_4METAINFOPARSER_OWNE_H
#define ID3V2_4METAINFOPARSER_OWNE_H

#include "frame.h"

class OWNE : public frame {
private:
    unsigned char encoding;

    std::string price;

    std::string date;

    std::string seller;

public:
    inline static const std::string ID = "OWNE";

    OWNE(std::vector<unsigned char> &);

    std::string print() const override;
};


#endif
