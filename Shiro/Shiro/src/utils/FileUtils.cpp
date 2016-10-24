#include "FileUtils.h"
namespace shiro { namespace utils {

	std::string FileUtils::loadFromFile(const char* filepath)
	{
		std::ifstream file;
		std::stringstream buffer;
		file.open(filepath);
		if (file.is_open())
		{
			buffer << file.rdbuf();
			std::cout << "FILE CONTENT:" << buffer.str() << std::endl;
			file.close();
			return buffer.str();
		}
		else throw std::runtime_error("File not found");
	}

} }
