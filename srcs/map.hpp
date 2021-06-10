#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <cstdbool>
#include <iostream>
#include <utility>

namespace ft {
	template < class Key,									// map::key_type
			class T,										// map::mapped_type
			class Compare = ft::less<Key>,					// map::key_compare
			class Alloc = std::allocator<std::pair<const Key,T> >		// map::allocator_type
	>
	class map {
	private:
		struct node {
			std::pair<Key, T> data;
			node *prev;
			node *left;
			node *right;

			node(std::pair<Key, T> val, node *p, node *l, node *r) : data(val), prev(p), left(l), right(r) {}
			void set_node_prev(node *p) { prev = p; }
			void set_node_left(node *l) { left = l; }
			void set_node_right(node *r) { right = r; }

		};
		node *root;
		size_t _size;
		std::allocator<node> allocator;
		Compare comp;
	public:

		typedef Key key_type;
		typedef T mapped_type;
		typedef std::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;

		class value_compare {
			friend class map;

		protected:
			Compare comp;

			value_compare() {
				comp = Compare();
			}  // constructed with map's comparison object
		public:
			typedef bool result_type;
			bool operator()(const value_type &x, const value_type &y) const {
				return comp(x.first, y.first);
			}
		};

		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		struct iterator {
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef std::pair<key_type, mapped_type> value_type;
			typedef node* node_pointer;
			typedef node& node_reference;
			typedef value_type* type_pointer;
			typedef value_type& type_reference;

			iterator() : m_ptr(nullptr), root(nullptr), begin(nullptr), end(nullptr) { }
			iterator(node_pointer ptr) {
				if (ptr == nullptr) {
					m_ptr = nullptr;
					root = nullptr;
					begin = nullptr;
					end = nullptr;
					return;
				}
				m_ptr = ptr;
				root = m_ptr;
				while (root->prev != nullptr)
					root = root->prev;
				begin = root;
				while (begin->left != nullptr)
					begin = begin->left;
				end = root;
				while (end->right != nullptr)
					end = end->right;
				
			}
			iterator(const iterator & src) {
				*this = src;
				return;
			}
			iterator & operator=(const iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				this->root = rhs.root;
				this->begin = rhs.begin;
				this->end = rhs.end;
				return *this;
			}
			~iterator() { }
			type_reference operator*() const { return m_ptr->data; } 
			type_pointer operator->() const { return &m_ptr->data; }
			iterator operator++() {			//clockwise
				node *ptr;
				if (m_ptr == nullptr) {
					m_ptr = root;
					while (m_ptr->left != nullptr)
						m_ptr = m_ptr->left;
				} else if (m_ptr->right->right != nullptr) {
					m_ptr = m_ptr->right;
					while (m_ptr->left != nullptr) {
						m_ptr = m_ptr->left;
					}
				} else if (m_ptr->right == end) {
					m_ptr = m_ptr->right;
				}
				 else {
					ptr = m_ptr->prev;
					while (ptr != nullptr && m_ptr == ptr->right) {
						m_ptr = ptr;
						ptr = ptr->prev;
					}
					m_ptr = ptr;
				}
				return *this;
			}
			iterator operator++(int) {			//clockwise
				node *ptr;
				if (m_ptr == nullptr) {
					m_ptr = root;
					while (m_ptr->left != nullptr)
						m_ptr = m_ptr->left;
				} else if (m_ptr->right->right != nullptr) {
					m_ptr = m_ptr->right;
					while (m_ptr->left != nullptr) {
						m_ptr = m_ptr->left;
					}
				} else if (m_ptr->right == end) {
					m_ptr = m_ptr->right;
				}
				 else {
					ptr = m_ptr->prev;
					while (ptr != nullptr && m_ptr == ptr->right) {
						m_ptr = ptr;
						ptr = ptr->prev;
					}
					m_ptr = ptr;
				}
				return *this;
			}
			iterator operator--() {			//clockwise
				node *ptr;
				if (m_ptr == nullptr) {
					m_ptr = root;
					while (m_ptr->right->right != nullptr)
						m_ptr = m_ptr->right;
				} else if (m_ptr->left != nullptr) {
					m_ptr = m_ptr->left;
					while (m_ptr->right->right != nullptr) {
						m_ptr = m_ptr->right;
					}
				} else if (m_ptr->left == begin) {
					m_ptr = m_ptr->left;
				}
				 else {
					ptr = m_ptr->prev;
					while (ptr != nullptr && m_ptr == ptr->left) {
						m_ptr = ptr;
						ptr = ptr->prev;
					}
					m_ptr = ptr;
				}
				return *this;
			}
			iterator operator--(int) {			//clockwise
				node *ptr;
				if (m_ptr == nullptr) {
					m_ptr = root;
					while (m_ptr->right->right != nullptr)
						m_ptr = m_ptr->right;
				} else if (m_ptr->left != nullptr) {
					m_ptr = m_ptr->left;
					while (m_ptr->right->right != nullptr) {
						m_ptr = m_ptr->right;
					}
				} else if (m_ptr->left == begin) {
					m_ptr = m_ptr->left;
				}
				 else {
					ptr = m_ptr->prev;
					while (ptr != nullptr && m_ptr == ptr->left) {
						m_ptr = ptr;
						ptr = ptr->prev;
					}
					m_ptr = ptr;
				}
				return *this;
			}
			bool operator==(const iterator & rhs) const { return this->m_ptr == rhs.m_ptr; }
			bool operator!=(const iterator & rhs) const { return this->m_ptr != rhs.m_ptr; }
			node_pointer get_node_pointer() const { return m_ptr; }
			type_reference operator[](const int & index) const {
				node_pointer tmp = m_ptr;
				for (int i = 0; i < index; ++i)
				{
					if (tmp->prev == nullptr)		// if next node is root
						tmp = tmp->right;
					else if (tmp == tmp->prev->left)	// if next node is prev
						tmp = tmp->prev;
					else if (tmp->right != nullptr)		// if next node is the right element
						tmp = tmp->right;
				}
				return tmp->data;
			}

		private:
			node_pointer m_ptr;
			node_pointer root;
			node_pointer begin;
			node_pointer end;
		};
		struct const_iterator {
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;
			typedef std::pair<key_type, mapped_type> value_type;
			typedef const node* node_pointer;
			typedef const node& node_reference;
			typedef const value_type* type_pointer;
			typedef const value_type& type_reference;

			const_iterator() : m_ptr(nullptr), root(nullptr), begin(nullptr), end(nullptr) { }
			const_iterator(node_pointer ptr) {
				if (ptr == nullptr) {
					m_ptr = nullptr;
					root = nullptr;
					begin = nullptr;
					end = nullptr;
					return;
				}
				m_ptr = ptr;
				root = m_ptr;
				while (root->prev != nullptr)
					root = root->prev;
				begin = root;
				while (begin->left != nullptr)
					begin = begin->left;
				end = root;
				while (end->right != nullptr)
					end = end->right;
				
			}
			const_iterator(const const_iterator & src) {
				*this = src;
				return;
			}
			const_iterator & operator=(const const_iterator & rhs) {
				this->m_ptr = rhs.m_ptr;
				this->root = rhs.root;
				this->begin = rhs.begin;
				this->end = rhs.end;
				return *this;
			}
			~const_iterator() { }
			type_reference operator*() const { return m_ptr->data; } 
			type_pointer operator->() const { return &m_ptr->data; }
			const_iterator operator++() {			//clockwise
				node *ptr;
				if (m_ptr == nullptr) {
					m_ptr = root;
					while (m_ptr->left != nullptr)
						m_ptr = m_ptr->left;
				} else if (m_ptr->right->right != nullptr) {
					m_ptr = m_ptr->right;
					while (m_ptr->left != nullptr) {
						m_ptr = m_ptr->left;
					}
				} else if (m_ptr->right == end) {
					m_ptr = m_ptr->right;
				}
				 else {
					ptr = m_ptr->prev;
					while (ptr != nullptr && m_ptr == ptr->right) {
						m_ptr = ptr;
						ptr = ptr->prev;
					}
					m_ptr = ptr;
				}
				return *this;
			}
			const_iterator operator++(int) {			//clockwise
				node *ptr;
				if (m_ptr == nullptr) {
					m_ptr = root;
					while (m_ptr->left != nullptr)
						m_ptr = m_ptr->left;
				} else if (m_ptr->right->right != nullptr) {
					m_ptr = m_ptr->right;
					while (m_ptr->left != nullptr) {
						m_ptr = m_ptr->left;
					}
				} else if (m_ptr->right == end) {
					m_ptr = m_ptr->right;
				}
				 else {
					ptr = m_ptr->prev;
					while (ptr != nullptr && m_ptr == ptr->right) {
						m_ptr = ptr;
						ptr = ptr->prev;
					}
					m_ptr = ptr;
				}
				return *this;
			}
			const_iterator operator--() {			//clockwise
				node *ptr;
				if (m_ptr == nullptr) {
					m_ptr = root;
					while (m_ptr->right->right != nullptr)
						m_ptr = m_ptr->right;
				} else if (m_ptr->left != nullptr) {
					m_ptr = m_ptr->left;
					while (m_ptr->right->right != nullptr) {
						m_ptr = m_ptr->right;
					}
				} else if (m_ptr->left == begin) {
					m_ptr = m_ptr->left;
				}
				 else {
					ptr = m_ptr->prev;
					while (ptr != nullptr && m_ptr == ptr->left) {
						m_ptr = ptr;
						ptr = ptr->prev;
					}
					m_ptr = ptr;
				}
				return *this;
			}
			const_iterator operator--(int) {			//clockwise
				node *ptr;
				if (m_ptr == nullptr) {
					m_ptr = root;
					while (m_ptr->right->right != nullptr)
						m_ptr = m_ptr->right;
				} else if (m_ptr->left != nullptr) {
					m_ptr = m_ptr->left;
					while (m_ptr->right->right != nullptr) {
						m_ptr = m_ptr->right;
					}
				} else if (m_ptr->left == begin) {
					m_ptr = m_ptr->left;
				}
				 else {
					ptr = m_ptr->prev;
					while (ptr != nullptr && m_ptr == ptr->left) {
						m_ptr = ptr;
						ptr = ptr->prev;
					}
					m_ptr = ptr;
				}
				return *this;
			}
			bool operator==(const const_iterator & rhs) const { return this->m_ptr == rhs.m_ptr; }
			bool operator!=(const const_iterator & rhs) const { return this->m_ptr != rhs.m_ptr; }
			node_pointer get_node_pointer() const { return m_ptr; }
			type_reference operator[](const int & index) const {
				node_pointer tmp = m_ptr;
				for (int i = 0; i < index; ++i)
				{
					if (tmp->prev == nullptr)		// if next node is root
						tmp = tmp->right;
					else if (tmp == tmp->prev->left)	// if next node is prev
						tmp = tmp->prev;
					else if (tmp->right != nullptr)		// if next node is the right element
						tmp = tmp->right;
				}
				return tmp->data;
			}

		private:
			node_pointer m_ptr;
			node_pointer root;
			node_pointer begin;
			node_pointer end;
		};
		struct reverse_iterator {
		};
		struct const_reverse_iterator {
		};
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

//		constructor[empty (1)]
		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) {
			root = nullptr;
			_size = 0;
		}
//		constructor[range (2)]
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()) {
			_size = 0;
			root = nullptr;
			while (first != last) {
				insert(value_type(first->first, first->second));
				++first;
			}
		}
//		constructor[copy (3)]
		map (const map& x) {
			_size = 0;
			root = nullptr;
			const_iterator first = x.begin();
			const_iterator last = x.end();
			while (first != last) {
				insert(value_type(first->first, first->second));
				++first;
			}
		}
		// destructor
		~map() {
			clear();
		}

//		operator=()
		map &operator=(const map &rhs) {
			clear();
			const_iterator first = rhs.begin();
			const_iterator last = rhs.end();
			while (first != last) {
				insert(value_type(first->first, first->second));
				++first;
			}
			return *this;
		}

//		begin()
		iterator begin() {
			node *ptr = root;
			if (ptr == nullptr)
				return iterator(nullptr);
			while (ptr->left != nullptr) {
				ptr = ptr->left;
			}
			return iterator(ptr);
		}

		const_iterator begin() const {
			node *ptr = root;
			if (ptr == nullptr)
				return const_iterator(nullptr);
			while (ptr->left != nullptr) {
				ptr = ptr->left;
			}
			return const_iterator(ptr);
		}

