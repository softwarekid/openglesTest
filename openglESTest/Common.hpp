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
#include <vector>

class Mesh;
class GlslProgram;
class Renderer;

typedef std::shared_ptr<Mesh> MeshPtr;
typedef std::shared_ptr<GlslProgram> GlslProgramPtr;
typedef std::shared_ptr<Renderer> RendererPtr;

#define glCheckError() glCheckError_(__FILE__, __LINE__)

GLint LoadAndSetDefaultTexture(const char* path);
GLenum glCheckError_(const char *file, int line);



// 将OGL的attribute进行封装，减少mesh和OGL状态的耦合
// 暂时只支持float和non-normalized的格式
struct VSAttribute
{
    GLuint  locationIndex;
    GLint   numOfCom;
    GLsizei stride;
    GLint   offsetPointer;
    
    VSAttribute(GLuint locationIndex_, GLint numOfCom_, GLsizei stride_, GLint offsetPointer_):
                locationIndex(locationIndex_),numOfCom(numOfCom_),stride(stride_),offsetPointer(offsetPointer_)
    {}
};

typedef std::shared_ptr<VSAttribute> VSAttributePtr;

struct VBO
{
    typedef std::vector<VSAttribute> VSAttributeArray;
    GLfloat* data;
    GLsizeiptr sizeInByte;
    GLenum hint;
    VSAttributeArray VSAttributes;
    
    
    VBO(GLfloat* data_, GLsizeiptr sizeInByte_, GLenum hint_, VSAttributeArray VSAttributes_):
    data(data_),sizeInByte(sizeInByte_),hint(hint_), VSAttributes(std::move(VSAttributes_))
    {}
};

#endif /* Common_hpp */
