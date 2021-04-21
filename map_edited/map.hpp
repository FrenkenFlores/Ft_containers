#include <memory>
#include <utility>

namespace ft {
	template<
			class StringT,
			class MappedT,
			class AllocatorT = std::allocator<MappedT>
	> class map {
	public:
		typedef key_type StringT;
		typedef mapped_type MappedT;
		typedef value_type std::pair<const key_type, MappedT>;
		typedef size_type std::size_t;
		typedef difference_type std::ptrdiff_t;
		typedef allocator_type AllocatorT;
		typedef typename iterator<key_type, mapped_type> iterator;
		typedef typename const_iterator<key_type, mapped_type> const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	};
}