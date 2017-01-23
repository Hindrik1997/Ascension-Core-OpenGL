//
// Created by hindrik on 1-12-16.
//

#include "ForwardRenderMode.h"

#include "../Core/GLFWFunctions.h"
#include "../OpenGLMesh.h"
#include "../../Procedural Generation/ProceduralMeshGeneration.h"
#include "../../Core classes/Console.h"

OpenGLMesh* mesh;
Shader* shader;


void ForwardRenderMode::render(OpenGLRenderer& renderer, float deltaTime) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    //if hdr is enabled, render scene to this buffer!
    if(m_isHDRenabled == GL_TRUE)
    {
        glBindFramebuffer(GL_FRAMEBUFFER, m_hdrFBO);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    shader->bind();
    mesh->Draw();
    //glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

    //Map everything back to default buffer with a tonemap shader if HDR is enabled
    if(m_isHDRenabled == GL_TRUE)
    {
        //Default frame buffer
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        m_hdrShader.bind();
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_hdrTexColorBuffer);
        glUniform1i(glGetUniformLocation(m_hdrShader.getProgramID(), "hdr"), m_isHDRenabled);
        glUniform1f(glGetUniformLocation(m_hdrShader.getProgramID(), "exposure"), m_exposure);
        m_postProcessing.renderFullScreenQuad();
    }
    renderer.swapBuffers();
}

void ForwardRenderMode::initialize() {

    glEnable(GL_DEPTH_TEST);

    glDepthMask(GL_TRUE);

    glEnable(GL_CULL_FACE);

    enableHDR();

    mesh = new OpenGLMesh(ProceduralMeshGeneration::GenerateCone(1.0f, 1.0f, 10));

    shader = new Shader("../Shaders/vertex_shader.glsl","../Shaders/fragment_shader.glsl");

    Console::printLine("Forward rendermode initialized");
}

void ForwardRenderMode::enableHDR() {

    //Create frame buffer
    glGenFramebuffers(1, &m_hdrFBO);
    glGenTextures(1, &m_hdrTexColorBuffer);
    glBindTexture(GL_TEXTURE_2D, m_hdrTexColorBuffer);

    //Create color tex buffer
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, WINDOW_SIZE_X, WINDOW_SIZE_Y, 0, GL_RGBA, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Bind FBO and attach buffer
    glBindFramebuffer(GL_FRAMEBUFFER, m_hdrFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_hdrTexColorBuffer, 0);

    //Check the FBO
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        Console::printLine("Framebuffer not complete!");

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    m_isHDRenabled = GL_TRUE;
}

void ForwardRenderMode::disableHDR() {
    m_isHDRenabled = GL_FALSE;
}

ForwardRenderMode::ForwardRenderMode() {
    enableHDR();
}
