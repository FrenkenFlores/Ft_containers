#include <iostream>
#include <unistd.h>


#define STD
#ifdef STD
#include "list.hpp"
#include <vector>
#include <string>
#include <list>

using namespace std;

//template <typename T, typename A = std::allocator<T> >
//ft::list<T, A>::list<typename T, typename A>() {}


int main(int argc, char **argv) {
	{
		std::list<int> k;
		std::cout << "OPERATR+() & OPERATOR-() & OPERATOR[]" << std::endl;
		ft::list<int> j;
		for (int i = 0; i < 10; ++i) {
			j.push_back(i);
		}
		ft::list<int>::reverse_iterator rev_it;
		rev_it = j.rbegin() +3;
		rev_it +2;
		rev_it -3;
		std::cout << *rev_it << std::endl;
		ft::list<int>::iterator it = j.begin();
		std::cout << it[4] << std::endl;
		rev_it = j.rbegin();
		std::cout << rev_it[4] << std::endl;
	}


//	{
//		std::cout << "DEFAULT CONSTRUCTOR[char]: PUSH_BACK, FORWARD ITERATOR, BEGIN, END, ++OPERATOR" << std::endl;
//		ft::list<char> j;
////		j.push_back(1);
////		j.push_back(2);
////		j.push_back(3);
////		j.push_back(4);
////		j.push_back(5);
////		j.push_back(6);
////		j.push_back(9);
//
//		ft::list<char>::iterator jit_begin = j.begin();
//		ft::list<char>::iterator jit_end = j.end();
//		j.push_back('a');
//		j.push_back('b');
//		j.push_back('c');
//		j.push_back('d');
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
//	{
//		std::cout << "DEFAULT CONSTRUCTOR[strings]: PUSH_BACK, FORWARD ITERATOR, BEGIN, END, ++OPERATOR" << std::endl;
//		ft::list<string> j;
////		j.push_back(1);
////		j.push_back(2);
////		j.push_back(3);
////		j.push_back(4);
////		j.push_back(5);
////		j.push_back(6);
////		j.push_back(9);
//
//		ft::list<string>::iterator jit_begin = j.begin();
//		ft::list<string>::iterator jit_end = j.end();
//		j.push_back("hello");
//		j.push_back("world");
//		j.push_back("that is great");
//		j.push_back("this is red");
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
//
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
//
//
//	{
//		std::cout << "DEFAULT CONSTRUCTOR: PUSH_BACK, BACK WORD ITERATOR, BEGIN, END, ++OPERATOR" << std::endl;
//		ft::list<int> j;
//		j.push_back(1);
//		j.push_back(2);
//		j.push_back(3);
//		j.push_back(4);
//		j.push_back(2);
//		j.push_back(6);
//		j.push_back(9);
//
//		ft::list<int>::iterator jit_begin = j.begin();
//		ft::list<int>::iterator jit_end = j.end();
////		std::cout << *jit_end << std::endl;
////		--jit_end;
////		std::cout << *jit_end << std::endl;
//		while (jit_begin != jit_end)
//		{
//			std::cout << *jit_end << std::endl;
//			--jit_end;
//		}
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//	}
//
//
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
//	{
//		std::cout << "REVERSE ITERATOR" << std::endl;
//		ft::list<int> j;
////		j.push_back(1);
////		j.push_back(2);
////		j.push_back(3);
////		j.push_back(4);
////		j.push_back(5);
////		j.push_back(6);
////		j.push_back(9);
//
//		ft::list<int>::reverse_iterator jit_begin = j.rbegin();
//		ft::list<int>::reverse_iterator jit_end = j.rend();
//		j.push_back(1);
//		j.push_back(2);
//		j.push_back(3);
//		j.push_back(4);
//		j.push_back(5);
//		j.push_back(6);
//		j.push_back(9);
//		std::cout << "<-RBEGIN()" << std::endl;
//		std::cout << *jit_begin << std::endl;
//		++jit_begin;
//		std::cout << *jit_begin << std::endl;
//		++jit_begin;
//		std::cout << *jit_begin << std::endl;
//		++jit_begin;
//		std::cout << *jit_begin << std::endl;
//		++jit_begin;
//		std::cout << "RBEGIN()->" << std::endl;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << "<-REND()" << std::endl;
//
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//
//		std::cout << "END()->" << std::endl;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//
////		ft::list<int>::iterator jit_begin = j.begin();
////		ft::list<int>::iterator jit_end = j.end();
////		while (jit_begin != jit_end)
////		{
////			std::cout << *jit_begin << std::endl;
////			++jit_begin;
////		}
//	}

//	{
//		std::cout << "ITERATOR OPERATOR[]" << std::endl;
//		ft::list<int> j;
//		j.push_back(1);
//		j.push_back(2);
//		j.push_back(3);
//		j.push_back(4);
//		j.push_back(5);
//		j.push_back(6);
//		j.push_back(9);
//		ft::list<int>::iterator jit_begin = j.begin();
//		ft::list<int>::iterator jit_end = j.end();
//		std::cout << jit_begin[3] << std::endl;
//	}

//	{
//		std::cout << "OPERATOR= " << std::endl;
//
//		ft::list<int> k;
//		k.push_back(1);
//		k.push_back(2);
//		k.push_back(3);
//		k.push_back(4);
//		k.push_back(5);
//		k.push_back(6);
//		k.push_back(9);
//		ft::list<int> j;
//		j.push_back(10);
//		j.push_back(20);
//		j.push_back(30);
//		j.push_back(40);
//		j.push_back(50);
//		k = j;
//
//		ft::list<int>::iterator jit_begin = k.begin();
//		ft::list<int>::iterator jit_end = k.end();
//		while (jit_begin != jit_end)
//		{
//			std::cout << *jit_begin << std::endl;
//			++jit_begin;
//		}
//	}

//	sleep(10);
	return 0;
}
#else

