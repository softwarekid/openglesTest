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
    InitProgram(vertSrcFile_ , fragSrcFile_, geomSource_);
}


void GlslProgram::InitProgram(const std::string& vertSrcFile,  const std::string& fragSrcFile, const std::string& geomSrcFile )
{
    hProg = glCreateProgram();
    GLuint hVerShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint hFragShader = glCreateShader(GL_FRAGMENT_SHADER);
    LoadShaderFile(hVerShader, vertSrcFile);
    LoadShaderFile(hFragShader, fragSrcFile);
    GLuint hGeomShader = 0;
    if (geomSrcFile != "")
    {
        GLuint hGeomShader = glCreateShader(GL_GEOMETRY_SHADER);
        LoadShaderFile(hGeomShader, geomSrcFile);
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

GLuint GlslProgram::GetUniformLocation(const std::string& uniformName)
{
    return glGetUniformLocation(hProg, uniformName.c_str());
}

GLuint GlslProgram::GetAttributeLocation(const std::string& attrName)
{
    return glGetAttribLocation(hProg, attrName.c_str());
}

void GlslProgram::Use()
{
    glUseProgram(hProg);
}
