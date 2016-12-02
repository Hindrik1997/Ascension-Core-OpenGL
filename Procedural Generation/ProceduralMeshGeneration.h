//
// Created by hindrik on 1-12-16.
//

#ifndef ASCENSION_CORE_PROCEDURALMESHGENERATION_H
#define ASCENSION_CORE_PROCEDURALMESHGENERATION_H

#include "Mesh.h"

namespace ProceduralMeshGeneration
{
    //Generates procedural plane
    Mesh GeneratePlane(int verticesWidth, int verticesHeight, float widthVertsDistance = 1, float heightVertsDistance = 1);

    //Generates procedural cone
    Mesh GenerateCone(float height, float radius, int segments);

    //Generates procedural circle
    Mesh GenerateCircle(float radius, int segments);

    //Generates procedural quad using differing width and height
    Mesh GenerateQuad(float width, float height);

    //Generates procedural quad
    Mesh GenerateQuad(float size);

    //Generates procedural quad used for texturing using differing width and height
    Mesh GenerateTextureQuad(float width, float height);

    //Generates procedural quad used for texturing
    Mesh GenerateTextureQuad(float size);

};

#endif //ASCENSION_CORE_PROCEDURALMESHGENERATION_H
