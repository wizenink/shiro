#include "graphics\Window.h"
using namespace shiro;
	int main()
	{
		Window w(800, 600, "Hola");
		glClearColor(0.2f, 0.2f, 0.2f,1.0f);
		std::cout << "OpenGL version:" << glGetString(GL_VERSION) << std::endl;
		while (!w.closed())
		{
			w.clear();
			glBegin(GL_TRIANGLES);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.0f, 0.5f);
			glVertex2f(0.5f, -0.5f);
			glEnd();
			w.update();
		}
		return 0;
	}