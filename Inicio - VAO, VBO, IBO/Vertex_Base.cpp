#include "Vertex_Base.h"

Vertex_Base::Vertex_Base(float x, float y, float z, float w) 
	: pos(glm::vec4(x,y,z,w))
{
}
