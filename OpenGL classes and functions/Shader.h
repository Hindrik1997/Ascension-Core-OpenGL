//
// Created by hindrik on 27-11-16.
//

#ifndef ASCENSION_CORE_SHADER_H
#define ASCENSION_CORE_SHADER_H

#include "../Common.h"

class Shader {
private:
    static GLuint loadVertexShader(const string _shader);
    static GLuint loadFragmentShader(const string _shader);
    static GLuint loadGeometryShader(const string _shader);
public:
    static GLuint compileShaderProgram(const string _vertexShader, const string _fragmentShader);
    static GLuint compileShaderProgram(const string _vertexShader, const string _geometryShader, const string _fragmentShader);
private:
    GLuint m_shaderProgram = 0;
public:
    Shader(const string _vertexShader, const string _fragmentShader);
    Shader(const string _vertexShader, const string _geometryShader, const string _fragmentShader);
    ~Shader();

    //No copying because it can screw the shader program deleting.
    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;
    //Moving is okay
    Shader(Shader&&) = default;
    Shader& operator=(Shader&&) = default;
public:
    void bind() const;
    GLuint getProgramID();
};


#endif //ASCENSION_CORE_SHADER_H