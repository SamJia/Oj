// Not Complete

#include "iostream"
using namespace std;

class OutOfBound{};

template<typename T>
class LinkList
{
public:
	LinkList();
	LinkList(LinkList<T> &list);
	~LinkList();
	void clear();
	int length() const;
	void add(const T &data);
	void add(LinkList<T> &list2);
	void insert(int pos,const T &data);
	void remove(int pos, int num = 1);
	int search(const T &data) const;
	T visit(int pos) const;
	void traverse();

	void push_front(const T &data);
	void push_back(const T &data);
	void sort();
	void quick_sort(Node *begin, Node *end, int state = 0);

	LinkList<T> &operator=(LinkList<T> &list);
private:
	struct Node{
		Node(Node *prev = NULL, Node *next = NULL) : prev_(NULL), next_(NULL){}
		Node(const T &data, Node *prev = NULL, Node *next = NULL) : data_(data), prev_(NULL), next_(NULL){}
		T data_;
		Node *prev_, *next_;
	};
	Node *head_, *tail_;
	int list_length_;

public:
	friend ostream &operator<<(ostream &os, LinkList<T> & blank){
		for(Node *p = blank.head_->next_;p;p = p->next_)
			os << p->data_ << ' ';
		os << '\n';
		return os;
	}
};


template <typename T>
LinkList<T>::LinkList() : head_(new Node()), tail_(new Node()), list_length_(0){
	head_->next_ = tail_;
	tail_->prev_ = head_;
}

template <typename T>
LinkList<T>::LinkList(LinkList<T> &list) : head_(new Node()), tail_(new Node()), list_length_(0){
	head_->next_ = tail_;
	tail_->prev_ = head_;
	for(Node *p = list.head_->next_; p != list.tail_; p = p->next_)
		push_back(p->data_);
}

template <typename T>
LinkList<T>::~LinkList(){
	for(Node *p = head_, *q;p;p=q){
		q=p->next_;
		delete p;
	}
};

template <typename T>
void LinkList<T>::clear(){
	for(Node *p = head_->next_, *q;p != tail_;p=q){
		q=p->next_;
		delete p;
	}
	head_->next_ = tail_;
	tail_->prev_ = head_;
	list_length_ = 0;
}

template <typename T>
int LinkList<T>::length() const{
	return list_length_;
}

template <typename T>
void LinkList<T>::add(const T &data){
	push_back(data);
}

template <typename T>
void LinkList<T>::add(LinkList<T> &list2){
	for(Node *p = list2.head_->next_;p != list2.tail_;p = p->next_)
		add(p->data_);
}

template <typename T>
void LinkList<T>::insert(int pos,const T &data){
	if (pos > list_length_ || pos < 0)
		throw OutOfBound();
	Node *p = head_;
	for	(int i = 0; i < pos; ++i, p = p->next_);
	Node *tmp = new Node(data, p, p->next_);
	tmp->next_->prev_ = tmp;
	tmp->prev_->next_ = tmp;
	list_length_++;
}

template <typename T>
void LinkList<T>::remove(int pos, int num){
	if (pos >= list_length_ || pos < 0)
		throw OutOfBound();
	if (pos + num > list_length_ || num < 0)
		throw OutOfBound();
	Node *p = head_;
	for	(int i = 0; i < pos; ++i, p = p->next_);
	Node *tmp = p;
	for (int i = 0; i < num; ++i){		
		tmp = p->next_;
		p->next_ = tmp->next_;
		delete tmp;
		list_length_--;
	}
	p->next_->prev_ = p;
}

template <typename T>
int LinkList<T>::search(const T &data) const{
	int pos = 0;
	for (Node *p = head_->next_; p != tail_; p = p->next_, ++pos)
		if (p->data_ == data)
			return pos;
	return -1;
}

template <typename T>
T LinkList<T>::visit(int pos) const{
	if (pos >= list_length_ || pos < 0)
		throw OutOfBound();
	Node *p = head_->next_;
	for (int traverse_pos = 0; traverse_pos < pos; p = p->next_, ++traverse_pos);
	return p->data_;
}

template <typename T>
void LinkList<T>::traverse(){
	for (Node *p = head_->next_; p != tail_; p = p->next_){

	}
}

template <typename T>
LinkList<T> &LinkList<T>::operator=(LinkList<T> &list){
	clear();
	for(Node *p = list.head_->next_; p != list.tail_; p = p->next_)
		push_back(p->data_);
	return *this;
}


template <typename T>
void LinkList<T>::push_front(const T &data){
	Node *tmp = new Node(data, head_, head_->next_);
	tmp->next_->prev_ = tmp;
	tmp->prev_->next_ = tmp;
}

template <typename T>
void LinkList<T>::push_back(const T &data){
	Node *tmp = new Node(data, tail_->prev_, tail_);
	tmp->next_->prev_ = tmp;
	tmp->prev_->next_ = tmp;
}

template <typename T>
void LinkList<T>::sort(){
	quick_sort(head_->next_, tail_->prev_);
}

template <typename T>
void LinkList<T>::quick_sort(Node *begin, Node *end, int state){
	// if (begin == end)
	// 	return;
	const T &tmp = state ? begin->data_ : end->data_;
	Node *left = begin, *right = end;
	while (left != right && right->next_ != left){
		for(; left != end && left->data_ < tmp; left = left->next_);
		for(; right != begin && !(right->data_ < tmp); right = right->prev_);
		if (left == right || right->next_ == left)
			break;
		swap(left, right);
		left = left->next_;
		right = right->prev_;
	}
}
