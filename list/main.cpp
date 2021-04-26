#include <iostream>



#define STD
#ifdef STD
#include "list.hpp"

//template <typename T, typename A = std::allocator<T> >
//ft::list<T, A>::list<typename T, typename A>() {}


int main(int argc, char **argv) {
	{
		std::cout << "DEFAULT CONSTRUCTOR: PUSH_BACK, ITERATOR, BEGIN, END, ++OPERATOR" << std::endl;
		ft::list<int> j;
		j.push_back(1);
		j.push_back(2);
		j.push_back(3);
		j.push_back(4);
		ft::list<int>::iterator jit;
		ft::list<int>::iterator jit_begin = j.begin();
		ft::list<int>::iterator jit_end = j.end();
		while (jit_begin != jit_end)
		{
			std::cout << *jit_begin << std::endl;
			++jit_begin;
		}
	}
	{
		std::cout << "FILL CONSTRUCTOR: PUSH_BACK, ITERATOR, BEGIN, END, ++OPERATOR" << std::endl;
		ft::list<int> j(4, 42);
//		ft::list<int>::iterator jit;
//		ft::list<int>::iterator jit_begin = j.begin();
//		ft::list<int>::iterator jit_end = j.end();
//		while (jit_begin != jit_end)
//		{
//			std::cout << *jit_begin << std::endl;
//			++jit_begin;
//		}
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


