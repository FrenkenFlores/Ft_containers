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
	for (size_type i = 0; i < n; i++)
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

// destructor
template <typename T, typename A>
ft::list<T, A>::~list() {
	clear();
	delete head;
	this->head = NULL;
	this->tail = NULL;
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
	if (head == tail)
		return reverse_iterator(tail->next);
	return reverse_iterator(tail);
}

template <typename T, typename A>
typename ft::list<T, A>::const_reverse_iterator ft::list<T, A>::rbegin() const {
	return reverse_iterator(tail);
}

template <typename T, typename A>
typename ft::list<T, A>::reverse_iterator ft::list<T, A>::rend() {
	return reverse_iterator(head);
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
	return node_allocator.max_size();
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
void ft::list<T,  A>::assign(size_type n, const value_type &val) {
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

template <typename T, typename A>
void ft::list<T, A>::push_front(const value_type &val) {
	node *tmp = new node(val, NULL, NULL);
	if (head->next == tail->next) {			// list's first node after sentinel node
		tmp->prev = head;						//
		tmp->next = tail;
		head->next = tmp;
		tail->prev = tmp;
		tail = tail->prev;
	}
	else {										// node chain
		tmp->prev = head;						// head is the sentinel node
		tmp->next = head->next;
		head->next->prev = tmp;
		head->next = tmp;
		head->prev = tail;
	}
	node_number++;
}

template <typename T, typename A>
void ft::list<T, A>::pop_front() {
	node *tmp = head->next;
	head->next->next->prev = head->next->prev;
	head->next = head->next->next;
	if (head->next == head->prev)			// for the last node
		tail = head;
	delete tmp;
	node_number--;
}


template <typename T, typename A>
void ft::list<T, A>::push_back (const value_type& val) {
	node *tmp = new node(val, NULL, NULL);
	if (head->next == tail->next) {			// list's first node after sentinel node
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
		head->prev = tail;						// it = end(); --it; in case when we move backward from the end of the list
	}
	node_number++;
}

template <typename T, typename A>
void ft::list<T, A>::pop_back() {
	node *tmp = tail;
	tail->next->prev = tail->prev;
	tail->prev->next = tail->next;
	tail = tail->prev;
	if (!size())			// for the last node
		tail = head;
	delete tmp;
	node_number--;
}

//single element (1)
template <typename T, typename A>
typename ft::list<T, A>::iterator ft::list<T, A>::insert(typename ft::list<T, A>::iterator position, const value_type &val) {
	node *ptr = position.get_node_pointer();
	node *tmp = new node(val, ptr, ptr->prev);
	ptr->prev->next = tmp;
	ptr->prev = tmp;
	node_number++;
	return (iterator(tmp));
}

//fill (2)
template <typename T, typename A>
void ft::list<T, A>::insert(typename ft::list<T, A>::iterator position, typename ft::list<T, A>::size_type n, const typename ft::list<T, A>::value_type &val) {
	for (size_type i = 0; i < n; ++i) {
		insert(position, val);
	}
}

//range (3)
template <typename T, typename A>
template <class InputIterator>
void ft::list<T, A>::insert(typename ft::list<T, A>::iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type*) {
	while (first != last) {
		insert(position, *first);
		++first;
	}
}

template <typename T, typename A>
typename ft::list<T, A>::iterator ft::list<T, A>::erase(typename ft::list<T, A>::iterator position) {
	node *tmp = position.get_node_pointer();
	node *prev = position.get_node_pointer()->prev;
	node *next = position.get_node_pointer()->next;
	prev->next = position.get_node_pointer()->next;
	next->prev = position.get_node_pointer()->prev;
	delete tmp;
	node_number--;
	return (iterator(prev));
}

template <typename T, typename A>
typename ft::list<T, A>::iterator ft::list<T, A>::erase(typename ft::list<T, A>::iterator first, typename ft::list<T, A>::iterator last) {
	while (first != last) {
		first = erase(first);
		++first;
	}
	return (first);
}

template <typename T, typename A>
void ft::list<T, A>::swap(list<T, A> &x) {
	list tmp = x;
	x = *this;
	*this = tmp;
}

template <typename T, typename A>
void ft::list<T, A>::resize(typename ft::list<T, A>::size_type n, typename ft::list<T, A>::value_type val) {
	size_type size = this->size();
	if (size < n) {
		while (size < n) {
			push_back(val);
			size++;
		}
	}
	else {
		while (size > n) {
			pop_back();
			size--;
		}
	}
}

template <typename T, typename A>
void ft::list<T, A>::clear() {
	while (head != tail)
	{
		delete tail;
		tail = tail->prev;
	}
	this->node_number = 0;
}

//entire list (1)
template <typename T, typename A>
void ft::list<T, A>::splice(typename ft::list<T, A>::iterator position, ft::list<T, A> &x) {
	this->splice(position, x, x.begin(), x.end());
}

//single element (2)
template <typename T, typename A>
void ft::list<T, A>::splice(typename ft::list<T, A>::iterator position, ft::list<T, A> &x, typename ft::list<T, A>::iterator i) {

	node *ptr = position.get_node_pointer();
	node *tmp = i.get_node_pointer();

	tmp->detach_node();
	ptr->insert_before(tmp);
	if (head == tail || tmp->next == head)	//in case if the list is empty or the node is that last one, make tail the node that been added
		tail = tmp;
}

//element range (3)
template <typename T, typename A>
void ft::list<T, A>::splice(typename ft::list<T, A>::iterator position, ft::list<T, A> &x, typename ft::list<T, A>::iterator first, typename ft::list<T, A>::iterator last) {
	node *ptr = position.get_node_pointer();
	node *tmp;
	while(first != last)
	{
		tmp = first.get_node_pointer();
		++first;
		if (tmp == x.get_tail())
			x.set_tail(x.get_tail()->prev);
		tmp->detach_node();
		ptr->insert_before(tmp);
		if (head == tail || tmp->next == head)
			tail = tmp;
	}
}

template <typename T, typename A>
void ft::list<T, A>::remove(const typename ft::list<T, A>::value_type &val) {
	node *tmp = tail;
	while (tmp != head) {
		if (tmp->data == val) {
			tmp->detach_node();
			delete tmp;
			tmp = tail;
			continue;
		}
		tmp = tmp->prev;
	}
}

template <typename T, typename A>
template <class Predicate>
void ft::list<T, A>::remove_if(Predicate pred) {
	node *tmp = tail;
	while (tmp != head) {
		if ((pred)(tmp->data)) {
			tmp->detach_node();
			delete tmp;
			tmp = tail;
			continue;
		}
		tmp = tmp->prev;
	}
}


template <typename T, typename A>
void ft::list<T, A>::unique() {

	node *first = tail;
	node *last = head;
	while (first != last) {
		if (std::abs((first->data - first->prev->data)) < std::numeric_limits<T>::epsilon()){   //same as first->data == first->next->data
			if (first == tail)
				tail = first->prev;
			first->detach_node();
			delete first;
			first = tail;
			continue;
		}
		first = first->prev;
	}
}

template <typename T, typename A>
template <class BinaryPredicate>
void ft::list<T, A>::unique(BinaryPredicate binary_pred) {
	node *first = tail;
	node *last = head;
	while (first != last) {
		if ((binary_pred)(first->data, first->prev->data)){
			if (first == tail)
				tail = first->prev;
			first->detach_node();																//same as first->data == first->next->data
			delete first;
			first = tail;
			continue;
		}
		first = first->prev;
	}
}

template <typename T, typename A>
void ft::list<T, A>::merge(ft::list<T, A> &x) {
	splice(begin(), x, x.begin(), x.end());
	sort();
}

template <typename T, typename A>
template<typename Condition>
void ft::list<T, A>::merge(ft::list<T, A> &x, Condition cond) {
	splice(begin(), x, x.begin(), x.end());
	sort(cond);
}


//Bubble sort(changes the nodes)
template <typename T, typename A>
void ft::list<T, A>::sort() {
	node *first = head->next;
	node *last = tail;
	node *ptr_next;
	node *ptr;
	while (first != last) {
		ptr = head->next;
		while (ptr != last) {
			if (ptr->data > ptr->next->data){
				if (ptr->next == tail)
					tail = ptr;
				ptr_next = ptr->next;
				ptr->detach_node();
				ptr_next->insert_after(ptr);
				ptr = ptr_next;
				continue;
			}
			ptr = ptr->next;
		}
		first = first->next;
	}
}

template <typename T, typename A>
template<typename Condition>
void ft::list<T, A>::sort(Condition cond) {
	node *first = head->next;
	node *last = tail;
	node *ptr_next;
	node *ptr;
	while (first != last) {
		ptr = head->next;
		while (ptr != last) {
			if ((cond)(ptr->data, ptr->next->data)){
				if (ptr->next == tail)
					tail = ptr;
				ptr_next = ptr->next;
				ptr->detach_node();
				ptr_next->insert_after(ptr);
				ptr = ptr_next;
				continue;
			}
			ptr = ptr->next;
		}
		first = first->next;
	}
}

template <typename T, typename A>
void ft::list<T, A>::reverse() {
	node *last = tail;
	node *first = head->next;
	node *tmp;
	node *ptr = tail;
	while (first != last) {
		first->swap_node(last);
		tmp = first;
		first = last;
		last = tmp;
		first = first->next;
		last = last->prev;

	}
	tail = head->prev;
	head = ptr->prev;
}

template <typename T, typename A>
void  ft::list<T, A>::set_tail(node *tail) {
	this->tail = tail;
}

template <typename T, typename A>
typename ft::list<T, A>::node *ft::list<T, A>::get_tail() const {
	return tail;
}

