//
// Created by RenanTaylan on 15/02/23.
//

#include "Window.h"

Window::Window() {
    width = 800;
    height = 600;

    for (size_t i = 0; i < 1024; i++) {
        keys[i] = 0;
    }

}

Window::Window(GLint windowWidth, GLint windowHeight) {
    width = windowWidth;
    height = windowHeight;
    for (size_t i = 0; i < 1024; i++) {
        keys[i] = 0;
    }
}

int Window::initialise() {
    if (!glfwInit()) {
        std::cout << "GLFW init failed" << std::endl;
        glfwTerminate();
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    mainWindow = glfwCreateWindow(width, width, "Test Window", NULL, NULL);
    if (!mainWindow) {
        std::cout << "Window couldn't created!" << std::endl;
        glfwTerminate();
        return 1;

    }


    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
    std::cout << bufferWidth << " " << bufferHeight << std::endl;

    glfwMakeContextCurrent(mainWindow);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        std::cout << "Glew init failed!" << std::endl;
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, bufferWidth, bufferHeight);

    glfwSetWindowUserPointer(mainWindow, this);
    createCallbacks();

}

void Window::handleKeys(GLFWwindow *window, int key, int code, int action, int mode) {
    Window *theWindow = static_cast<Window *>(glfwGetWindowUserPointer(window));
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS) {
            theWindow->keys[key] = true;
        } else if (action == GLFW_RELEASE) {
            theWindow->keys[key] = false;
        }
    }
}

Window::~Window() {
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
}

void Window::createCallbacks() {
    glfwSetKeyCallback(mainWindow, handleKeys);
    glfwSetCursorPosCallback(mainWindow, handleMouse);
}

void Window::handleMouse(GLFWwindow *window, double xPos, double yPos) {
//    Window *theWindow = static_cast<Window *>(glfwGetWindowUserPointer(window));
    Window *theWindow = (Window*) glfwGetWindowUserPointer(window);
    if (theWindow->mouseFirstMoved) {
        theWindow->lastX = xPos;
        theWindow->lastY = yPos;
        theWindow->mouseFirstMoved = false;
    }

    theWindow->xChange = xPos - theWindow->lastX;
    theWindow->yChange = theWindow->lastY - yPos;

    theWindow->lastX = xPos;
    theWindow->lastY = yPos;

    printf("x:%.6f, y:%.6f\n", theWindow->xChange, theWindow->yChange);

}
