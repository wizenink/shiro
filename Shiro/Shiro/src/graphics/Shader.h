#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <vector>
#include "../utils/FileUtils.h"
namespace shiro {

	class Shader {
	private:
		GLuint m_shaderid;
		const char* m_vertexpath;
		const char* m_fragmentpath;
	public:
		Shader(const char* vertexpath, const char* fragmentpath);
		void bind();
		void unbind();
	private:
		GLuint load();
	};
}