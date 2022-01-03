#pragma once

#include <inttypes.h>
#include <gl/glew.h>
#include <gl/GL.h>
#include "Vertex_Data.h"

template<class T>
class VBO
{
	GLuint _object;
public: 
	VBO(Vertex_Data<T> vertex_data) {
		GLuint	stride		= vertex_data.Stride();
		GLuint  buffer_size = vertex_data.BufferSize();
		T*		data		= vertex_data.Data();
		auto    descriptor = vertex_data.Descriptor();

		glGenBuffers(1, &_object);
		glBindBuffer(GL_ARRAY_BUFFER, _object);
		glBufferData(GL_ARRAY_BUFFER, buffer_size, data, GL_STATIC_DRAW);

		int offset = 0;
		for (int i = 0; i < descriptor.size(); i++) {
			glVertexAttribPointer(i, descriptor[i].count, descriptor[i].type, GL_FALSE, stride, (const void*)offset);
			glEnableVertexAttribArray(i);
			offset += Vertex_Attribute::typeSize(descriptor[i].type) * descriptor[i].count;
		}

	}
	~VBO() {
		Unbind();
		glDeleteBuffers(1, &_object);
	}
	GLuint Object() {
		return _object;
	}
	void Bind() {
		glBindBuffer(GL_ARRAY_BUFFER, _object);
	}
	void Unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
};

