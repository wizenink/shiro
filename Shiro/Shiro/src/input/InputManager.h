#pragma once
#define KEYMAP_SIZE 1024
#define MOUSEMAP_SIZE 32
#include <GLFW\glfw3.h>
#include <iostream>
#include <exception>
namespace shiro {
	class InputManager
	{
	public:
	private:
		static bool m_keymap[KEYMAP_SIZE];
		static bool m_mousemap[MOUSEMAP_SIZE];
		static double m_mousex, m_mousey;
		GLFWwindow* m_window;
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
		static void mousebutton_callback(GLFWwindow* window, int button, int action, int mods);
	public:
		InputManager(GLFWwindow* window);
		~InputManager();
		void Update();
		bool isKeyPressed(unsigned int keycode) const;
		bool isMouseButtonPressed(unsigned int mousebuttoncode) const;
	};
}
