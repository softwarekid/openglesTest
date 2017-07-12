//
//  UVAnimationProg.cpp
//  openglESTest
//
//  Created by 王一 on 04/07/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#include "UVAnimationProg.hpp"
#include <glm/gtc/type_ptr.hpp>


UVAnimationProg::UVAnimationProg(const std::string& vertexSource_,  const std::string& fragSource_, const std::string& geomSource_) : GlslProgram(vertexSource_, fragSource_, geomSource_)
{
    InitAttrLocations({"vPos", "vTex"});
    
    SetInt("albedo", 0);
    SetInt("rowFrameNum", 8);
    SetInt("colFrameNum", 4);
    SetFloat("speed", 60.0f);
    
    Reset();
    startTime = std::chrono::system_clock::now();
}

void UVAnimationProg::Prepare(const glm::mat4& mvp)
{
    std::chrono::duration<double> eplasedTime = std::chrono::system_clock::now() - startTime;
    SetFloat("time_", eplasedTime.count());
    SetMatrix("MVP", mvp);
    glCheckError();
}