//		end()
		iterator end() {
			node *ptr = root;
			if (ptr == nullptr)
				return iterator(nullptr);
			while (ptr->right != nullptr) {
				ptr = ptr->right;
			}
			return iterator(ptr);
		}

		const_iterator end() const {
			node *ptr = root;
			if (ptr == nullptr)
				return const_iterator(nullptr);
			while (ptr->right != nullptr) {
				ptr = ptr->right;
			}
			return const_iterator(ptr);
		}
		// empty()
		bool empty() const {
			return (_size == 0 ? true : false);
		}

//		size()
		size_type size() const {
			return _size;
		}

		// max_size()
		size_type max_size() const {
			return allocator.max_size();
		}

		// operator[]()
		mapped_type& operator[] (const key_type& k) {
			iterator it = find(k);
			if (it == end()) {		// if the element dose not exist
				value_type tmp = value_type(k, mapped_type());
				return (insert(tmp).first->second);
			}
			return find(k)->second; // if it already exists
		}

//		insert[single element (1)]
		std::pair<iterator, bool> insert(const value_type &val) {
			value_compare func;
			iterator it;
			if ((it = find(val.first)) != end()) {			//if the element exist
				return (std::pair<iterator, bool>(it, false));
			}
			if (root == nullptr) {						//if the element is the first node
				root = new node(val, nullptr, nullptr, (new node(value_type(), root, nullptr, nullptr)));		// the most right element (aka last element) is always an ` node
				_size++;
				return (std::pair<iterator, bool>(iterator(root), true));
			}
			node *ptr = root;
			while (ptr != nullptr) {
				if (func(ptr->data, val)) {
					if (ptr->right->right == nullptr) {
						delete ptr->right;
						ptr->right = new node(val, ptr, nullptr, (new node(value_type(), nullptr, nullptr, nullptr)));		// the most right element (aka last element) is always an empty node
						ptr->right->right->set_node_prev(ptr->right);
						_size++;
						ptr = ptr->right;
						break;
					}
					ptr = ptr->right;
				} else {
					if (ptr->left == nullptr) {
						ptr->left = new node(val, ptr, nullptr, (new node(value_type(), nullptr, nullptr, nullptr)));
						ptr->left->right->set_node_prev(ptr->left);
						_size++;
						ptr = ptr->left;
						break;
					}
					ptr = ptr->left;
				}
			}
			return (std::pair<iterator, bool>(iterator(ptr), true));
		}

