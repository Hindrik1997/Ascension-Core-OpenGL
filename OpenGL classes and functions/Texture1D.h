//
// Created by hindrik on 29-11-16.
//

#ifndef ASCENSION_CORE_TEXTURE1D_H
#define ASCENSION_CORE_TEXTURE1D_H

#include "../Common.h"

class Texture1D {
private:
    string m_sourceName;
    int m_width = 0;
    GLuint m_textureID;
public:
    Texture1D(string _image, bool _generateMips = true);
    ~Texture1D();
    GLuint getTextureID();
    int getWidth();
};


#endif //ASCENSION_CORE_TEXTURE1D_H
