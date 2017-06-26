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
#include <vector>
#include <unordered_map>
#include "Renderer.hpp"

// 由于继承了enable_shared_from_this，所以glslProgram只能通过shared_ptr来调用。
class GlslProgram : public std::enable_shared_from_this<GlslProgram>
{
public:
    GlslProgram(const std::string& vertexSource_,  const std::string& fragSource_, const std::string& geomSource_= "");
    void Use();
    
    void InitAttrLocations(const std::vector<std::string>& attrNames_);
    
    GLuint GetUniformLocation(const std::string& uniformName);
    GLuint GetAttributeLocation(const std::string& attrName);
    
    // register and unregister program to a renderer
    void Register(Renderer& rendererPtr);
    void Unregister(Renderer& rendererPtr);
    GLint GetLocByIndex(int index);
    
    
    // set uniform values
    void SetFloat(const std::string& name, GLfloat value);
    void SetFloat(int locIndex, GLfloat value);
    
    void SetInt(const std::string& name, GLint value);
    void SetInt(int locIndex, GLint value);
    
    void SetMatrix(const std::string& name, GLfloat* value);
    void SetMatrix(int locIndex, GLfloat* value);
    
    void SetVector(const std::string& name, GLfloat* value);
    void SetVector(int locIndex, GLfloat* value);
    
private:
    void LoadShaderFile(GLuint hShader, std::string fileName);
    GLuint hProg = 0;
    
    // 这个vector中atrrLocation的顺序默认对应Mesh中定义的顺序
    // 如果要改对应关系，建议改这个vector中的顺序，将Mesh中的顺序视为不变
    // ---                ---
    // |1|   -----------> |1|
    // ---                ---
    
    std::vector<GLint> attrLocations;
    std::unordered_map<std::string, GLint> nameLocMap;
};


#endif /* GlslProgram_hpp */
