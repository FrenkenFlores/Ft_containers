#include "unit_tests.hpp"
#define T1 // constructors
#define T2 // operator=()
#define T3 // begin(), end(), rbegin(), rend()
#define T4 // empty()
#define T5 // size()
//#define T6 // max_size()
#define T7 // operator[]()
#define T8 // insert()
#define T9 // erase()
#define T10 // swap()
#define T11 // clear()
#define T12 // key_comp()
#define T13 // value_comp()
#define T14 // find()
#define T15 // count()
#define T16 // lower_bound()
#define T17 // upper_bound()
#define T18 // equal_range()


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
//			cout << P << ft_itb->first << ":" << ft_itb->second << " == " << std_itb->first << ":" << std_itb->second << CLEAN << std::endl;
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
//		cout << P << x.size() << " == " << y.size() << CLEAN << std::endl;
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
//		std::cout << std.max_size() << " == " << ft.max_size() << std::endl;
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
		std::map<char,int> std_mymap;
		std::map<char,int>::iterator std_it;
		ft::map<char,int> ft_mymap;
		ft::map<char,int>::iterator ft_it;

		// insert some values:
		std_mymap['a']=10;
		std_mymap['b']=20;
		std_mymap['c']=30;
		std_mymap['d']=40;
		std_mymap['e']=50;
		std_mymap['f']=60;

		ft_mymap['a']=10;
		ft_mymap['b']=20;
		ft_mymap['c']=30;
		ft_mymap['d']=40;
		ft_mymap['e']=50;
		ft_mymap['f']=60;

		std_it=std_mymap.find('b');
		std_mymap.erase (std_it);                   // erasing by iterator

		ft_it=ft_mymap.find('b');
		ft_mymap.erase (ft_it);                   // erasing by iterator
		check_value(ft_mymap, std_mymap, flag);
		check_flag(flag);
		check_size(ft_mymap, std_mymap, flag);
		check_flag(flag);


		std_mymap.erase ('c');                  // erasing by key
		ft_mymap.erase ('c');                  // erasing by key
		check_value(ft_mymap, std_mymap, flag);
		check_flag(flag);
		check_size(ft_mymap, std_mymap, flag);
		check_flag(flag);

		std_it=std_mymap.find ('e');
		std_mymap.erase ( std_it, std_mymap.end() );    // erasing by range
		ft_it=ft_mymap.find ('e');
		ft_mymap.erase ( ft_it, ft_mymap.end() );    // erasing by range
		check_value(ft_mymap, std_mymap, flag);
		check_flag(flag);
		check_size(ft_mymap, std_mymap, flag);
		check_flag(flag);

		for (std_it=std_mymap.begin(), ft_it=ft_mymap.begin(); std_it!=std_mymap.end() && ft_it!=ft_mymap.end(); ++std_it, ++ft_it)
			if (std_it->first == ft_it->first && std_it->second == ft_it->second)
				PUT_STR(OK);
			else
				PUT_STR(KO);
	}
#endif
#ifdef T10
	{
		PUT_STR(B"SWAP()");
		std::map<char,int> std_foo,std_bar;
		ft::map<char,int> ft_foo,ft_bar;

		std_foo['x']=100;
		std_foo['y']=200;
		ft_foo['x']=100;
		ft_foo['y']=200;

		std_bar['a']=11;
		std_bar['b']=22;
		std_bar['c']=33;
		ft_bar['a']=11;
		ft_bar['b']=22;
		ft_bar['c']=33;

		std_foo.swap(std_bar);
		ft_foo.swap(ft_bar);
		check_value(ft_foo, std_foo, flag);
		check_flag(flag);
		check_size(ft_foo, std_foo, flag);
		check_flag(flag);
		check_value(ft_bar, std_bar, flag);
		check_flag(flag);
		check_size(ft_bar, std_bar, flag);
		check_flag(flag);
	}
