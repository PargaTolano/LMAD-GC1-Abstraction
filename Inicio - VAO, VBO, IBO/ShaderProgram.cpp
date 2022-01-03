#include "ShaderProgram.h"
#include "Shader.h"

ShaderProgram::ShaderProgram(std::string vs_path, std::string fs_path) {
	m_vertex_shader = new Shader(vs_path, ShaderType::VertexShader);
	m_fragment_shader = new Shader(fs_path, ShaderType::FragmentShader);

	_object = glCreateProgram();
	glAttachShader(_object, m_vertex_shader  ->Object());
	glAttachShader(_object, m_fragment_shader->Object());
	glLinkProgram(_object);
}

GLuint ShaderProgram::Object()
{
	return _object;
}

void ShaderProgram::Use()
{
	glUseProgram(_object);
}

void ShaderProgram::Unuse()
{
	glUseProgram(0);
}
