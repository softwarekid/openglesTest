//
//  Renderer.cpp
//  openglESTest
//
//  Created by 王一 on 22/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#include "Renderer.hpp"
#include "GLBindBufferGuard.hpp"

void Renderer::SetProgram(GlslProgramPtr program)
{
    this->program = program;
}

void Renderer::SetMesh(MeshPtr mesh_)
{
    this->mesh = mesh_;
}

void UpdateRenderState()
{
    
}


void Renderer::UpdateBindingAttribtue()
{
    if(mesh != nullptr && program != nullptr)
    {
        auto vboSize = mesh->GetVboSize();
        
        VBOIndices.reserve(vboSize);
        glGenBuffers(vboSize, VBOIndices.data());
        
        for (int i = 0 ; i < vboSize; i++)
        {
            GLBindBufferGuard bindGuard(GL_ARRAY_BUFFER, VBOIndices[i]);
            auto vbo = mesh->GetVBO(i);
            glBufferData(GL_ARRAY_BUFFER, vbo.sizeInByte, vbo.data, vbo.hint);
            for (auto iter = vbo.VSAttributes.begin(); iter != vbo.VSAttributes.end();++iter)
            {
                GLuint loc = program->GetLocByIndex(iter->locationIndex);
                glEnableVertexAttribArray(loc);
                glVertexAttribPointer(loc, iter->numOfCom, GL_FLOAT, GL_FALSE, iter->stride, (GLvoid*)iter->offsetPointer);
            }
        }
    }
}

void Renderer::Draw() const
{
    program->Use();
    for (int i = 0; i < VBOIndices.size(); i++)
    {
        glBindBuffer(GL_ARRAY_BUFFER,VBOIndices[i]);
    }
    
    if (mesh->GetIndiceSize() != 0)
    {
        glDrawElements(mesh->GetPrimitiveType(), mesh->GetIndiceSize(), GL_UNSIGNED_INT, mesh->GetIndiceData());
    }
    else
    {
        glDrawArrays(mesh->GetPrimitiveType(),0 , mesh->GetVerticeCount());
    }
    
    for (int i = 0; i < VBOIndices.size(); i++)
    {
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }
}
