//
// Created by RenanTaylan on 14/02/23.
//

#ifndef OPENGLCOURSE_SHADER_H
#define OPENGLCOURSE_SHADER_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "GL/glew.h"

class Shader {
public:
    Shader();
    ~Shader();

    void CreateFromString(const char* vertexCode, const char* fragmentCode);
    void CreateFromFile(const char* vertexFile, const char* fragmentFile);
    std::string ReadFile(const char* fileLocation);
    GLuint GetProjectionLocation();
    GLuint GetModelLocation();

    void UseShader();
    void ClearShader();

private:
    GLuint shaderID, uniformProjection, uniformModel;
    void CompileShader(const char* vertexCode, const char* fragmentCode);
    void AddShader(GLuint theProgram, const char *shaderCode, GLenum shaderType);

};


#endif //OPENGLCOURSE_SHADER_H
