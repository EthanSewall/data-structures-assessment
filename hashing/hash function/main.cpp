#include "hashing.h"
#include <iostream>

int main()
{
	std::cout << "hashing int: 42" << std::endl;
	std::cout << hash(42) << std::endl;

	std::cout << "" << std::endl;

	char h[12] = "lorem ipsum";
	
	std::cout << "hashing string: lorem ipsum" << std::endl;
	std::cout << hash(h,11) << std::endl;
	
	return 543;
}