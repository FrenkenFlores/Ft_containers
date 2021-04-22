#include "simple.hpp"
#include <iostream>
int main(int argc, char **argv, char **env) {
	simple_namespace::simple i;
	simple_namespace::simple::iterator it_begin;
	simple_namespace::simple::iterator it_end = i.get_n_element(5);
	for (it_begin = i.begin(); it_begin != it_end; ++it_begin)
		std::cout << "X" << std::endl;
	return (0);
}
