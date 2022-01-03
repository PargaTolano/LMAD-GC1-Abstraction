#include "GLWindow.h"
#include "Scene.h"

GLWindow::GLWindow(int width, int height, std::string title) :
	m_width(width),
	m_height(height),
	m_title(title),
	m_scene(nullptr) {}

GLWindow::~GLWindow() {
#ifdef _GLFW3_MODE
	glfwTerminate();
#endif
}

bool GLWindow::Init() {
#ifdef _GLFW3_MODE

	if (glfwInit() == GLFW_FALSE)
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	m_window = glfwCreateWindow(
		m_width,
		m_height,
		m_title.c_str(),
		nullptr,  //Monitor para fullscreen						-> No usado
		nullptr); //Otra ventana con la cual compartir recursos	-> No usado

	if (m_window == nullptr)
		return false;

	glfwMakeContextCurrent(m_window);

	glewExperimental = GL_TRUE;
	int res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return false;
	}

#endif

	m_scene = new Scene();

	return true;
}

void GLWindow::Loop() {
#ifdef _GLFW3_MODE
	while (!glfwWindowShouldClose(m_window)) {
		m_scene->Render();
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
#endif
}
