#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include <algorithm>
#include <iterator>
#include <limits>
#include <initializer_list>
#include <list>

std::list<int> i;
namespace ft
{
	template < class T, class Alloc = allocator<T> >;

	class List
	{
	private:

	public:
		typedef T		value_type;
		typedef	Alloc	allocator_type;

	};

}




#endif