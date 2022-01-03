#pragma once

#include <vector>
#include <inttypes.h>
#include <gl/glew.h>
#include <gl/GL.h>

class IBO
{
	GLuint _object;
	GLuint _count;
public:
	IBO(std::vector<uint32_t> indices) {
		_count = indices.size();
		glGenBuffers(1, &_object);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _object);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(), GL_STATIC_DRAW);
	}
	~IBO() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &_object);
	}
	GLuint Object() {
		return _object;
	}
	GLuint Count() {
		return _count;
	}
};

