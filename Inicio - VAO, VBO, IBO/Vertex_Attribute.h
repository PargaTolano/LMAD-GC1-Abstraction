#pragma once
#include <gl/glew.h>
#include <gl/GL.h>
struct Vertex_Attribute {
	GLuint type;
	GLuint count;
	static GLuint typeSize(GLuint);
};