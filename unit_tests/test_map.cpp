#include "unit_tests.hpp"
#define T1 // constructors
#define T2 // operator=()
#define T3 // begin(), end(), rbegin(), rend()
#define T4 // empty()
#define T5 // size()
#define T6 // max_size()
#define T7 // operator[]()
#define T8 // insert()
#define T9 // erase()
//#define T10 // swap()
//#define T11 // clear[]
//#define T12 // key_comp()
//#define T13 // value_comp()
//#define T14 // find()
//#define T15 // count()
//#define T16 // lower_bound()
//#define T17 // upper_bound()
//#define T18 // equal_range()
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
	flag = false;
}

template <typename T, typename U>
void check_value(ft::map<T, U> &x, std::map<T, U> &y, bool &flag) {
	typename ft::map<T, U>::iterator ft_itb = x.begin();
	typename ft::map<T, U>::iterator ft_ite = x.end();
	typename std::map<T, U>::iterator std_itb = y.begin();
	typename std::map<T, U>::iterator std_ite = y.end();
	while (ft_itb != ft_ite && std_itb != std_ite)
	{
		if (ft_itb->first != std_itb->first && ft_itb->second != std_itb->second)
		{
			flag = false;
			cout << LB << ft_itb->first << ":" << ft_itb->second << " != " << std_itb->first << ":" << std_itb->second << CLEAN << std::endl;
			break;
		} else {
			cout << P << ft_itb->first << ":" << ft_itb->second << " == " << std_itb->first << ":" << std_itb->second << CLEAN << std::endl;
			flag = true;
		}
		++ft_itb;
		++std_itb;
	}
}

template <typename T, typename U>
void check_size(ft::map<T, U> &x, std::map<T, U> &y, bool &flag) {
	if (x.size() != y.size())
	{
		flag = false;
		cout << LB << x.size() << " != " << y.size() << CLEAN << std::endl;
	} else {
		flag = true;
		cout << P << x.size() << " == " << y.size() << CLEAN << std::endl;
	}
}



//for map constructor testing
bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

