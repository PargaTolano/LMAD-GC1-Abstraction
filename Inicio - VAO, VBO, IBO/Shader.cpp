#include "Shader.h"

Shader::Shader(std::string path, ShaderType shader_type) {

	std::ifstream shader_file(path);
	std::string shader_string(std::istreambuf_iterator<char>(shader_file), (std::istreambuf_iterator<char>()));
	const char* shader_code = shader_string.c_str();

	_object = glCreateShader(shader_type);
	glShaderSource(_object, 1, &shader_code, NULL);
	glCompileShader(_object);
}

GLuint Shader::Object() {
	return _object;
}
