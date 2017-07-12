//
//  TexFilterProgram.hpp
//  openglESTest
//
//  Created by 王一 on 04/07/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#ifndef TexFilterProgram_hpp
#define TexFilterProgram_hpp
#include "GlslProgram.hpp"

class  TexFilterProgram : public GlslProgram
{
public:
    TexFilterProgram(const std::string& vertexSource_,  const std::string& fragSource_, const std::string& geomSource_= "");
    void Prepare(glm::mat4 MVP);
};


#endif /* TexFilterProgram_hpp */
