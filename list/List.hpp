#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include <iterator>

namespace ft {
	template < typename T, typename A = std::allocator<T> >
	class list {
	public:
		typedef T														value_type;
		typedef A														allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef size_t													size_type;
		std::bidirectional_iterator_tag									iterator;
		const std::bidirectional_iterator_tag							const_itertor;
		std::reverse_iterator<iterator>									reverse_iterator;
		std::reverse_iterator<const_itertor>							const_reverse_iterator;
	protected:
		A																the_allocator;
	public:
		explicit list (const allocator_type& alloc = allocator_type());
		~list();
		list & operator=(const list &src);
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
		void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);
		void push_front (const value_type& val);
		void pop_front();
		void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
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
		template <class Compare>
		void merge (list& x, Compare comp);
		void sort();
		template <class Compare>
		void sort (Compare comp);
		void reverse();
		allocator_type get_allocator() const;
	};
}

//#include "list.tpp"
#endif