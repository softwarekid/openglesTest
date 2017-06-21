//
//  GlslProgram.hpp
//  openglESTest
//
//  Created by 王一 on 20/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#ifndef GlslProgram_hpp
#define GlslProgram_hpp

#include <GL/glew.h>
#include <string>

class GlslProgram
{
public:
    GlslProgram(const std::string& vertexSource_,  const std::string& fragSource_, const std::string& geomSource_= "");
    void Use();
    GLuint GetUniformLocation(const std::string& uniformName);
    GLuint GetAttributeLocation(const std::string& attrName);
private:
    void InitProgram(const std::string& vertexSource_,  const std::string& fragSource_, const std::string& geomSource_= "");
    void SetUnifromData();
    void LoadShaderFile(GLuint hShader, std::string fileName);
    
    GLuint hProg = 0;
};


#endif /* GlslProgram_hpp */
