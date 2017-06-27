//
//  GlslProgram.cpp
//  openglESTest
//
//  Created by 王一 on 20/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#include "GlslProgram.hpp"

#include <fstream>
#include <iostream>
#include "Common.hpp"


GlslProgram::GlslProgram(const std::string& vertSrcFile_, const std::string& fragSrcFile_, const std::string& geomSource_)  
{
    hProg = glCreateProgram();
    GLuint hVerShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint hFragShader = glCreateShader(GL_FRAGMENT_SHADER);
    LoadShaderFile(hVerShader, vertSrcFile_);
    LoadShaderFile(hFragShader, fragSrcFile_);
    GLuint hGeomShader = 0;
    if (geomSource_!= "")
    {
        GLuint hGeomShader = glCreateShader(GL_GEOMETRY_SHADER);
        LoadShaderFile(hGeomShader, geomSource_);
        glAttachShader(hProg, hGeomShader);
    }
    
    glAttachShader(hProg, hVerShader);
    glAttachShader(hProg, hFragShader);
    
    glLinkProgram(hProg);
    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(hProg, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(hProg, 512, NULL, infoLog);
        std::cout<<infoLog<<std::endl;
    }
    glUseProgram(hProg);
    glDeleteShader(hVerShader);
    glDeleteShader(hFragShader);
    glDeleteShader(hGeomShader);
}

void GlslProgram::LoadShaderFile(GLuint hShader, std::string fileName)
{
    std::ifstream file(fileName.c_str());
    if (file)
    {
        file.seekg(0, file.end);
        std::size_t length = file.tellg();
        file.seekg(0, file.beg);
        char* buffer = new char[length + 1];
        memset(buffer, 0, sizeof(char) * (length + 1));
        file.read(buffer, length);
        glShaderSource(hShader, 1, &buffer, NULL);
        delete[] buffer;
        glCompileShader(hShader);
        
        GLint success;
        GLchar infoLog[512];
        glGetShaderiv(hShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(hShader, 512, NULL, infoLog);
            std::cout << fileName << " Compile error: " << infoLog << std::endl;
        }
    }
    file.close();
}

void GlslProgram::InitAttrLocations(const std::vector<std::string>& attrNames_)
{
    attrLocations.reserve(attrNames_.size());
    for (int i = 0; i < attrNames_.size(); i++)
    {
        GLint loc = glGetAttribLocation(hProg, attrNames_[i].c_str());
        attrLocations.push_back(loc);
        nameLocMap[attrNames_[i]] = loc;
    }
}

GLuint GlslProgram::GetUniformLocation(const std::string& uniformName)
{
    return glGetUniformLocation(hProg, uniformName.c_str());
}

GLuint GlslProgram::GetAttributeLocation(const std::string& attrName)
{
    auto iter = nameLocMap.find(attrName);
    return iter == nameLocMap.end()? -1 : iter->second;
}

void GlslProgram::Use()
{
    glUseProgram(hProg);
}

void GlslProgram::Register(Renderer& renderer)
{
    renderer.SetProgram(shared_from_this());
}

void GlslProgram::Unregister(Renderer& renderer)
{
    renderer.SetProgram(nullptr);
}

GLint GlslProgram::GetLocByIndex(int index)
{
    return attrLocations[index];
}

//void GlslProgram::SetBlendActive(bool isEnabled)
//{
//    blendEnabled = isEnabled;
//}
//
//void GlslProgram::SetBlendFunc(GLenum srcFactor, GLenum dstFactor)
//{
//    srcBlendFactor = srcFactor;
//    dstBlendFactor = dstFactor;
//}
//    
//bool GlslProgram::IsBlendEnabled()
//{
//    return blendEnabled;
//}
//
//std::tuple<GLenum, GLenum> GlslProgram::GetBlendFunc()
//{
//    return std::make_tuple(srcBlendFactor, dstBlendFactor);
//}

void GlslProgram::SetFloat(const std::string& name, GLfloat value)
{
    SetFloat(GetUniformLocation(name), value);
}

void GlslProgram::SetFloat(int locIndex, GLfloat value)
{
    glUniform1f(locIndex, value);
}
    
void GlslProgram::SetInt(const std::string& name, GLint value)
{
    SetInt(GetUniformLocation(name), value);
}

void GlslProgram::SetInt(int locIndex, GLint value)
{
    glUniform1i(locIndex, value);
}
    
void GlslProgram::SetMatrix(const std::string& name, GLfloat* value)
{
    SetMatrix(GetUniformLocation(name), value);
}

void GlslProgram::SetMatrix(int locIndex, GLfloat* value)
{
    glUniformMatrix4fv(locIndex, 1, GL_FALSE, value);
}
    
void GlslProgram::SetVector(const std::string& name, GLfloat* value)
{
    SetVector(GetUniformLocation(name), value);
}

void GlslProgram::SetVector(int locIndex, GLfloat* value)
{
    glUniform3fv(locIndex, 1, value);
}
