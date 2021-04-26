#include <iostream>



#define STD
#ifdef STD
#include "list.hpp"

//template <typename T, typename A = std::allocator<T> >
//ft::list<T, A>::list<typename T, typename A>() {}


int main(int argc, char **argv) {
	std::cout << "Case 1" << std::endl;
	ft::list<int> j;
	ft::list<int>::iterator it;
	j.push_back(1);
	j.push_back(2);
	j.push_back(3);
	j.push_back(4);
	ft::list<int>::iterator it_begin = j.begin();
	ft::list<int>::iterator it_end = j.end();
	while (it_begin != it_end)
	{
		std::cout << *it_begin << std::endl;
		++it_begin;
	}

	return 0;
}
#else
#include <list>

int main(int argc, char **argv) {
	std::cout << "Case 2" << std::endl;
	std::list<int> k;
	return 0;
}

#endif