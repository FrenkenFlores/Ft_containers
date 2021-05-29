#include "unit_tests.hpp"
#define T1 // constructors
//#define T2 // operator=()
//#define T3	// begin(), end(), rbegin(), rend()
//#define T4	// size()
//#define T5	// max_size()
//#define T6 // resize()
//#define T7 // capacity()
//#define T8 // empty()
//#define T9 // reserve()
//#define T10 // operator[]
//#define T11 // at()
//#define T12 // front()
//#define T13 // back()
//#define T14 // assign()
//#define T15 // push_back()
//#define T16 // pop_back()
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


//void check_flag(bool flag) {
//	if (flag == true)
//		PUT_STR(OK);
//	else
//		PUT_STR(KO);
//	flag = false;
//}
//
//template <typename T>
//void check_value(ft::vector<T> &x, std::vector<T> &y, bool &flag) {
//	typename ft::vector<T>::iterator ft_itb = x.begin();
//	typename ft::vector<T>::iterator ft_ite = x.end();
//	typename std::vector<T>::iterator std_itb = y.begin();
//	typename std::vector<T>::iterator std_ite = y.end();
//	while (ft_itb != ft_ite)
//	{
//		if (*ft_itb != *std_itb)
//		{
//			flag = false;
//			cout << LB << *ft_itb << " != " << *std_itb << CLEAN << std::endl;
//			break;
//		} else {
////			cout << P << *ft_itb << " == " << *std_itb << CLEAN << std::endl;
//			flag = true;
//		}
//		++ft_itb;
//		++std_itb;
//	}
//}
//
//template <typename T>
//void check_reverse_value(ft::vector<T> &x, std::vector<T> &y, bool &flag) {
//	typename ft::vector<T>::reverse_iterator ft_itb = x.rbegin();
//	typename ft::vector<T>::reverse_iterator ft_ite = x.rend();
//	typename std::vector<T>::reverse_iterator std_itb = y.rbegin();
//	typename std::vector<T>::reverse_iterator std_ite = y.rend();
//	while (ft_itb != ft_ite && std_itb != std_ite)
//	{
//		if (*ft_itb != *std_itb)
//		{
//			flag = false;
//			cout << LB << *ft_itb << " != " << *std_itb << CLEAN << std::endl;
//			break;
//		} else {
////			cout << P << *ft_itb << " == " << *std_itb << CLEAN << std::endl;
//			flag = true;
//		}
//		++ft_itb;
//		++std_itb;
//	}
//}
//
//
//
//template <typename T>
//void check_size(ft::vector<T> &x, std::vector<T> &y, bool &flag) {
//	if (x.size() != y.size())
//	{
//		flag = false;
//		cout << LB << x.size() << " != " << y.size() << CLEAN << std::endl;
//	} else {
//		flag = true;
////		cout << P << x.size() << " == " << y.size() << CLEAN << std::endl;
//	}
//}
//
//template <typename T>
//void check_capacity(ft::vector<T> &x, std::vector<T> &y, bool &flag) {
//	if (x.capacity() != y.capacity())
//	{
//		flag = false;
//		cout << LB << x.capacity() << " != " << y.capacity() << CLEAN << std::endl;
//	} else {
//		flag = true;
////		cout << P << x.capacity() << " == " << y.capacity() << CLEAN << std::endl;
//	}
//}

int main(void) {
	bool flag = true;
#ifdef T1
	{
//		PUT_STR(B"CONSTRUCTOR[default (1)]");
		ft::map<int, int> _map;
		_map.insert ( std::pair<int,int>(2,200) );
		_map.insert ( std::pair<int,int>(3,300) );
		_map.insert ( std::pair<int,int>(4,400) );
		_map.insert ( std::pair<int,int>(5,500) );
		_map.insert ( std::pair<int,int>(1,100) );

		_map.DUMP(_map.get_root());

	}
#endif
#ifdef T2
	{
		PUT_STR(B"OPERATOR=()");
	}
#endif
#ifdef T3
	{

	}
#endif
#ifdef T4
	{
		PUT_STR(B"SIZE()");
	}
#endif
#ifdef T5
	{
		PUT_STR(B"MAX_SIZE()");
	}
#endif
#ifdef T6
	{
		PUT_STR(B"RESIZE()");
	}
#endif
#ifdef T7
	{
		PUT_STR(B"CAPACITY()");
	}
#endif
#ifdef T8
	{
		PUT_STR(B"EMPTY()");
	}
#endif
#ifdef T9
	{
		PUT_STR(B"RESERVE()");
	}
#endif
#ifdef T10
	{
		PUT_STR(B"OPERATOR[]");
	}
#endif
#ifdef T11
	{
		PUT_STR(B"at()");
	}
#endif
#ifdef T12
	{
		PUT_STR(B"front()");
	}
#endif
#ifdef T13
	{
		PUT_STR(B"back()");
	}
#endif
#ifdef T14
	{
		PUT_STR(B"assign()");
	}
#endif
#ifdef T15
	{
		PUT_STR(B"PUSH_BACK()");
	}
#endif
#ifdef T16
	{
		PUT_STR(B"POP_BACK()");
	}
#endif
#ifdef T17
	{
		PUT_STR(B"INSERT()");
	}
#endif
#ifdef T18
	{
		PUT_STR(B"ERASE()");
	}
#endif
#ifdef T19
	{
		PUT_STR(B"SWAP()");
	}
#endif
#ifdef T20
	{
		PUT_STR(B"CLEAR()");
	}
#endif
	return 0;
}