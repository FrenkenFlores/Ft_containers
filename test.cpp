#include "test.hpp"

int main() {
	ns::test<int> _test;
	_test._print(5);
	ns::test<int> __test;
	__test = _test;
	__test._print(4);
	return 0;
}