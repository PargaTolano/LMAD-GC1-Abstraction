#pragma once

#include <inttypes.h>
#include <gl/glew.h>
#include <gl/GL.h>

class VBO
{
	GLuint _object;
public: 
	VBO(float* vertices, int length);
	void Bind();
};

