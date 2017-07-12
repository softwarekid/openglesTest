//
//  TexFilterProgram.cpp
//  openglESTest
//
//  Created by 王一 on 04/07/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#include "TexFilterProgram.hpp"

TexFilterProgram::TexFilterProgram(const std::string& vertexSource_,  const std::string& fragSource_, const std::string& geomSource_) :GlslProgram(vertexSource_, fragSource_, geomSource_)
{
    InitAttrLocations({"vPos", "vTex"});
    
    SetInt("albedo", 0);
    int width = 800;
    int height = 800;
    SetVector("oriTexSize", glm::vec4(width,height,0,0));
    SetVector("downTexSize", glm::vec4(width,height,0,0));
}

void TexFilterProgram::Prepare(glm::mat4 MVP)
{
}
