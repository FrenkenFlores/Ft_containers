
// default (1)
template <typename T, typename A>
ft::list<T, A>::list (const allocator_type& alloc) {
	head = NULL;
	tail = NULL;
	return;
}
// fill (2)
template <typename T, typename A>
ft::list<T, A>::list (size_type n, const value_type& val, const allocator_type& alloc) {
	head = NULL;
	tail = NULL;
	for (size_t i = 0; i < n; i++)
		push_back(val);
};

// range (3)
template <typename T, typename A>
template <class InputIterator, class>
ft::list<T, A>::list (InputIterator first, InputIterator last, const allocator_type& alloc) {
	head = NULL;
	tail = NULL;
	while (first != last) {
		push_back(*first);
		first++;
	}
}

template <typename T, typename A>
void ft::list<T, A>::push_back (const value_type& val) {
	node *tmp = new node(val, NULL, NULL);
	if (!head && !tail) {
		head = tmp;
		tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tail->next;
		tail->next = NULL;
	}
}





//template <typename T, typename A>
//ft::list<T, A>::list() {}
//
//template <typename T, typename A>
//ft::list<T, A>::list(const ft::list<T, A> &src) {}
//
//template <typename T, typename A>
//ft::list<T, A>::list(const allocator_type &alloc) {}
//
template <typename T, typename A>
ft::list<T, A>::~list() {
	this->head = NULL;
	this->tail = NULL;
}
//
//template <typename T, typename A>
//ft::list<T, A> & ft::list<T, A>::operator=(const ft::list<T, A> &rhs) {}
//
template <typename T, typename A>
typename ft::list<T, A>::iterator ft::list<T, A>::begin() {
	return iterator(head);
}
//
//template <typename T, typename A>
//typename ft::list<T, A>::const_iterator ft::list<T, A>::begin() const {}
//
template <typename T, typename A>
typename ft::list<T, A>::iterator ft::list<T, A>::end() {
	node *tmp = head;
	while (tmp != NULL) {
		tmp = tmp->next;
	}
	return iterator(tmp);
}
//
//template <typename T, typename A>
//typename ft::list<T, A>::const_iterator ft::list<T, A>::end() const {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::reverse_iterator ft::list<T, A>::rbegin() {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::const_reverse_iterator ft::list<T, A>::rbegin() const {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::reverse_iterator ft::list<T, A>::rend() {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::const_reverse_iterator ft::list<T, A>::rend() const {}
//
//template <typename T, typename A>
//bool ft::list<T, A>::empty() const {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::size_type ft::list<T, A>::size() const {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::size_type ft::list<T, A>::max_size() const {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::reference ft::list<T, A>::front() {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::const_reference ft::list<T, A>::front() const {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::reference ft::list<T, A>::back() {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::const_reference ft::list<T, A>::back() const {}
//
//template <typename T, typename A>
//void ft::list<T, A>::assign(ft::list<T, A>::iterator first, ft::list<T, A>::iterator last) {}
//
//template <typename T, typename A>
//void ft::list<T,  A>::assign(typename ft::list<T, A>::size_type n, const typename ft::list<T, A>::value_type &val) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::push_front(const typename ft::list<T, A>::value_type &val) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::pop_front() {}
//
//template <typename T, typename A>
//void ft::list<T, A>::push_back(const typename ft::list<T, A>::value_type &val) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::pop_back() {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::iterator ft::list<T, A>::insert(typename ft::list<T, A>::iterator position, const typename ft::list<T, A>::value_type &val) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::insert(typename ft::list<T, A>::iterator position, typename ft::list<T, A>::size_type n, const typename ft::list<T, A>::value_type &val) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::insert(typename ft::list<T, A>::iterator position, typename ft::list<T, A>::iterator first, typename ft::list<T, A>::iterator last) {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::iterator ft::list<T, A>::erase(typename ft::list<T, A>::iterator position) {}
//
//template <typename T, typename A>
//typename ft::list<T, A>::iterator ft::list<T, A>::erase(typename ft::list<T, A>::iterator first, typename ft::list<T, A>::iterator last) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::swap(list<T, A> &x) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::resize(typename ft::list<T, A>::size_type n, typename ft::list<T, A>::value_type val) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::clear() {}
//
//template <typename T, typename A>
//void ft::list<T, A>::splice(typename ft::list<T, A>::iterator position, ft::list<T, A> &x) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::splice(typename ft::list<T, A>::iterator position, ft::list<T, A> &x, typename ft::list<T, A>::iterator i) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::splice(typename ft::list<T, A>::iterator position, ft::list<T, A> &x, typename ft::list<T, A>::iterator first, typename ft::list<T, A>::iterator last) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::remove(const typename ft::list<T, A>::value_type &val) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::remove_if(T pred) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::unique() {}
//
//template <typename T, typename A>
//void ft::list<T, A>::unique(T binary_pred) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::merge(ft::list<T, A> &x) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::merge(ft::list<T, A> &x, void (*f)(T, T)) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::sort() {}
//
//template <typename T, typename A>
//void ft::list<T, A>::sort(void (*f)(T, T)) {}
//
//template <typename T, typename A>
//void ft::list<T, A>::reverse() {}