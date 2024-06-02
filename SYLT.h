#ifndef ID3V2_4METAINFOPARSER_SYLT_H
#define ID3V2_4METAINFOPARSER_SYLT_H

#include "frame.h"
#include "encLenFrame.h"

class SYLT : public frame, public encLenFrame {
private:
    std::string timeStampFormat;

    std::string contentType;

    std::string contentDescriptor;

public:
    inline static const std::string ID = "SYLT";

    SYLT(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif
