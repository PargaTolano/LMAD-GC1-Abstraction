#pragma once
#include "Renderable.h"
#include "IBO.h"
class UnIndexedRenderable :
    public Renderable
{
    IBO* _ibo;
public:
    UnIndexedRenderable(VAO* vao) : Renderable(vao) {
    };

    void Render() override {
        _vao->Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
};

