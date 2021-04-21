#include <iostream>

template <typename T>
void ns::test<T>::_print(const T test) {
	std::cout << "Testing" << std::endl;
}

template <typename T>
ns::test<T> & ns::test<T>::operator = (const ns::test<T> &t) {
	std::cout << "= operator" << std::endl;
	return *this;
}

template <typename T>
typename ns::test<T>::j ns::test<T>::getJ(typename ns::test<T>::j a) {
	j f = a;
	std::cout << " Get J" << a << std::endl;
	return a;
}