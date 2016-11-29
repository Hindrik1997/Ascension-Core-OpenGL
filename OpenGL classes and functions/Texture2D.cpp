//
// Created by hindrik on 29-11-16.
//

#include "Texture2D.h"

Texture2D::Texture2D(string _image, bool _generateMips) : m_sourceName(_image)
{
    unsigned char* image = SOIL_load_image(_image.c_str(), &m_width, &m_height, 0, SOIL_LOAD_RGBA);

    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D,m_textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    if(_generateMips)
        glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D,0);
    SOIL_free_image_data(image);
}

GLuint Texture2D::getTextureID() const {
    return m_textureID;
}

int Texture2D::getWidth() const {
    return m_width;
}

int Texture2D::getHeight() const {
    return m_height;
}

Texture2D::~Texture2D() {
    glDeleteTextures(1, &m_textureID);
}

void Texture2D::bind() const {
    glBindTexture(GL_TEXTURE_2D, m_textureID);
}
