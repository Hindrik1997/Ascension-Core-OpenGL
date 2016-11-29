cmake_minimum_required(VERSION 3.6)
project(Ascension-Core)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

link_libraries(libGLEW.a glfw3.a GL GLU X11 Xxf86vm dl Xinerama Xcursor pthread Xi Xrandr freetype)

set(SOURCE_FILES main.cpp main.cpp "Core classes/Engine.cpp" "Core classes/Engine.h" "OpenGL classes and functions/Shader.cpp" "OpenGL classes and functions/Shader.h" Common.h "Core classes/Clock.cpp" "Core classes/Clock.h" "OpenGL classes and functions/OpenGLRenderer.cpp" "OpenGL classes and functions/OpenGLRenderer.h" "Core classes/Renderer.h" "Data Storage/CacheOptimizedStorage.h" "Data Storage/Pool.h" "Data Storage/PoolItem.h" "Data Storage/StorageItem.h")
add_executable(Ascension-Core ${SOURCE_FILES})