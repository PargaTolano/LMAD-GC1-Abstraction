#include "utils.h"

#include "Scene.h"
#include "VAO.h"
#include "VBO.h"
#include "IBO.h"

#include "UnIndexedRenderable.h"
#include "IndexedRenderable.h"

#include "Vertex_Base.h"

Scene::Scene() {
	VAO* vao = new VAO();
	vao->Bind();

	std::vector<Vertex_Base> vertices = {
		Vertex_Base(-1,  1),
		Vertex_Base( 0,  0),
		Vertex_Base(-1,-1)
	};

	std::vector<Vertex_Attribute> descriptor = {
		{ GL_FLOAT, 4 }
	};

	Vertex_Data<Vertex_Base> vertex_data(vertices, descriptor);

	VBO<Vertex_Base> vbo(vertex_data);
	m_renderables.push_back(new UnIndexedRenderable(vao));
	vao->Unbind();

	vao = new VAO();
	vao->Bind();

	vertices = {
		Vertex_Base( 1, 1),
		Vertex_Base( 0, 0),
		Vertex_Base( 1,-1)
	};

	std::vector<uint32_t> indices = {
		0,1,2
	};

	VBO<Vertex_Base> vbo2(Vertex_Data<Vertex_Base>(vertices, descriptor));
	IBO* ibo = new IBO(indices);
	Renderable* r = new IndexedRenderable(vao, ibo);
	m_renderables.push_back( r );
	vao->Unbind();
}

void Scene::Render() {
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	for (auto& renderable : m_renderables) {
		renderable->Render();
	}
}
