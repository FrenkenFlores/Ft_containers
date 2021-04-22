#ifndef SIMPLE_HPP
#define SIMPLE_HPP

#include <iterator>	// std::forward_iterator_tag
#include <cstddef>	// std::ptrdiff_t
#define SIZE 100

namespace simple_namespace {
	class simple {
		public:
			struct iterator {
				typedef std::forward_iterator_tag iterator_category;
				typedef std::ptrdiff_t difference_type;
				typedef int value_type;
				typedef int* pointer;
				typedef int& reference;
	
				iterator() : m_ptr(0) { }
				iterator(pointer ptr) : m_ptr(ptr) { }
				iterator(const iterator & src) {
					*this = src;
				}
				iterator & operator=(const iterator & rhs) {
					this->m_ptr = rhs.m_ptr;
					return *this;
				}
				~iterator() { }
				reference operator*() const { return *m_ptr; }
				pointer operator->() const { return m_ptr; }
				// prefix iterators
				iterator operator++() { m_ptr++; return *this; }
				iterator operator--() { m_ptr--; return *this; }
				// postfix iterators
				iterator operator++(int) {
					iterator tmp = *this;
					++(*this);
					return tmp;
				}
				bool operator==(const iterator & rhs) { return this->m_ptr == rhs.m_ptr; }
				bool operator!=(const iterator & rhs) { return this->m_ptr != rhs.m_ptr; }
				private:
					pointer m_ptr;
			};
			iterator begin() { return iterator(&m_data[0]); }
			iterator end() { return iterator(&m_data[SIZE]); }
			iterator get_n_element(const int & n) { return iterator(&m_data[n]); }
		private:
			int m_data[SIZE];
	};
}

#endif
