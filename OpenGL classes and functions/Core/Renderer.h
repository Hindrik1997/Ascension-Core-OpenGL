//
// Created by hindrik on 29-11-16.
//

#ifndef ASCENSION_CORE_OPENGLRENDERER_H
#define ASCENSION_CORE_OPENGLRENDERER_H

#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 800

#include "../../Common.h"

class RenderMode;

class Renderer {
private:
    GLFWwindow* m_window = nullptr;
    RenderMode* m_renderMode = nullptr;
public:
    Renderer();
    ~Renderer();
public:
    void render(float deltaTime);
    bool processAPI(float deltaTime);
    void swapBuffers();
public:
    void setRenderMode(RenderMode& renderMode);
    const RenderMode& getRenderMode();
};


#endif //ASCENSION_CORE_OPENGLRENDERER_H