#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &_object);
	glBindVertexArray(_object);
}

VAO::~VAO()
{
	Unbind();
	glDeleteVertexArrays(1, &_object);
}

GLuint VAO::Object()
{
	return _object;
}

void VAO::Bind() {
	glBindVertexArray(_object);
}

void VAO::Unbind() {
	glBindVertexArray(0);
}
