//
//  GLFWWindow.hpp
//  openglESTest
//
//  Created by 王一 on 21/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#ifndef GLFWWindow_hpp
#define GLFWWindow_hpp

#include <GLFW/glfw3.h>

class GLFWWindow
{
private:
    GLFWwindow* window;
public:
    GLFWWindow(int width, int height, const char* windowName);
    void SetErrorHandleFunc(GLFWerrorfun errFunc);
    void SetKeyboardFunc(GLFWkeyfun keyboardFunc);
    int ShouldClose();
    void SwapBuffer();
    void GetFrameBufferSize(int* widht, int* height);
    
    ~GLFWWindow();
};

#endif /* GLFWWindow

_hpp */
