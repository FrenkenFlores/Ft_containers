#include <vector>

namespace ns {
	template <typename T>
	class test
	{
	public:
		std::vector<T> Vtest;
		void _print(const T test);
		test & operator=(const test & t);
	};
}

#include "test.tpp"