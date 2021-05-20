#include "unit_tests.hpp"
#define T1
//#define T2
//#define T3
//#define T4
//#define T5
//#define T6
//#define T7
//#define T8
//#define T9
//#define T10
//#define T11
//#define T12
//#define T13
//#define T14
//#define T15
//#define T16
//#define T17
//#define T18
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




using namespace std;

int main(void) {
#ifdef T1
	{
		std::vector<int> first;                                // empty vector of ints
		std::vector<int> second (4,100);                       // four ints with value 100
		std::vector<int> third (second.begin(),second.end());  // iterating through second
		std::vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are:";
		for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
#endif
#ifdef T2
	{

	}
#endif
#ifdef T3
	{

	}
#endif
#ifdef T4
	{

	}
#endif
#ifdef T5
	{

	}
#endif
#ifdef T6
	{

	}
#endif
#ifdef T7
	{

	}
#endif
#ifdef T8
	{

	}
#endif
#ifdef T9
	{

	}
#endif
#ifdef T10
	{

	}
#endif
#ifdef T11
	{

	}
#endif
#ifdef T12
	{

	}
#endif
#ifdef T13
	{

	}
#endif
#ifdef T14
	{

	}
#endif
	return 0;
}