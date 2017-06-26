//
//  Mesh.cpp
//  openglESTest
//
//  Created by 王一 on 21/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#include "Mesh.hpp"


void Mesh::Register(Renderer& renderer)
{
    renderer.SetMesh(shared_from_this());
}

void Mesh::Unregister(Renderer&renderer)
{
    renderer.SetMesh(nullptr);
}

std::size_t Mesh::GetVboSize() const
{
    return VBOVec.size();
}

const VBO& Mesh::GetVBO(int index) const
{
    return VBOVec[index];
}


GLenum Mesh::GetPrimitiveType()
{
    return GL_TRIANGLES;
}

int Mesh::GetIndiceSize()
{
    return 0;
}

GLvoid* Mesh::GetIndiceData()
{
    return NULL;
}
