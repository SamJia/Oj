/*
 * list.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Kainan Wang
 */


#include "list.h"
namespace test {

class OutOfBound{};

template <typename T>
list<T>::list() : head_(new Node()), tail_(new Node()), size_(0){
	head_->next_ = tail_;
	tail_->prev_ = head_;
}

template <typename T>
list<T>::list(const list<T> &li) : head_(new Node()), tail_(new Node()), size_(0){
	head_->next_ = tail_;
	tail_->prev_ = head_;
	for(Node *p = li.head_->next_; p != li.tail_; p = p->next_)
		push_back(p->data_);
}


template <typename T>
list<T>::~list(){
	for(Node *p = head_, *q; p; p = q){
		q=p->next_;
		delete p;
	}
}

template <typename T>
int list<T>::size() const{
	return size_;
}

template <typename T>
void list<T>::push_front(const T &data){
	Node *tmp = new Node(data, head_, head_->next_);
	tmp->prev_->next_ = tmp;
	tmp->next_->prev_ = tmp;
	size_++;
}

template <typename T>
void list<T>::push_back(const T &data){
	Node *tmp = new Node(data, tail_->prev_, tail_);
	tmp->prev_->next_ = tmp;
	tmp->next_->prev_ = tmp;
	size_++;
}

template <typename T>
void list<T>::pop_front(){
	if(size_ <= 0)
		throw OutOfBound();
	Node *tmp = head_->next_;
	tmp->prev_->next_ = tmp->next_;
	tmp->next_->prev_ = tmp->prev_;
	delete tmp;
	size_--;
}

template <typename T>
void list<T>::pop_back(){
	if(size_ <= 0)
		throw OutOfBound();
	Node *tmp = tail_->prev_;
	tmp->prev_->next_ = tmp->next_;
	tmp->next_->prev_ = tmp->prev_;
	delete tmp;
	size_--;
}

template <typename T>
void list<T>::sort(){
	merge_sort(head_, tail_, size_);
}

template <typename T>
void list<T>::sort(bool (*cmp)(const T &data1, const T &data2)){
	merge_sort(head_, tail_, size_, cmp);
}

template <typename T>
list<T>& list<T>::operator=(const list<T> &li){
	while(size_){
		pop_back();
	}
	for(Node *p = li.head_->next_; p != li.tail_; p = p->next_)
		push_back(p->data_);
}


// template <typename T>
// void list<T>::quick_sort(Node *begin, Node *end, int state = 0){

// }

template <typename T>
void list<T>::merge_sort(Node *left_begin, Node *right_end, int size){
	if(size <= 1)
		return;
	int left_size = size / 2, right_size = size - size / 2;
	Node *left_end = left_begin->next_;
	for(int i = 0; i < left_size; ++i)
		left_end = left_end->next_;
	merge_sort(left_begin, left_end, left_size);
	Node *right_begin = left_end->prev_;
	merge_sort(right_begin, right_end, right_size);
	left_end = right_begin->next_;
	Node *left_p = left_begin->next_, *right_p = right_begin->next_;
	for(; right_p != right_end; left_end = right_p = right_begin->next_){
		for(; !(left_p == left_end || (right_p->data_ < left_p->data_)); left_p = left_p->next_);
		if(left_p == left_end)
			return;
		insert_prev(left_p, right_p);
	}
}

template <typename T>
void list<T>::merge_sort(Node *left_begin, Node *right_end, int size, bool (*cmp)(const T &data1, const T &data2)){
	if(size <= 1)
		return;
	int left_size = size / 2, right_size = size - size / 2;
	Node *left_end = left_begin->next_;
	for(int i = 0; i < left_size; ++i)
		left_end = left_end->next_;
	merge_sort(left_begin, left_end, left_size, cmp);
	Node *right_begin = left_end->prev_;
	merge_sort(right_begin, right_end, right_size, cmp);
	left_end = right_begin->next_;
	Node *left_p = left_begin->next_, *right_p = right_begin->next_;
	for(; right_p != right_end; left_end = right_p = right_begin->next_){
		for(; !(left_p == left_end || cmp(right_p->data_, left_p->data_)); left_p = left_p->next_);
		if(left_p == left_end)
			return;
		insert_prev(left_p, right_p);
	}
}

template <typename T>
void list<T>::insert_prev(Node *to, Node *from){
	if(to == from)
		return;
	from->prev_->next_ = from->next_;
	from->next_->prev_ = from->prev_;
	from->prev_ = to->prev_;
	from->next_ = to;
	from->prev_->next_ = from;
	from->next_->prev_ = from;
}

template <typename T>
void list<T>::insert_next(Node *to, Node *from){
	if(to == from)
		return;
	from->prev_->next_ = from->next_;
	from->next_->prev_ = from->prev_;
	from->prev_ = to;
	from->next_ = to->next_;
	from->prev_->next_ = from;
	from->next_->prev_ = from;

}

template <typename T>
void list<T>::swap(Node *node1, Node *node2){
	 // swap two nodes, not pointer.
	Node *tmp;
	
	tmp = node1->prev_;
	node1->prev_ = node2->prev_;
	node2->prev_ = tmp;

	tmp = node1->next_;
	node1->next_ = node2->next_;
	node2->next_ = tmp;
	
	node1->prev_->next_ = node1;
	node1->next_->prev_ = node1;
	
	node2->prev_->next_ = node2;
	node2->next_->prev_ = node2;
}

template <typename T>
typename list<T>::iterator list<T>::begin() const{
	return iterator(head_->next_);
}

template <typename T>
typename list<T>::iterator list<T>::end() const{
	return iterator(tail_);
}

template <typename T>
list<T>::iterator::iterator(Node *pointer) : pointer_(pointer){}

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator++(){
	pointer_ = pointer_->next_;
	if (pointer_ == NULL)
		throw OutOfBound();
	return *this;
}

template <typename T>
typename list<T>::iterator list<T>::iterator::operator++(int){
	iterator tmp = *this;
	++(*this);
	return tmp;
}

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator--(){
	pointer_ = pointer_->prev_;
	if (pointer_->prev_ == NULL)
		throw OutOfBound();
	return *this;
}

template <typename T>
typename list<T>::iterator list<T>::iterator::operator--(int){
	iterator tmp = *this;
	--(*this);
	return tmp;
}

template <typename T>
bool list<T>::iterator::operator==(const iterator &it2) const{
	if(pointer_ == it2.pointer_)
		return true;
	return false;
}

template <typename T>
bool list<T>::iterator::operator!=(const iterator &it2) const{
	return !((*this) == it2);
}

template <typename T>
T list<T>::iterator::operator*() const{
	return pointer_->data_;
}


template <typename T>
list<T>::Node::Node(Node *prev, Node *next) : prev_(prev), next_(next){}

template <typename T>
list<T>::Node::Node(const T &data, Node *prev, Node *next) : data_(data), prev_(prev), next_(next){}

template <typename T>
list<T>::Node::Node(const Node &node) : data_(node.data_), prev_(node.prev_), next_(node.next_){}

}

// using namespace test;
// main(){
// 	list<int> a;
// 	int b[4] = {4, 3, 2, 1};
// 	for(int i = 0; i < 4; ++i)
// 		a.push_back(b[i]);
// 	a.sort();
// 	for(list<int>::iterator it = a.begin(); it != a.end(); ++it)
// 		std::cout << *it << ' ';
// }
