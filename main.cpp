#include <iostream>
#include <string.h>
#include "stdlib.h"

#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <vector>
#include "Mesh.h"
#include "Shader.h"
#include "Window.h"

const GLint WIDTH = 800, HEIGHT = 600;

std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;
Window myWindow;



// Vertex Shader
static const char *vShader = "Shaders/shader.vert";
//Fragment Shader
static const char *fShader = "Shaders/shader.frag";

void CreateObjects() {
    unsigned int indicies[] = {
            0,3,1,
            1,3,2,
            2,3,0,
            0,1,2
    };
    GLfloat vertices[] = {
            -1.0f, -1.0f, 1.0f,   // (-1,-1,0) Bottom-left
            0.0f, -1.0f, -1.0f,    // (0,-1,1)  Behind-bottom
            1.0f, -1.0f, 1.0f,    // (1,-1,0) Bottom-right
            0.0f, 1.0f, 0.0f     // (0,1,0)  Top
    };

    Mesh *obj1 = new Mesh();
    obj1->CreateMesh(vertices,indicies,12,12);
    meshList.push_back(obj1);

    Mesh *obj2 = new Mesh();
    obj2->CreateMesh(vertices,indicies,12,12);
    meshList.push_back(obj2);
}



void CreateShaders(){
    Shader *shader1 = new Shader();
    shader1->CreateFromFile(vShader, fShader);
    shaderList.push_back(*shader1);

}

int main() {
    myWindow = Window(800,600);
    myWindow.initialise();
    
    GLuint uniformModel = 0, uniformProjection=0;

    CreateObjects();
    CreateShaders();
    glm::mat4 projection = glm::perspective(45.0f, (GLfloat)myWindow.getBufferWidth()/(GLfloat)myWindow.getBufferHeight(),0.1f, 100.0f);

    while (!myWindow.getShouldClose()) {
        glfwPollEvents();

        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderList[0].UseShader();
        uniformModel = shaderList[0].GetModelLocation();
        uniformProjection = shaderList[0].GetProjectionLocation();

        glm::mat4 model(1.0f);
        model = glm::translate(model, glm::vec3 ( 0.0f,0.0f,-10.0f));
        model = glm::rotate(model, 0.0f, glm::vec3(0.0f, 1.0f, 0.f) );
        glUniformMatrix4fv(uniformModel,1, GL_FALSE, glm::value_ptr(model) );
        glUniformMatrix4fv(uniformProjection,1, GL_FALSE, glm::value_ptr(projection) );
        meshList[0]->RenderMesh();

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3 ( 0.0f,1.0f,-2.5f));
        model = glm::rotate(model, 0.0f, glm::vec3(0.0f, 1.0f, 0.f) );
        model = glm::scale(model, glm::vec3(0.4f,0.4f,1.0f));
        glUniformMatrix4fv(uniformModel,1, GL_FALSE, glm::value_ptr(model) );
        meshList[1]->RenderMesh();

        glUseProgram(0);
        myWindow.swapBuffers();

    }
    return 0;
}
