#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <type_traits>

namespace ft {

	template <bool>
	struct enable_if {};

	template <>
	struct enable_if<true> {
		typedef void type;
	};

class out_of_range : public std::logic_error {
	public:
		explicit out_of_range (const std::string& what_arg) : logic_error(what_arg) { }
		explicit out_of_range (const char *what_arg) : logic_error(what_arg) { }
};

	template <typename T, typename A = std::allocator<T> >
	class vector {
	private:
		T *arr;
		size_t _size;
		size_t _capacity;
		A _allocator;
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
			iterator & operator+(const int x) { m_ptr = m_ptr + x; return *this; }
			iterator & operator-(const int x) { m_ptr = m_ptr - x; return *this; }
			void operator++() { m_ptr++; }
			void operator--() { m_ptr--; }
			bool operator==(const iterator & rhs) { return m_ptr == rhs.m_ptr; }
			bool operator!=(const iterator & rhs) { return m_ptr != rhs.m_ptr; }
			reference operator[](const int & index) { return *(m_ptr + index); }
		};

		class const_iterator {
		private:
			T *m_ptr;
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef const T value_type;
			typedef const T* pointer;
			typedef const T& reference;

			const_iterator() : m_ptr(NULL){ }
			const_iterator(pointer ptr) : m_ptr(ptr) { }
			const_iterator(const const_iterator & src) {
				*this = src;
			}
			const_iterator & operator=(const const_iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				return *this;
			}
			~const_iterator() { }
			reference operator*() const{ return *m_ptr;}
			pointer operator->() const { return m_ptr; }
			void operator++() { m_ptr++; }
			void operator--() { m_ptr--; }
			bool operator==(const const_iterator & rhs) { return m_ptr == rhs.m_ptr; }
			bool operator!=(const const_iterator & rhs) { return m_ptr != rhs.m_ptr; }
			reference operator[](const int & index) const { return *(m_ptr + index); }
		};

		class reverse_iterator {
		private:
			T *m_ptr;
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;

			reverse_iterator() : m_ptr(NULL){ }
			reverse_iterator(pointer ptr) : m_ptr(ptr) { }
			reverse_iterator(const reverse_iterator & src) {
				*this = src;
			}
			reverse_iterator & operator=(const reverse_iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				return *this;
			}
			~reverse_iterator() { }
			reference operator*() const{ return *m_ptr;}
			pointer operator->() const { return m_ptr; }
			void operator++() { m_ptr--; }
			void operator--() { m_ptr++; }
			bool operator==(const reverse_iterator & rhs) { return m_ptr == rhs.m_ptr; }
			bool operator!=(const reverse_iterator & rhs) { return m_ptr != rhs.m_ptr; }
			reference operator[](const int & index) { return *(m_ptr - index); }
		};

		class const_reverse_iterator {
		private:
			T *m_ptr;
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;

			const_reverse_iterator() : m_ptr(NULL){ }
			const_reverse_iterator(pointer ptr) : m_ptr(ptr) { }
			const_reverse_iterator(const const_reverse_iterator & src) {
				*this = src;
			}
			const_reverse_iterator & operator=(const const_reverse_iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				return *this;
			}
			~const_reverse_iterator() { }
			reference operator*() const{ return *m_ptr;}
			pointer operator->() const { return m_ptr; }
			void operator++() { m_ptr--; }
			void operator--() { m_ptr++; }
			bool operator==(const const_reverse_iterator & rhs) { return m_ptr == rhs.m_ptr; }
			bool operator!=(const const_reverse_iterator & rhs) { return m_ptr != rhs.m_ptr; }
			reference operator[](const int & index) const { return *(m_ptr - index); }
		};


		//default (1)
		explicit vector (const allocator_type& alloc = allocator_type()) : arr(nullptr), _size(0), _capacity(0) { }
		//fill (2)
		explicit vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) {
			arr = new value_type[n];
			_size = n;
			_capacity = n;
			for(size_t i = 0; i < _size; ++i)
				arr[i] = val;
		}
		//range (3)
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type(), typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type *_if = 0) {
			iterator tmp = first;
			_size = 0;
			_capacity = 0;
			while (tmp != last) {
				++tmp;
				_size++;
				_capacity++;
			}
			arr = new value_type[_size];
			for (int i = 0; i != _size; i++)
				arr[i] = first[i];
		}
		//copy (4)
		vector (const vector& src) {
			iterator it_b = src.begin();
			_size = src.size();
			_capacity = src.capacity();
			arr = new value_type[_size];
			for (int i = 0; i < _size; i++)
				arr[i] = it_b[i];
		}

		//destructor
		~vector() {
			delete[] arr;
			clear();
		}

		//operator=()
		vector & operator=(const vector & rhs) {
			clear();
			iterator it_b = rhs.begin();
			_size = rhs.size();
			_capacity = rhs.capacity();
			arr = new value_type[_size];
			for (int i = 0; i < _size; i++)
				arr[i] = it_b[i];
			return *this;
		}
		//clear
		void clear() {
			_size = 0;
			_capacity = 0;
		}
		//reserve
		void reserve (size_type n) {
			if (n > this->capacity()) {
				value_type *tmp = arr;
				arr = new value_type[n];
				for (int i = 0; i < _size; i++)
					arr[i] = tmp[i];
				_capacity = n;
				delete[] tmp;
			}
		}
		//operator[]
		reference operator[] (size_type n) { return *(arr + n); }
		//at
		reference at (size_type n) {
			if (n >= size()) {
				throw out_of_range("out of range");
			} else {
				return *(arr + n);
			}
		}
		//front
		reference front() {
			return *(arr);
		}
		//back
		reference back() {
			return *(arr + size() - 1);
		}
		//begin
		iterator begin() const { return iterator(arr); }
		//end
		iterator end() const { return iterator(arr + _size); }
		//rbegin
		reverse_iterator rbegin() const { return reverse_iterator(arr + _size - 1); }
		//rend
		reverse_iterator rend() const { return reverse_iterator(arr - 1); }
		//size
		size_type size() const { return _size; }
		//max_size
		size_type max_size() const { return _allocator.max_size(); }
		//resize
		void resize (size_type n, value_type val = value_type()) {
			if (n < _size) {
				while (n < size())
					pop_back();
			} else {
				while (n > size())
					push_back(val);
			}
		}
		//capacity
		size_type capacity() const { return _capacity; }
		//empty
		bool empty() const { return size() == 0; }
		//assign
		//range (1)
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type *_if = 0) {
			delete[] arr;
			clear();

			InputIterator tmp = first;
			size_t i = 0;
			while (tmp != last) {
				i++;
				++tmp;
			}
			_size = i;
			_capacity = i;
			arr = new value_type[_size];
			i = 0;
			while (first != last) {
				arr[i] = *first;
				++first;
				i++;
			}
		}
		//fill (2)
		void assign (size_type n, const value_type& val) {
			delete[] arr;
			clear();

			_size = n;
			_capacity = n;
			arr = new value_type[n];
			int i = 0;
			while (i < n) {
				arr[i] = val;
				i++;
			}
		}





		//push_back
		void push_back (const value_type& val) {
			value_type *tmp = arr;
			if (size() >= capacity()) {
				_capacity = size() * 2;
				arr = new value_type[_capacity];
				for (int i = 0; i < _size; i++)
					arr[i] = tmp[i];
				arr[_size] = val;
				_size++;
				delete [] tmp;
			} else {
				arr[_size] = val;
				_size++;
			}
		}
		//pop_back
		void pop_back() {
			T tmp;
			arr[this->size() - 1] = tmp;
			_size--;
		}



	};

}


#endif
