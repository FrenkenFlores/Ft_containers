#include "unit_tests.hpp"

#define T1	//DEFAULT CONSTRUCTOR[int]
#define T2	//DEFAULT CONSTRUCTOR[float]
#define T3	//DEFAULT CONSTRUCTOR[double]
#define T4	//DEFAULT CONSTRUCTOR[char]
#define T5	//DEFAULT CONSTRUCTOR[string]
#define T6	//DEFAULT CONSTRUCTOR[vector]
#define T7	//FILL CONSTRUCTOR
#define T8	//RANGE CONSTRUCTOR[ARRAY]
#define T9	//RANGE CONSTRUCTOR[VECTOR]
#define T10	//OPERATOR()=
#define T11	//COPY CONSTRUCTOR
#define T12	//...
#define T13	//BEGIN()
#define T14	//END()
#define T15	//RBEGIN()
#define T16	//REND()
#define T17	//EMPTY()
#define T18	//SIZE()
#define T19	//MAX_SIZE()
#define T20	//FRONT()
#define T21	//BACK()
#define T22	//ASSIGN()
#define T23	//PUSH_FRONT()
#define T24	//POP_FRONT()
#define T25	//PUSH_BACK()
#define T26	//POP_BACK()
#define T27	//INSERT()[single element]
#define T28	//
#define T29	//
#define T30	//
#define T31	//



using namespace std;


void check_flag(bool flag) {
	if (flag == true)
		PUT_STR(OK);
	else
		PUT_STR(KO);
}

template <typename T>
void check_value(typename ft::list<T>::iterator ft_itb, typename ft::list<T>::iterator ft_ite, typename std::list<T>::iterator std_itb, typename std::list<T>::iterator std_ite, bool &flag) {
	while (ft_itb != ft_ite)
	{
		if (*ft_itb != *std_itb)
		{
			flag = false;
			cout << LB << *ft_itb << " != " << *std_itb << CLEAN << std::endl;
			break;
		} else {
//			cout << P << *ft_itb << " == " << *std_itb << CLEAN << std::endl;
			flag = true;
		}
		++ft_itb;
		++std_itb;
	}
}

template <typename T>
void check_size(ft::list<T> ft, std::list<T> std, bool &flag) {
	if (ft.size() != std.size())
	{
		flag = false;
		cout << LB << ft.size() << " != " << std.size() << CLEAN << std::endl;
	} else {
		flag = true;
	}
}



