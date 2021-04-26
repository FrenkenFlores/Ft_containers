#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include <iterator>
#include <cstddef>

//list iterator
//namespace ft {
//	template<typename T>
//	class iterator {
//	public:
//		typedef iterator<T> self;
//		typedef ptrdiff_t difference_type;
//		typedef std::bidirectional_iterator_tag iterator_category;
//		typedef T value_type;
//		typedef T *pointer;
//		typedef T &reference;
//
//		iterator *next;
//		iterator *prev;
//		T data;
//
//		iterator() : next(this), prev(this), data(0) {}
//
//		iterator(const self &src) {
//			this->next = src.next;
//			this->prev = src.prev;
//			this->data = src.data;
//		}
//
//		self &operator=(const self &rhs) {
//			this->next = rhs.next;
//			this->prev = rhs.prev;
//			this->data = rhs.data;
//			return *this;
//		}
//
//		~iterator() {};
//
//		bool operator==(const iterator<T> &rhs) const { return *this == rhs; }
//
//		bool operator!=(const iterator<T> &rhs) const { return *this != rhs; }
//
//		reference operator*() const { return data; }
//
//		pointer operator->() const { return std::addressof(data); }
//
//		self &operator++() {
//			this = this->next;
//			return *this;
//		}
//
//		self &operator--() {
//			this = this->prev;
//			return *this;
//		}
//	};

//
//
//	class list_node_base {
//	public:
//		list_node_base *next;
//		list_node_base *prev;
//		static void swap(list_node_base &x, list_node_base &y) throw();
//		void transfer(const list_node_base *first, const list_node_base *last) throw();
//		void reverse() throw();
//		void hook() throw();
//		void unhook() throw();
//	};
//
//	template <typename T>
//	class list_node : public list_node_base {
//		T data;
//	};
//
//	template <typename T>
//	class list_iterator {
//	public:
//		typedef list_iterator<T> self;
//		typedef list_node<T> node;
//		typedef ptrdiff_t difference_type;
//		typedef std::bidirectional_iterator_tag iterator_category;
//		typedef T value_type;
//		typedef T* pointer;
//		typedef T& reference;
//		list_node_base *node_base;
//
//		list_iterator() : node_base() { }
//		explicit list_iterator(list_node_base *x) : node_base(x) { }
//		self _const_cast() const {return *this; }
//		// Must downcast from list_node_base to list_node to get to data.
//		reference operator*() const { return static_cast<node *>(node_base)->data; }
//		pointer operator->() const { return std::addressof(static_cast<node *>(node_base)->data); }
//		self &operator++() {
//			node_base = node_base->next;
//			return *this;
//		}
//		self &operator--() {
//			node_base = node_base->prev;
//			return *this;
//		}
//		bool operator==(const self &x) const { return node_base == x.node; }
//		bool operator!=(const self &x) const { return node_base != x.node; }
//	};
//
//	template<typename T>
//	class list_const_iterator {
//	public:
//		typedef list_const_iterator<T> self;
//		typedef const list_node<T> node;
//		typedef list_iterator<T> iterator;
//		typedef ptrdiff_t difference_type;
//		typedef std::bidirectional_iterator_tag iterator_category;
//		typedef T value_type;
//		typedef const T* pointer;
//		typedef const T& reference;
//		const list_node_base *node_base;
//
//		list_const_iterator() : node_base() { }
//		explicit list_const_iterator(const list_node_base *x) : node_base(x) { }
//		list_const_iterator(const iterator &x) : node_base(x.node_base) { }
//
//		iterator _const_cast() const {return iterator(const_cast<list_node_base *>(node_base)) ; }
//		// Must downcast from list_node_base to list_node to get to data.
//		reference operator*() const { return static_cast<node *>(node_base)->data; }
//		pointer operator->() const { return std::addressof(static_cast<node *>(node_base)->data); }
//		self &operator++() {
//			node_base = node_base->next;
//			return *this;
//		}
//		self &operator--() {
//			node_base = node_base->prev;
//			return *this;
//		}
//		bool operator==(const self &x) const { return node_base == x.node; }
//		bool operator!=(const self &x) const { return node_base != x.node; }
//	};
//}
//list container
namespace ft {
	template < typename T, typename A = std::allocator<T> >
	class list {
	public:
		struct iterator {
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;

			iterator() : m_ptr(0) { }
			iterator(pointer ptr) : m_ptr(ptr) { }
			iterator(const iterator & src) {
				*this = src;
				return;
			}
			iterator & operator=(const iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				return *this;
			}
			~iterator() { }
			reference operator*() const{ return *m_ptr; }
			pointer operator->() const { return m_ptr; }
			reference operator++() { m_ptr++; return *this; }
			reference operator--() { m_ptr--; return *this; }
			bool operator==(const iterator & rhs) { return *(this->m_ptr) == *(rhs.m_ptr) }
			bool operator!=(const iterator & rhs) { return *(this->m_ptr) != *(rhs.m_ptr) }
		private:
			pointer m_ptr;
		};
		struct const_iterator {
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;

			iterator() : m_ptr(0) { }
			iterator(pointer ptr) : m_ptr(ptr) { }
			iterator(const iterator & src) {
				*this = src;
				return;
			}
			iterator & operator=(const iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				return *this;
			}
			~iterator() { }
			reference operator*() const{ return *m_ptr; }
			pointer operator->() const { return m_ptr; }
			reference operator++() { m_ptr++; return *this; }
			reference operator--() { m_ptr--; return *this; }
			bool operator==(const iterator & rhs) { return *(this->m_ptr) == *(rhs.m_ptr) }
			bool operator!=(const iterator & rhs) { return *(this->m_ptr) != *(rhs.m_ptr) }
		private:
			pointer m_ptr;
		};
		typedef T											value_type;
		typedef A											allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef std::reverse_iterator<iterator>				reverse_iterator;
		typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

		list();
		~list();
		list & operator=(const list &rhs);
		list(const list &src);
		explicit list (const allocator_type& alloc);
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
		void assign (iterator first, iterator last);
		void assign (size_type n, const value_type& val);
		void push_front (const value_type& val);
		void pop_front();
		void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		void insert (iterator position, iterator first, iterator last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (list& x);
		void resize (size_type n, value_type val = value_type());
		void clear();
		void splice (iterator position, list& x);
		void splice (iterator position, list& x, iterator i);
		void splice (iterator position, list& x, iterator first, iterator last);
		void remove (const value_type& val);
		void remove_if (T pred);
		void unique();
		void unique (T binary_pred);
		void merge (list& x);
		void merge (list& x, void (*f)(T, T));
		void sort();
		void sort (void (*f)(T, T));
		void reverse();
	protected:
		A	the_allocator;
	};
}

#include "list.tpp"

#endif