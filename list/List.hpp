#ifndef LIST_HPP
#define LIST_HPP

#include <memory>

//list iterator
namespace ft {
	class list_node_base {
	public:
		list_node_base *next;
		list_node_base *prev;
		static void swap(list_node_base &x, list_node_base &y) throw();
		void transfer(const list_node_base *first, const list_node_base *last) throw();
		void reverse() throw();
		void hook() throw();
		void unhook() throw();
	};

	template <typename T>
	class list_node : public list_node_base {
		T data;
	};

	template <typename T>
	class list_iterator {
	public:
		typedef list_iterator<T> self;
		typedef list_node<T> node;
		typedef ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		list_node_base *node_base;

		list_iterator() : node_base() { }
		explicit list_iterator(list_node_base *x) : node_base(x) { }
		self _const_cast() const {return *this; }
		// Must downcast from list_node_base to list_node to get to data.
		reference operator*() const { return static_cast<node *>(node_base)->data; }
		pointer operator->() const { return std::addressof(static_cast<node *>(node_base)->data); }
		self &operator++() {
			node_base = node_base->next;
			return *this;
		}
		self &operator--() {
			node_base = node_base->prev;
			return *this;
		}
		bool operator==(const self &x) const { return node_base == x.node; }
		bool operator!=(const self &x) const { return node_base != x.node; }
	};

	template<typename T>
	class list_const_iterator {
	public:
		typedef list_const_iterator<T> self;
		typedef const list_node<T> node;
		typedef list_iterator<T> iterator;
		typedef ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		const list_node_base *node_base;

		list_const_iterator() : node_base() { }
		explicit list_const_iterator(const list_node_base *x) : node_base(x) { }
		list_const_iterator(const iterator &x) : node_base(x.node_base) { }

		iterator _const_cast() const {return iterator(const_cast<list_node_base *>(node_base)) ; }
		// Must downcast from list_node_base to list_node to get to data.
		reference operator*() const { return static_cast<node *>(node_base)->data; }
		pointer operator->() const { return std::addressof(static_cast<node *>(node_base)->data); }
		self &operator++() {
			node_base = node_base->next;
			return *this;
		}
		self &operator--() {
			node_base = node_base->prev;
			return *this;
		}
		bool operator==(const self &x) const { return node_base == x.node; }
		bool operator!=(const self &x) const { return node_base != x.node; }
	};
}

//list container
namespace ft {
	template < typename T, typename A = std::allocator<T> >
	class list {
	public:
		typedef T											value_type;
		typedef A											allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef list_iterator<T>							iterator;
		typedef list_const_iterator<T>						const_iterator;
		typedef std::reverse_iterator<iterator>				reverse_iterator;
		typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;
	protected:
		A													the_allocator;
	public:
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
	};
}

#include "list.tpp"

#endif