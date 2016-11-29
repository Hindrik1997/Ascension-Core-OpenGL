//
// Created by hindrik on 29-11-16.
//

#ifndef ASCENSION_CORE_TEXTURE3D_H
#define ASCENSION_CORE_TEXTURE3D_H

#include "../../Common.h"

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

    //No copying because it can screw the textureID deleting.
    Texture3D(const Texture3D&) = delete;
    Texture3D& operator=(const Texture3D&) = delete;
    //Moving is okay
    Texture3D(Texture3D&&) = default;
    Texture3D& operator=(Texture3D&&) = default;

    GLuint getTextureID() const;
    int getWidth() const;
    int getHeight() const;
    int getDepth() const;
    void bind() const;
};


#endif //ASCENSION_CORE_TEXTURE3D_H
