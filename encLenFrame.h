#ifndef ID3V2_4METAINFOPARSER_ENCLENFRAME_H
#define ID3V2_4METAINFOPARSER_ENCLENFRAME_H

#include <vector>

class encLenFrame {
protected:
    struct textInfo {
        char encoding;
        char language[3];
    };

    textInfo textInfo;
public:
    encLenFrame(std::vector<unsigned char> &);
};

#endif
