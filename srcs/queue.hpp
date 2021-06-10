#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "list.hpp"
namespace ft {
	template <class T, class Container = ft::list<T> >
	class queue : public ft::list<T> {
	private:
		Container ctnr;
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

		explicit queue(const container_type &_ctnr = container_type()) : ctnr(_ctnr) {}
		queue(queue const &x) : ctnr(x.ctnr) {}
		virtual ~queue() {};

		bool empty() const {
			return this->ctnr.empty();
		}

		size_type size() const {
			return this->ctnr.size();
		}

		value_type& front(){
			return this->ctnr.front();
		}
		const value_type& front() const{
			return this->ctnr.front();
		}

		value_type& back(){
			return this->ctnr.back();
		}
		const value_type& back() const{
			return this->ctnr.back();
		}

		void push (const value_type& val){
			this->ctnr.push_back(val);
		}

		void pop() {
			this->ctnr.pop_front();
		}
	};
}
#endif