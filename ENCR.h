#ifndef ID3V2_4METAINFOPARSER_ENCR_H
#define ID3V2_4METAINFOPARSER_ENCR_H

#include "frame.h"

class ENCR : public frame {
private:
    std::string ownerInfo;

    std::string encryptionMethodSymbol;

    std::string encryptionData;

public:
    inline static const std::string ID = "ENCR";

    ENCR(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif
