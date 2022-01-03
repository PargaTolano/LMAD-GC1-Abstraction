#pragma once
#include <gl/glew.h>
#include <gl/GL.h>

#include <glm/glm.hpp>
#include <vector>


class Vertex_Base
{
public:

	Vertex_Base() = default;
	Vertex_Base(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);
	glm::vec4 pos;
};