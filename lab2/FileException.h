#pragma once
#include <string>
#include <system_error>
class FileException: public std::runtime_error{
public:
	FileException(std::string fileName);
};

