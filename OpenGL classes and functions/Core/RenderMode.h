//
// Created by hindrik on 1-12-16.
//

#ifndef ASCENSION_CORE_OPENGLRENDERMODE_H
#define ASCENSION_CORE_OPENGLRENDERMODE_H

#include "../../Common.h"
#include "Renderer.h"

class Renderer;

class RenderMode {
public:
    virtual void initialize() = 0;
    virtual void render(Renderer &renderer, float deltaTime) = 0;
};

class NullRenderMode : public RenderMode {
public:
    void initialize() override {
        std::cout << "NULL rendermode initialized. Swallow drawing..." << std::endl;
    }
    void render(Renderer &renderer, float deltaTime) override {
        //Swallow it
    }
};


#endif //ASCENSION_CORE_OPENGLRENDERMODE_H