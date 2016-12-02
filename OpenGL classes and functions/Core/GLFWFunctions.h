//
// Created by hindrik on 30-11-16.
//

#ifndef ASCENSION_CORE_GLFWFUNCTIONS_H
#define ASCENSION_CORE_GLFWFUNCTIONS_H

#include "../../Common.h"


inline static void KeyCallback(GLFWwindow *window, int key, int scanCode, int action, int mods) {
    if(key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        int k = glfwGetInputMode(window, GLFW_CURSOR);
        int t;
        if(k == GLFW_CURSOR_DISABLED)
            t = GLFW_CURSOR_NORMAL;
        else
            t = GLFW_CURSOR_DISABLED;

        glfwSetInputMode(window, GLFW_CURSOR, t);
    }
}

inline static void MouseCallback(GLFWwindow *window, double x, double y) {

}

#endif //ASCENSION_CORE_GLFWFUNCTIONS_H
