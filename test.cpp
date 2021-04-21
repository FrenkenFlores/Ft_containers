#include "test.hpp"
#include <iterator>
#include <list>

std::bidirectional_iterator_tag i;
std::list<int> j;

int main() {
	ns::test<int> _test;
	_test._print(5);
	ns::test<int> __test;
	__test = _test;
	__test._print(4);
	_test.getJ(8);
	return 0;
}