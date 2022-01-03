#pragma once

#include<gl/glew.h>
#include<gl/GL.h>
#include<vector>

#include"Vertex_Attribute.h"

template<class T>
class Vertex_Data
{
	GLuint m_stride;
	GLuint m_buffer_size;

	std::vector<T> m_data;
	std::vector<Vertex_Attribute> m_descriptor;

public:

	Vertex_Data(std::vector<T> data, std::vector<Vertex_Attribute> descriptor) :
		m_data(data),
		m_descriptor(descriptor)
	{
		m_stride = sizeof T;
		m_buffer_size = sizeof T * m_data.size();
	}

	void Data(std::vector<T> data) {
		m_data = data;
		m_buffer_size = sizeof T * m_data.size();
	}

	T* Data() {
		return m_data.data();
	}

	GLuint BufferSize() {
		return m_buffer_size;
	}


	GLuint Stride() {
		return m_stride;
	}

	std::vector<Vertex_Attribute> Descriptor() {
		return m_descriptor;
	}
};

