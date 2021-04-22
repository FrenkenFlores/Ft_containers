#include <list>
#include "list.hpp"

//template <typename T, typename A = std::allocator<T> >
//ft::list<T, A>::list<typename T, typename A>() {}


int main(int argc, char **argv) {
	std::list<int> j;
	j.push_back(1);
	j.push_back(2);
	j.push_back(3);
	j.push_back(4);
	std::list<int>::iterator w;
	ft::iterator<int> k = j.begin();
//	k = j.begin();

	return 0;
}