#include <vector>

namespace ns {
	template <typename T>
	class test
	{
	public:
		typedef int16_t j;
		std::vector<T> Vtest;
		void _print(const T test);
		test & operator=(const test & t);
		j getJ(j a);
	};
}

#include "test.tpp"