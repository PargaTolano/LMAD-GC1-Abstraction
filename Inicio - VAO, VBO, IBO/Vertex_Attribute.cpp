#include "Vertex_Attribute.h"

GLuint Vertex_Attribute::typeSize(GLuint type)
{
	switch (type) {
	case GL_FLOAT:
		return sizeof GLfloat;
	case GL_DOUBLE:
		return sizeof GLdouble;
	case GL_INT:
		return sizeof GLint;
	case GL_BYTE:
		return sizeof GLbyte;
	}
	return 0;
}