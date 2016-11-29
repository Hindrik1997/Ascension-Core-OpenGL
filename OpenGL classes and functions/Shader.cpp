//
// Created by hindrik on 27-11-16.
//

#include "Shader.h"
#include <fstream>

GLuint Shader::loadVertexShader(const string _shader) {
    const int debugBufSize = 512;
    GLint success;
    GLchar debugMsg[debugBufSize];
    std::ifstream vertex(_shader);

    string vSource((std::istreambuf_iterator<char>(vertex)), std::istreambuf_iterator<char>());
    const char* vp = vSource.c_str();

    GLuint shader;
    shader= glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(shader, 1, &vp, NULL);
    glCompileShader(shader);

    //Check of alles goed gelukt is

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, debugBufSize, NULL, debugMsg);
        cout << debugMsg << endl;
        throw "FAILED COMPILATION VERTEXSHADER";
    }
    return shader;
}

GLuint Shader::loadFragmentShader(const string _shader) {
    const int debugBufSize = 512;
    GLint success;
    GLchar debugMsg[debugBufSize];
    std::ifstream vertex(_shader);

    string vSource((std::istreambuf_iterator<char>(vertex)), std::istreambuf_iterator<char>());
    const char* vp = vSource.c_str();

    GLuint shader;
    shader= glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(shader, 1, &vp, NULL);
    glCompileShader(shader);

    //Check of alles goed gelukt is

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, debugBufSize, NULL, debugMsg);
        cout << debugMsg << endl;
        throw "FAILED COMPILATION VERTEXSHADER";
    }
    return shader;
}

GLuint Shader::loadGeometryShader(const string _shader) {
    const int debugBufSize = 512;
    GLint success;
    GLchar debugMsg[debugBufSize];
    std::ifstream vertex(_shader);

    string vSource((std::istreambuf_iterator<char>(vertex)), std::istreambuf_iterator<char>());
    const char* vp = vSource.c_str();

    GLuint shader;
    shader= glCreateShader(GL_GEOMETRY_SHADER);

    glShaderSource(shader, 1, &vp, NULL);
    glCompileShader(shader);

    //Check of alles goed gelukt is

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, debugBufSize, NULL, debugMsg);
        cout << debugMsg << endl;
        throw "FAILED COMPILATION VERTEXSHADER";
    }
    return shader;
}

GLuint Shader::compileShaderProgram(const string _vertexShader, const string _fragmentShader) {
    const int debugBufSize = 512;
    GLint success;
    GLchar debugMsg[debugBufSize];

    GLuint vShader = loadVertexShader(_vertexShader);
    GLuint fShader = loadFragmentShader(_fragmentShader);

    GLuint shaderID = glCreateProgram();
    glAttachShader(shaderID, vShader);
    glAttachShader(shaderID, fShader);
    glLinkProgram(shaderID);

    //Checken of linken gelukt is!
    glGetProgramiv(shaderID, GL_LINK_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shaderID, debugBufSize, NULL, debugMsg);
        cout << debugMsg << endl;
        throw "FAILED LINKING SHADERPROGRAM";
    }

    //Rotzooi opruimen
    glDeleteShader(vShader);
    glDeleteShader(fShader);
    return shaderID;
}

GLuint Shader::compileShaderProgram(const string _vertexShader, const string _geometryShader, const string _fragmentShader) {
    const int debugBufSize = 512;
    GLint success;
    GLchar debugMsg[debugBufSize];

    GLuint vShader = loadVertexShader(_vertexShader);
    GLuint gShader = loadGeometryShader(_geometryShader);
    GLuint fShader = loadFragmentShader(_fragmentShader);

    GLuint shaderID = glCreateProgram();
    glAttachShader(shaderID, vShader);
    glAttachShader(shaderID, gShader);
    glAttachShader(shaderID, fShader);
    glLinkProgram(shaderID);

    //Checken of linken gelukt is!
    glGetProgramiv(shaderID, GL_LINK_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shaderID, debugBufSize, NULL, debugMsg);
        cout << debugMsg << endl;
        throw "FAILED LINKING SHADERPROGRAM";
    }

    //Rotzooi opruimen
    glDeleteShader(vShader);
    glDeleteShader(gShader);
    glDeleteShader(fShader);
    return shaderID;
}

Shader::Shader(const string _vertexShader, const string _fragmentShader) {
    m_shaderProgram = compileShaderProgram(_vertexShader, _fragmentShader);
}

Shader::Shader(const string _vertexShader, const string _geometryShader, const string _fragmentShader) {
    m_shaderProgram = compileShaderProgram(_vertexShader,_geometryShader,_fragmentShader);
}

Shader::~Shader() {
    glUseProgram(0);
    glDeleteProgram(m_shaderProgram);
}

void Shader::bind() const {
    glUseProgram(m_shaderProgram);
}