#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <cstdbool>
#include <iostream>

namespace ft {
	template <class T> struct less : std::binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const {return x<y;}
	};

	template < class Key,									// map::key_type
			class T,										// map::mapped_type
			class Compare = ft::less<Key>,					// map::key_compare
			class Alloc = std::allocator<std::pair<const Key,T> >		// map::allocator_type
	> class map {
	private:
		struct node {
			std::pair<Key, T> data;
			node *prev;
			node *left;
			node *right;

			node(std::pair<Key, T> val, node *p, node *l, node *r) : data(val), prev(p), left(l), right(r) {}
		};
		node *root;
		size_t count;
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

			iterator() : m_ptr(nullptr) { }
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
			iterator operator++() {			//clockwise
				if (m_ptr->prev == nullptr)		// if next node is root
					m_ptr = m_ptr->right;
				else if (m_ptr == m_ptr->prev->left)	// if next node is prev
					m_ptr = m_ptr->prev;
				else if (m_ptr->right != nullptr)		// if next node is the right element
					m_ptr = m_ptr->right;
				return *this;
			}
			iterator operator--() {			//counter clockwise
				if (m_ptr->prev == nullptr)		// if prev node is root
					m_ptr = m_ptr->left;
				else if (m_ptr == m_ptr->prev->right)	// if prev node is prev
					m_ptr = m_ptr->prev;
				else if (m_ptr->left != nullptr)		// if prev node is the left element
					m_ptr = m_ptr->left;
				return *this;
			}
			bool operator==(const iterator & rhs) { return this->m_ptr == rhs.m_ptr; }
			bool operator!=(const iterator & rhs) { return this->m_ptr != rhs.m_ptr; }
			node_pointer get_node_pointer() { return m_ptr; }
			type_reference operator[](const int & index) {
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
		};
		struct const_iterator {
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
			count = 0;
		}
//		constructor[range (2)]
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()) {
			root = nullptr;
			count = 0;
			while (first != last) {
				insert(value_type(first->first, first->second));
				++first;
			}
		}
//		constructor[copy (3)]
		map (const map& x) {
			iterator first = begin();
			iterator last = end();
			root = nullptr;
			count = 0;
			while (first != last) {
				insert(value_type(first->first, first->second));
				++first;
			}
		}