#endif
#ifdef T11
	{
		PUT_STR(B"clear()");
		std::map<char,int> std_mymap;
		std::map<char,int>::iterator std_it;
		ft::map<char,int> ft_mymap;
		ft::map<char,int>::iterator ft_it;
		std_mymap.clear();
		ft_mymap.clear();
		check_value(ft_mymap, std_mymap, flag);
		check_flag(flag);
		check_size(ft_mymap, std_mymap, flag);
		check_flag(flag);
		// insert some values:
		std_mymap['a']=10;
		std_mymap['b']=20;
		std_mymap['c']=30;
		ft_mymap['a']=10;
		ft_mymap['b']=20;
		ft_mymap['c']=30;
		std_mymap.clear();
		ft_mymap.clear();
		check_value(ft_mymap, std_mymap, flag);
		check_flag(flag);
		check_size(ft_mymap, std_mymap, flag);
		check_flag(flag);

		std_mymap['d']=40;
		std_mymap['e']=50;
		std_mymap['f']=60;
		ft_mymap['d']=40;
		ft_mymap['e']=50;
		ft_mymap['f']=60;
		std_mymap.clear();
		ft_mymap.clear();
		check_value(ft_mymap, std_mymap, flag);
		check_flag(flag);
		check_size(ft_mymap, std_mymap, flag);
		check_flag(flag);

	}
