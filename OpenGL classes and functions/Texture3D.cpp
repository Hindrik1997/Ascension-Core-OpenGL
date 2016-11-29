//
// Created by hindrik on 29-11-16.
//

#include "Texture3D.h"

Texture3D::Texture3D(string _image, bool _generateMips) : m_sourceName(_image)
{
    unsigned char* image = SOIL_load_image(_image.c_str(), &m_width, &m_height, 0, SOIL_LOAD_RGBA);

    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_3D,m_textureID);

    glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, m_width, m_height, m_depth, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    if(_generateMips)
        glGenerateMipmap(GL_TEXTURE_3D);

    glBindTexture(GL_TEXTURE_3D,0);
    SOIL_free_image_data(image);
}

GLuint Texture3D::getTextureID() {
    return m_textureID;
}

int Texture3D::getWidth() {
    return m_width;
}

int Texture3D::getHeight() {
    return m_height;
}

int Texture3D::getDepth() {
    return m_depth;
}

Texture3D::~Texture3D() {
    glDeleteTextures(1, &m_textureID);
}