//
// Created by hindrik on 27-11-16.
//

#include "Engine.h"
#include "../OpenGL classes and functions/OpenGLRenderer.h"

void Engine::run() {

    for(uint16_t i = 0; i < m_objects.size(); ++i)
    {
        m_objects.getNewItem(0,0);
    }

    for(uint16_t i = 0; i < m_objects.size(); ++i)
    {
        m_objects.removeItem(i);
    }



    while(!m_Quit)
    {
        float deltaTime = m_internalClock.getDeltaTime();

        if(!m_renderer->processAPI(deltaTime))
        {
            m_Quit = false;
            break;
        }

        m_renderer->render();
    }
}

Engine::Engine() {
    m_renderer = new OpenGLRenderer();
}

Engine::~Engine() {
    SAFE_PNTR_DEL(m_renderer);
}
