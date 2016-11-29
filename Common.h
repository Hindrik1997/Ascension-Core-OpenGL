//
// Created by hindrik on 27-11-16.
//

#ifndef ASCENSION_CORE_COMMON_H
#define ASCENSION_CORE_COMMON_H

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <stdint.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::vector;

// GLEW as static lib
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//SOIL
#include <SOIL/SOIL.h>

//Simpele macro om pointers te deleten enzo
#define SAFE_PNTR_DEL(x) if(x != nullptr) delete x;

#endif //ASCENSION_CORE_COMMON_H
