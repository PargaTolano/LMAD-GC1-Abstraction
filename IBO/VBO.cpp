#include "VBO.h"

 VBO::VBO(float* vertices, int length) {
	glGenBuffers(1, &_object);
	glBindBuffer(GL_ARRAY_BUFFER, _object);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * length, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
}

void VBO::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, _object);
}
