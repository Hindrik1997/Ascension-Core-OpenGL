cmake_minimum_required(VERSION 3.6)
project(Ascension-Core)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories("${PROJECT_SOURCE_DIR}/Includes/")


link_libraries(GLEW libglfw.so libSOIL.a GL GLU X11 Xxf86vm dl Xinerama Xcursor pthread Xi Xrandr freetype assimp)

set(SOURCE_FILES
        "main.cpp"
        "Core classes/Engine.cpp"
        "Core classes/Engine.h"
        "OpenGL classes and functions/Shader.cpp"
        "OpenGL classes and functions/Shader.h"
        "Common.h"
        "Core classes/Clock.cpp"
        "Core classes/Clock.h"
        "OpenGL classes and functions/Core/OpenGLRenderer.cpp"
        "OpenGL classes and functions/Core/OpenGLRenderer.h"
        "Core classes/Renderer.h"
        "Data Storage/CacheOptimizedStorage.h"
        "Data Storage/Pool.h"
        "Data Storage/PoolItem.h"
        "Data Storage/StorageItem.h"
        "OpenGL classes and functions/Textures/Texture2D.cpp"
        "OpenGL classes and functions/Textures/Texture2D.h"
        "OpenGL classes and functions/Textures/Texture3D.cpp"
        "OpenGL classes and functions/Textures/Texture3D.h"
        "OpenGL classes and functions/Textures/Texture1D.cpp"
        "OpenGL classes and functions/Textures/Texture1D.h"
        "OpenGL classes and functions/Core/GLFWFunctions.h"
        "Procedural Generation/ProceduralMeshGeneration.h"
        "Procedural Generation/ProceduralMeshGeneration.cpp"
        "Procedural Generation/Mesh.cpp"
        "Procedural Generation/Mesh.h"
        "Procedural Generation/Vertex.cpp"
        "Procedural Generation/Vertex.h"
        "Procedural Generation/Vectors/Vector2f.h"
        "Procedural Generation/Vectors/Vector2f.cpp"
        "Procedural Generation/Vectors/Vector3f.h"
        "Procedural Generation/Vectors/Vector3f.cpp"
        "Procedural Generation/Vectors/Vector4f.h"
        "Procedural Generation/Vectors/Vector4f.cpp"
        "OpenGL classes and functions/Core/OpenGLRenderMode.h"
        "OpenGL classes and functions/RenderModes/ForwardRenderMode.cpp"
        "OpenGL classes and functions/RenderModes/ForwardRenderMode.h"
        "OpenGL classes and functions/PostProcessing/PostProcessing.h"
        "OpenGL classes and functions/PostProcessing/PostProcessing.cpp"

        "OpenGL classes and functions/OpenGLMesh.cpp" "OpenGL classes and functions/OpenGLMesh.h" "Core classes/Console.h")

add_executable(Ascension-Core ${SOURCE_FILES})
