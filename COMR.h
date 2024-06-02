#ifndef ID3V2_4METAINFOPARSER_COMR_H
#define ID3V2_4METAINFOPARSER_COMR_H

#include "frame.h"

class COMR : public frame {
private:
    unsigned char encoding;

    std::string price;

    std::string date;

    std::string url;

    std::string receivedAs;

    std::string seller;

    std::string description;

public:
    inline static const std::string ID = "COMR";

    COMR(std::vector<unsigned char> &);

    std::string print() const override;
};


#endif
