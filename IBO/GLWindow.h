#pragma once

#include "mode.h"

#ifdef _WINDOWSx64_MODE
#include <Windows.h>
#endif


#include <gl/glew.h>
#include <string>

#ifdef _GLFW3_MODE
	#include <GLFW/glfw3.h>
#endif

class Scene;
	
//Inyectar una escena a la ventana para renderizar
class GLWindow
{
		#ifdef _GLFW3_MODE
			GLFWwindow* m_window;
		#endif

		int	m_width;
		int	m_height;
		std::string m_title;

		Scene*		m_scene;
public:
	GLWindow(int width, int height, std::string title);
	~GLWindow();

	bool Init();
	void Loop();
};