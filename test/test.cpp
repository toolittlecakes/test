

#include <iostream>

#include "filter.h"

int main() {
	Filter<float> f1{ std::vector<float>{3,3,3} };

	std::vector<float> in{ 0, 0, 0, 0, 3, 0, 0, 0, 0 };
	std::vector<float> result = f1.conv1d(in);

	for (auto it : result) {
		std::cout << it << std::endl;
	}


	return 0;
}