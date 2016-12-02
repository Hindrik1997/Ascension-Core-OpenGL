//
// Created by hindrik on 1-12-16.
//

#ifndef ASCENSION_CORE_VERTEX_H
#define ASCENSION_CORE_VERTEX_H

#include "Vectors/Vector2f.h"
#include "Vectors/Vector3f.h"
#include "Vectors/Vector4f.h"

class Vertex
{
public:
    Vertex();
    ~Vertex();

    Vertex(Vector3f position, Vector4f color);
    Vertex(Vector3f position, Vector3f uv, Vector3f normal, Vector4f color);
    Vertex(Vector3f position, Vector3f uv, Vector3f normal);
    Vertex(Vector3f position, Vector3f uv);
    Vertex(Vector3f position);

    Vertex(float pos_x, float pos_y, float pos_z, float uv_u, float uv_v, float uv_w, float normal_x, float normal_y, float normal_z, float color_r, float color_g, float color_b, float color_a);
    Vertex(float pos_x, float pos_y, float pos_z, float uv_u, float uv_v, float uv_w, float normal_x, float normal_y, float normal_z);
    Vertex(float pos_x, float pos_y, float pos_z, float color_r, float color_g, float color_b, float color_a);
    Vertex(float pos_x, float pos_y, float pos_z, float uv_u, float uv_v, float uv_w);
    Vertex(float pos_x, float pos_y, float pos_z);

public:
    Vector3f Position = Vector3f();
    Vector3f UVW = Vector3f();
    Vector3f Normal = Vector3f();
    Vector3f BiNormal = Vector3f();
    Vector3f Tangent = Vector3f();
    Vector4f Color = Vector4f();
};


#endif //ASCENSION_CORE_VERTEX_H
