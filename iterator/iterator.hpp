#include <memory>

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
}