//
// Created by hindrik on 1-12-16.
//

#include "PostProcessing.h"

PostProcessing::~PostProcessing() {
    if(m_quadVAO != 0)
    {
        glBindVertexArray(0);
        glDeleteVertexArrays(1,&m_quadVAO);
    }
    if(m_quadVBO != 0)
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &m_quadVBO);
    }
}

PostProcessing::PostProcessing()
{
    GLfloat quadVertices[] = {
            // Positions        // Texture Coords
            -1.0f,   1.0f,  0.0f,   0.0f, 1.0f,
            -1.0f,  -1.0f,  0.0f,   0.0f, 0.0f,
             1.0f,   1.0f,  0.0f,   1.0f, 1.0f,
             1.0f,  -1.0f,  0.0f,   1.0f, 0.0f,
    };

    glGenVertexArrays(1, &m_quadVAO);
    glGenBuffers(1, &m_quadVBO);

    glBindVertexArray(m_quadVAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_quadVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
}

void PostProcessing::renderFullScreenQuad() {
    glBindVertexArray(m_quadVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);
}