//		insert[with hint (2)]
		iterator insert (iterator position, const value_type& val) {
			value_compare func;
			iterator it;
			node *ptr;
			if ((it = find(val.first)) != end()) {			//if the element exist
				return it;
			}
			if (root == nullptr) {						//if the element is the first node
				root = new node(val, nullptr, nullptr, (new node(value_type(), root, nullptr, nullptr)));		// the most right element (aka last element) is always an ` node
				_size++;
				return iterator(root);
			}
			if (func(root->data, val))
				ptr = root;
			else
				ptr = position.get_node_pointer();
			while (ptr != nullptr) {
				if (func(ptr->data, val)) {
					if (ptr->right->right == nullptr) {
						delete ptr->right;
						ptr->right = new node(val, ptr, nullptr, (new node(value_type(), nullptr, nullptr, nullptr)));		// the most right element (aka last element) is always an empty node
						ptr->right->right->set_node_prev(ptr->right);
						_size++;
						ptr = ptr->right;
						break;
					}
					ptr = ptr->right;
				} else {
					if (ptr->left == nullptr) {
						ptr->left = new node(val, ptr, nullptr, (new node(value_type(), nullptr, nullptr, nullptr)));
						ptr->left->right->set_node_prev(ptr->left);
						_size++;
						ptr = ptr->left;
						break;
					}
					ptr = ptr->left;
				}
			}
			return iterator(ptr);
		}
//		insert[range (3)]
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			while (first != last) {
				insert(std::pair<key_type, mapped_type>(first->first, first->second));
				++first;
			}
		}
//		(1)
		void erase (iterator position) {
			node *tmp = position.get_node_pointer();
			if (tmp->right->right == nullptr && tmp->left == nullptr) {		//case1: if node is leaf-node
				if (tmp == tmp->prev->left) {
					tmp->prev->left = nullptr;
				} else if (tmp == tmp->prev->right){
					tmp->prev->right = new node(value_type(), tmp->prev, nullptr, nullptr);
				}
				delete tmp->right->right;
				delete tmp;
			} else if (tmp->right->right != nullptr && tmp->left == nullptr){		//case2: if node have only one right subtree
				tmp->prev->right = tmp->right;
				tmp->right->prev = tmp->prev;
				delete tmp;
			} else if (tmp->right->right == nullptr && tmp->left != nullptr){		//case3: if node have only one left subtree
				tmp->prev->left = tmp->left;
				tmp->left->prev = tmp->prev;
				delete tmp;
			} else if (tmp->right->right != nullptr && tmp->left != nullptr){		//case4: if node have tow subtrees
				node *ptr = tmp->left;
				while (ptr->right->right != nullptr)
					ptr = ptr->right;
				if (tmp == tmp->prev->left) {
					tmp->prev->left = ptr;
				} else if (tmp == tmp->prev->right){
					tmp->prev->right = ptr;
				}
				ptr->right = tmp->right;
				ptr->right->prev = ptr;
				ptr->prev = tmp->prev;
				delete tmp;
			}
			_size--;
		}
//		(2)
		size_type erase (const key_type& k) {
			iterator it = find(k);
			if (it != end()) {
				erase(it);
				return 1;
			}
			return 0;
		}

//		(3)
		void erase (iterator first, iterator last) {
			iterator it_tmp;
			while (first != last) {
				it_tmp = first;
				++first;
				erase(it_tmp);
			}
	     }

//		swap()
		void swap (map& x){
			map tmp = x;
			x = *this;
			*this = tmp;
		}

