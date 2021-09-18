#include "module1.h"
#include "module2.h"
#include "module3.h"
#include <iostream>

int main() {

	std::cout << "Hello World" << std::endl;
	
	std::cout << Module1::getMyName() << std::endl;
	std::cout << Module2::getMyName() << std::endl;

	using namespace Module1;
	std::cout << getMyName() << std::endl;
	std::cout << Module2::getMyName() << std::endl;

	//using namespace Module2;
	//std::cout << getMyName() << std::endl;

	using Module3::getMyName;
	std::cout << getMyName() << std::endl;

	return 0;
}