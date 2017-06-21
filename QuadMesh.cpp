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

void QuadMesh::Setup()
{
    GLfloat quadVertices[] = {
        			// Positions        // Texture Coords
        			0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        			0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        			1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        			1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        		};
    
    if (mVertexVBO == 0) {
        glGenBuffers(1, &mVertexVBO);
        
        GLBindBufferGuard bindGuard(GL_ARRAY_BUFFER, mVertexVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices),&quadVertices, GL_STATIC_DRAW);
        
        glCheckError();
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        
    }
}

void QuadMesh::Draw()
{
    GLBindBufferGuard bindGuard(GL_ARRAY_BUFFER, mVertexVBO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
