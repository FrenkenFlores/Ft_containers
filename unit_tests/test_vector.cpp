#include "unit_tests.hpp"
#define T1 // constructors
#define T2 // operator=()
#define T3	// begin(), end(), rbegin(), rend()
#define T4	// size()
#define T5	// max_size()
#define T6 // resize()
#define T7 // capacity()
#define T8 // empty()
#define T9 // reserve()
#define T10 // operator[]
#define T11 // at()
#define T12 // front()
#define T13 // back()
#define T14 // assign()
#define T15 // push_back()
#define T16 // pop_back()
//#define T17 // insert()
//#define T18 // erase()
//#define T19 // swap()
//#define T20 // clear()
//#define T21
//#define T22
//#define T23
//#define T24
//#define T25
//#define T26
//#define T27
//#define T28

using namespace std;


void check_flag(bool flag) {
	if (flag == true)
		PUT_STR(OK);
	else
		PUT_STR(KO);
	flag = false;
}

template <typename T>
void check_value(ft::vector<T> &x, std::vector<T> &y, bool &flag) {
	typename ft::vector<T>::iterator ft_itb = x.begin();
	typename ft::vector<T>::iterator ft_ite = x.end();
	typename std::vector<T>::iterator std_itb = y.begin();
	typename std::vector<T>::iterator std_ite = y.end();
	while (ft_itb != ft_ite)
	{
		if (*ft_itb != *std_itb)
		{
			flag = false;
			cout << LB << *ft_itb << " != " << *std_itb << CLEAN << std::endl;
//			break;
		} else {
			cout << P << *ft_itb << " == " << *std_itb << CLEAN << std::endl;
			flag = true;
		}
		++ft_itb;
		++std_itb;
	}
}

template <typename T>
void check_reverse_value(ft::vector<T> &x, std::vector<T> &y, bool &flag) {
	typename ft::vector<T>::reverse_iterator ft_itb = x.rbegin();
	typename ft::vector<T>::reverse_iterator ft_ite = x.rend();
	typename std::vector<T>::reverse_iterator std_itb = y.rbegin();
	typename std::vector<T>::reverse_iterator std_ite = y.rend();
	while (ft_itb != ft_ite && std_itb != std_ite)
	{
		if (*ft_itb != *std_itb)
		{
			flag = false;
			cout << LB << *ft_itb << " != " << *std_itb << CLEAN << std::endl;
//			break;
		} else {
			cout << P << *ft_itb << " == " << *std_itb << CLEAN << std::endl;
			flag = true;
		}
		++ft_itb;
		++std_itb;
	}
}



template <typename T>
void check_size(ft::vector<T> &x, std::vector<T> &y, bool &flag) {
	if (x.size() != y.size())
	{
		flag = false;
		cout << LB << x.size() << " != " << y.size() << CLEAN << std::endl;
	} else {
		flag = true;
		cout << P << x.size() << " == " << y.size() << CLEAN << std::endl;
	}
}

template <typename T>
void check_capacity(ft::vector<T> &x, std::vector<T> &y, bool &flag) {
	if (x.capacity() != y.capacity())
	{
		flag = false;
		cout << LB << x.capacity() << " != " << y.capacity() << CLEAN << std::endl;
	} else {
		flag = true;
		cout << P << x.capacity() << " == " << y.capacity() << CLEAN << std::endl;
	}
}

