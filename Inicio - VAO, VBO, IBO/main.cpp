#define GLEW_BUILD
#include "GLWindow.h"

int main() {
	// Meterlo en un scope para llamar deconstructor 
	{
		GLWindow window(512, 480, "Leccion - 01");
		if(window.Init())
			window.Loop();
	}
	return 0;
};