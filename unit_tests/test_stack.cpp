#include "unit_tests.hpp"
#define T1 // constructors
#define T2 // empty()
#define T3 // size()
#define T4 // top()
#define T5 // push()
//#define T6 // max_size()
//#define T7 // operator[]()
//#define T8 // insert()
//#define T9 // erase()
//#define T10 // swap()
//#define T11 // clear()
//#define T12 // key_comp()
//#define T13 // value_comp()
//#define T14 // find()
//#define T15 // count()
//#define T16 // lower_bound()
//#define T17 // upper_bound()
//#define T18 // equal_range()


using namespace std;


void check_flag(bool flag) {
	if (flag == true)
		PUT_STR(OK);
	else
		PUT_STR(KO);
	flag = false;
}

//template <typename T>
//void check_value(ft::stack<T> &x, std::stack<T> &y, bool &flag) {
//	typename ft::stack<T>::iterator ft_itb = x.begin();
//	typename ft::stack<T>::iterator ft_ite = x.end();
//	typename std::stack<T>::iterator std_itb = y.begin();
//	typename std::stack<T>::iterator std_ite = y.end();
//	while (ft_itb != ft_ite && std_itb != std_ite)
//	{
//		if (ft_itb->first != std_itb->first && ft_itb->second != std_itb->second)
//		{
//			flag = false;
//			cout << LB << ft_itb->first << ":" << ft_itb->second << " != " << std_itb->first << ":" << std_itb->second << CLEAN << std::endl;
//			break;
//		} else {
//			cout << P << ft_itb->first << ":" << ft_itb->second << " == " << std_itb->first << ":" << std_itb->second << CLEAN << std::endl;
//			flag = true;
//		}
//		++ft_itb;
//		++std_itb;
//	}
//}

template <typename T>
void check_size(ft::stack<T> &x, std::stack<T> &y, bool &flag) {
	if (x.size() != y.size())
	{
		flag = false;
		cout << LB << x.size() << " != " << y.size() << CLEAN << std::endl;
	} else {
		flag = true;
		cout << P << x.size() << " == " << y.size() << CLEAN << std::endl;
	}
}


int main(void) {
	bool flag = true;
#ifdef T1
	{
		PUT_STR(B"CONSTRUCTORS");
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		check_size(ft_stack, std_stack, flag);
		check_flag(flag);
	}
#endif
#ifdef T2
	{
		PUT_STR(B"EMPTY()");
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		if (ft_stack.empty() == std_stack.empty())
			PUT_STR(OK);
		else
			PUT_STR(KO);
		for (int i = 0; i < 10; i++)
			ft_stack.push(i);
		for (int i = 0; i < 10; i++)
			std_stack.push(i);
		if (ft_stack.empty() == std_stack.empty())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T3
	{
		PUT_STR(B"SIZE()");
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		if (ft_stack.size() == std_stack.size())
			PUT_STR(OK);
		else
			PUT_STR(KO);
		for (int i = 0; i < 10; i++)
			ft_stack.push(i);
		for (int i = 0; i < 10; i++)
			std_stack.push(i);
		if (ft_stack.size() == std_stack.size())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T4
	{
		PUT_STR(B"TOP()");
		std::map<char,int> std;
		ft::map<char,int> ft;
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		if (ft_stack.top() == std_stack.top())
			PUT_STR(OK);
		else
			PUT_STR(KO);
		for (int i = 0; i < 10; i++)
			ft_stack.push(i);
		for (int i = 0; i < 10; i++)
			std_stack.push(i);
		if (ft_stack.top() == std_stack.top())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T5
	{
		PUT_STR(B"PUSH()");
		PUT_STR(B"TOP()");
		std::map<char,int> std;
		ft::map<char,int> ft;
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		if (ft_stack.top() == std_stack.top())
			PUT_STR(OK);
		else
			PUT_STR(KO);
		for (int i = 0; i < 10; i++)
			ft_stack.push(i);
		for (int i = 0; i < 10; i++)
			std_stack.push(i);
		if (ft_stack.top() == std_stack.top())
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
		if (ft_map.lower_bound(777)->first == std_map.lower_bound(777)->first)
			PUT_STR(OK);
		else
			PUT_STR(KO);
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
		if (ft_map.upper_bound(777)->first == std_map.upper_bound(777)->first)
			PUT_STR(OK);
		else
			PUT_STR(KO);
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
//			std::cout << std_map.equal_range(777).first->first << "\t" << ft_map.equal_range(777).first->first << "\t" << std_map.equal_range(777).second->first << "\t" << ft_map.equal_range(777).second->first << std::endl;
		}
	}
#endif
	return 0;
}
