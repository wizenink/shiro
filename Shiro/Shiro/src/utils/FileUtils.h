#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>
#include <algorithm>
namespace shiro { namespace utils {
	class FileUtils {
	public:
		static std::string loadFromFile(const char* filepath);
	};
} }