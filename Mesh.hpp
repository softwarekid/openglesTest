//
//  Mesh.hpp
//  openglESTest
//
//  Created by 王一 on 21/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp
#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <GL/glew.h>

class Mesh
{
protected:
    GLuint mVertexVBO = 0;
    GLuint mEBO = 0;
public:
    Mesh() = default;
    virtual void Setup(){};
    virtual void Draw() = 0;
    virtual void Update(){}
    virtual ~Mesh() = default;
};

#endif /* Mesh_hpp */
