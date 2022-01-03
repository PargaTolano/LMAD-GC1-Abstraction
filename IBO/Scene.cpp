#include "utils.h"

#include "Scene.h"
#include "VAO.h"
#include "VBO.h"

Scene::Scene() {
	VAO* vao = new VAO();

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 1.0f,
		 0.5f, -0.5f, 0.0f, 1.0f,
		 0.0f,  0.5f, 0.0f, 1.0f
	};

	VBO vbo(vertices, unsafe_array_size(vertices));
	m_renderables.push_back(vao);
}

void Scene::Render() {
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	for (auto& renderable : m_renderables) {
		renderable->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}
