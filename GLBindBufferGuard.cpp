//
//  GLBindBufferGuard.cpp
//  openglESTest
//
//  Created by 王一 on 21/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#include "GLBindBufferGuard.hpp"

GLBindBufferGuard::GLBindBufferGuard(GLenum target_, GLuint buffer)
{
    target = target_;
    glBindBuffer(target, buffer);
}

GLBindBufferGuard::~GLBindBufferGuard()
{
    glBindBuffer(target, 0);
}
