#ifndef ID3V2_4METAINFOPARSER_USLT_H
#define ID3V2_4METAINFOPARSER_USLT_H

#include "frame.h"
#include "encLenFrame.h"

class USLT : public frame, public encLenFrame {
private:
    std::string contentDescriptor;

    std::string lyrics;

public:
    inline static const std::string ID = "USLT";

    USLT(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif
