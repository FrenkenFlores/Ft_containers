#ifndef _STACK_HPP
#define _STACK_HPP
#include <type_traits>
#include <memory>
#include <limits>
#include "../utils/utils.hpp"
namespace ft {
	template <class T, class Alloc = allocator<T> >
		class stack {
		private:
			struct node {
				T data;
				node *next;
				node(T _data) : data(_data), next(nullptr) { }
			};
			node *root;
			size_t _size;
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef allocator_type::reference reference;
			typedef allocator_type::const_reference const_reference;
			typedef allocator_type::pointer pointer;
			typedef allocator_type::const_pointer const_pointer;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;

			stack () {
				root = nullptr;
				_size = 0;
			}

			template<class InputIterator>
			stack (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				   class ft::enable_if<std::numeric_limits<InputIterator>::is_specialized>::type *_if = 0) {
				root = new(node(*first));
				node *tmp = root;
				_size = 1;
				while (++first != last) {
					tmp->next = new(node(*first));
					tmp = tmp->next;
					_size++;
				}
			}
			stack(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) {
				root = new(node(val));
				node *tmp = root;
				_size = 1;
				while (n--) {
					tmp->next = new(node(val));
					tmp = tmp->next;
					_size++;
				}
			}
			stack(const stack& x) {
			}
		};
}




#endif