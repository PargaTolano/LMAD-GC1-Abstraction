#pragma once

#include <inttypes.h>
#include <gl/glew.h>
#include <gl/GL.h>

class VAO
{
	GLuint _object;
public:
	VAO();
	~VAO();

	GLuint Object();

	void Bind();
	void Unbind();
};

