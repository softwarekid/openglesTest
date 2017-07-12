//
//  UVAnimationProg.hpp
//  openglESTest
//
//  Created by 王一 on 04/07/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#ifndef UVAnimationProg_hpp
#define UVAnimationProg_hpp

#include "GlslProgram.hpp"
#include <chrono>

class UVAnimationProg : public GlslProgram
{
public:
    UVAnimationProg(const std::string& vertexSource_,  const std::string& fragSource_, const std::string& geomSource_= "");
    
    void Prepare(const glm::mat4& mvp) override;
private:
    
    std::chrono::time_point<std::chrono::system_clock> startTime;
};


#endif /* UVAnimationProg_hpp */
