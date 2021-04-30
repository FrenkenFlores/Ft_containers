#include <iostream>



#define STD
#ifdef STD
#include "list.hpp"
#include <vector>


//template <typename T, typename A = std::allocator<T> >
//ft::list<T, A>::list<typename T, typename A>() {}


int main(int argc, char **argv) {
//	{
//		std::cout << "DEFAULT CONSTRUCTOR: PUSH_BACK, FORWARD ITERATOR, BEGIN, END, ++OPERATOR" << std::endl;
//		ft::list<int> j;
////		j.push_back(1);
////		j.push_back(2);
////		j.push_back(3);
////		j.push_back(4);
////		j.push_back(5);
////		j.push_back(6);
////		j.push_back(9);
//
//		ft::list<int>::iterator jit_begin = j.begin();
//		ft::list<int>::iterator jit_end = j.end();
//		j.push_back(1);
//		j.push_back(2);
//		j.push_back(3);
//		j.push_back(4);
//		j.push_back(5);
//		j.push_back(6);
//		j.push_back(9);
//		std::cout << *jit_begin << std::endl;
//		++jit_begin;
////		ft::list<int>::iterator jit_begin = j.begin();
////		ft::list<int>::iterator jit_end = j.end();
//		while (jit_begin != jit_end)
//		{
//			std::cout << *jit_begin << std::endl;
//			++jit_begin;
//		}
//	}


	{
		std::cout << "DEFAULT CONSTRUCTOR: PUSH_BACK, BACK WORD ITERATOR, BEGIN, END, ++OPERATOR" << std::endl;
		ft::list<int> j;
		j.push_back(1);
		j.push_back(2);
		j.push_back(3);
		j.push_back(4);
		j.push_back(2);
		j.push_back(6);
		j.push_back(9);

		ft::list<int>::iterator jit_begin = j.begin();
		ft::list<int>::iterator jit_end = j.end();
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
		while (jit_begin != jit_end)
		{
			std::cout << *jit_end << std::endl;
			--jit_end;
		}
		++jit_end;
		std::cout << *jit_end << std::endl;
		++jit_end;
		std::cout << *jit_end << std::endl;
		--jit_end;
		std::cout << *jit_end << std::endl;
		--jit_end;
		std::cout << *jit_end << std::endl;
	}


//	{
//		std::cout << "FILL CONSTRUCTOR: PUSH_BACK, ITERATOR, BEGIN, END, ++OPERATOR" << std::endl;
//		ft::list<int> j(4, 42);
//		ft::list<int>::iterator jit;
//		ft::list<int>::iterator jit_begin = j.begin();
//		ft::list<int>::iterator jit_end = j.end();
//		while (jit_begin != jit_end)
//		{
//			std::cout << *jit_begin << std::endl;
//			++jit_begin;
//		}
//	}
//	{
//		std::cout << "RANGE <VECTOR> CONSTRUCTOR: PUSH_BACK, ITERATOR, BEGIN, END, ++OPERATOR" << std::endl;
//		std::vector<int> h(5, 42);
//		ft::list<int> k(h.begin(), h.end());
//		ft::list<int>::iterator kt;
//		ft::list<int>::iterator kit_begin = k.begin();
//		ft::list<int>::iterator kit_end = k.end();
//		while (kit_begin != kit_end)
//		{
//			std::cout << *kit_begin << std::endl;
//			++kit_begin;
//		}
//	}
//	{
//		std::cout << "RANGE <ARRAY> CONSTRUCTOR: PUSH_BACK, ITERATOR, BEGIN, END, ++OPERATOR" << std::endl;
//		int array[] = {1, 2, 3, 4, 5};
//		ft::list<int> k(array, array + sizeof(array) / sizeof(int));
//		ft::list<int>::iterator kt;
//		ft::list<int>::iterator kit_begin = k.begin();
//		ft::list<int>::iterator kit_end = k.end();
//		while (kit_begin != kit_end)
//		{
//			std::cout << *kit_begin << std::endl;
//			++kit_begin;
//		}
//	}
//	{
//		std::cout << "COPY CONSTRUCTOR: PUSH_BACK, ITERATOR, BEGIN, END, ++OPERATOR" << std::endl;
//		int array[] = {1, 2, 3, 4, 5};
//		ft::list<int> z(array, array + sizeof(array) / sizeof(int));
//		std::cout << "-------------------------------------------------------------" << std::endl;
//		ft::list<int> k(z);
//		ft::list<int>::iterator kit_begin = k.begin();
//		ft::list<int>::iterator kit_end = k.end();
//		while (kit_begin != kit_end)
//		{
//			std::cout << *kit_begin << std::endl;
//			++kit_begin;
//		}
//	}
//

	return 0;
}
#else

#include <iostream>
#include <string>
#include <list>

int main()
{
    std::list<int> l;
	std::list<int>::iterator it_begin = l.begin();
	std::list<int>::iterator it_end = l.end();
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    std::cout << *it_begin << std::endl;
//	std::list<int>::iterator it_begin = l.begin();
//	std::list<int>::iterator it_end = l.end();
	++it_begin;
	while (it_begin != it_end)
	{
		std::cout << *it_begin << std::endl;
		++it_begin;
	}


}

#endif


