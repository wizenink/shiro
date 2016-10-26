#include "FileUtils.h"
namespace shiro { namespace utils {

	std::string FileUtils::loadFromFile(const char* filepath)
	{
		FILE* file = fopen(filepath, "rb");
		fseek(file, 0, SEEK_END);
		int length = ftell(file);
		std::string result(length, 0);
		fseek(file, 0, SEEK_SET);
		fread(&result[0], 1, length, file);
		fclose(file);
		result.erase(std::remove(result.begin(), result.end(), '\r'), result.end());
		return result;
	}

} }
