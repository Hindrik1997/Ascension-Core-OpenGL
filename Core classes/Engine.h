//
// Created by hindrik on 27-11-16.
//

#ifndef ASCENSION_CORE_ENGINE_H
#define ASCENSION_CORE_ENGINE_H

#include "../Common.h"
#include "Clock.h"
#include "Renderer.h"
#include "../Data Storage/CacheOptimizedStorage.h"
#include "../OpenGL classes and functions/RenderModes/ForwardRenderMode.h"

class Engine {
public:
    Engine();
    ~Engine();
private:
    bool m_quit = false;
    Clock m_internalClock;
    Renderer* m_renderer = nullptr;
    ForwardRenderMode* m_forward = nullptr;
public:
    void run();
};


#endif //ASCENSION_CORE_ENGINE_H
