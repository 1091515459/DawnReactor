#pragma once
#include <string>


class shaderClass1
{
public:
	shaderClass1(const char* vertexPath, const char* fragmentPath);
	std::string vertexString;
	std::string fragmentString;
	const char* vertexSource;
	const char* fragmentSource;

	unsigned int ID;
	void  use();

	//~shaderClass1();

};

