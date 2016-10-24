#include "InputManager.h"

namespace shiro {
	bool InputManager::m_keymap[KEYMAP_SIZE];
	bool InputManager::m_mousemap[MOUSEMAP_SIZE];
	double InputManager::m_mousex = 0;
	double InputManager::m_mousey = 0;
	void InputManager::key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
	{
		if (action == GLFW_PRESS)
			InputManager::m_keymap[key] = true;
		else if (action == GLFW_RELEASE)
			InputManager::m_keymap[key] = false;
	}
	void InputManager::mousebutton_callback(GLFWwindow * window, int button, int action, int mods)
	{
		if (action == GLFW_PRESS)
			InputManager::m_keymap[button] = true;
		else if (action == GLFW_RELEASE)
			InputManager::m_keymap[button] = false;
	}
	InputManager::InputManager(GLFWwindow* window):m_window(window)
	{
		
		glfwSetKeyCallback(window,key_callback);
		glfwSetMouseButtonCallback(window, mousebutton_callback);
		for (int i = 0; i < KEYMAP_SIZE - 1; i++)
			InputManager::m_keymap[i] == false;
		for (int i = 0; i < MOUSEMAP_SIZE - 1; i++)
			InputManager::m_mousemap[i] == false;
		
	}


	InputManager::~InputManager()
	{
	}
	void InputManager::Update()
	{
		glfwGetCursorPos(m_window, &m_mousex, &m_mousey);
	}
	bool InputManager::isKeyPressed(unsigned int keycode)
	{
		if (keycode >= KEYMAP_SIZE)
			throw std::invalid_argument("Keycode out of range. Range is [0,KEYMAP_SIZE)");
		return InputManager::m_keymap[keycode];
	}
	bool InputManager::isMouseButtonPressed(unsigned int mousebuttoncode)
	{
		if (mousebuttoncode >= MOUSEMAP_SIZE)
			throw std::invalid_argument("Mouse Button Code out of range. Range is [0,MOUSEMAP_SIZE)");
		return InputManager::m_mousemap[mousebuttoncode];
	}
}