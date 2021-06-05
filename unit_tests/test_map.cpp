#include "unit_tests.hpp"
//#define T1 // constructors
#define T2 // operator=()
//#define T3 // begin(), end(), rbegin(), rend()
//#define T4 // empty()
//#define T5 // size()
//#define T6 // max_size()
//#define T7 // operator[]()
//#define T8 // insert()
//#define T9 // erase()
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




//		std::cout << ft_first.insert(std::pair<char, int>('a', 10)).first->first << "/" << ft_first.insert(std::pair<char, int>('a', 10)).first->second << std::endl;
//		std::cout << std_first.insert(std::pair<char, int>('a', 10)).first->first << "/" << std_first.insert(std::pair<char, int>('a', 10)).first->second << std::endl;

//		ft_first.insert(std::pair<char, int>('a', 10));
//		ft_first.insert(std::pair<char, int>('b', 20));
//		ft_first.insert(std::pair<char, int>('c', 30));
//		ft_first.insert(std::pair<char, int>('d', 40));

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
	}
#endif
#ifdef T2
	{
//		PUT_STR(B"OPERATOR=()");

		std::map<int,int> std_first;
		ft::map<int,int> ft_first;

		std::map<int,int>::iterator it_std_b;
		ft::map<int,int>::iterator it_ft_b;
		std::map<int,int>::iterator it_std_e;
		ft::map<int,int>::iterator it_ft_e;
		
// 		std_first[12]=10;
// 		std_first[5]=30;
// 		std_first[15]=50;
// 		std_first[13]=70;
// 		std_first[17]=70;
// //		std_first[14]=70;
// //		std_first[20]=70;
// //		std_first[18]=70;
// //		std_first[3]=70;
// //		std_first[7]=70;
// 		std_first[1]=70;
// 		std_first[9]=70;
// //		std_first[8]=70;
// //		std_first[11]=70;


// 		it_std_b = std_first.begin();
// 		it_std_e = std_first.end();
// 		while (it_std_b != it_std_e)
// 		{
// 			std::cout << it_std_b->first << std::endl;
// 			++it_std_b;
// 		}

		ft_first[12]=10;
		ft_first[5]=30;
		ft_first[15]=50;
		ft_first[13]=70;
		ft_first[17]=70;
//		ft_first[14]=70; // <-
//		ft_first[20]=70;
//		ft_first[18]=70;
//		ft_first[3]=70;
//		ft_first[7]=70;
		ft_first[1]=70;
		ft_first[9]=70; // <-
//		ft_first[8]=70;
//		ft_first[11]=70;


		it_ft_b = ft_first.begin();
		it_ft_e = ft_first.end();
		while (it_ft_b != it_ft_e)
		{
			std::cout << it_ft_b->first << std::endl;
			++it_ft_b;
		}
		

		ft_first.DUMP(ft_first.get_root());

//
//
//		ft_first.erase(--(--ft_first.end()));
//		ft_first.DUMP(ft_first.get_root());

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