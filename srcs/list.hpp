#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <memory>
#include <iterator>
#include <cstddef>
#include <type_traits>
#include <limits>
#include <cmath>
#include "utils.hpp"

namespace ft {
	template < typename T, typename A = std::allocator<T> >
	class list {
	private:
		struct node {
			node(const T &data, struct node *next, struct node *prev) {
				this->data = data;
				this->next = next;
				this->prev = prev;
			}
			node() {
//				this->data = node_number;
				this->next = NULL;
				this->prev = NULL;
			}
			void insert_before(node *tmp) {
				tmp->prev = this->prev;
				tmp->next = this;
				this->prev->next = tmp;
				this->prev = tmp;
			}
			void insert_after(node *tmp) {
				tmp->prev = this;
				tmp->next = this->next;
				this->next->prev = tmp;
				this->next = tmp;
			}
			void detach_node() {
				this->prev->next = this->next;
				this->next->prev = this->prev;
			}
			void swap_node(node *tmp) {
				node *_next = this->next;
				node *_prev = this->prev;

				this->next = tmp->next;
				this->prev = tmp->prev;
				tmp->prev->next = this;
				tmp->next->prev = this;

				tmp->next = _next;
				tmp->prev = _prev;
				_next->prev = tmp;
				_prev->next = tmp;
			}
			T	data;
			node *next;
			node *prev;
		};
		node *sentinel;
		node *head;
		node *tail;
		static size_t node_number;
	public:
		struct iterator {
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef node* node_pointer;
			typedef node& node_reference;
			typedef T* type_pointer;
			typedef T& type_reference;

			iterator() : m_ptr(0) { }
			iterator(node_pointer ptr) : m_ptr(ptr) { }
			iterator(const iterator & src) {
				*this = src;
				return;
			}
			iterator & operator=(const iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				return *this;
			}
			~iterator() { }
			type_reference operator*() const{ return m_ptr->data; }
			type_pointer operator->() const { return &m_ptr->data; }
			iterator operator++() { m_ptr = m_ptr->next; return *this;}
			iterator operator--() { m_ptr = m_ptr->prev; return *this;}
			iterator operator++(int) { m_ptr = m_ptr->next; return *this;}
			iterator operator--(int) { m_ptr = m_ptr->prev; return *this;}
			bool operator==(const iterator & rhs) { return this->m_ptr == rhs.m_ptr; }
			bool operator!=(const iterator & rhs) { return this->m_ptr != rhs.m_ptr; }
			node_pointer get_node_pointer() { return m_ptr; }
			type_reference operator[](const int & index) {
				node_pointer tmp = m_ptr;
				for (int i = 0; i < index && index < node_number; ++i)
				{
					tmp = tmp->next;
				}
				return tmp->data;
			}

		private:
			node_pointer m_ptr;
		};
		struct const_iterator {
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef node* node_pointer;
			typedef node& node_reference;
			typedef T* type_pointer;
			typedef T& type_reference;

			const_iterator() : m_ptr(0) { }
			const_iterator(node_pointer ptr) : m_ptr(ptr) { }
			const_iterator(const const_iterator & src) {
				*this = src;
				return;
			}
			const_iterator & operator=(const const_iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				return *this;
			}
			~const_iterator() { }
			type_reference operator*() const{ return m_ptr->data; }
			type_pointer operator->() const { return &m_ptr->data; }
			const_iterator operator++() { m_ptr = m_ptr->next; return *this; }
			const_iterator operator--() { m_ptr = m_ptr->prev; return *this; }
			const_iterator operator++(int) { m_ptr = m_ptr->next; return *this; }
			const_iterator operator--(int) { m_ptr = m_ptr->prev; return *this; }
			bool operator==(const const_iterator & rhs) { return this->m_ptr == rhs.m_ptr; }
			bool operator!=(const const_iterator & rhs) { return this->m_ptr != rhs.m_ptr; }
		private:
			node_pointer m_ptr;
		};

