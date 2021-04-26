#include "list.hpp"

//template <typename T, typename A = std::allocator<T> >
//ft::list<T, A>::list<typename T, typename A>() {}


int main(int argc, char **argv) {
	ft::list<int> j;
	j.push_back(1);
	j.push_back(2);
	j.push_back(3);
	j.push_back(4);
	ft::iterator<int> it_begin = j.begin();
	ft::iterator<int> it_end = j.end();
	return 0;
}