#include <iostream>
#include <string>
#include <list>

int main() {
//    {
//		std::list<int> l;
//		std::list<int>::iterator it_begin = l.begin();
//		std::list<int>::iterator it_end = l.end();
//		l.push_back(1);
//		l.push_back(2);
//		l.push_back(3);
//		l.push_back(4);
//		std::cout << *it_begin << std::endl;
//	//	std::list<int>::iterator it_begin = l.begin();
//	//	std::list<int>::iterator it_end = l.end();
//		++it_begin;
//		while (it_begin != it_end)
//		{
//			std::cout << *it_begin << std::endl;
//			++it_begin;
//		}
//	}
//
//	{
//		std::cout << "REVERSE ITERATOR" << std::endl;
//		std::list<int> j;
////		j.push_back(1);
////		j.push_back(2);
////		j.push_back(3);
////		j.push_back(4);
////		j.push_back(5);
////		j.push_back(6);
////		j.push_back(9);
//
//		std::list<int>::reverse_iterator jit_begin = j.rbegin();
//		std::list<int>::iterator jit_end = j.end();
//		j.push_back(1);
//		j.push_back(2);
//		j.push_back(3);
//		j.push_back(4);
//		j.push_back(5);
//		j.push_back(6);
//		j.push_back(9);
////		std::cout << *jit_begin << std::endl;
////		++jit_begin;
////		std::cout << *jit_begin << std::endl;
////		++jit_begin;
////		std::cout << *jit_begin << std::endl;
////		++jit_begin;
////		std::cout << *jit_begin << std::endl;
////		++jit_begin;
//
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//
//
////		ft::list<int>::iterator jit_begin = j.begin();
////		ft::list<int>::iterator jit_end = j.end();
////		while (jit_begin != jit_end)
////		{
////			std::cout << *jit_begin << std::endl;
////			++jit_begin;
////		}
//	}

//	{
//
//		std::cout << "REVERSE ITERATOR" << std::endl;
//		std::list<int> j;
////		j.push_back(1);
////		j.push_back(2);
////		j.push_back(3);
////		j.push_back(4);
////		j.push_back(5);
////		j.push_back(6);
////		j.push_back(9);
//
//		std::list<int>::reverse_iterator jit_begin = j.rbegin();
//		std::list<int>::reverse_iterator jit_end = j.rend();
//		j.push_back(1);
//		j.push_back(2);
//		j.push_back(3);
//		j.push_back(4);
//		j.push_back(5);
//		j.push_back(6);
//		j.push_back(9);
//		std::cout << "BEGIN()->" << std::endl;
//		std::cout << *jit_begin << std::endl;
//		++jit_begin;
//		std::cout << *jit_begin << std::endl;
//		++jit_begin;
//		std::cout << *jit_begin << std::endl;
//		++jit_begin;
//		std::cout << *jit_begin << std::endl;
//		++jit_begin;
//		std::cout << "<-BEGIN()" << std::endl;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << *jit_begin << std::endl;
//		--jit_begin;
//		std::cout << "END()->" << std::endl;
//
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//		std::cout << *jit_end << std::endl;
//		++jit_end;
//
//		std::cout << "<-END()" << std::endl;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//		std::cout << *jit_end << std::endl;
//		--jit_end;
//	}


	{

		std::cout << "REVERSE ITERATOR" << std::endl;
		std::list<int> j;
//		j.push_back(1);
//		j.push_back(2);
//		j.push_back(3);
//		j.push_back(4);
//		j.push_back(5);
//		j.push_back(6);
//		j.push_back(9);

		std::list<int>::reverse_iterator jit_begin = j.rbegin();
		std::list<int>::reverse_iterator jit_end = j.rend();
		j.push_back(1);
		j.push_back(2);
		j.push_back(3);
		j.push_back(4);
		j.push_back(5);
		j.push_back(6);
		j.push_back(9);
		std::cout << "<-RBEGIN()" << std::endl;
		std::cout << *jit_begin << std::endl;
		++jit_begin;
		std::cout << *jit_begin << std::endl;
		++jit_begin;
		std::cout << *jit_begin << std::endl;
		++jit_begin;
		std::cout << *jit_begin << std::endl;
		++jit_begin;
		std::cout << "RBEGIN()->" << std::endl;
		std::cout << *jit_begin << std::endl;
		--jit_begin;
		std::cout << *jit_begin << std::endl;
		--jit_begin;
		std::cout << *jit_begin << std::endl;
		--jit_begin;
		std::cout << *jit_begin << std::endl;
		--jit_begin;
		std::cout << *jit_begin << std::endl;
		--jit_begin;
		std::cout << *jit_begin << std::endl;
		--jit_begin;
		std::cout << "<-REND()" << std::endl;

		std::cout << *jit_end << std::endl;
		++jit_end;
		std::cout << *jit_end << std::endl;
		++jit_end;
		std::cout << *jit_end << std::endl;
		++jit_end;
		std::cout << *jit_end << std::endl;
		++jit_end;
		std::cout << *jit_end << std::endl;
		++jit_end;
		std::cout << *jit_end << std::endl;
		++jit_end;
		std::cout << *jit_end << std::endl;
		++jit_end;

		std::cout << "END()->" << std::endl;
		std::cout << *jit_end << std::endl;
		--jit_end;
		std::cout << *jit_end << std::endl;
		--jit_end;
		std::cout << *jit_end << std::endl;
		--jit_end;
		std::cout << *jit_end << std::endl;
		--jit_end;
		std::cout << *jit_end << std::endl;
		--jit_end;
		std::cout << *jit_end << std::endl;
		--jit_end;
	}




}

#endif


