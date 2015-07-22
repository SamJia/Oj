#ifndef NULL
#define NULL 0
#endif
class IsEmpty{};
template <typename T>
class Queue
{
public:
	Queue();
	bool isEmpty() const;
	int length() const;
	void enQueue(T data);
	T deQueue();
	T getHead() const;
	~Queue();
	
private:
	struct Node{
		Node() : next_(NULL){}
		T data_;
		Node *next_;
	};
	Node *head_, *tail_;
	int length_;
};


template <typename T>
Queue<T>::Queue() : head_(new Node()), length_(0){
	tail_ = head_;
}

template <typename T>
bool Queue<T>::isEmpty() const{
	return !bool(length_);
}

template <typename T>
int Queue<T>::length() const{
	return length_;
}


template <typename T>
void Queue<T>::enQueue(T data){
	tail_->next_ = new Node();
	tail_ = tail_->next_;
	tail_->data_ = data;
	++length_;
}

template <typename T>
T Queue<T>::deQueue(){
	if(length_ == 0)
		throw IsEmpty();
	T tmp = head_->next_->data_;
	Node *tmpNote = head_->next_;
	head_->next_ = tmpNote->next_;
	delete tmpNote;
	--length_;
	return tmp;
}

template <typename T>
T Queue<T>::getHead() const{
	if(length_ == 0)
		throw IsEmpty();
	return head_->next_->data_;
}

template <typename T>
Queue<T>::~Queue(){
	for(Node *p = head_, *q; p; p = q){
		q = p->next_;
		delete p;
	}
}
