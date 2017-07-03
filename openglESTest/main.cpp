#include <GL/glew.h>
#define  GLEW_STATIC
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include "GlslProgram.hpp"
#include "GLFWWindow.hpp"
#include "Mesh.hpp"
#include "QuadMesh.hpp"
#include "Common.hpp"
#include "Renderer.hpp"

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
    GLFWWindow window{256, 256, "Simple example"};
    window.SetErrorHandleFunc(error_callback);
    window.SetKeyboardFunc(key_callback);
    
    GLenum err = glewInit();
    if(glewInit() !=  GLEW_OK)
    {
        std::cout<<glewGetErrorString(err);
    }
    
    Renderer quadRenderer;
    auto prog = std::make_shared<GlslProgram>("shader/test.vert", "shader/test.frag");
    prog->Register(quadRenderer);
    auto mesh = std::make_shared<QuadMesh>();
    mesh->Register(quadRenderer);
    
    prog->InitAttrLocations({"vPos", "vTex"});
    quadRenderer.UpdateBindingAttribtue();
    
    GLint textureId = LoadAndSetDefaultTexture("textures/BakedSpriteTexture.png");
    
    prog->SetInt("albedo", 0);
    prog->SetInt("rowFrameNum", 5);
    prog->SetInt("colFrameNum", 5);
    prog->SetFloat("speed", 30.0f);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
//    std::chrono::time_point<std::chrono::system_clock> startTime;
    auto startTime = std::chrono::system_clock::now();
    while (!window.ShouldClose())
    {
        int width, height;
        glm::mat4 mvp;
        window.GetFrameBufferSize(&width, &height);
        float ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        
        std::chrono::duration<double> eplasedTime = std::chrono::system_clock::now() - startTime;
        prog->SetFloat("time_", eplasedTime.count());
        
        prog->SetMatrix("MVP", glm::value_ptr(mvp));
        glBindTexture(GL_TEXTURE_2D, textureId);
        quadRenderer.Draw();
        
        window.SwapBuffer();
        glfwPollEvents();
    }
    exit(EXIT_SUCCESS);
}
