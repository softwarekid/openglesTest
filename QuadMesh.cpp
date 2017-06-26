//
//  QuadMesh.cpp
//  openglESTest
//
//  Created by 王一 on 21/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#include "QuadMesh.hpp"
#include <GL/glew.h>
#include "GLBindBufferGuard.hpp"
#include "Common.hpp"



QuadMesh::QuadMesh()
{
    static GLfloat vertices[] = {
            			// Positions        // Texture Coords
            			0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            			0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            			1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
            1.0f, 0.0f, 0.0f, 1.0f, 0.0f,};
    
    data = vertices;
    
    VBO::VSAttributeArray vsAttributes;
    vsAttributes.reserve(2);
    vsAttributes.emplace_back(0, 3, 5 * sizeof(GLfloat), 0);
    vsAttributes.emplace_back(1, 2, 5 * sizeof(GLfloat), 3 * sizeof(GLfloat));
    
    VBOVec.emplace_back(data, sizeof(vertices), GL_STATIC_DRAW , std::move(vsAttributes));
}

int QuadMesh::GetVerticeCount()
{
    return 4;
}

GLenum QuadMesh::GetPrimitiveType()
{
    return GL_TRIANGLE_STRIP;
}
