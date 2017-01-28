//
// Created by hindrik on 29-11-16.
//

//#include "GLFWFunctions.h"
#include "Renderer.h"
#include "RenderMode.h"
#include "../../Core classes/Console.h"
#include "../RenderModes/ForwardRenderMode.h"

bool Renderer::processAPI(float deltaTime) {

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

Renderer::Renderer()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    m_window = glfwCreateWindow(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Ascension Engine", nullptr, nullptr);
    if (m_window == nullptr)
    {
        Console::printLine("Window creation failed!");
        glfwTerminate();
        throw("Initialization failed!");
    }
    glfwMakeContextCurrent(m_window);

    Console::printLine("OpenGL Rendering initialized");
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        Console::printLine("GLEW init failed!");
    }

    /*
    if (!GLEW_VERSION_4_5) {
        Console::printLine("OpenGL 4.5 API is not available, terminating...");
        throw std::runtime_error("OpenGL 4.5 API is not available.");
    }
     */

    glViewport(0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

Renderer::~Renderer() {
    glfwTerminate();
}

void Renderer::render(float deltaTime) {
    if(m_renderMode != nullptr)
        m_renderMode->render(*this, deltaTime);
}

void Renderer::swapBuffers() {
    glfwSwapBuffers(m_window);
}

void Renderer::setRenderMode(RenderMode& renderMode) {
    m_renderMode = &renderMode;
}

const RenderMode& Renderer::getRenderMode() {
    return *m_renderMode;
}