		struct reverse_iterator {
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef node* node_pointer;
			typedef node& node_reference;
			typedef T* type_pointer;
			typedef T& type_reference;
			reverse_iterator() : m_ptr(0) { }
			reverse_iterator(node_pointer ptr) : m_ptr(ptr) { }
			reverse_iterator(const reverse_iterator & src) {
				*this = src;
				return;
			}
			reverse_iterator & operator=(const reverse_iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				return *this;
			}
			~reverse_iterator() { }
			type_reference operator*() const{ return m_ptr->data; }
			type_pointer operator->() const { return &m_ptr->data; }
			node_pointer operator+(const unsigned int n) {
				for (int i = 0; i < n; ++i) {
					m_ptr = m_ptr->prev;
				}
				return m_ptr;
			}
			reverse_iterator operator++() { m_ptr = m_ptr->prev; return  *this; }
			reverse_iterator operator++(int) { m_ptr = m_ptr->prev; return *this; }
			node_pointer operator-(const unsigned int n) {
				for (int i = 0; i < n; ++i) {
					m_ptr = m_ptr->next;
				}
				return m_ptr;
			}
			reverse_iterator operator--() { m_ptr = m_ptr->next; return  *this; }
			reverse_iterator operator--(int) { m_ptr = m_ptr->next; return *this; }
			bool operator==(const reverse_iterator & rhs) { return this->m_ptr == rhs.m_ptr; }
			bool operator!=(const reverse_iterator & rhs) { return this->m_ptr != rhs.m_ptr; }
			type_reference operator[](const int & index) {
				node_pointer tmp = m_ptr;
				for (int i = 0; i < index && index < node_number; ++i)
				{
					tmp = tmp->prev;
				}
				return tmp->data;
			}
		private:
			node_pointer m_ptr;
		};
		struct const_reverse_iterator {
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef node* node_pointer;
			typedef node& node_reference;
			typedef T* type_pointer;
			typedef T& type_reference;

			const_reverse_iterator() : m_ptr(0) { }
			const_reverse_iterator(node_pointer ptr) : m_ptr(ptr) { }
			const_reverse_iterator(const const_reverse_iterator & src) {
				*this = src;
				return;
			}
			const_reverse_iterator & operator=(const const_reverse_iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				return *this;
			}
			~const_reverse_iterator() { }
			type_reference operator*() const{ return m_ptr->data; }
			type_pointer operator->() const { return &m_ptr->data; }
			const_reverse_iterator operator++() { m_ptr = m_ptr->prev; return *this; }
			const_reverse_iterator operator--() { m_ptr = m_ptr->next; return *this; }
			const_reverse_iterator operator++(int) { m_ptr = m_ptr->prev; return *this; }
			const_reverse_iterator operator--(int) { m_ptr = m_ptr->next; return *this; }
			bool operator==(const const_reverse_iterator & rhs) { return this->m_ptr == rhs.m_ptr; }
			bool operator!=(const const_reverse_iterator & rhs) { return this->m_ptr != rhs.m_ptr; }
		private:
			node_pointer m_ptr;
		};
		typedef T											value_type;
		typedef A											allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

//		default constructor
		explicit list (const allocator_type& alloc = allocator_type());
//		fill constructor
		explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
//		range constructor
//		c++11 standard
//		template <class InputIterator, class = typename ft::enable_if<std::is_class<InputIterator>::value || std::is_pointer<InputIterator>::value >::type>
//		list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

//		c++98 standard
		template <class InputIterator>
		list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0);
//		list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<std::is_class<InputIterator>::value || std::is_pointer<InputIterator>::value >::type* c = 0);

//		copy constructor
		list (const list& x);
		virtual ~list();
		list & operator=(const list &rhs);
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0);
		void assign (size_type n, const value_type& val);
		void push_front (const value_type& val);
		void pop_front();
		void push_back (const value_type& val);
		void pop_back();

		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void insert (typename ft::list<T, A>::iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (list& x);
		void resize (size_type n, value_type val = value_type());
		void clear();
		void splice (iterator position, list& x);
		void splice (iterator position, list& x, iterator i);
		void splice (iterator position, list& x, iterator first, iterator last);
		void remove (const value_type& val);
		template <class Predicate>
		void remove_if (Predicate pred);
		void unique();
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);
		void merge (list& x);
		template<typename Condition>
		void merge (list& x, Condition cond);
		void sort();
		template<typename Condition>
		void sort (Condition cond);
		void reverse();
		void set_tail(node *tail);
		node *get_tail() const;
	protected:
		std::allocator<node> node_allocator;
	};
}

#include "list.tpp"

#endif