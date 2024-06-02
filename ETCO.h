#ifndef ID3V2_4METAINFOPARSER_ETCO_H
#define ID3V2_4METAINFOPARSER_ETCO_H

#include "frame.h"

class ETCO : public frame {
private:
    std::string timeStampFormat;

    std::string events;

    void eventTypeDefinition(std::vector<unsigned char> &);

public:
    inline static const std::string ID = "ETCO";

    ETCO(std::vector<unsigned char> &);

    std::string print() const override;
};


#endif
