#include "list.hpp"

template <typename T, typename A = std::allocator<T> >
ft::list<T, A>::list(const typename allocator_type &alloc) {}

template <typename T, typename A = std::allocator<T> >
ft::list<T, A>::~list() {}

template <typename T, typename A = std::allocator<T> >
ft::list<T, A> & ft::list<T, A>::operator=(const list<T, A> &src) {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::iterator ft::list<T, A>::begin() {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::const_iterator ft::list<T, A>::begin() const {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::iterator ft::list<T, A>::end() {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::const_itertor ft::list<T, A>::end() const {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::reverse_iterator ft::list<T, A>::rbegin() {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::const_reverse_iterator ft::list<T, A>::rbegin() const {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::reverse_iterator ft::list<T, A>::rend() {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::const_reverse_iterator ft::list<T, A>::rend() const {}

template <typename T, typename A = std::allocator<T> >
bool ft::list<T, A>::empty() const {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::size_type ft::list<T, A>::size() const {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::size_type ft::list<T, A>::max_size() const {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::reference ft::list<T, A>::front() {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::const_reference ft::list<T, A>::front() const {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::reference ft::list<T, A>::back() {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::const_reference ft::list<T, A>::back() const {}

template <typename T, typename A = std::allocator<T>, typename InputIterator>
void ft::list<T, A>::assign(InputIterator first, InputIterator last) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T,  A>::assign(typename ft::list<T, A>::size_type n, const typename ft::list<t, A>::value_type &val) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::push_front(const typename ft::list<T, A>::value_type &val) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::pop_front() {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::push_back(const typename ft::list<T, A>::value_type &val) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::pop_back() {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::iterator ft::list<T, A>::insert(typename ft::list<T, A>::iterator position, const typename ft::list<T, A>::value_type &val) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::insert(typename ft::list<T, A>::iterator position, typename ft::list<T, A>::size_type n, const typename ft::list<T, A>::value_type &val) {}

template <typename T, typename A = std::allocator<T>, typename InputIterator >
void ft::list<T, A>::insert(typename ft::list<T, A>::iterator position, InputIterator first, InputIterator last) {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::iterator ft::list<T, A>::erase(typename ft::list<T, A>::iterator position) {}

template <typename T, typename A = std::allocator<T> >
typename ft::list<T, A>::iterator ft::list<T, A>::erase(typename ft::list<T, A>::iterator first, typename ft::list<T, A>::iterator last) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::swap(list<T, A> &x) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::resize(typename ft::list<T, A>::size_type n, typename ft::list<T, A>::value_type val) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::clear() {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::splice(typename ft::list<T, A>::iterator position, ft::list<T, A> &x) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::splice(typename ft::list<T, A>::iterator position, ft::list<T, A> &x, typename ft::list<T, A>::iterator i) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::splice(typename ft::list<T, A>::iterator position, ft::list<T, A> &x, typename ft::list<T, A>::iterator first, typename ft::list<T, A>::iterator last) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::remove(const typename ft::list<T, A>::value_type &val) {}

template <typename T, typename A = std::allocator<T>, typename Predicate >
void ft::list<T, A>::remove_if(Predicate pred) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::unique() {}

template <typename T, typename A = std::allocator<T>, typename BinaryPredicate >
void ft::list<T, A>::unique(BinaryPredicate binary_pred) {}

template <typename T, typename A = std::allocator<T> >
ft::list<T, A>::merge(ft::list<T, A> &x) {}

template <typename T, typename A = std::allocator<T> >
void ft::list<T, A>::sort() {}

template <typename T, typename A = std::allocator<T>, typename Compare>
void ft::list<T, A>::sort(Compare comp) {}

template <typename T, typename A = std::allocator<T>, typename Compare>
void ft::list<T, A>::reverse() {}

template <typename T, typename A = std::allocator<T>, typename Compare>
typename ft::list<T, A>::allocator_type ft::list<T, A>::get_allocator() const {}