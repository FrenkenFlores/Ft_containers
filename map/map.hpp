#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
namespace ft {
	template <class T> struct less : binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const {return x<y;}
	};

	template < class Key,									// map::key_type
			class T,										// map::mapped_type
			class Compare = ft::less<Key>,					// map::key_compare
			class Alloc = std::allocator<std::pair<const Key,T> >		// map::allocator_type
	> class map {
	public:

		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type,mapped_type> value_type;
		typedef Compare key_compare;
		class value_compare {
			friend class map;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};
		typedef Alloc allocator_type;
		typedef allocator_type::reference reference;
		typedef allocator_type::const_reference const_reference;
		typedef allocator_type::pointer pointer;
		typedef allocator_type::const_pointer const_pointer;
		struct iterator { };
		struct const_iterator { };
		struct reverse_iterator { };
		struct const_reverse_iterator { };
		typedef ptrdiff_t difference_type;
		typedef size_type size_t;



	};

}



#endif