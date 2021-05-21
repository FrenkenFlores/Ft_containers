#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <type_traits>

namespace ft {

//	template<bool B, class T = void>
//	struct enable_if {};
//
//	template<class T>
//	struct enable_if<true, T> { typedef T type; };






	template <typename T, typename A = std::allocator<T> >
	class vector {
	private:
		T *arr;
		size_t _size;
	public:
		typedef T value_type;
		typedef A allocator_type;
		typedef value_type & reference;
		typedef const value_type & const_reference;
		typedef value_type * pointer;
		typedef const value_type * const_pointer;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		class iterator {
		private:
			T *m_ptr;
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;

			iterator() : m_ptr(NULL){ }
			iterator(pointer ptr) : m_ptr(ptr) { }
			iterator(const iterator & src) {
				*this = src;
			}
			iterator & operator=(const iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				return *this;
			}
			~iterator() { }
			reference operator*() const{ return *m_ptr;}
			pointer operator->() const { return m_ptr; }
			void operator++() { m_ptr++; }
			void operator--() { m_ptr--; }
			bool operator==(const iterator & rhs) { return m_ptr == rhs.m_ptr; }
			bool operator!=(const iterator & rhs) { return m_ptr != rhs.m_ptr; }
			reference operator[](const int & index) { return *(m_ptr + index); }
		};

		explicit vector (const allocator_type& alloc = allocator_type()) : arr(nullptr), _size(0) { }
		explicit vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) {
			arr = new value_type[n];
			_size = sizeof(arr);
			for(size_t i = 0; i < n; ++i)
				arr[i] = val;
		}


		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type(), typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type *_if = 0) {
			iterator tmp = first;
			size_type i = 0;
			while (tmp != last) {
				++tmp;
				i++;
			}
			arr = new value_type[i];
			tmp = first;
			i = 0;
			while (tmp != last) {
				arr[i] = *tmp;
				++tmp;
				i++;
			}
		}

		vector (const vector& x) {
//			for (int i = 0; i < x.size(); i++)
//				this[i] = x[i];
		}


		iterator begin() { return arr; }
		iterator end() { return arr + sizeof(arr); }
		size_type size() const { return sizeof(arr); }
		reference operator[](const int & index) const { return *(arr + index); }
	};

}


#endif