#ifndef ID3V2_4METAINFOPARSER_UFID_H
#define ID3V2_4METAINFOPARSER_UFID_H

#include "frame.h"

class UFID : public frame {
private:
    std::string owner;

    std::string identifier;

public:
    inline static const std::string ID = "UFID";

    UFID(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif
