#include "test.hpp"
#include <iterator>
#include <list>
#include <iostream>
#include <string>
#include <vector>

int main() {
	std::vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	v.erase(v.begin());
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	return 0;
}