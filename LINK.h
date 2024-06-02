#ifndef ID3V2_4METAINFOPARSER_LINK_H
#define ID3V2_4METAINFOPARSER_LINK_H

#include "frame.h"

class LINK : public frame {
private:
    std::string linkedFrameIdentifier;

    std::string url;

    std::string additionalData;

public:
    inline static const std::string ID = "LINK";

    LINK(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif
