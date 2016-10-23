#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>


namespace shiro {
	class Window {
	private:
		int m_width, m_height;
		const char* m_name;
		GLFWwindow *m_window;
		bool m_closed;
	public:
		Window(int width, int height, const char* name);
		~Window();
		void update();
		bool closed() const;
		void clear() const;
		inline GLFWwindow* getWindowHandler() { return m_window; };
	private:
		bool init();
	};
}
