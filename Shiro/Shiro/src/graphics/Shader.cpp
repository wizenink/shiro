#include "Shader.h"
namespace shiro {
	Shader::Shader(const char * vertexpath, const char * fragmentpath):m_vertexpath(vertexpath),m_fragmentpath(fragmentpath)
	{
		m_shaderid = load();
	}
	GLuint Shader::load()
	{
		const char* vertexstring = utils::FileUtils::loadFromFile(m_vertexpath).c_str();
		const char* fragmentstring = utils::FileUtils::loadFromFile(m_fragmentpath).c_str();
		GLint result;
		GLint length;
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vertex, 1,&vertexstring, NULL);
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> log(length);
			glGetShaderInfoLog(vertex,length,&length,&log[0]);
			std::cerr << "Failed to compile vertex shader:" <<&log[0] << std::endl;
			glDeleteShader(vertex);
			return 0;
		}

		glShaderSource(fragment, 1, &fragmentstring, NULL);
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> log(length);
			glGetShaderInfoLog(fragment, length, &length, &log[0]);
			std::cerr << "Failed to compile fragment shader:" << &log[0] << std::endl;
			glDeleteShader(fragment);
			return 0;
		}
		glAttachShader(program, vertex);
		glAttachShader(program, fragment);
		glValidateProgram(program);
		glDeleteShader(vertex);
		glDeleteShader(fragment);
		
		return program;
	}
}
