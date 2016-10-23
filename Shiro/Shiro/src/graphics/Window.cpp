#include "Window.h"
namespace shiro {
	Window::Window(int width, int height, const char * name):m_name(name),m_width(width),m_height(height)
	{
		if (!init())
			glfwTerminate();
	}
	Window::~Window()
	{
		glfwTerminate();
	}
	void Window::update() 
	{
		glfwPollEvents();
		glfwGetFramebufferSize(m_window, &m_width, &m_height);
		glViewport(0, 0, m_width, m_height);
		glfwSwapBuffers(m_window);
	}
	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_window);
	}
	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cerr << "Fatal error initilizing glfw.Terminating" << std::endl;
			return false;
		}
		m_window = glfwCreateWindow(m_width, m_height, m_name, NULL, NULL);
		if (!m_window)
		{
			
			std::cerr << "Fatal error creating window.Terminating" << std::endl;
			return false;
		}
		if (!glewInit())
		{
			std::cerr << "Fatal error initializing glew.Terminating" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_window);
		return true;
	}
}