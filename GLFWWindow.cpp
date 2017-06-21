//
//  GLFWManager.cpp
//  openglESTest
//
//  Created by 王一 on 21/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#include "GLFWWindow.hpp"
#include <stdlib.h>

GLFWWindow::GLFWWindow(int width, int height, const char* title)
{
    if (!glfwInit())
        exit(EXIT_FAILURE);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    
    if(!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
}

GLFWWindow::~GLFWWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void GLFWWindow::SetErrorHandleFunc(GLFWerrorfun errFunc)
{
    glfwSetErrorCallback(errFunc);
}

void GLFWWindow::SetKeyboardFunc(GLFWkeyfun keyboardFunc)
{
    glfwSetKeyCallback(window, keyboardFunc);
}

int GLFWWindow::ShouldClose()
{
    return glfwWindowShouldClose(window);
}

void GLFWWindow::SwapBuffer()
{
    glfwSwapBuffers(window);
}

void GLFWWindow::GetFrameBufferSize(int* width, int* height)
{
    return glfwGetFramebufferSize(window, width, height);
}
