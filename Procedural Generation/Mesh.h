//
// Created by hindrik on 1-12-16.
//

#ifndef ASCENSION_CORE_MESH_H
#define ASCENSION_CORE_MESH_H

#include "Vertex.h"
#include <vector>

using std::vector;

class Mesh
{
public:
    Mesh();
    Mesh(vector<Vertex> vertices, vector<int> indices);

    ~Mesh();

    void ReverseWindingOrder();
    void GenerateNormals();

    inline int VerticeCount();
    inline int IndiceCount();
public:
    vector<Vertex> Vertices;
    vector<int> Indices;
};

inline int Mesh::IndiceCount()
{
    return static_cast<int>(Indices.size());
}

inline int Mesh::VerticeCount()
{
    return static_cast<int>(Vertices.size());
}


#endif //ASCENSION_CORE_MESH_H
