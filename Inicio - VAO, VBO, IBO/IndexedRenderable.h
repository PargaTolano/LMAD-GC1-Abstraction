#pragma once
#include "Renderable.h"
#include "IBO.h"

class IndexedRenderable :
    public Renderable
{
    IBO* _ibo;
public:
    IndexedRenderable(VAO* vao, IBO* ibo) : Renderable(vao), _ibo(ibo) {
    };

    void Render() override {
        _vao->Bind();
        glDrawElements(GL_TRIANGLES, _ibo->Count(), GL_UNSIGNED_INT, 0);
    }
};

