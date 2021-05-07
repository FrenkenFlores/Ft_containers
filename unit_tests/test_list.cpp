#include "unit_tests.hpp"

int main(void) {
	{
		int flag = true;
		PUT_STR(B"DEFAULT CONSTRUCTOR");
		ft::list<int> ft;
		std::list<int> std;
		ft::list<int>::iterator ft_itb = ft.begin();
		ft::list<int>::iterator ft_ite = ft.end();
		std::list<int>::iterator std_itb = std.begin();
		std::list<int>::iterator std_ite = std.end();
		while (ft_itb != ft_ite && std_itb != std_ite)
		{
			if (*ft_itb != *ft_ite)
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



	return (0);
}