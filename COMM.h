#ifndef ID3V2_4METAINFOPARSER_COMM_H
#define ID3V2_4METAINFOPARSER_COMM_H

#include "frame.h"
#include "encLenFrame.h"

class COMM : public frame, public encLenFrame {
private:
    std::string text;

public:
    inline static const std::string ID = "COMM";

    COMM(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif
