//
// Created by RenanTaylan on 1/02/23.
//

#ifndef OPENGLCOURSE_MESH_H
#define OPENGLCOURSE_MESH_H
#include "GL/glew.h"

class Mesh {

public:
    Mesh();
    void CreateMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices);
    void RenderMesh();
    void ClearMesh();
    ~Mesh();
private:
    GLuint VAO,VBO,IBO;
    GLsizei indexCount;

};


#endif //OPENGLCOURSE_MESH_H
