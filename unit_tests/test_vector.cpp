#include "unit_tests.hpp"
#define T1 // constructors
#define T2 // operator=()
#define T3	//
//#define T4
//#define T5
//#define T6
//#define T7
//#define T8
//#define T9
//#define T10
//#define T11
//#define T12
//#define T13
//#define T14
//#define T15
//#define T16
//#define T17
//#define T18
//#define T19
//#define T20
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
}

template <typename T>
void check_value(ft::vector<T> &x, std::vector<T> &y, bool &flag) {
	typename ft::vector<T>::iterator ft_itb = x.begin();
	typename ft::vector<T>::iterator ft_ite = x.end();
	typename std::vector<T>::iterator std_itb = y.begin();
	typename std::vector<T>::iterator std_ite = y.end();
	while (ft_itb != ft_ite && std_itb != std_ite)
	{
		if (*ft_itb != *std_itb)
		{
			flag = false;
			cout << LB << *ft_itb << " != " << *std_itb << CLEAN << std::endl;
			break;
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
		cout << LB << x.size() << " == " << y.size() << CLEAN << std::endl;
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

		PUT_STR(B"CONSTRUCTOR[fill (2)]");
		std::vector<int> std_second (4,100);                       // four ints with value 100
		ft::vector<int> ft_second(4, 100);
		check_value(ft_second, std_second, flag);
		check_flag(flag);
		check_size(ft_second, std_second, flag);
		check_flag(flag);

		PUT_STR(B"CONSTRUCTOR[range (3)]");
		std::vector<int> std_third (std_second.begin(),std_second.end());  // iterating through second
		ft::vector<int> ft_third (ft_second.begin(),ft_second.end());  // iterating through second
		check_value(ft_third, std_third, flag);
		check_flag(flag);
		check_size(ft_third, std_third, flag);
		check_flag(flag);

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::vector<int> std_fifth (myints, myints + sizeof(myints) / sizeof(int) );
		ft::vector<int> ft_fifth (myints, myints + sizeof(myints) / sizeof(int) );
		check_value(ft_fifth, std_fifth, flag);
		check_flag(flag);
		check_size(ft_fifth, std_fifth, flag);
		check_flag(flag);

		PUT_STR(B"CONSTRUCTOR[copy (4)]");
		std::vector<int> std_fourth (std_third);                       // a copy of third
		ft::vector<int> ft_fourth (ft_third);                       // a copy of third
		check_value(ft_fourth, std_fourth, flag);
		check_flag(flag);
		check_size(ft_fourth, std_fourth, flag);
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
		ft_foo = ft::vector<int>();
		std_foo = std::vector<int>();
		check_value(ft_foo, std_foo, flag);
		check_flag(flag);
		check_size(ft_foo, std_foo, flag);
		check_flag(flag);
	}
#endif
#ifdef T3
	{

	}
#endif
#ifdef T4
	{

	}
#endif
#ifdef T5
	{

	}
#endif
#ifdef T6
	{

	}
#endif
#ifdef T7
	{

	}
#endif
#ifdef T8
	{

	}
#endif
#ifdef T9
	{

	}
#endif
#ifdef T10
	{

	}
#endif
#ifdef T11
	{

	}
#endif
#ifdef T12
	{

	}
#endif
#ifdef T13
	{

	}
#endif
#ifdef T14
	{

	}
#endif
	return 0;
}