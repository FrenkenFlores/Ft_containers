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

	class out_of_range : public std::logic_error {
	public:
		explicit out_of_range (const std::string& what_arg) : logic_error(what_arg) { }
		explicit out_of_range (const char *what_arg) : logic_error(what_arg) { }
	};

	template <class T> struct less : std::binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const {return x<y;}
	};
}



#endif