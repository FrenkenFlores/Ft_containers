template <typename T, typename A>
size_t ft::list<T, A>::node_number = 0;

// default (1)
template <typename T, typename A>
ft::list<T, A>::list (const allocator_type& alloc) {
	sentinel = new node();
	head = sentinel;
	tail = sentinel;
	return;
}
// fill (2)
template <typename T, typename A>
ft::list<T, A>::list (size_type n, const value_type& val, const allocator_type& alloc) {
	sentinel = new node();
	head = sentinel;
	tail = sentinel;
	for (size_t i = 0; i < n; i++)
		push_back(val);
};

// C++98 range (3), InputIterator can be vector or array
template <typename T, typename A>
template <class InputIterator>
ft::list<T, A>::list (InputIterator first, InputIterator last, const allocator_type& alloc, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type*) {
//ft::list<T, A>::list (InputIterator first, InputIterator last, const allocator_type& alloc, typename ft::enable_if<std::is_class<InputIterator>::value || std::is_pointer<InputIterator>::value >::type*) {
	sentinel = new node();
	head = sentinel;
	tail = sentinel;
	while (first != last) {
		push_back(*first);
		first++;
	}
}

// C++11 range (3), InputIterator can be vector or array
//template <typename T, typename A>
//template <class InputIterator, class>
//ft::list<T, A>::list (InputIterator first, InputIterator last, const allocator_type& alloc) {
//	sentinel = new node();
//	head = sentinel;
//	tail = sentinel;
//	while (first != last) {
//		push_back(*first);
//		first++;
//	}
//}

// copy (4)
template <typename T, typename A>
ft::list<T, A>::list (const list& x) {
	sentinel = new node();
	head = sentinel;
	tail = sentinel;
	const_iterator it_begin = x.begin();
	const_iterator it_end = x.end();
	while (it_begin != it_end)
	{
		push_back(*it_begin);
		++it_begin;
	}
}

template <typename T, typename A>
void ft::list<T, A>::push_back (const value_type& val) {
	node *tmp = new node(val, NULL, NULL);
	if (!head->next && !tail->next) {			// list's first node after sentinel node
		tmp->prev = tail;						//
		tmp->next = head;
		tail->next = tmp;
		tail = tail->next;
	}
	else {										// node chain
		tmp->prev = tail;						// tail is the last node
		tmp->next = head;						// head = sentinel, circular list
		tail->next = tmp;						// adding new node
		tail = tail->next;						// moving to the added node, that way the last node will be the added one
		head->prev = tail;						// it = end(); --it; in case when we move backword from the end of the list
	}
	node_number++;
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
	iterator it_begin = begin();
	iterator it_end = end();
	while (it_begin != it_end)
	{
		delete it_end.get_node_pointer();
		--it_end;
	}
	delete it_begin.get_node_pointer();
	this->head = NULL;
	this->tail = NULL;
	this->node_number = 0;
}

template <typename T, typename A>
ft::list<T, A> & ft::list<T, A>::operator=(const ft::list<T, A> &rhs) {
	iterator it_begin = begin();
	iterator it_end = end();
	while (it_begin != it_end)
	{
		delete it_end.get_node_pointer();
		--it_end;
	}
	delete it_begin.get_node_pointer();
	node_number = 0;
	sentinel = new node();
	head = sentinel;
	tail = sentinel;
	const_iterator const_it_begin = rhs.begin();
	const_iterator const_it_end = rhs.end();
	while (const_it_begin != const_it_end)
	{
		push_back(*const_it_begin);
		++const_it_begin;
	}
	return *this;
}

template <typename T, typename A>
typename ft::list<T, A>::iterator ft::list<T, A>::begin() {
	if (head == tail)
		return iterator(head);
	return iterator(head->next);
}

template <typename T, typename A>
typename ft::list<T, A>::const_iterator ft::list<T, A>::begin() const {
	if (head == tail)
		return const_iterator(head);
	return const_iterator(head->next);
}

template <typename T, typename A>
typename ft::list<T, A>::iterator ft::list<T, A>::end() {
	if (tail == head)
		return iterator(tail);
	return iterator(tail->next);
}

template <typename T, typename A>
typename ft::list<T, A>::const_iterator ft::list<T, A>::end() const {
	if (tail == head)
		return const_iterator(tail);
	return const_iterator(tail->next);
}

template <typename T, typename A>
typename ft::list<T, A>::reverse_iterator ft::list<T, A>::rbegin() {
//	std::cout << "->" << head->data << std::endl;
//	std::cout << "->" << tail->data << std::endl;
//	std::cout << "->" << tail->next->data << std::endl;

	if (head == tail)
		return reverse_iterator(tail->next);
//		return reverse_iterator(tail);
//	return reverse_iterator(tail->next);
	return reverse_iterator(tail);
}

template <typename T, typename A>
typename ft::list<T, A>::const_reverse_iterator ft::list<T, A>::rbegin() const {
	if (head == tail)
		return const_reverse_iterator(tail);
	return const_reverse_iterator(tail->next);
}

template <typename T, typename A>
typename ft::list<T, A>::reverse_iterator ft::list<T, A>::rend() {
	if (head == tail)
		return reverse_iterator(head);
	return reverse_iterator(head->next);
}

template <typename T, typename A>
typename ft::list<T, A>::const_reverse_iterator ft::list<T, A>::rend() const {
	if (head == tail)
		return const_reverse_iterator(head);
	return const_reverse_iterator(head->next);
}

template <typename T, typename A>
bool ft::list<T, A>::empty() const {
	if (node_number == 0)
		return true;
	return false;
}

template <typename T, typename A>
typename ft::list<T, A>::size_type ft::list<T, A>::size() const {
	typename ft::list<T, A>::size_type i = 0;
	const_iterator it_begin = begin();
	const_iterator it_end = end();
	while(it_begin != it_end)
	{
		i++;
		++it_begin;
	}
	return i;
}

template <typename T, typename A>
typename ft::list<T, A>::size_type ft::list<T, A>::max_size() const {
	return the_allocator.max_size();
}

template <typename T, typename A>
typename ft::list<T, A>::reference ft::list<T, A>::front() {
	return head->next->data;
}

template <typename T, typename A>
typename ft::list<T, A>::const_reference ft::list<T, A>::front() const {
	return head->next->data;
}

template <typename T, typename A>
typename ft::list<T, A>::reference ft::list<T, A>::back() {
	return tail->data;
}

template <typename T, typename A>
typename ft::list<T, A>::const_reference ft::list<T, A>::back() const {
	return tail->data;
}

template <typename T, typename A>
template <class InputIterator>
void ft::list<T, A>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type*) {
	iterator it_begin = begin();
	iterator it_end = end();
	while (it_begin != it_end)
	{
		delete it_end.get_node_pointer();
		--it_end;
	}
	delete it_begin.get_node_pointer();
	node_number = 0;
	sentinel = new node();
	head = sentinel;
	tail = sentinel;
	while (first != last)
	{
		push_back(*first);
		++first;
	}
}

template <typename T, typename A>
void ft::list<T,  A>::assign(typename ft::list<T, A>::size_type n, const typename ft::list<T, A>::value_type &val) {
	iterator it_begin = begin();
	iterator it_end = end();
	while (it_begin != it_end)
	{
		delete it_end.get_node_pointer();
		--it_end;
	}
	delete it_begin.get_node_pointer();
	node_number = 0;
	sentinel = new node();
	head = sentinel;
	tail = sentinel;
	for (int i = 0; i < n; ++i)
		push_back(val);
}

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