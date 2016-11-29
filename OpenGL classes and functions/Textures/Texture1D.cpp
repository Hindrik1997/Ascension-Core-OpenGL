//
// Created by hindrik on 29-11-16.
//

#include "Texture1D.h"

Texture1D::Texture1D(string _image, bool _generateMips) : m_sourceName(_image)
{
    int height;
    unsigned char* image = SOIL_load_image(_image.c_str(), &m_width, &height, 0, SOIL_LOAD_RGBA);

    if(height != 1)
        throw "Use texture2D for loading 2D images";

    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_1D,m_textureID);

    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, m_width, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    if(_generateMips)
        glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_1D, 0);
    SOIL_free_image_data(image);
}

GLuint Texture1D::getTextureID() const {
    return m_textureID;
}

int Texture1D::getWidth() const {
    return m_width;
}

Texture1D::~Texture1D() {
    glDeleteTextures(1, &m_textureID);
}

void Texture1D::bind() const {
    glBindTexture(GL_TEXTURE_1D, m_textureID);
}
