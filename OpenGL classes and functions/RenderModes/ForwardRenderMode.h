//
// Created by hindrik on 1-12-16.
//

#ifndef ASCENSION_CORE_FORWARDRENDERMODE_H
#define ASCENSION_CORE_FORWARDRENDERMODE_H

#include "../Core/RenderMode.h"
#include "../PostProcessing/PostProcessing.h"
#include "../Shader.h"

class ForwardRenderMode : public RenderMode {
private:
    GLboolean m_isHDRenabled = GL_FALSE;
    GLuint m_hdrFBO = 0;
    GLuint m_hdrTexColorBuffer = 0;
    Shader m_hdrShader = Shader("../Shaders/hdr_vertex.glsl","../Shaders/hdr_fragment.glsl");
    GLfloat m_exposure = 1.0f;
    PostProcessing m_postProcessing;
public:
    ForwardRenderMode();

    void initialize() override;

    void render(Renderer &renderer, float deltaTime) override;

    void enableHDR();
    void disableHDR();
};


#endif //ASCENSION_CORE_FORWARDRENDERMODE_H
