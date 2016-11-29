//
// Created by hindrik on 27-11-16.
//

#ifndef ASCENSION_CORE_ENGINE_H
#define ASCENSION_CORE_ENGINE_H

#include "../Common.h"
#include "Clock.h"
#include "Renderer.h"
#include "../Data Storage/CacheOptimizedStorage.h"

struct GameObject {

    GameObject(int a,short b){ this->a = a; this->b = b; }

    int a;
    short b;
};

class Engine {
public:
    Engine();
    ~Engine();
private:
    CacheOptimizedStorage<GameObject> m_objects;

    bool m_Quit = false;
    Clock m_internalClock;
    Renderer* m_renderer = nullptr;
public:
    void run();
};


#endif //ASCENSION_CORE_ENGINE_H
