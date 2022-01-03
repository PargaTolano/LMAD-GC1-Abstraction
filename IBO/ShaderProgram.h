#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>

#include <gl/glew.h>
#include <gl/GL.h>
#include <gl/GLU.h>

class Shader;

class ShaderProgram
{
	GLuint _object;

	Shader* m_vertex_shader;
	Shader* m_fragment_shader;

public:
	ShaderProgram(std::string vs_path, std::string fs_path);

	GLuint Object();

	void Use();

	void Unuse();
};

