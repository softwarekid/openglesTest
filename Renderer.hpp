//
//  Renderer.hpp
//  openglESTest
//
//  Created by 王一 on 22/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp
#include "Mesh.hpp"
#include "GlslProgram.hpp"
#include <vector>

class Renderer
{
private:
    MeshPtr mesh = nullptr;
    GlslProgramPtr program = nullptr;
    
    
    // OGL buffer index
    std::vector<GLuint> VBOIndices;
    
public:
    Renderer() = default;
    
    void UpdateRenderState();
    void UpdateBindingAttribtue();
    void UpdateBindingUniform();
    void SetProgram(GlslProgramPtr program);
    void SetMesh(MeshPtr mesh);
    void Draw() const;
};

#endif /* Renderer_hpp */
