#ifndef STACK_HPP
#define STACK_HPP
#include ""
namespace ft {
	template <class T, class Container = deque<T> >
	class stack {

		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
		explicit stack (const container_type& ctnr = container_type()) {
			
		}

	};

}

#endif