//		clear()
		void clear() {
			if (size() != 0)
				erase_nodes(root);
			root = nullptr;
			_size = 0;
		}

		key_compare key_comp() const {
			return comp;
		}

		value_compare value_comp() const {
			return value_compare();
		}

		iterator find (const key_type& k) {
			node *ptr = root;
			while (ptr != nullptr) {
				if (ptr->data.first == k)
					return iterator(ptr);
				if (ptr->data.first < k) {
					if (ptr->right == nullptr) {
						return end();
					}
					ptr = ptr->right;
				} else {
					if (ptr->left == nullptr) {
						return end();
					}
					ptr = ptr->left;
				}
			}
			return end();
		}

		const_iterator find (const key_type& k) const {
			node *ptr = root;
			while (ptr != nullptr) {
				if (ptr->data.first == k)
					return const_iterator(ptr);
				if (ptr->data.first < k) {
					if (ptr->right == nullptr) {
						return end();
					}
					ptr = ptr->right;
				} else {
					if (ptr->left == nullptr) {
						return end();
					}
					ptr = ptr->left;
				}
			}
			return end();
		}


		size_type count (const key_type& k) const {
			if (find(k) != end())
				return 1;
			else
				return 0;
		}

		iterator lower_bound (const key_type& k) {
			iterator it_e = end();
			iterator it_f = find(k);
			size_t __size = size();
			while (__size != 0) {
				--it_e;
				if (comp(it_e->first, k)) {
					++it_e;
					return it_e;
				}
				__size--;
			}
			if (it_f != end())
				return it_f;
			return end();
		}
		const_iterator lower_bound (const key_type& k) const {
			const_iterator it_e = end();
			const_iterator it_f = find(k);
			size_t __size = size();
			while (__size != 0) {
				--it_e;
				if (comp(it_e->first, k)) {
					++it_e;
					return it_e;
				}
				__size--;
			}
			if (it_f != end())
				return it_f;
			return end();
		}

		iterator upper_bound (const key_type& k) {
			iterator it_e = end();
			iterator it_b = begin();
			iterator it_f = find(k);
			size_t __size = size();
			while (__size != 0) {
				if (comp(k, it_b->first)) {
					return it_b;
				}
				__size--;
				++it_b;
			}
			if (it_f != end())
				return it_f;
			return end();
		}
		const_iterator upper_bound (const key_type& k) const {
			const_iterator it_e = end();
			const_iterator it_b = begin();
			const_iterator it_f = find(k);
			size_t __size = size();
			while (__size != 0) {
				if (comp(k, it_b->first)) {
					return it_b;
				}
				__size--;
				++it_b;
			}
			if (it_f != end())
				return it_f;
			return end();
		}


		std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			const_iterator first = lower_bound(k);
			const_iterator second = upper_bound(k);
			if (first == end())
				first = begin();
			if (second == end())
				second = begin();
			return (std::pair<const_iterator, const_iterator>(first, second));
//			return (std::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}
		std::pair<iterator,iterator>	equal_range (const key_type& k) {
			iterator first = lower_bound(k);
			iterator second = upper_bound(k);
			if (first == end())
				first = begin();
			if (second == end())
				second = begin();
			return (std::pair<iterator, iterator>(first, second));
//			return (std::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}

		void DUMP (node *ptr, int level = 0) {
			if (ptr == nullptr) {
				for(int i = 0; i < level; i++) std::cout << "\t";
				std::cout << "\033[32m leaf \033[0m" << std::endl;
				return;
			}
			for(int i = 0; i < level; i++) std::cout << '\t';
			std::cout << ptr->prev << ":" << ptr << " : " << ptr->data.first << " : " << ptr->data.second << std::endl;
			for(int i = 0; i < level; i++) std::cout << '\t';
			std::cout << "\033[33m left \033[0m" << std::endl;
			DUMP(ptr->left, level + 1);
			for(int i = 0; i < level; i++) std::cout << '\t';
			std::cout << "\033[31m right \033[0m" << std::endl;
			DUMP(ptr->right, level + 1);
		}

		node *get_root() {
			return root;
		}


		private:
		void erase_nodes(node *n) {
			if (n->left != nullptr) {
				// std::cout << n->data.first << ":" << n->data.second << "\t";
				erase_nodes(n->left);
			}
			if (n->right != nullptr) {
				// std::cout << n->data.first << ":" << n->data.second << "\t";
				erase_nodes(n->right);
			}
			if (n->left == nullptr && n->right  == nullptr) {
				// std::cout << n->data.first << ":" << n->data.second << std::endl;
				if (n->prev != nullptr && n == n->prev->left) {
					n->prev->left = nullptr;
				} else if (n->prev != nullptr && n == n->prev->right) {
					n->prev->right = nullptr;
				}
				delete n;
				_size--;
			}
		}

	};

	

}



#endif