int main(void) {
	bool flag = true;
#ifdef T1
	{
		PUT_STR(B"CONSTRUCTOR[default (1)]");
		std::vector<int> std_first;                                // empty vector of ints
		ft::vector<int> ft_first;
		check_value(ft_first, std_first, flag);
		check_flag(flag);
		check_size(ft_first, std_first, flag);
		check_flag(flag);
		check_capacity(ft_first, std_first, flag);
		check_flag(flag);

		PUT_STR(B"CONSTRUCTOR[fill (2)]");
		std::vector<int> std_second (4,100);                       // four ints with value 100
		ft::vector<int> ft_second(4, 100);
		check_value(ft_second, std_second, flag);
		check_flag(flag);
		check_size(ft_second, std_second, flag);
		check_flag(flag);
		check_capacity(ft_second, std_second, flag);
		check_flag(flag);

		PUT_STR(B"CONSTRUCTOR[range (3)]");
		std::vector<int> std_third (std_second.begin(),std_second.end());  // iterating through second
		ft::vector<int> ft_third (ft_second.begin(),ft_second.end());  // iterating through second
		check_value(ft_third, std_third, flag);
		check_flag(flag);
		check_size(ft_third, std_third, flag);
		check_flag(flag);
		check_capacity(ft_third, std_third, flag);
		check_flag(flag);

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::vector<int> std_fifth (myints, myints + sizeof(myints) / sizeof(int) );
		ft::vector<int> ft_fifth (myints, myints + sizeof(myints) / sizeof(int) );
		check_value(ft_fifth, std_fifth, flag);
		check_flag(flag);
		check_size(ft_fifth, std_fifth, flag);
		check_flag(flag);
		check_capacity(ft_fifth, std_fifth, flag);
		check_flag(flag);

		PUT_STR(B"CONSTRUCTOR[copy (4)]");
		std::vector<int> std_fourth (std_third);                       // a copy of third
		ft::vector<int> ft_fourth (ft_third);                       // a copy of third
		check_value(ft_fourth, std_fourth, flag);
		check_flag(flag);
		check_size(ft_fourth, std_fourth, flag);
		check_flag(flag);
		check_capacity(ft_fourth, std_fourth, flag);
		check_flag(flag);
	}
#endif
#ifdef T2
	{
		PUT_STR(B"OPERATOR=()");
		ft::vector<int> ft_foo (3,0);
		std::vector<int> std_foo (3,0);
		ft::vector<int> ft_bar (5,0);
		std::vector<int> std_bar (5,0);

		ft_bar = ft_foo;
		std_bar = std_foo;
		check_value(ft_bar, std_bar, flag);
		check_flag(flag);
		check_size(ft_bar, std_bar, flag);
		check_flag(flag);
		check_capacity(ft_bar, std_bar, flag);
		check_flag(flag);
		ft_foo = ft::vector<int>();
		std_foo = std::vector<int>();
		check_value(ft_foo, std_foo, flag);
		check_flag(flag);
		check_size(ft_foo, std_foo, flag);
		check_flag(flag);
		check_capacity(ft_foo, std_foo, flag);
	}
#endif
#ifdef T3
	{
		int myints[] = {16,2,77,29};
		std::vector<int> std (myints, myints + sizeof(myints) / sizeof(int) );
		ft::vector<int> ft (myints, myints + sizeof(myints) / sizeof(int) );


		PUT_STR(B"BEGIN()");
		if (*std.begin() != *ft.begin())
		{
			flag = false;
			std::cout << *std.begin() << " != " << *ft.begin() << std::endl;
		}
		else
			flag = true;
		check_flag(flag);

		PUT_STR(B"END()");
		if (*std.end() != *ft.end())
		{
			flag = false;
			std::cout << *ft.end() << " != " << *std.end() << std::endl;
		}
		else
			flag = true;
		check_flag(flag);

		PUT_STR(B"RBEGIN()");
		if (*std.rbegin() != *ft.rbegin())
		{
			flag = false;
			std::cout << *ft.rbegin() << " != " << *std.rbegin() << std::endl;
		}
		else
			flag = true;
		check_flag(flag);

		PUT_STR(B"REND()");
		if (*std.rend() != *ft.rend())
		{
			flag = false;
			std::cout << *ft.rend() << " != " << *std.rend() << std::endl;
		}
		else
			flag = true;
		check_flag(flag);

//		PUT_STR(B"_________");
//
//		check_reverse_value(ft, std, flag);
//		check_flag(flag);
//
//
//		PUT_STR(B"=========");
//		ft::vector<int> v(10, 42);
//		ft::vector<int>::reverse_iterator ritb = v.rbegin();
//		ft::vector<int>::reverse_iterator rite = v.rend();
//		while (ritb != rite) {
//			std::cout << *ritb << std::endl;
//			++ritb;
//		}
	}
#endif
#ifdef T4
	{
		PUT_STR(B"SIZE()");

		int myints[] = {16,2,77,29};
		std::vector<int> x (myints, myints + sizeof(myints) / sizeof(int) );
		ft::vector<int> y (myints, myints + sizeof(myints) / sizeof(int) );
		if (x.size() != y.size())
		{
			flag = false;
			cout << LB << x.size() << " != " << y.size() << CLEAN << std::endl;
		} else {
			flag = true;
//			cout << LB << x.size() << " == " << y.size() << CLEAN << std::endl;
		}
		check_flag(flag);
	}
#endif
#ifdef T5
	{
		PUT_STR(B"MAX_SIZE()");

		int myints[] = {16,2,77,29};
		std::vector<int> x (myints, myints + sizeof(myints) / sizeof(int) );
		ft::vector<int> y (myints, myints + sizeof(myints) / sizeof(int) );
		if (x.max_size() != y.max_size())
		{
			flag = false;
			cout << LB << x.max_size() << " != " << y.max_size() << CLEAN << std::endl;
		} else {
			flag = true;
//			cout << LB << x.max_size() << " == " << y.max_size() << CLEAN << std::endl;
		}
		check_flag(flag);
	}
#endif
#ifdef T6
	{
		PUT_STR(B"RESIZE()");
		std::vector<int> std;
		ft::vector<int> ft;

		for (int i=1;i<10;i++) std.push_back(i);
		for (int i=1;i<10;i++) ft.push_back(i);

		std.resize(5);
		ft.resize(5);

		check_value(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		check_capacity(ft, std, flag);
		check_flag(flag);

		std.resize(8,100);
		ft.resize(8,100);
		check_value(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		check_capacity(ft, std, flag);
		check_flag(flag);

		std.resize(12);
		ft.resize(12);
		check_value(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		check_capacity(ft, std, flag);
		check_flag(flag);

	}
#endif
#ifdef T7
	{
		PUT_STR(B"CAPACITY()");

		std::vector<int> std;
		ft::vector<int> ft;
		for (int i=1;i<100;i++) std.push_back(i);
		for (int i=1;i<100;i++) ft.push_back(i);
		check_capacity(ft, std, flag);
		check_flag(flag);
	}
#endif
#ifdef T8
	{
		PUT_STR(B"EMPTY()");

		std::vector<int> std;
		ft::vector<int> ft;

		if (std.empty() == ft.empty())
			PUT_STR(OK);
		else
			PUT_STR(KO);

		for (int i=1;i<100;i++) std.push_back(i);
		for (int i=1;i<100;i++) ft.push_back(i);
		check_capacity(ft, std, flag);
		check_flag(flag);

		if (std.empty() == ft.empty())
			PUT_STR(OK);
		else
			PUT_STR(KO);

		ft.clear();
		std.clear();
		if (std.empty() == ft.empty())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T9
	{
		PUT_STR(B"RESERVE()");

		std::vector<int> std;
		ft::vector<int> ft;

		std.reserve(20);
		ft.reserve(20);
		check_value(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		check_capacity(ft, std, flag);
		check_flag(flag);

		for (int i=1;i<10;i++) std.push_back(i);
		for (int i=1;i<10;i++) ft.push_back(i);
		check_value(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		check_capacity(ft, std, flag);
		check_flag(flag);

		std.reserve(1);
		ft.reserve(1);
		check_value(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		check_capacity(ft, std, flag);
		check_flag(flag);
	}
#endif
#ifdef T10
	{
		PUT_STR(B"OPERATOR[]");

		std::vector<int> std;
		ft::vector<int> ft;

		for (int i=0;i<10;i++) std.push_back(i);
		for (int i=0;i<10;i++) ft.push_back(i);

		for (int i = 0; i < 10; ++i) {
			if (ft[i] != std[i])
			{
				std::cout << ft[i] << " != " << std[i] << std::endl;
				PUT_STR(KO);
				break;
			}
			PUT_STR(OK);
		}
	}
#endif
#ifdef T11
	{
		PUT_STR(B"at()");

		std::vector<int> std;
		ft::vector<int> ft;

		for (int i=0;i<10;i++) std.push_back(i);
		for (int i=0;i<10;i++) ft.push_back(i);

		for (int i = 0; i < 10; ++i) {
			if (ft.at(i) != std.at(i))
			{
				std::cout << ft.at(i) << " != " << std.at(i) << std::endl;
				PUT_STR(KO);
				break;
			}
			PUT_STR(OK);
		}
		try {
			ft.at(1000) = 0;
		} catch (std::logic_error &e) {
			std::cout << e.what() << std::endl;
		}
	}

#endif
#ifdef T12
	{
		PUT_STR(B"front()");
		std::vector<int> std;
		ft::vector<int> ft;

		for (int i=0;i<10;i++) std.push_back(i);
		for (int i=0;i<10;i++) ft.push_back(i);
		if (ft.front() == std.front()) {
			PUT_STR(OK);
		} else {
			PUT_STR(KO);
		}
	}
#endif
#ifdef T13
	{
		PUT_STR(B"back()");
		std::vector<int> std;
		ft::vector<int> ft;

		for (int i=0;i<10;i++) std.push_back(i);
		for (int i=0;i<10;i++) ft.push_back(i);
		if (ft.back() == std.back()) {
			PUT_STR(OK);
		} else {
			PUT_STR(KO);
		}
	}
#endif
#ifdef T14
	{

	}
#endif
#ifdef T15
	{
		PUT_STR(B"PUSH_BACK()");
		std::vector<int> std(5, 10);
		ft::vector<int> ft(5, 10);
		check_capacity(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		for (int i = 0; i < 10; i++)
			std.push_back(i);

		for (int i = 0; i < 10; i++)
			ft.push_back(i);

		check_value(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		check_capacity(ft, std, flag);
		check_flag(flag);

		ft.push_back(50);
		std.push_back(50);
		check_value(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		check_capacity(ft, std, flag);
		check_flag(flag);

	}
#endif
#ifdef T16
	{
		PUT_STR(B"POP_BACK()");
		std::vector<int> std(5, 10);
		ft::vector<int> ft(5, 10);
		std.pop_back();
		ft.pop_back();
		check_capacity(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		for (int i = 0; i < 10; i++)
			std.push_back(i);

		for (int i = 0; i < 10; i++)
			ft.push_back(i);

		for (int i = 0; i < 5; ++i) {
			ft.pop_back();
		}
		for (int i = 0; i < 5; ++i) {
			std.pop_back();
		}
		check_value(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		check_capacity(ft, std, flag);
		check_flag(flag);
	}
#endif
#ifdef T17
	{

	}
#endif
	return 0;
}