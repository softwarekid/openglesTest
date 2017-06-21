//
//  QuadMesh.hpp
//  openglESTest
//
//  Created by 王一 on 21/06/2017.
//  Copyright © 2017 王一. All rights reserved.
//

#ifndef QuadMesh_hpp
#define QuadMesh_hpp

#include "Mesh.hpp"

class QuadMesh : public Mesh
{
public:
    QuadMesh(){};
    void Setup() override;
    void Draw() override;
};

#endif /* QuadMesh_hpp */
