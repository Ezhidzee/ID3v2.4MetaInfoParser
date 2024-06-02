#ifndef ID3V2_4METAINFOPARSER_USER_H
#define ID3V2_4METAINFOPARSER_USER_H

#include "frame.h"
#include "encLenFrame.h"

class USER : public frame, public encLenFrame {
private:
    std::string text;

public:
    inline static const std::string ID = "USER";

    USER(std::vector<unsigned char> &);

    std::string print() const override;
};


#endif
