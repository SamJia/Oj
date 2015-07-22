#include "iostream"
using namespace std;

class OutOfBound{};

template<typename T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(LinkedList<T> &list);
	~LinkedList();
	void clear();
	int length() const;
	void add(T data);
	void add(LinkedList<T> &list2);
	void insert(int pos,const T data);
	void remove(int pos, int num = 1);
	int search(const T &data) const;
	T visit(int pos) const;
	void traverse();
	LinkedList<T> &operator=(LinkedList<T> &list);
private:
	struct Node{
		Node() : next_(NULL){}
		T data_;
		Node *next_;
	};
	Node *head_, *tail_;
	int list_length_;

public:
	friend ostream &operator<<(ostream &os, LinkedList<T> & blank){
		for(Node *p = blank.head_->next_;p;p = p->next_)
			os << p->data_ << ' ';
		os << '\n';
		return os;
	}
};


template <typename T>
LinkedList<T>::LinkedList() : head_(new Node()), list_length_(0){
	tail_ = head_;
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &list) : head_(new Node()), list_length_(0){
	tail_ = head_;
	for(Node *p = list.head_->next_; p; p = p->next_)
		add(p->data_);
}

template <typename T>
LinkedList<T>::~LinkedList(){
	for(Node *p = head_, *q;p;p=q){
		q=p->next_;
		delete p;
	}
};

template <typename T>
void LinkedList<T>::clear(){
	for(Node *p = head_->next_, *q;p;p=q){
		q=p->next_;
		delete p;
	}
	head_->next_ = NULL;
	tail_ = head_;
	list_length_ = 0;
}

template <typename T>
int LinkedList<T>::length() const{
	return list_length_;
}

template <typename T>
void LinkedList<T>::add(T data){
	tail_->next_ = new Node();
	tail_ = tail_->next_;
	tail_->data_ = data;
	list_length_++;
}

template <typename T>
void LinkedList<T>::add(LinkedList<T> &list2){
	for(Node *p = list2.head_->next_;p;p = p->next_)
		add(p->data_);
}

template <typename T>
void LinkedList<T>::insert(int pos,const T data){
	if (pos > list_length_ || pos < 0)
		throw OutOfBound();
	Node *p = head_;
	for	(int i = 0; i < pos; ++i, p = p->next_);
	Node *tmp = new Node();
	tmp->data_ = data;
	tmp->next_ = p->next_;
	p->next_ = tmp;
	list_length_++;
}

template <typename T>
void LinkedList<T>::remove(int pos, int num){
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
}

template <typename T>
int LinkedList<T>::search(const T &data) const{
	int pos = 0;
	for (Node *p = head_->next_; p; p = p->next_, ++pos)
		if (p->data_ == data)
			return pos;
	return -1;
}

template <typename T>
T LinkedList<T>::visit(int pos) const{
	if (pos >= list_length_ || pos < 0)
		throw OutOfBound();
	Node *p = head_->next_;
	for (int traverse_pos = 0; traverse_pos < pos; p = p->next_, ++traverse_pos);
	return p->data_;
}

template <typename T>
void LinkedList<T>::traverse(){
	for (Node *p = head_->next_; p; p = p->next_){

	}
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &list){
	clear();
	for(Node *p = list.head_->next_; p; p = p->next_)
		add(p->data_);
	return *this;
}
