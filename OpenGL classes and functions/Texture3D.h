//
// Created by hindrik on 29-11-16.
//

#ifndef ASCENSION_CORE_TEXTURE3D_H
#define ASCENSION_CORE_TEXTURE3D_H

#include "../Common.h"

class Texture3D {
private:
    string m_sourceName;
    int m_width = 0;
    int m_height = 0;
    int m_depth = 0;
    GLuint m_textureID;
public:
    Texture3D(string _image, bool _generateMips = true);
    ~Texture3D();
    GLuint getTextureID();
    int getWidth();
    int getHeight();
    int getDepth();
};


#endif //ASCENSION_CORE_TEXTURE3D_H
