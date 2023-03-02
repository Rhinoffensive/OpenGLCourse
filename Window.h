//
// Created by RenanTaylan on 15/02/23.
//

#ifndef OPENGLCOURSE_WINDOW_H
#define OPENGLCOURSE_WINDOW_H

#include <stdio.h>
#include <iostream>

#include <GL/glew.h>
#include "GLFW/glfw3.h"

class Window {
public:
    Window();

    Window(GLint windowWidth, GLint windowheight);

    ~Window();

    int initialise();

    GLfloat getBufferWidth() { return bufferWidth; }

    GLfloat getBufferHeight() { return bufferHeight; }

    bool getShouldClose() { return glfwWindowShouldClose(mainWindow); }

    void swapBuffers(){ glfwSwapBuffers(mainWindow);}

private:
    GLFWwindow *mainWindow;
    GLint width, height;
    GLint bufferWidth, bufferHeight;

    GLfloat lastX, lastY;
    GLfloat xChange, yChange;
    bool mouseFirstMoved;

    bool keys[1024];
    void createCallbacks();

    static void handleKeys(GLFWwindow *window, int key, int code, int action, int mode);
    static void handleMouse(GLFWwindow* window, double xPos, double yPost);

};


#endif //OPENGLCOURSE_WINDOW_H
