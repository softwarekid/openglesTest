//
//  GLBindBufferGuard.hpp
//  openglESTest
//
//  Created by 王一 on 21/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#ifndef GLBindBufferGuard_hpp
#define GLBindBufferGuard_hpp
#include <GL/glew.h>

class GLBindBufferGuard {
private:
    GLenum target;
public:
    GLBindBufferGuard(GLenum target, GLuint buffer);
    ~GLBindBufferGuard();
};

#endif /* GLBindBufferGuard_hpp */
