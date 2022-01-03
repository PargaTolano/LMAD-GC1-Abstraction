#pragma once

#include <string>
#include <fstream>
#include <iterator>

#include <gl/glew.h>
#include <gl/GL.h>
#include <gl/GLU.h>

enum ShaderType {
	VertexShader	= GL_VERTEX_SHADER,
	FragmentShader	= GL_FRAGMENT_SHADER,
};

class Shader
{
	GLuint _object;
public:
	Shader(std::string path, ShaderType shader_type);
	GLuint Object();
};