int main(void) {
	bool flag = true;
#ifdef T1
	{
		PUT_STR(B"CONSTRUCTOR[default (1)]");
		std::map<char,int> std_first;
		ft::map<char,int> ft_first;

		check_value(ft_first, std_first, flag);
		check_flag(flag);
		check_size(ft_first, std_first, flag);
		check_flag(flag);

		PUT_STR(B"CONSTRUCTOR[range (2)]");
		std_first['a']=10;
		std_first['b']=30;
		std_first['c']=50;
		std_first['d']=70;

		ft_first['a']=10;
		ft_first['b']=30;
		ft_first['c']=50;
		ft_first['d']=70;

		std::map<char,int> std_second (std_first.begin(),std_first.end());
		ft::map<char,int> ft_second (ft_first.begin(),ft_first.end());

		check_value(ft_second, std_second, flag);
		check_flag(flag);
		check_size(ft_second, std_second, flag);
		check_flag(flag);

		PUT_STR(B"CONSTRUCTOR[copy (3)]");
		std::map<char,int> std_third (std_second);
		ft::map<char,int> ft_third (ft_second);
		check_value(ft_second, std_second, flag);
		check_flag(flag);
		check_size(ft_second, std_second, flag);
		check_flag(flag);

		std::map<char,int,classcomp> std_fourth;                 // class as Compare
		ft::map<char,int,classcomp> ft_fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		std::map<char,int,bool(*)(char,char)> std_fifth (fn_pt);
		ft::map<char,int,bool(*)(char,char)> ft_fifth (fn_pt);
		PUT_STR(B"DESTRUCTOR");
	}
#endif
#ifdef T2
	{
		PUT_STR(B"OPERATOR=()");

		std::map<char,int> std_first;
		ft::map<char,int> ft_first;
		std::map<char,int> std_second;
		ft::map<char,int> ft_second;

		ft_first['x']=8;
		ft_first['y']=16;
		ft_first['z']=32;

		std_first['x']=8;
		std_first['y']=16;
		std_first['z']=32;
		
		std_second=std_first;              // second now contains 3 ints
		ft_second=ft_first;                // second now contains 3 ints
		check_value(ft_second, std_second, flag);
		check_flag(flag);
		check_size(ft_second, std_second, flag);
		check_flag(flag);

		ft_first=ft::map<char,int>();  	// and first is now empty
		std_first=std::map<char,int>();  // and first is now empty
		check_value(ft_first, std_first, flag);
		check_flag(flag);
		check_size(ft_first, std_first, flag);
		check_flag(flag);

	}
#endif
#ifdef T3
	{
		std::map<char,int> std;
		ft::map<char,int> ft;


		ft['x']=8;
		ft['y']=16;
		ft['z']=32;

		std['x']=8;
		std['y']=16;
		std['z']=32;

		PUT_STR(B"BEGIN()");
		if (ft.begin()->first == std.begin()->first && ft.begin()->second == std.begin()->second)
			PUT_STR(OK);
		else
			PUT_STR(KO);

		PUT_STR(B"END()");
		if (ft.end()->first == std.end()->first || ft.end()->second == std.end()->second)
			PUT_STR(OK);
		else
			PUT_STR(KO);

		PUT_STR(B"RBEGIN()");
		PUT_STR(B"REND()");
	}
#endif
#ifdef T4
	{
		PUT_STR(B"EMPTY()");
		std::map<char,int> std;
		ft::map<char,int> ft;


		ft['x']=8;
		ft['y']=16;
		ft['z']=32;

		std['x']=8;
		std['y']=16;
		std['z']=32;
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
#ifdef T5
	{
		PUT_STR(B"SIZE()");
		std::map<char,int> std;
		ft::map<char,int> ft;


		ft['x']=8;
		ft['y']=16;
		ft['z']=32;

		std['x']=8;
		std['y']=16;
		std['z']=32;
		if (std.size() == ft.size())
			PUT_STR(OK);
		else
			PUT_STR(KO);
		
		ft.clear();
		std.clear();
		if (std.size() == ft.size())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T6
	{
		PUT_STR(B"MAX_SIZE()");
		std::map<char,int> std;
		ft::map<char,int> ft;
		if (std.max_size() == ft.max_size())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T7
	{
		PUT_STR(B"OPERATOR[]()");
		std::map<char,int> std;
		ft::map<char,int> ft;


		ft['x']=8;
		ft['y']=16;
		ft['z']=32;

		std['x']=8;
		std['y']=16;
		std['z']=32;
		check_value(ft, std, flag);
		check_flag(flag);
		check_size(ft, std, flag);
		check_flag(flag);
	}
#endif
#ifdef T8
	{
		PUT_STR(B"INSERT()");
		
		std::map<char,int> std_mymap;
		ft::map<char,int> ft_mymap;

		// first insert function version (single parameter):
		ft_mymap.insert ( std::pair<char,int>('a',100) );
		ft_mymap.insert ( std::pair<char,int>('z',200) );
		std_mymap.insert ( std::pair<char,int>('a',100) );
		std_mymap.insert ( std::pair<char,int>('z',200) );
		check_value(ft_mymap, std_mymap, flag);
		check_flag(flag);
		check_size(ft_mymap, std_mymap, flag);
		check_flag(flag);

		std::pair<std::map<char,int>::iterator,bool> std_ret;
		std_ret = std_mymap.insert ( std::pair<char,int>('z',500) );

		std::pair<ft::map<char,int>::iterator,bool> ft_ret;
		ft_ret = ft_mymap.insert ( std::pair<char,int>('z',500) );

		if (std_ret.second==ft_ret.second)
			PUT_STR(OK);
		else
			PUT_STR(KO);

		// second insert function version (with hint position):
		std::map<char,int>::iterator std_it = std_mymap.begin();
		std_mymap.insert (std_it, std::pair<char,int>('b',300));  // max efficiency inserting
		std_mymap.insert (std_it, std::pair<char,int>('c',400));  // no max efficiency inserting

		ft::map<char,int>::iterator ft_it = ft_mymap.begin();
		ft_mymap.insert (ft_it, std::pair<char,int>('b',300));  // max efficiency inserting
		ft_mymap.insert (ft_it, std::pair<char,int>('c',400));  // no max efficiency inserting

		check_value(ft_mymap, std_mymap, flag);
		check_flag(flag);
		check_size(ft_mymap, std_mymap, flag);
		check_flag(flag);

		// third insert function version (range insertion):
		std::map<char,int> std_anothermap;
		std_anothermap.insert(std_mymap.begin(),std_mymap.find('c'));
		ft::map<char,int> ft_anothermap;
		ft_anothermap.insert(ft_mymap.begin(),ft_mymap.find('c'));

		check_value(ft_anothermap, std_anothermap, flag);
		check_flag(flag);
		check_size(ft_anothermap, std_anothermap, flag);
		check_flag(flag);

	}
#endif
#ifdef T9
	{
		PUT_STR(B"ERASE()");
	}
#endif
#ifdef T10
	{
		PUT_STR(B"OPERATOR[]");
		std::map<char,int>::iterator it_std_b;
		ft::map<char,int>::iterator it_ft_b;
		std::map<char,int>::iterator it_std_e;
		ft::map<char,int>::iterator it_ft_e;
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
