#include "Shader.h"
namespace shiro {
	Shader::Shader(const char * vertexpath, const char * fragmentpath):m_vertexpath(vertexpath),m_fragmentpath(fragmentpath)
	{
		m_shaderid = load();
	}
	void Shader::bind()
	{
		glUseProgram(m_shaderid);
	}
	void Shader::unbind()
	{
		glUseProgram(0);
	}
	GLuint Shader::load()
	{
		std::string vertexstringInitial = utils::FileUtils::loadFromFile(m_vertexpath);
		std::string fragmentstringInitial = utils::FileUtils::loadFromFile(m_fragmentpath);

		const char* vertexstring = vertexstringInitial.c_str();
		const char* fragmentstring = fragmentstringInitial.c_str();
		GLint result;
		GLint length;
 		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vertex, 1,&vertexstring, NULL);
		glCompileShader(vertex);
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
		glCompileShader(fragment);
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
		glLinkProgram(program);
		glValidateProgram(program);
		glDeleteShader(vertex);
		glDeleteShader(fragment);
		
		return program;
	}
}
