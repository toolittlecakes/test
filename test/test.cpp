

#include <iostream>

#include "filter.h"

typedef float type;

int main() {
	Filter<type> f1{ std::vector<type>{3,3,3} };

	std::vector<type> in{ 0, 0, 0, 0, 3, 0, 0, 0, 0 };
	std::vector<type> result = f1.conv1d(in);

	for (auto it : result) {
		std::cout << static_cast<int>(it) << std::endl;
	}


	return 0;
}