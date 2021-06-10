#ifndef STACK_HPP
#define STACK_HPP
#include "list.hpp"
namespace ft {
	template <class T, class Container = ft::list<T> >
	class stack {
	private:
		Container ctnr;
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

		explicit stack(const container_type &_ctnr = container_type()) : ctnr(_ctnr) {}
		stack(stack const &x) : ctnr(x.ctnr) {}
		virtual ~stack() {};

		bool empty() const {
			return this->ctnr.empty();
		}

		size_type size() const {
			return this->ctnr.size();
		}

		value_type& top(){
			return this->ctnr.back();
		}
		const value_type& top() const{
			return this->ctnr.back();
		}

		void push (const value_type& val){
			this->ctnr.push_back(val);
		}

		void pop() {
			this->ctnr.pop_back();
		}
	};

}

#endif