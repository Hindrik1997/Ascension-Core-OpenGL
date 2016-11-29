//
// Created by hindrik on 29-11-16.
//

#ifndef ASCENSION_CORE_TEXTURE2D_H
#define ASCENSION_CORE_TEXTURE2D_H

#include "../../Common.h"

class Texture2D {
private:
    string m_sourceName;
    int m_width = 0;
    int m_height = 0;
    GLuint m_textureID;
public:
    Texture2D(string _image, bool _generateMips = true);
    ~Texture2D();

    //No copying because it can screw the textureID deleting.
    Texture2D(const Texture2D&) = delete;
    Texture2D& operator=(const Texture2D&) = delete;
    //Moving is okay
    Texture2D(Texture2D&&) = default;
    Texture2D& operator=(Texture2D&&) = default;

    GLuint getTextureID() const;
    int getWidth() const;
    int getHeight() const;
    void bind() const;
};

#endif //ASCENSION_CORE_TEXTURE2D_H