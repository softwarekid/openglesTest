#include <GL/glew.h>
#define  GLEW_STATIC
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

#include <GLFW/glfw3.h>
#include <iostream>
#include "GlslProgram.hpp"
#include "GLFWWindow.hpp"
#include "Mesh.hpp"
#include "QuadMesh.hpp"
#include "Common.hpp"

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void)
{
    GLFWWindow window{640, 480, "Simple example"};
    window.SetErrorHandleFunc(error_callback);
    window.SetKeyboardFunc(key_callback);
    
    GLenum err = glewInit();
    if(glewInit() !=  GLEW_OK)
    {
        std::cout<<glewGetErrorString(err);
    }
    
    GlslProgram prog("shader/test.vert", "shader/test.frag");
    
    GLint mvp_location;
    mvp_location = prog.GetUniformLocation("MVP");
    
    GLuint vpos_location = prog.GetAttributeLocation("vPos");
    GLuint vcol_location = prog.GetAttributeLocation("vCol");
    
    glCheckError();
    Mesh* m = new QuadMesh();
    m->Setup();
    
    while (!window.ShouldClose())
    {
        int width, height;
        glm::mat4 mvp;
        
        window.GetFrameBufferSize(&width, &height);
        
        float ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        
        prog.Use();
        
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));
        m->Draw();
        window.SwapBuffer();
        glfwPollEvents();
    }
    exit(EXIT_SUCCESS);
}



