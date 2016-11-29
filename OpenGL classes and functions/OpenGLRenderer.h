//
// Created by hindrik on 29-11-16.
//

#ifndef ASCENSION_CORE_OPENGLRENDERER_H
#define ASCENSION_CORE_OPENGLRENDERER_H

#define WINDOW_SIZE_X 800
#define WINDOW_SIZE_Y 600

#include "../Common.h"
#include "../Core classes/Renderer.h"

class OpenGLRenderer : public Renderer {
private:
    GLFWwindow* m_window = nullptr;
public:
    OpenGLRenderer();
    ~OpenGLRenderer();
public:
    void render() override;
    bool processAPI(float deltaTime) override;
};


#endif //ASCENSION_CORE_OPENGLRENDERER_H
