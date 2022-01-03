#pragma once

#include <inttypes.h>
#include <gl/glew.h>
#include <gl/GL.h>

class VAO
{
	GLuint _object;
public:
	VAO();
	void Bind();
	void Unbind();
};

