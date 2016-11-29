//
// Created by hindrik on 29-11-16.
//

#ifndef ASCENSION_CORE_RENDERER_H
#define ASCENSION_CORE_RENDERER_H

class Renderer {
public:
    virtual void render() = 0;
    virtual bool processAPI(float deltaTime) = 0;
    inline virtual ~Renderer() = 0;
};

inline Renderer::~Renderer()
{

}

#endif //ASCENSION_CORE_RENDERER_H