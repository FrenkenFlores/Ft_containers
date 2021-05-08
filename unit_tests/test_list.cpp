#include "unit_tests.hpp"
using namespace std;
int main(void) {
	{
		int flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[int]");
		ft::list<int> ft;
		std::list<int> std;
		ft::list<int>::iterator ft_itb = ft.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_itb = std.begin();
		std::list<int>::iterator std_ite = std.end();
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
		if (flag == true)
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
	{
		int flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[float]");
		ft::list<float> ft;
		std::list<float> std;
		ft::list<float>::iterator ft_itb = ft.begin();
		ft::list<float>::iterator ft_ite = ft.end();
		std::list<float>::iterator std_itb = std.begin();
		std::list<float>::iterator std_ite = std.end();
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
		if (flag == true)
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
	{
		int flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[double]");
		ft::list<double> ft;
		std::list<double> std;
		ft::list<double>::iterator ft_itb = ft.begin();
		ft::list<double>::iterator ft_ite = ft.end();
		std::list<double>::iterator std_itb = std.begin();
		std::list<double>::iterator std_ite = std.end();
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
		if (flag == true)
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
	{
		int flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[char]");
		ft::list<char> ft;
		std::list<char> std;
		ft::list<char>::iterator ft_itb = ft.begin();
		ft::list<char>::iterator ft_ite = ft.end();
		std::list<char>::iterator std_itb = std.begin();
		std::list<char>::iterator std_ite = std.end();
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
		if (flag == true)
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
	{
		int flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[string]");
		ft::list<string> ft;
		std::list<string> std;
		ft::list<string>::iterator ft_itb = ft.begin();
		ft::list<string>::iterator ft_ite = ft.end();
		std::list<string>::iterator std_itb = std.begin();
		std::list<string>::iterator std_ite = std.end();
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
		if (flag == true)
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
	{
		int flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR[vector]");
		ft::list<vector<int> > ft;
		std::list<vector<int> > std;
		ft::list<vector<int> >::iterator ft_itb = ft.begin();
		ft::list<vector<int> >::iterator ft_ite = ft.end();
		std::list<vector<int> >::iterator std_itb = std.begin();
		std::list<vector<int> >::iterator std_ite = std.end();
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
		if (flag == true)
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
	{
		int flag = true;
		PUT_STR(B"FILL CONSTRUCTOR");
		ft::list<int> ft(10, 42);
		std::list<int> std(10, 42);
		ft::list<int>::iterator ft_itb = ft.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_itb = std.begin();
		std::list<int>::iterator std_ite = std.end();
		while (ft_itb != ft_ite && std_itb != std_ite)
		{
			if (*ft_itb != *std_itb)
			{
				std::cout << *ft_itb << " != " << *std_itb << std::endl;
				flag = false;
				break;
			}
			else
				flag = true;
			++ft_itb;
			++std_itb;
		}
		if (flag == true)
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
	{
		int flag = true;
		PUT_STR(B"RANGE CONSTRUCTOR[ARRAY]");
		int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		ft::list<int> ft(array, array + sizeof(array));
		std::list<int> std(array, array + sizeof(array));
		ft::list<int>::iterator ft_itb = ft.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_itb = std.begin();
		std::list<int>::iterator std_ite = std.end();
		while (ft_itb != ft_ite && std_itb != std_ite)
		{
			if (*ft_itb != *std_itb)
			{
				std::cout << *ft_itb << " != " << *std_itb << std::endl;
				flag = false;
				break;
			}
			else
				flag = true;
			++ft_itb;
			++std_itb;
		}
		if (flag == true)
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
	{
		int flag = true;
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
		while (ft_itb != ft_ite && std_itb != std_ite)
		{
			if (*ft_itb != *std_itb)
			{
				std::cout << *ft_itb << " != " << *std_itb << std::endl;
				flag = false;
				break;
			}
			else
				flag = true;
			++ft_itb;
			++std_itb;
		}
		if (flag == true)
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
	{
		int flag = true;
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
		while (ft_itb != ft_ite && std_itb != std_ite)
		{
			if (*ft_itb != *std_itb)
			{
				std::cout << *ft_itb << " != " << *std_itb << std::endl;
				flag = false;
				break;
			}
			else
				flag = true;
			++ft_itb;
			++std_itb;
		}
		if (flag == true)
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
	{
		int flag = true;
		PUT_STR(B"COPY CONSTRUCTOR");
		ft::list<int> ft_src(10, 42);
		std::list<int> std_src(10, 42);
		std::list<int> std = std_src;
		ft::list<int> ft = ft_src;
		ft::list<int>::iterator ft_itb = ft.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_itb = std.begin();
		std::list<int>::iterator std_ite = std.end();
		while (ft_itb != ft_ite && std_itb != std_ite)
		{
			if (*ft_itb != *std_itb)
			{
				std::cout << *ft_itb << " != " << *std_itb << std::endl;
				flag = false;
				break;
			}
			else
				flag = true;
			++ft_itb;
			++std_itb;
		}
		if (flag == true)
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
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
		else
		{
			cout << LB << *(ft.end()) << " != " << *(std.end()) << CLEAN << std::endl;
			PUT_STR(KO);
		}
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
	}

	return (0);
}