//		operator=()
		map &operator=(const map &rhs) {
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


//		size()
		size_type size() const {
			return count;
		}

//		insert[single element (1)]
//		std::pair<Key, T> &insert(const value_type &val) {
//			value_compare func;
//			if (root == nullptr) {
//				root = new node(val, nullptr, nullptr, nullptr);
//				return root->data;
//			}
//			node *ptr = root;
//			while (ptr != nullptr) {
//				if (func(ptr->data, val)) {
//					if (ptr->right == nullptr) {
//						ptr->right = new node(val, ptr, nullptr, nullptr);
//						break;
//					}
//					ptr = ptr->right;
//				} else {
//					if (ptr->left == nullptr) {
//						ptr->left = new node(val, ptr, nullptr, nullptr);
//						break;
//					}
//					ptr = ptr->left;
//				}
//			}
//			return ptr->data;
//		}


		std::pair<iterator, bool> insert(const value_type &val) {
			value_compare func;
			iterator it;
			if ((it = find(val.first)) != end()) {			//if the element exist
				return (std::pair<iterator, bool>(it, false));
			}
			if (root == nullptr) {						//if the element is the first node
				root = new node(val, nullptr, nullptr, (new node(value_type(), root, nullptr, nullptr)));		// the most right element (aka last element) is always an empty node
				count++;
				return (std::pair<iterator, bool>(iterator(root), true));
			}
			node *ptr = root;
			while (ptr != nullptr) {
				if (func(ptr->data, val)) {
					if (ptr->right->right == nullptr) {
						delete ptr->right;
						ptr->right = new node(val, ptr, nullptr, (new node(value_type(), ptr->right, nullptr, nullptr)));		// the most right element (aka last element) is always an empty node
						count++;
						ptr = ptr->right;
						break;
					}
					ptr = ptr->right;
				} else {
					if (ptr->left == nullptr) {
						ptr->left = new node(val, ptr, nullptr, nullptr);
						count++;
						ptr = ptr->left;
						break;
					}
					ptr = ptr->left;
				}
			}
			return (std::pair<iterator, bool>(iterator(ptr), true));
		}


//		std::pair<iterator, bool> insert(const value_type &val) {
//			value_compare func;
//			iterator it;
//			if ((it = find(val.first)) != end()) {			//if the element exist
//				return (std::pair<iterator, bool>(it, false));
//			}
//			if (root == nullptr) {						//if the element is the first node
//				root = new node(val, nullptr, nullptr, nullptr);
//				count++;
//				return (std::pair<iterator, bool>(iterator(root), true));
//			}
//			node *ptr = root;
//			while (ptr != nullptr) {
//				if (func(ptr->data, val)) {
//					if (ptr->right == nullptr) {
//						ptr->right = new node(val, ptr, nullptr, nullptr);
//						count++;
//						ptr = ptr->right;
//						break;
//					}
//					ptr = ptr->right;
//				} else {
//					if (ptr->left == nullptr) {
//						ptr->left = new node(val, ptr, nullptr, nullptr);
//						count++;
//						ptr = ptr->left;
//						break;
//					}
//					ptr = ptr->left;
//				}
//			}
//			return (std::pair<iterator, bool>(iterator(ptr), true));
//		}

////		insert[with hint (2)]
//		iterator insert (iterator position, const value_type& val);
////		insert[range (3)]
//		template <class InputIterator>
//		void insert (InputIterator first, InputIterator last);

		void DUMP (node *ptr, int level = 0) {
			if (ptr == nullptr) {
				for(int i = 0; i < level; i++) std::cout << '\t';
				std::cout << " leaf " << std::endl;
				return;
			}
			for(int i = 0; i < level; i++) std::cout << '\t';
			std::cout << ptr->data.first << " : " << ptr->data.second << std::endl;
			for(int i = 0; i < level; i++) std::cout << '\t';
			std::cout << "left" << std::endl;
			DUMP(ptr->left, level + 1);
			for(int i = 0; i < level; i++) std::cout << '\t';
			std::cout << "right" << std::endl;
			DUMP(ptr->right, level + 1);
		}

		node *get_root() {
			return root;
		}

		mapped_type& operator[] (const key_type& k) {
			iterator it = find(k);
			if (it == end()) {		// if the element dose not exist
				value_type tmp = value_type(k, mapped_type());
				return (insert(tmp).first->second);
			}
			return find(k)->second; // if it already exists
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


		void erase (iterator position) {
			if (position.get_node_pointer()->right == nullptr && position.get_node_pointer()->left == nullptr) {		//case1: if node is leaf-node
				position.get_node_pointer()->prev = nullptr;
				delete position.get_node_pointer();
			} else if (position.get_node_pointer()->right != nullptr && position.get_node_pointer()->left == nullptr){		//case2: if node have only one right subtree
				position.get_node_pointer()->prev->right = position.get_node_pointer()->right;
				position.get_node_pointer()->right->prev = position.get_node_pointer()->prev;
				delete position.get_node_pointer();
			} else if (position.get_node_pointer()->right == nullptr && position.get_node_pointer()->left != nullptr){		//case3: if node have only one left subtree
				position.get_node_pointer()->prev->left = position.get_node_pointer()->left;
				position.get_node_pointer()->left->prev = position.get_node_pointer()->prev;
				delete position.get_node_pointer();
			} else if (position.get_node_pointer()->right != nullptr && position.get_node_pointer()->left != nullptr){		//case4: if node have tow subtrees
				node *tmp = position.get_node_pointer()->left;
				while (tmp->right != nullptr)
					tmp = tmp->right;
				tmp->right = position.get_node_pointer()->right;
				tmp->left = position.get_node_pointer()->left;
				tmp->prev = position.get_node_pointer()->prev;
				if (position.get_node_pointer() == position.get_node_pointer()->prev->left)
					position.get_node_pointer()->prev->left = tmp;
				else if (position.get_node_pointer() == position.get_node_pointer()->prev->right)
					position.get_node_pointer()->prev->right = tmp;
				delete position.get_node_pointer();
			}
			count--;
		}

	};

}



#endif