#endif
#ifdef T12
	{
		PUT_STR(B"key_comp()");
		ft::map<int, int> ft_map;
		ft::map<int, int>::key_compare ft_comp = ft_map.key_comp();
		std::map<int, int> std_map;
		std::map<int, int>::key_compare std_comp = std_map.key_comp();
		if (std_comp(1, 10) == ft_comp(1, 10))
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T13
	{
		PUT_STR(B"value_comp()");
		ft::map<int, int> ft_map;
		ft::map<int, int>::value_compare ft_comp = ft_map.value_comp();
		std::map<int, int> std_map;
		std::map<int, int>::value_compare std_comp = std_map.value_comp();

		std_map['a']=10;
		std_map['b']=20;
		std_map['c']=30;
		std_map['d']=40;
		std_map['e']=50;
		std_map['f']=60;

		ft_map['a']=10;
		ft_map['b']=20;
		ft_map['c']=30;
		ft_map['d']=40;
		ft_map['e']=50;
		ft_map['f']=60;

		ft::map<int, int>::iterator ft_it = ft_map.end();
		std::map<int, int>::iterator std_it = std_map.end();
		--ft_it; --std_it;
		if (std_map.value_comp()(*std_map.begin(), *std_it) == ft_map.value_comp()(*ft_map.begin(), *ft_it))
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T14
	{
		PUT_STR(B"find()");
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;

		std_map['a']=10;
		std_map['b']=20;
		std_map['c']=30;
		std_map['d']=40;
		std_map['e']=50;
		std_map['f']=60;

		ft_map['a']=10;
		ft_map['b']=20;
		ft_map['c']=30;
		ft_map['d']=40;
		ft_map['e']=50;
		ft_map['f']=60;

		if ((ft_map.find('d')->first == std_map.find('d')->first) && (ft_map.find('d')->second == std_map.find('d')->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if ((ft_map.find('a')->first == std_map.find('a')->first) && (ft_map.find('a')->second == std_map.find('a')->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if ((ft_map.find('f')->first == std_map.find('f')->first) && (ft_map.find('f')->second == std_map.find('f')->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T15
	{
		PUT_STR(B"count()");
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;

		std_map['a']=10;
		std_map['b']=20;
		std_map['c']=30;
		std_map['d']=40;
		std_map['e']=50;
		std_map['f']=60;

		ft_map['a']=10;
		ft_map['b']=20;
		ft_map['c']=30;
		ft_map['d']=40;
		ft_map['e']=50;
		ft_map['f']=60;

		if (ft_map.count('d') == std_map.count('d'))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if (ft_map.count('a') == std_map.count('a'))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if (ft_map.count('f') == std_map.count('f'))
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T16
	{
		PUT_STR(B"LOWER_BOUND()");
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		std_map[1]=10;
		std_map[20]=20;
		std_map[30]=30;
		std_map[444]=40;
		std_map[555]=50;
		std_map[666]=60;

		ft_map[1]=10;
		ft_map[20]=20;
		ft_map[30]=30;
		ft_map[444]=40;
		ft_map[555]=50;
		ft_map[666]=60;


		if ((ft_map.lower_bound(19)->first == std_map.lower_bound(19)->first) && (ft_map.lower_bound(19)->second == std_map.lower_bound(19)->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if ((ft_map.lower_bound(20)->first == std_map.lower_bound(20)->first) && (ft_map.lower_bound(20)->second == std_map.lower_bound(20)->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if ((ft_map.lower_bound(25)->first == std_map.lower_bound(25)->first) && (ft_map.lower_bound(25)->second == std_map.lower_bound(25)->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if (ft_map.lower_bound(777) == ft_map.end())
			PUT_STR(OK);
		else {
			std::cout << ft_map.lower_bound(777)->first << " != " << std_map.lower_bound(777)->first << std::endl;
			PUT_STR(KO);
		}
	}
#endif
#ifdef T17
	{
		PUT_STR(B"UPPER_BOUND()");
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		std_map[1]=10;
		std_map[20]=20;
		std_map[30]=30;
		std_map[444]=40;
		std_map[555]=50;
		std_map[666]=60;

		ft_map[1]=10;
		ft_map[20]=20;
		ft_map[30]=30;
		ft_map[444]=40;
		ft_map[555]=50;
		ft_map[666]=60;


		if ((ft_map.upper_bound(19)->first == std_map.upper_bound(19)->first) && (ft_map.upper_bound(19)->second == std_map.upper_bound(19)->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if ((ft_map.upper_bound(20)->first == std_map.upper_bound(20)->first) && (ft_map.upper_bound(20)->second == std_map.upper_bound(20)->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if ((ft_map.upper_bound(25)->first == std_map.upper_bound(25)->first) && (ft_map.upper_bound(25)->second == std_map.upper_bound(25)->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if (ft_map.upper_bound(777) == ft_map.end())
			PUT_STR(OK);
		else {
			std::cout << ft_map.upper_bound(777)->first << " != " << std_map.upper_bound(777)->first << std::endl;
			PUT_STR(KO);
		}
	}
#endif
#ifdef T18
	{
		PUT_STR(B"EQUAL_RANGE()");
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		std_map[1]=10;
		std_map[20]=20;
		std_map[30]=30;
		std_map[444]=40;
		std_map[555]=50;
		std_map[666]=60;

		ft_map[1]=10;
		ft_map[20]=20;
		ft_map[30]=30;
		ft_map[444]=40;
		ft_map[555]=50;
		ft_map[666]=60;


		if ((std_map.equal_range(19).first->first == ft_map.equal_range(19).first->first) && (std_map.equal_range(19).first->second == ft_map.equal_range(19).first->second) && (std_map.equal_range(19).second->first == ft_map.equal_range(19).second->first) && (std_map.equal_range(19).second->second == ft_map.equal_range(19).second->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if ((std_map.equal_range(20).first->first == ft_map.equal_range(20).first->first) && (std_map.equal_range(20).first->second == ft_map.equal_range(20).first->second) && (std_map.equal_range(20).second->first == ft_map.equal_range(20).second->first) && (std_map.equal_range(20).second->second == ft_map.equal_range(20).second->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if ((std_map.equal_range(25).first->first == ft_map.equal_range(25).first->first) && (std_map.equal_range(25).first->second == ft_map.equal_range(25).first->second) && (std_map.equal_range(25).second->first == ft_map.equal_range(25).second->first) && (std_map.equal_range(25).second->second == ft_map.equal_range(25).second->second))
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if ((std_map.equal_range(777).first->first == ft_map.equal_range(777).first->first) && (std_map.equal_range(777).second->first == ft_map.equal_range(777).second->first)) {
			PUT_STR(OK);
		}
		else {
			PUT_STR(KO);
			std::cout << std_map.equal_range(777).first->first << "\t" << ft_map.equal_range(777).first->first << "\t" << std_map.equal_range(777).second->first << "\t" << ft_map.equal_range(777).second->first << std::endl;
		}
	}
#endif
	return 0;
}