int main(void) {
#ifdef T1
	{
		bool flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[int]");
		ft::list<int> ft;
		std::list<int> std;
		ft::list<int>::iterator ft_itb = ft.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_itb = std.begin();
		std::list<int>::iterator std_ite = std.end();
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
//		while (ft_itb != ft_ite && std_itb != std_ite)
//		{
//			if (*ft_itb != *std_itb)
//			{
//				flag = false;
//				break;
//			}
//			++ft_itb;
//			++std_ite;
//		}
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T2
	{
		bool flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[float]");
		ft::list<float> ft;
		std::list<float> std;
		ft::list<float>::iterator ft_itb = ft.begin();
		ft::list<float>::iterator ft_ite = ft.end();
		std::list<float>::iterator std_itb = std.begin();
		std::list<float>::iterator std_ite = std.end();
		check_value<float>(ft_itb, ft_ite, std_itb, std_ite, flag);
//		while (ft_itb != ft_ite && std_itb != std_ite)
//		{
//			if (*ft_itb != *std_itb)
//			{
//				flag = false;
//				break;
//			}
//			++ft_itb;
//			++std_ite;
//		}
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T3
	{
		bool flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[double]");
		ft::list<double> ft;
		std::list<double> std;
		ft::list<double>::iterator ft_itb = ft.begin();
		ft::list<double>::iterator ft_ite = ft.end();
		std::list<double>::iterator std_itb = std.begin();
		std::list<double>::iterator std_ite = std.end();
		check_value<double>(ft_itb, ft_ite, std_itb, std_ite, flag);
//		while (ft_itb != ft_ite && std_itb != std_ite)
//		{
//			if (*ft_itb != *std_itb)
//			{
//				flag = false;
//				break;
//			}
//			++ft_itb;
//			++std_ite;
//		}
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T4
	{
		bool flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[char]");
		ft::list<char> ft;
		std::list<char> std;
		ft::list<char>::iterator ft_itb = ft.begin();
		ft::list<char>::iterator ft_ite = ft.end();
		std::list<char>::iterator std_itb = std.begin();
		std::list<char>::iterator std_ite = std.end();
		check_value<char>(ft_itb, ft_ite, std_itb, std_ite, flag);
//		while (ft_itb != ft_ite && std_itb != std_ite)
//		{
//			if (*ft_itb != *std_itb)
//			{
//				flag = false;
//				break;
//			}
//			++ft_itb;
//			++std_ite;
//		}
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T5
	{
		bool flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[string]");
		ft::list<string> ft;
		std::list<string> std;
		ft::list<string>::iterator ft_itb = ft.begin();
		ft::list<string>::iterator ft_ite = ft.end();
		std::list<string>::iterator std_itb = std.begin();
		std::list<string>::iterator std_ite = std.end();
		check_value<string>(ft_itb, ft_ite, std_itb, std_ite, flag);
//		while (ft_itb != ft_ite && std_itb != std_ite)
//		{
//			if (*ft_itb != *std_itb)
//			{
//				flag = false;
//				break;
//			}
//			++ft_itb;
//			++std_ite;
//		}
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T6
	{
		bool flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[vector]");
		ft::list<vector<int> > ft;
		std::list<vector<int> > std;
		ft::list<vector<int> >::iterator ft_itb = ft.begin();
		ft::list<vector<int> >::iterator ft_ite = ft.end();
		std::list<vector<int> >::iterator std_itb = std.begin();
		std::list<vector<int> >::iterator std_ite = std.end();
//		check_value<vector<int> >(ft_itb, ft_ite, std_itb, std_ite, flag);
		while (ft_itb != ft_ite && std_itb != std_ite)
		{
			if (*ft_itb != *std_itb)
			{
				flag = false;
				break;
			}
			++ft_itb;
			++std_ite;
		}
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T7
	{
		bool flag = true;
		PUT_STR(B"FILL CONSTRUCTOR");
		ft::list<int> ft(10, 42);
		std::list<int> std(10, 42);
		ft::list<int>::iterator ft_itb = ft.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_itb = std.begin();
		std::list<int>::iterator std_ite = std.end();
//		while (ft_itb != ft_ite && std_itb != std_ite)
//		{
//			if (*ft_itb != *std_itb)
//			{
//				std::cout << *ft_itb << " != " << *std_itb << std::endl;
//				flag = false;
//				break;
//			}
//			else
//				flag = true;
//			++ft_itb;
//			++std_itb;
//		}
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T8
	{
		bool flag = true;
		PUT_STR(B"RANGE CONSTRUCTOR[ARRAY]");
		int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		ft::list<int> ft(array, array + sizeof(array));
		std::list<int> std(array, array + sizeof(array));
		ft::list<int>::iterator ft_itb = ft.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_itb = std.begin();
		std::list<int>::iterator std_ite = std.end();
//		while (ft_itb != ft_ite && std_itb != std_ite)
//		{
//			if (*ft_itb != *std_itb)
//			{
//				std::cout << *ft_itb << " != " << *std_itb << std::endl;
//				flag = false;
//				break;
//			}
//			else
//				flag = true;
//			++ft_itb;
//			++std_itb;
//		}
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T9
	{
		bool flag = true;
		PUT_STR(B"RANGE CONSTRUCTOR[VECTOR]");
		std::vector<int> v;
		for (int i = 0; i < 10; ++i)
			v.push_back(i);
		ft::list<int> ft(v.begin(), v.end());
		std::list<int> std(v.begin(), v.end());
		ft::list<int>::iterator ft_itb = ft.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_itb = std.begin();
		std::list<int>::iterator std_ite = std.end();
//		while (ft_itb != ft_ite && std_itb != std_ite)
//		{
//			if (*ft_itb != *std_itb)
//			{
//				std::cout << *ft_itb << " != " << *std_itb << std::endl;
//				flag = false;
//				break;
//			}
//			else
//				flag = true;
//			++ft_itb;
//			++std_itb;
//		}
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T10
	{
		bool flag = true;
		PUT_STR(B"OPERATOR()=");
		ft::list<int> ft_src(10, 42);
		ft::list<int> ft;
		std::list<int> std_src(10, 42);
		std::list<int> std;
		ft = ft_src;
		std = std_src;
		ft::list<int>::iterator ft_itb = ft.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_itb = std.begin();
		std::list<int>::iterator std_ite = std.end();
//		while (ft_itb != ft_ite && std_itb != std_ite)
//		{
//			if (*ft_itb != *std_itb)
//			{
//				std::cout << *ft_itb << " != " << *std_itb << std::endl;
//				flag = false;
//				break;
//			}
//			else
//				flag = true;
//			++ft_itb;
//			++std_itb;
//		}
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T11
	{
		bool flag = true;
		PUT_STR(B"COPY CONSTRUCTOR");
		ft::list<int> ft_src(10, 42);
		std::list<int> std_src(10, 42);
		std::list<int> std = std_src;
		ft::list<int> ft = ft_src;
		ft::list<int>::iterator ft_itb = ft.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_itb = std.begin();
		std::list<int>::iterator std_ite = std.end();
//		while (ft_itb != ft_ite && std_itb != std_ite)
//		{
//			if (*ft_itb != *std_itb)
//			{
//				std::cout << *ft_itb << " != " << *std_itb << std::endl;
//				flag = false;
//				break;
//			}
//			else
//				flag = true;
//			++ft_itb;
//			++std_itb;
//		}
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T12
	// IF list gets filled with array the last element shows the sizeof array in some OS, in others it show garbage
//	{
//		PUT_STR(B"BEGIN()");
//		int array[] = {0, 1, 2, 3};
//		ft::list<int> ft(array, array + sizeof(array));
//		std::list<int> std(array, array + sizeof(array));
//		if (*(ft.begin()) == *(std.begin()))
//			PUT_STR(OK);
//		else {
//			cout << LB << *(ft.begin()) << " != " << *(std.begin()) << CLEAN << std::endl;
//			PUT_STR(KO);
//		}
//	}
//	{
//		PUT_STR(B"END()");
//		int array[] = {0, 1, 2, 3};
//		ft::list<int> ft(array, array + sizeof(array));
//		std::list<int> std(array, array + sizeof(array));
//		if (*(ft.end()) == *(std.end()))
//			PUT_STR(OK);
//		else
//		{
//			cout << LB << *(ft.end()) << " != " << *(std.end()) << CLEAN << std::endl;
//			PUT_STR(KO);
//		}
//		{
//			PUT_STR(B"RBEGIN()");
//			int array[] = {0, 1, 2, 3};
//			ft::list<int> ft(array, array + sizeof(array));
//			std::list<int> std(array, array + sizeof(array));
//			if (*(ft.rbegin()) == *(std.rbegin()))
//				PUT_STR(OK);
//			else {
//				cout << LB << *(ft.rbegin()) << " != " << *(std.rbegin()) << CLEAN << std::endl;
//				PUT_STR(KO);
//			}
//		}
//		{
//			PUT_STR(B"REND()");
//			int array[] = {0, 1, 2, 3};
//			ft::list<int> ft(array, array + sizeof(array));
//			std::list<int> std(array, array + sizeof(array));
//			if (*(ft.rend()) == *(std.rend()))
//				PUT_STR(OK);
//			else {
//				cout << LB << *(ft.rend()) << " != " << *(std.rend()) << CLEAN << std::endl;
//				PUT_STR(KO);
//			}
//		}
#endif
#ifdef T13
	{
		PUT_STR(B"BEGIN()");
		ft::list<int> ft;
		std::list<int> std;
		for (int i = 0; i < 10; ++i) {
			ft.push_back(i);
			std.push_back(i);
		}
		if (*(ft.begin()) == *(std.begin()))
			PUT_STR(OK);
		else {
			cout << LB << *(ft.begin()) << " != " << *(std.begin()) << CLEAN << std::endl;
			PUT_STR(KO);
		}
	}
#endif
#ifdef T14
	{
		PUT_STR(B"END()");
		ft::list<int> ft;
		std::list<int> std;
		for (int i = 0; i < 10; ++i) {
			ft.push_back(i);
			std.push_back(i);
		}
		if (*(ft.end()) == *(std.end()))
			PUT_STR(OK);
		else {
			cout << LB << *(ft.end()) << " != " << *(std.end()) << CLEAN << std::endl;
			PUT_STR(KO);
		}
	}
#endif
#ifdef T15
	{
		PUT_STR(B"RBEGIN()");
		ft::list<int> ft;
		std::list<int> std;
		for (int i = 0; i < 10; ++i) {
			ft.push_back(i);
			std.push_back(i);
		}
		if (*(ft.rbegin()) == *(std.rbegin()))
			PUT_STR(OK);
		else {
			cout << LB << *(ft.rbegin()) << " != " << *(std.rbegin()) << CLEAN << std::endl;
			PUT_STR(KO);
		}
	}
#endif
#ifdef T16
	{
		PUT_STR(B"REND()");
		ft::list<int> ft;
		std::list<int> std;
		for (int i = 0; i < 10; ++i) {
			ft.push_back(i);
			std.push_back(i);
		}
		if (*(ft.rend()) == *(std.rend()))
			PUT_STR(OK);
		else {
			cout << LB << *(ft.rend()) << " != " << *(std.rend()) << CLEAN << std::endl;
			PUT_STR(KO);
		}
	}
#endif
#ifdef T17
	{
		PUT_STR(B"EMPTY()");
		ft::list<int> ft;
		std::list<int> std;
		if (ft.empty() == std.empty())
			PUT_STR(OK);
		else {
			cout << LB << ft.empty() << " != " << std.empty() << CLEAN << std::endl;
			PUT_STR(KO);
		}
		for (int i = 0; i < 10; ++i) {
			ft.push_back(i);
			std.push_back(i);
		}
		if (ft.empty() == std.empty())
			PUT_STR(OK);
		else {
			cout << LB << ft.empty() << " != " << std.empty() << CLEAN << std::endl;
			PUT_STR(KO);
		}
	}
#endif
#ifdef T18
	{
		PUT_STR(B"SIZE()");
		ft::list<int> ft;
		std::list<int> std;
		if (ft.size() == std.size())
			PUT_STR(OK);
		else {
			cout << LB << ft.size() << " != " << std.size() << CLEAN << std::endl;
			PUT_STR(KO);
		}
		for (int i = 0; i < 10; ++i) {
			ft.push_back(i);
			std.push_back(i);
		}
		if (ft.size() == std.size())
			PUT_STR(OK);
		else {
			cout << LB << ft.size() << " != " << std.size() << CLEAN << std::endl;
			PUT_STR(KO);
		}
	}
#endif
#ifdef T19
	{
		PUT_STR(B"MAX_SIZE()");
		ft::list<int> ft;
		std::list<int> std;
		if(ft.max_size() == std.max_size())
			PUT_STR(OK);
		else {
			cout << LB << ft.max_size() << " != " << std.max_size() << CLEAN << std::endl;
			PUT_STR(KO);
		}
	}
#endif
#ifdef T20
	{
		PUT_STR(B"FRONT()");
		ft::list<int> ft;
		std::list<int> std;
		const ft::list<int> ft_const(3, 3);
		const std::list<int> std_const(3, 3);

		ft.push_back(77);
		ft.push_back(22);
		std.push_back(77);
		std.push_back(22);

		if(ft.front() == std.front())
			PUT_STR(OK);
		else {
			cout << LB << ft.front() << " != " << std.front() << CLEAN << std::endl;
			PUT_STR(KO);
		}
		if(ft_const.front() == std_const.front())
			PUT_STR(OK);
		else {
			cout << LB << ft_const.front() << " != " << std_const.front() << CLEAN << std::endl;
			PUT_STR(KO);
		}
	}
#endif
#ifdef T21
	{
		PUT_STR(B"BACK()");
		ft::list<int> ft;
		std::list<int> std;
		const ft::list<int> ft_const(3, 3);
		const std::list<int> std_const(3, 3);

		ft.push_back(77);
		ft.push_back(22);
		std.push_back(77);
		std.push_back(22);

		if(ft.back() == std.back())
			PUT_STR(OK);
		else {
			cout << LB << ft.back() << " != " << std.back() << CLEAN << std::endl;
			PUT_STR(KO);
		}
		if(ft_const.back() == std_const.back())
			PUT_STR(OK);
		else {
			cout << LB << ft_const.back() << " != " << std_const.back() << CLEAN << std::endl;
			PUT_STR(KO);
		}
	}
#endif
#ifdef T22
	{
		PUT_STR(B"ASSIGN()");
		bool flag = true;
		ft::list<int> ft_first;
		ft::list<int> ft_second;
		std::list<int> std_first;
		std::list<int> std_second;

		ft_first.assign (7,100);                      // 7 ints with value 100
		std_first.assign (7,100);                      // 7 ints with value 100

		ft_second.assign (ft_first.begin(),ft_first.end()); // a copy of first
		std_second.assign (std_first.begin(),std_first.end()); // a copy of first

		int myints[]={1776,7,4};
		ft_first.assign (myints,myints+3);            // assigning from array
		std_first.assign (myints,myints+3);            // assigning from array

		if(ft_first.size() == std_first.size())
			PUT_STR(OK);
		else {
			cout << LB << ft_first.size() << " != " << std_first.size() << CLEAN << std::endl;
			PUT_STR(KO);
		}
		if(ft_second.size() == std_second.size())
			PUT_STR(OK);
		else {
			cout << LB << ft_second.size() << " != " << std_second.size() << CLEAN << std::endl;
			PUT_STR(KO);
		}
		ft::list<int>::iterator ft_first_itb = ft_first.begin();
		ft::list<int>::iterator ft_first_ite = ft_first.end();
		ft::list<int>::iterator ft_second_itb = ft_second.begin();
		ft::list<int>::iterator ft_second_ite = ft_second.end();
		std::list<int>::iterator std_first_itb = std_first.begin();
		std::list<int>::iterator std_first_ite = std_first.end();
		std::list<int>::iterator std_second_itb = std_second.begin();
		std::list<int>::iterator std_second_ite = std_second.end();
//		while (ft_first_itb != ft_first_ite && std_first_itb != std_first_ite)
//		{
//			if (*ft_first_itb == *std_first_itb)
//			{
//				flag = true;
//			} else {
//				flag = false;
//				cout << LB << *ft_first_itb << " != " << *std_first_itb << CLEAN << std::endl;
//				break;
//			}
//			++ft_first_itb;
//			++std_first_itb;
//		}
		check_value<int>(ft_first_itb, ft_first_ite, std_first_itb, std_first_ite, flag);
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
//		while (ft_second_itb != ft_second_ite && std_second_itb != std_first_ite)
//		{
//			if (*ft_second_itb == *std_second_itb)
//			{
//				flag = true;
//			} else {
//				flag = false;
//				cout << LB << *ft_second_itb << " != " << *std_second_itb << CLEAN << std::endl;
//				break;
//			}
//			++ft_second_itb;
//			++std_second_itb;
//		}
		check_value<int>(ft_second_itb, ft_second_ite, std_second_itb, std_second_ite, flag);
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T23
	{
		PUT_STR(B"PUSH_FRONT()");
		bool flag = true;
		ft::list<int> ft;
		std::list<int> std;
		for (int i = 0; i < 10; ++i) {
			ft.push_front(i);
			std.push_front(i);
		}
		ft::list<int>::iterator ft_itb = ft.begin();
		std::list<int>::iterator std_itb = std.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_ite = std.end();
//		while (std_itb != std_ite && ft_itb != ft_ite)
//		{
//			if (*ft_itb != *std_itb && ft_itb != ft_ite)
//			{
//				flag = false;
//				cout << LB << *ft_itb << " != " << *std_itb << CLEAN << std::endl;
//				break;
//			} else {
//				flag = true;
//			}
//			++ft_itb;
//			++std_itb;
//		}
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T24
	{
		PUT_STR(B"POP_FRONT()");
		bool flag = true;
		ft::list<int> ft;
		std::list<int> std;
		ft::list<int>::iterator ft_itb;
		std::list<int>::iterator std_itb;
		ft::list<int>::iterator ft_ite;
		std::list<int>::iterator std_ite;
		for (int i = 0; i < 10; ++i) {
			ft.push_front(i);
			std.push_front(i);
		}
		for (int i = 0; i < 5; ++i) {
			ft.pop_front();
			std.pop_front();
		}
		ft_itb = ft.begin();
		std_itb = std.begin();
		ft_ite = ft.end();
		std_ite = std.end();
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		for (int i = 0; i < 3; ++i) {
			ft.pop_front();
			std.pop_front();
		}
		ft_itb = ft.begin();
		std_itb = std.begin();
		ft_ite = ft.end();
		std_ite = std.end();
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
	}
#endif
#ifdef T25
	{
		PUT_STR(B"PUSH_BACK()");
		bool flag = true;
		ft::list<int> ft;
		std::list<int> std;
		for (int i = 0; i < 10; ++i) {
			ft.push_back(i);
			std.push_back(i);
		}
		ft::list<int>::iterator ft_itb = ft.begin();
		std::list<int>::iterator std_itb = std.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_ite = std.end();
//		while (std_itb != std_ite)
//		{
//			if (*ft_itb != *std_itb && ft_itb != ft_ite)
//			{
//				flag = false;
//				cout << LB << *ft_itb << " != " << *std_itb << CLEAN << std::endl;
//				break;
//			} else {
//				flag = true;
//			}
//			++ft_itb;
//			++std_itb;
//		}
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
	}
#endif
#ifdef T26
	{
		PUT_STR(B"POP_BACK()");
		bool flag = true;
		ft::list<int> ft;
		std::list<int> std;
		ft::list<int>::iterator ft_itb;
		std::list<int>::iterator std_itb;
		ft::list<int>::iterator ft_ite;
		std::list<int>::iterator std_ite;
		for (int i = 0; i < 10; ++i) {
			ft.push_front(i);
			std.push_front(i);
		}
		for (int i = 0; i < 5; ++i) {
			ft.pop_back();
			std.pop_back();
		}
		ft_itb = ft.begin();
		std_itb = std.begin();
		ft_ite = ft.end();
		std_ite = std.end();
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
		for (int i = 0; i < 3; ++i) {
			ft.pop_back();
			std.pop_back();
		}
		ft_itb = ft.begin();
		std_itb = std.begin();
		ft_ite = ft.end();
		std_ite = std.end();
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
	}
#endif
#ifdef T27
	{
		{
			PUT_STR(B"INSERT()[single element]");
			bool flag = true;
			ft::list<int> ft;
			std::list<int> std;
			for (int i = 0; i < 10; ++i) {
				ft.push_front(i);
				std.push_front(i);
			}
			ft::list<int>::iterator ft_itb = ft.begin();
			std::list<int>::iterator std_itb = std.begin();
			ft::list<int>::iterator ft_ite = ft.end();
			std::list<int>::iterator std_ite = std.end();
			for (int i = 0; i < 5; ++i) {
				++ft_itb;
				++std_itb;
			}
			for (int i = 0; i < 3; ++i) {
				ft::list<int>::iterator ft_j = ft.insert(ft_itb, 42);
				std::list<int>::iterator std_j = std.insert(std_itb, 42);
				if (*ft_j != *std_j)
				{
					flag = false;
					cout << LB << *ft_j << " != " << *std_j << CLEAN << std::endl;
					break;
				} else
				{
					flag = true;
				}
				++ft_itb;
				++std_itb;
			}
			check_flag(flag);
			ft_itb = ft.begin();
			std_itb = std.begin();
			check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
			check_flag(flag);
			check_size(ft, std, flag);
//			if (ft.size() != std.size())
//			{
//				flag = false;
//				cout << LB << ft.size() << " != " << std.size() << CLEAN << std::endl;
//			} else {
//				flag = true;
//			}
			check_flag(flag);
		}
		{
			PUT_STR(B"INSERT()[fill]");
			bool flag = true;
			ft::list<int> ft;
			std::list<int> std;
			for (int i = 0; i < 10; ++i) {
				ft.push_front(i);
				std.push_front(i);
			}
			ft::list<int>::iterator ft_itb = ft.begin();
			std::list<int>::iterator std_itb = std.begin();
			ft::list<int>::iterator ft_ite = ft.end();
			std::list<int>::iterator std_ite = std.end();
			for (int i = 0; i < 5; ++i) {
				++ft_itb;
				++std_itb;
			}
			ft.insert(ft_itb, 3, 42);
			std.insert(std_itb, 3, 42);
			ft_itb = ft.begin();
			std_itb = std.begin();
			check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
			check_flag(flag);
			check_size(ft, std, flag);
//			if (ft.size() != std.size())
//			{
//				flag = false;
//				cout << LB << ft.size() << " != " << std.size() << CLEAN << std::endl;
//			} else {
//				flag = true;
//			}
			check_flag(flag);
		}
		{
			PUT_STR(B"INSERT()[range]");
			bool flag = true;
			ft::list<int> ft;
			std::list<int> std;
			for (int i = 0; i < 10; ++i) {
				ft.push_front(i);
				std.push_front(i);
			}
			ft::list<int>::iterator ft_itb = ft.begin();
			std::list<int>::iterator std_itb = std.begin();
			ft::list<int>::iterator ft_ite = ft.end();
			std::list<int>::iterator std_ite = std.end();
			for (int i = 0; i < 5; ++i) {
				++ft_itb;
				++std_itb;
			}
			std::list<int> tmp(5, 10);
			ft.insert(ft_itb, tmp.begin(), tmp.end());
			std.insert(std_itb, tmp.begin(), tmp.end());
			ft_itb = ft.begin();
			std_itb = std.begin();
			ft_ite = ft.end();
			std_ite = std.end();
			check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
			check_flag(flag);
			check_size(ft, std, flag);
//			if (ft.size() != std.size())
//			{
//				flag = false;
//				cout << LB << ft.size() << " != " << std.size() << CLEAN << std::endl;
//			} else {
//				flag = true;
//			}
			check_flag(flag);
		}
	}
#endif
#ifdef T28
	{
		{
			PUT_STR(B"ERASE()[single element]");
			bool flag = true;
			ft::list<int> ft;
			std::list<int> std;
			for (int i = 0; i < 10; ++i) {
				ft.push_front(i);
				std.push_front(i);
			}
			ft::list<int>::iterator ft_itb = ft.begin();
			std::list<int>::iterator std_itb = std.begin();
			ft::list<int>::iterator ft_ite = ft.end();
			std::list<int>::iterator std_ite = std.end();
			for (int i = 0; i < 5; ++i) {
				++ft_itb;
				++std_itb;
			}
//			for (int i = 0; i < 3; ++i) {				//strange error occurred: segfault, check ft_itb value before and afrer std.erase()
//				ft.erase(ft_itb);
//				std.erase(std_itb);
//				check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
//				check_flag(flag);
//				++ft_itb;
//				++std_itb;
//			}
			for (int i = 0; i < 3; ++i) {
				ft.erase(ft_itb);
				++ft_itb;
			}
			for (int i = 0; i < 3; ++i) {
				std.erase(std_itb);
				++std_itb;
			}
			ft_itb = ft.begin();
			std_itb = std.begin();
			ft_ite = ft.end();
			std_ite = std.end();
			check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
			check_flag(flag);
			check_size(ft, std, flag);
//			if (ft.size() != std.size())
//			{
//				flag = false;
//				cout << LB << ft.size() << " != " << std.size() << CLEAN << std::endl;
//			} else {
//				flag = true;
//			}
			check_flag(flag);
		}
		{
			PUT_STR(B"ERASE()[range]");
			bool flag = true;
			ft::list<int> ft;
			std::list<int> std;
			for (int i = 0; i < 10; ++i) {
				ft.push_front(i);
				std.push_front(i);
			}
			ft::list<int>::iterator ft_itb1 = ft.begin();
			std::list<int>::iterator std_itb1 = std.begin();
			ft::list<int>::iterator ft_ite1 = ft.end();
			std::list<int>::iterator std_ite1 = std.end();
			ft::list<int>::iterator ft_itb2 = ft.begin();
			std::list<int>::iterator std_itb2 = std.begin();
			ft::list<int>::iterator ft_ite2 = ft.end();
			std::list<int>::iterator std_ite2 = std.end();
			for (int i = 0; i < 2; ++i) {
				++ft_itb1;
				++std_itb1;
				++ft_itb2;
				++std_itb2;
			}
			for (int i = 0; i < 6; ++i) {
				++ft_itb2;
				++std_itb2;
			}
			ft.erase(ft_itb1, ft_itb2);
			std.erase(std_itb1, std_itb2);
			ft::list<int>::iterator ft_itb = ft.begin();
			std::list<int>::iterator std_itb = std.begin();
			ft::list<int>::iterator ft_ite = ft.end();
			std::list<int>::iterator std_ite = std.end();
			check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
			check_flag(flag);
			check_size(ft, std, flag);
//			if (ft.size() != std.size())
//			{
//				flag = false;
//				cout << LB << ft.size() << " != " << std.size() << CLEAN << std::endl;
//			} else {
//				flag = true;
//			}
			check_flag(flag);
		}
	}
#endif
#ifdef T29
	{
		bool flag = true;
		PUT_STR(B"SWAP()");
		ft::list<int> ft_first (3,100);   // three ints with a value of 100
		ft::list<int> ft_second (5,200);  // five ints with a value of 200
		std::list<int> std_first (3,100);   // three ints with a value of 100
		std::list<int> std_second (5,200);  // five ints with a value of 200

		ft_first.swap(ft_second);
		std_first.swap(std_second);

		ft::list<int>::iterator ft_first_itb = ft_first.begin();
		std::list<int>::iterator std_first_itb = std_first.begin();
		ft::list<int>::iterator ft_first_ite = ft_first.end();
		std::list<int>::iterator std_first_ite = std_first.end();

		ft::list<int>::iterator ft_second_itb = ft_second.begin();
		std::list<int>::iterator std_second_itb = std_second.begin();
		ft::list<int>::iterator ft_second_ite = ft_second.end();
		std::list<int>::iterator std_second_ite = std_second.end();

		check_value<int>(ft_first_itb, ft_first_ite, std_first_itb, std_first_ite, flag);
		check_flag(flag);
		check_value<int>(ft_second_itb, ft_second_ite, std_second_itb, std_second_ite, flag);
		check_flag(flag);
		check_size(ft_first, std_first, flag);
		check_flag(flag);
		check_size(ft_second, std_second, flag);
		check_flag(flag);
	}
#endif
#ifdef T30
	{
		PUT_STR(B"RESIZE()");
		bool flag = true;
		ft::list<int> ft;
		std::list<int> std;
		ft::list<int>::iterator ft_itb;
		std::list<int>::iterator std_itb;
		ft::list<int>::iterator ft_ite;
		std::list<int>::iterator std_ite;
		for (int i = 0; i < 10; ++i) {
			ft.push_front(i);
			std.push_front(i);
		}
		ft.resize(8);
		std.resize(8);
		ft_itb = ft.begin();
		std_itb = std.begin();
		ft_ite = ft.end();
		std_ite = std.end();
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);

		ft.resize(5, 42);
		std.resize(5, 42);
		ft_itb = ft.begin();
		std_itb = std.begin();
		ft_ite = ft.end();
		std_ite = std.end();
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);

		ft.resize(20);
		std.resize(20);
		ft_itb = ft.begin();
		std_itb = std.begin();
		ft_ite = ft.end();
		std_ite = std.end();
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
	}
#endif
#ifdef T31
	{
		PUT_STR(B"CLEAR()");
		bool flag = true;
		ft::list<int> ft;
		std::list<int> std;
		ft::list<int>::iterator ft_itb;
		std::list<int>::iterator std_itb;
		ft::list<int>::iterator ft_ite;
		std::list<int>::iterator std_ite;
		for (int i = 0; i < 10; ++i) {
			ft.push_front(i);
			std.push_front(i);
		}
		ft.clear();
		std.clear();
		ft_itb = ft.begin();
		std_itb = std.begin();
		ft_ite = ft.end();
		std_ite = std.end();
//		std::cout << *std_itb << std::endl;
//		std::cout << *ft_itb << std::endl;
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);

		for (int i = 0; i < 10; ++i) {
			ft.push_front(i);
			std.push_front(i);
		}
		ft_itb = ft.begin();
		std_itb = std.begin();
		ft_ite = ft.end();
		std_ite = std.end();
		check_value<int>(ft_itb, ft_ite, std_itb, std_ite, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
	}


#endif
#ifdef T32


#endif
#ifdef T33

#endif
	return (0);
}