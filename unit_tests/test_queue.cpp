#include "unit_tests.hpp"
#define T1 // constructors
#define T2 // empty()
#define T3 // size()
#define T4 // front(), back()
#define T5 // push(), pop()

using namespace std;

void check_flag(bool flag) {
	if (flag == true)
		PUT_STR(OK);
	else
		PUT_STR(KO);
	flag = false;
}

template <typename T>
void check_size(ft::queue<T> &x, std::queue<T> &y, bool &flag) {
	if (x.size() != y.size())
	{
		flag = false;
		cout << LB << x.size() << " != " << y.size() << CLEAN << std::endl;
	} else {
		flag = true;
//		cout << P << x.size() << " == " << y.size() << CLEAN << std::endl;
	}
}

int main(void) {
	bool flag = true;
#ifdef T1
	{
		PUT_STR(B"CONSTRUCTORS");
		ft::queue<int> ft_queue;
		std::queue<int> std_queue;
		check_size(ft_queue, std_queue, flag);
		check_flag(flag);
	}
#endif
#ifdef T2
	{
		PUT_STR(B"EMPTY()");
		ft::queue<int> ft_queue;
		std::queue<int> std_queue;
		if (ft_queue.empty() == std_queue.empty())
			PUT_STR(OK);
		else
			PUT_STR(KO);
		for (int i = 0; i < 10; i++)
			ft_queue.push(i);
		for (int i = 0; i < 10; i++)
			std_queue.push(i);
		if (ft_queue.empty() == std_queue.empty())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T3
	{
		PUT_STR(B"SIZE()");
		ft::queue<int> ft_queue;
		std::queue<int> std_queue;
		if (ft_queue.size() == std_queue.size())
			PUT_STR(OK);
		else
			PUT_STR(KO);
		for (int i = 0; i < 10; i++)
			ft_queue.push(i);
		for (int i = 0; i < 10; i++)
			std_queue.push(i);
		if (ft_queue.size() == std_queue.size())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T4
	{
		PUT_STR(B"FRONT()/BACK()");
		ft::queue<int> ft_queue;
		std::queue<int> std_queue;
		for (int i = 0; i < 10; i++)
			ft_queue.push(i);
		for (int i = 0; i < 10; i++)
			std_queue.push(i);
		if (ft_queue.front() == std_queue.front())
			PUT_STR(OK);
		else
			PUT_STR(KO);
		if (ft_queue.back() == std_queue.back())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T5
	{
		PUT_STR(B"PUSH()/POP()");
		ft::queue<int> ft_queue;
		std::queue<int> std_queue;
		for (int i = 0; i < 3; i++)
			ft_queue.push(i);
		for (int i = 0; i < 3; i++)
			std_queue.push(i);
		while (!ft_queue.empty() && !std_queue.empty()) {
			if (ft_queue.front() == std_queue.front()) {
//				std::cout << ft_queue.front() << " : " << std_queue.front() << std::endl;
				PUT_STR(OK);
			}
			else {
//				std::cout << ft_queue.front() << " : " << std_queue.front() << std::endl;
				PUT_STR(KO);
			}
			ft_queue.pop();
			std_queue.pop();
		}
	}
#endif
	return 0;
}
