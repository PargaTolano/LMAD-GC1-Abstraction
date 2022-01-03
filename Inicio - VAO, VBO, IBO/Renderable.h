#pragma once

#include "VAO.h"

class Renderable
{
protected:
	VAO* _vao;
public:
	Renderable(VAO* vao);
	virtual void Render() = 0;
};