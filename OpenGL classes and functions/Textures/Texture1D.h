//
// Created by hindrik on 29-11-16.
//

#ifndef ASCENSION_CORE_TEXTURE1D_H
#define ASCENSION_CORE_TEXTURE1D_H

#include "../../Common.h"

class Texture1D {
private:
    string m_sourceName;
    int m_width = 0;
    GLuint m_textureID;
public:
    Texture1D(string _image, bool _generateMips = true);
    ~Texture1D();

    //No copying because it can screw the textureID deleting.
    Texture1D(const Texture1D&) = delete;
    Texture1D& operator=(const Texture1D&) = delete;
    //Moving is okay
    Texture1D(Texture1D&&) = default;
    Texture1D& operator=(Texture1D&&) = default;


    GLuint getTextureID() const;
    int getWidth() const;
    void bind() const;
};


#endif //ASCENSION_CORE_TEXTURE1D_H
