//
//  Common.hpp
//  openglESTest
//
//  Created by 王一 on 20/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#ifndef Common_hpp
#define Common_hpp

#include <GL/glew.h>
#include <string>

#define glCheckError() glCheckError_(__FILE__, __LINE__)

GLint TextureFromFile(const char* path);
GLenum glCheckError_(const char *file, int line);

//struct GlslAttribute{
//    char* name;
//    union value{
//        int iValue;
//        float fValue;
//    };
//};


#endif /* Common_hpp */
