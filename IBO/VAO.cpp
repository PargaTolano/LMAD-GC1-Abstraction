#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &_object);
	glBindVertexArray(_object);
}

void VAO::Bind() {
	glBindVertexArray(_object);
}

void VAO::Unbind() {
	glBindVertexArray(0);
}
