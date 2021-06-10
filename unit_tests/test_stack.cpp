#include "unit_tests.hpp"
#define T1 // constructors
#define T2 // empty()
#define T3 // size()
#define T4 // top()
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
void check_size(ft::stack<T> &x, std::stack<T> &y, bool &flag) {
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
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		check_size(ft_stack, std_stack, flag);
		check_flag(flag);
	}
#endif
#ifdef T2
	{
		PUT_STR(B"EMPTY()");
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		if (ft_stack.empty() == std_stack.empty())
			PUT_STR(OK);
		else
			PUT_STR(KO);
		for (int i = 0; i < 10; i++)
			ft_stack.push(i);
		for (int i = 0; i < 10; i++)
			std_stack.push(i);
		if (ft_stack.empty() == std_stack.empty())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T3
	{
		PUT_STR(B"SIZE()");
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		if (ft_stack.size() == std_stack.size())
			PUT_STR(OK);
		else
			PUT_STR(KO);
		for (int i = 0; i < 10; i++)
			ft_stack.push(i);
		for (int i = 0; i < 10; i++)
			std_stack.push(i);
		if (ft_stack.size() == std_stack.size())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T4
	{
		PUT_STR(B"TOP()");
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		for (int i = 0; i < 10; i++)
			ft_stack.push(i);
		for (int i = 0; i < 10; i++)
			std_stack.push(i);
		if (ft_stack.top() == std_stack.top())
			PUT_STR(OK);
		else
			PUT_STR(KO);
	}
#endif
#ifdef T5
	{
		PUT_STR(B"PUSH()/POP()");
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		for (int i = 0; i < 3; i++)
			ft_stack.push(i);
		for (int i = 0; i < 3; i++)
			std_stack.push(i);
		while (!ft_stack.empty() && !std_stack.empty()) {
			if (ft_stack.top() == std_stack.top()) {
//				std::cout << ft_stack.top() << " : " << std_stack.top() << std::endl;
				PUT_STR(OK);
			}
			else {
//				std::cout << ft_stack.top() << " : " << std_stack.top() << std::endl;
				PUT_STR(KO);
			}
			ft_stack.pop();
			std_stack.pop();
		}
	}
#endif
	return 0;
}
