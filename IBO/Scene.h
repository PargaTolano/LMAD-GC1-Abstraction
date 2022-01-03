#pragma once

#include <vector>

class VAO;

class Scene
{
	std::vector<VAO*> m_renderables;
public:
	Scene();

	void Render();
};