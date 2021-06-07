#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft{
//	https://www.cplusplus.com/reference/type_traits/enable_if/?kw=enable_if
//	template<bool Cond, class T = void> struct enable_if {};
//	template<class T> struct enable_if<true, T> { typedef T type; };
	template <bool>
	struct enable_if { };

	template <>
	struct enable_if<true> {
		typedef void type;
	};

}



#endif