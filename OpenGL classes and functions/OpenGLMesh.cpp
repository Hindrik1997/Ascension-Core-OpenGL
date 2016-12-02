//
// Created by hindrik on 2-12-16.
//

#include "OpenGLMesh.h"

void OpenGLMesh::Draw() {
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, m_triangle_count, GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}

OpenGLMesh::OpenGLMesh(Mesh mesh) {

    vector<GLfloat> vertices;
    vector<GLint> indices;

    for(Vertex v : mesh.Vertices)
    {
        vertices.push_back(v.Position.x);
        vertices.push_back(v.Position.y);
        vertices.push_back(v.Position.z);

        vertices.push_back(v.Normal.x);
        vertices.push_back(v.Normal.y);
        vertices.push_back(v.Normal.z);

        vertices.push_back(v.UVW.x);
        vertices.push_back(v.UVW.y);
        vertices.push_back(v.UVW.z);
    }

    for(int indice : mesh.Indices)
    {
        indices.push_back(indice);
    }

    if(m_EBO != 0)
        glDeleteBuffers(1,&m_EBO);
    if(m_VBO != 0)
        glDeleteBuffers(1,&m_VBO);
    if(m_VAO != 0)
        glDeleteVertexArrays(1,&m_VAO);

    glGenBuffers(1, &m_EBO);
    glGenBuffers(1, &m_VBO);
    glGenVertexArrays(1, &m_VAO);

    //alles moet in de VAO, dus die binden we hier.
    glBindVertexArray(m_VAO);

    //Vanaf nu wordt het aan de VAO gekoppeld

    //Vertex buffer koppelen
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    //Vertices copyen
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

    //Index buffer koppelen
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);

    //indices copyen
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLint), &indices[0], GL_STATIC_DRAW);

    //vertex attributes instellen
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)0);
    //positie is index 0 instellen
    glEnableVertexAttribArray(0);

    //normal attributes instellen
    glVertexAttribPointer(1,3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

    //normal is index 2 instellen
    glEnableVertexAttribArray(1);


    //texcoord attributes instellen
    glVertexAttribPointer(2,3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));

    //texcoord is index 2 instellen
    glEnableVertexAttribArray(2);


    //Unbinden van de VAO
    glBindVertexArray(0);

    m_triangle_count = mesh.IndiceCount();

}
