//
// Created by hindrik on 29-11-16.
//

#include "OpenGLRenderer.h"
#include "Shader.h"

Shader* shader;

void temp_test();

bool OpenGLRenderer::processAPI(float deltaTime) {

    bool shouldClose = glfwWindowShouldClose(m_window) > 0;
    if(shouldClose)
        return false;

    glfwPollEvents();

    if(deltaTime > 0.0f)
    {
        float fps = 1000.0f / deltaTime;
        string c = "Ascension Engine ";
        c.append(std::to_string(static_cast<int>(fps)));
        c.append(" FPS");
        glfwSetWindowTitle(m_window, c.c_str());
    }

    return true;
}

OpenGLRenderer::OpenGLRenderer() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    m_window = glfwCreateWindow(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Ascension Engine", nullptr, nullptr);
    if (m_window == nullptr)
    {
        cout << "Window creation failed!" << endl;
        glfwTerminate();
        throw("Initialization failed!");
    }
    glfwMakeContextCurrent(m_window);

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        cout << "GLEW init failed!" << endl;
    }
    temp_test();
}

OpenGLRenderer::~OpenGLRenderer() {
    glfwTerminate();
    delete shader;
}

void OpenGLRenderer::render() {
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(m_window);
}

void temp_test(){
    shader = new Shader("Shaders/vertex_shader.glsl","Shaders/fragment_shader.glsl");
}