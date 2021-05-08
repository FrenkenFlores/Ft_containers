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
//	{
//		int flag = true;
//		PUT_STR(B"DEFAULT CONSTRUCTOR[vector]");
//		ft::list<vector<int> > ft;
//		std::list<vector<int> > std;
//		ft::list<vector<int> >::iterator ft_itb = ft.begin();
//		ft::list<vector<int> >::iterator ft_ite = ft.end();
//		std::list<vector<int> >::iterator std_itb = std.begin();
//		std::list<vector<int> >::iterator std_ite = std.end();
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
//		if (flag == true)
//			PUT_STR(OK);
//		else
//			PUT_STR(KO);
//	}
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
		PUT_STR(B"RANGE CONSTRUCTOR");
		PUT_STR(B"RANGE CONSTRUCTOR FILL WITH ARRAY");
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
		PUT_STR(B"RANGE CONSTRUCTOR");
		PUT_STR(B"RANGE CONSTRUCTOR FILL WITH VECTOR");
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

	return (0);
}