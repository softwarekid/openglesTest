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
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "Common.hpp"
#include "Renderer.hpp"

class Mesh : public std::enable_shared_from_this<Mesh>
{
    enum class MeshType
    {
        DEFORMABLE,
        NONEDEFORMABLE
    };
    
protected:
    std::vector<VBO> VBOVec;
    MeshType deformable = MeshType::NONEDEFORMABLE;
    
    
public:
    Mesh() = default;
    void Register(Renderer& rendererPtr);
    void Unregister(Renderer& rendererPtr);
    
//    virtual const std::vector<VBO>& GetVBOVec() = 0;
    virtual GLenum GetPrimitiveType();
    virtual int GetIndiceSize();
    virtual GLvoid* GetIndiceData();
    virtual int GetVerticeCount() = 0;
    
//    virtual GLfloat* GetPostionArray() = 0;
//    virtual GLfloat* GetNonPostionArray() {return NULL;}
    
    std::size_t GetVboSize() const;
    const VBO& GetVBO(int index) const;
    
    
    virtual void Update(){}
    virtual ~Mesh() = default;
};

#endif /* Mesh_hpp */
