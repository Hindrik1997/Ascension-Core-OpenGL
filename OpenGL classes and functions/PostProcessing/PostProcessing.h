//
// Created by hindrik on 1-12-16.
//

#ifndef ASCENSION_CORE_POSTPROCESSING_H
#define ASCENSION_CORE_POSTPROCESSING_H

#include "../../Common.h"

class PostProcessing
{
private:
    GLuint m_quadVBO = 0;
    GLuint m_quadVAO = 0;
public:
    PostProcessing();
    ~PostProcessing();
public:
    void renderFullScreenQuad();
};

#endif //ASCENSION_CORE_POSTPROCESSING_H
