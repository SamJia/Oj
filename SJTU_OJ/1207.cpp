#include "cstdio"

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

int main(int argc, char const *argv[])
{
	Queue<int> passenger, goods;
	int total_car_number, car_kind, arrive_time, passenger_wait_time = 0, goods_wait_time = 0, passenger_number, goods_number;
	scanf("%d", &total_car_number);
	for(int i = 0; i < total_car_number; ++i){
		scanf("%d %d", &car_kind, &arrive_time);
		if(car_kind == 1)
			goods.enQueue(arrive_time);
		else
			passenger.enQueue(arrive_time);
	}
	passenger_number = passenger.length();
	goods_number = goods.length();
	for(int ship_time = 0, cars_on_ship = 0; !passenger.isEmpty() || !goods.isEmpty(); ship_time += 10, cars_on_ship = 0){
		for(; cars_on_ship < 8 && !passenger.isEmpty() && passenger.getHead() <= ship_time; ++cars_on_ship)
			passenger_wait_time += ship_time - passenger.deQueue();
		for(; cars_on_ship < 10 && !goods.isEmpty() && goods.getHead() <= ship_time; ++cars_on_ship)
			goods_wait_time += ship_time - goods.deQueue();
	}
	printf("%.3f %.3f", double(passenger_wait_time)/passenger_number, double(goods_wait_time)/goods_number);
	return 0;
}