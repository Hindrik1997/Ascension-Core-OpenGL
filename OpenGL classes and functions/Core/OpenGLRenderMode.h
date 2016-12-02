//
// Created by hindrik on 1-12-16.
//

#ifndef ASCENSION_CORE_OPENGLRENDERMODE_H
#define ASCENSION_CORE_OPENGLRENDERMODE_H

#include "../../Common.h"
#include "OpenGLRenderer.h"

class OpenGLRenderer;

class OpenGLRenderMode {
public:
    virtual void initialize() = 0;

    virtual void render(OpenGLRenderer &renderer, float deltaTime) = 0;
};


#endif //ASCENSION_CORE_OPENGLRENDERMODE_H