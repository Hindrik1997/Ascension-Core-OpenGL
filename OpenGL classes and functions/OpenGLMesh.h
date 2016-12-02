//
// Created by hindrik on 2-12-16.
//

#ifndef ASCENSION_CORE_OPENGLMESH_H
#define ASCENSION_CORE_OPENGLMESH_H

#include "../Common.h"
#include "../Procedural Generation/Mesh.h"

class OpenGLMesh {
private:
    Mesh m_mesh;
    GLuint m_VBO = 0, m_EBO = 0, m_VAO = 0;
    int m_triangle_count = 0;
public:
    OpenGLMesh(Mesh mesh);


    void Draw();


};


#endif //ASCENSION_CORE_OPENGLMESH_H
