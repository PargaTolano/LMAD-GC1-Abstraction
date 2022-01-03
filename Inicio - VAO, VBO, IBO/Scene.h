#pragma once

#include <vector>

#include "Renderable.h"

class VAO;

class Scene
{
	std::vector<Renderable*> m_renderables;
public:
	Scene();

	void Render();
};