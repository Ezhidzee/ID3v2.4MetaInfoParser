#ifndef ID3V2_4METAINFOPARSER_RBUF_H
#define ID3V2_4METAINFOPARSER_RBUF_H

#include "frame.h"

class RBUF : public frame {
private:
    int bufferSize;

    bool flag;

    int nextTagOffset;
public:
    inline static const std::string ID = "RBUF";

    RBUF(std::vector<unsigned char> &);

    std::string print() const override;
};

#endif
