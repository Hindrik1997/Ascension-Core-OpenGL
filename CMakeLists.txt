cmake_minimum_required(VERSION 3.6)
project(Ascension-Core)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

link_directories("${PROJECT_SOURCE_DIR}/Libs/SOIL")
include_directories("${PROJECT_SOURCE_DIR}/Includes/")


link_libraries(libGLEW.a glfw3.a libSOIL.a GL GLU X11 Xxf86vm dl Xinerama Xcursor pthread Xi Xrandr freetype)

set(SOURCE_FILES main.cpp main.cpp "Core classes/Engine.cpp" "Core classes/Engine.h" "OpenGL classes and functions/Shader.cpp" "OpenGL classes and functions/Shader.h" Common.h "Core classes/Clock.cpp" "Core classes/Clock.h" "OpenGL classes and functions/OpenGLRenderer.cpp" "OpenGL classes and functions/OpenGLRenderer.h" "Core classes/Renderer.h" "Data Storage/CacheOptimizedStorage.h" "Data Storage/Pool.h" "Data Storage/PoolItem.h" "Data Storage/StorageItem.h" "OpenGL classes and functions/Texture2D.cpp" "OpenGL classes and functions/Texture2D.h" "OpenGL classes and functions/Texture3D.cpp" "OpenGL classes and functions/Texture3D.h" "OpenGL classes and functions/Texture1D.cpp" "OpenGL classes and functions/Texture1D.h")
add_executable(Ascension-Core ${SOURCE_FILES})