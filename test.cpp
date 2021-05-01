#include "test.hpp"
#include <iterator>
#include <list>
#include <iostream>
#include <string>
#include <vector>


std::bidirectional_iterator_tag i;
std::list<int> j;

int main() {
//	{
//		std::list<vector<int> > l;
//		//	l.push_back('d');
//		//	l.push_back('a');
//		//	l.push_back('c');
//		//	l.push_back('z');
//		std::list<vector<int> >::iterator it_b = l.begin();
//		std::list<vector<int> >::iterator it_e = l.end();
//		l.push_back(vector<int>(3,3));
//		l.push_back(vector<int>(3,3));
//		l.push_back(vector<int>(3,3));
//		l.push_back(vector<int>(3,3));
//		std::cout << *it_b->begin() << std::endl;
//	}
	{
		std::list<std::string> l;
	//	l.push_back('d');
	//	l.push_back('a');
	//	l.push_back('c');
	//	l.push_back('z');
		std::list<std::string>::iterator it_b = l.begin();
		std::list<std::string>::iterator it_e = l.end();
		l.push_back("dawqdqw");
		l.push_back("dqwdqwdqw");
		l.push_back("dwqdq");
		l.push_back("Dwqdw");
		std::cout << *it_b << std::endl;
	}
	{
		std::list<char> l;
		std::list<char>::iterator it_b = l.begin();
		std::list<char>::iterator it_e = l.end();
		l.push_back('d');
		l.push_back('a');
		l.push_back('c');
		l.push_back('z');
		std::cout << *it_b << std::endl;
	}
	return 0;
}