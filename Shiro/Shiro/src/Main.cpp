#include "graphics\Window.h"
#include "input\InputManager.h"
#include "utils\FileUtils.h"
#include "maths\vec4f.h"
#include "graphics\Shader.h"

using namespace shiro;
	int main()
	{
		//utils::FileUtils::loadFromFile(R"(test.txt)");
		vec4f x(1, 2, 3, 4);
		vec4f y(1, 2, 3, 4);
		vec4f z = x + y;
		//z += y;
		//std::cout << z.x << z.y << z.z << z.w << std::endl;
		std::cout << z;
		getchar();

		Window w(800, 600, "Hola");
		
		glClearColor(0.2f, 0.2f, 0.2f,1.0f);
		std::cout << "GLFW version:" << glfwGetVersionString() << std::endl;
		std::cout << "OpenGL version:" << glGetString(GL_VERSION) << std::endl;
		Shader s(R"(C:\Users\David\Source\Repos\shiro\Shiro\Debug\basic.vert)",R"(C:\Users\David\Source\Repos\shiro\Shiro\Debug\basic.frag)");

		GLfloat vertices[] =
		{
			-0.5f,0.5f,0.0f,
			0.0f,0.5f,0.0f,
			0.5f,-0.5f,0.0f

		};
		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);
		s.bind();
		InputManager m(w.getWindowHandler());
		float offsetx = 0;
		float offsety = 0;
		while (!w.closed())
		{
			if (m.isKeyPressed(GLFW_KEY_UP) == true)
				offsety += 0.001f;
			if (m.isKeyPressed(GLFW_KEY_RIGHT) == true)
				offsetx += 0.001f;
			if (m.isKeyPressed(GLFW_KEY_DOWN) == true)
				offsety -= 0.001f;
			if (m.isKeyPressed(GLFW_KEY_LEFT) == true)
				offsetx -= 0.001f;
			//std::cout << offsetx << std::endl;
			w.clear();
#if 0
			glBegin(GL_TRIANGLES);
			glVertex2f(-0.5f+offsetx, -0.5f+offsety);
			glVertex2f(0.0f + offsetx, 0.5f+offsety);
			glVertex2f(0.5f + offsetx, -0.5f+offsety);
			glEnd();
#endif
			glDrawArrays(GL_TRIANGLES, 0, 3);
			w.update();
		}
		return 0;
	}