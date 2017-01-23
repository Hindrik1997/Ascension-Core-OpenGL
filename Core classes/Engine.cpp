//
// Created by hindrik on 27-11-16.
//

#include "Engine.h"

void Engine::run() {
    while(!m_quit)
    {
        float deltaTime = m_internalClock.getDeltaTime();

        if(!m_renderer->processAPI(deltaTime))
        {
            m_quit = false;
            break;
        }

        m_renderer->render(deltaTime);
    }
}

Engine::Engine() {
    m_renderer = new OpenGLRenderer();
    m_forward = new ForwardRenderMode();
    m_forward->initialize();
    static_cast<OpenGLRenderer*>(m_renderer)->setRenderMode(*m_forward);
}

Engine::~Engine() {
    SAFE_PNTR_DEL(m_renderer);
    SAFE_PNTR_DEL(m_forward);
}