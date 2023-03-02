cmake_minimum_required(VERSION 3.24)
project(OpenGLCourse)

set(CMAKE_CXX_STANDARD 17)


add_executable(OpenGLCourse main.cpp Mesh.cpp Mesh.h Mesh.cpp Shader.cpp Shader.h Window.cpp Window.h)
file(COPY Shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(PkgConfig REQUIRED)

pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(GLEW REQUIRED glew)
pkg_check_modules(GLM REQUIRED glm)


find_package(GLEW REQUIRED)
find_package(glfw3 3.3.8 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm 0.9 REQUIRED)


#include_directories(${GLFW_INCLUDE_DIRS}/include)
#link_directories(${GLFW_INCLUDE_DIRS}/lib)
target_link_libraries(OpenGLCourse OpenGL::GL glfw GLEW::GLEW glm::glm)

#link_libraries(glfw)
