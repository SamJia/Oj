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
#include <algorithm>
using namespace std;
#define SIZE 1000010
Queue<int> boy, girl, music;
int total_music_number, music_length, total_student_number, student_kind, arrive_time;
long long boy_wait_time = 0, girl_wait_time = 0, boy_number = 0, girl_number = 0;
int boys[SIZE], girls[SIZE];

int main(int argc, char const *argv[])
{
	scanf("%d", &total_music_number);
	for(int i = 0; i < total_music_number; ++i){
		scanf("%d", &music_length);
		music.enQueue(music_length);
	}
	scanf("%d", &total_student_number);
	for(int i = 0; i < total_student_number; ++i){
		scanf("%d %d", &student_kind, &arrive_time);
		if(student_kind == 2)
			girls[girl_number++] = arrive_time;
			// girl.enQueue(arrive_time);
		else
			boys[boy_number++] = arrive_time;
			// boy.enQueue(arrive_time);
	}
	sort(boys, boys + boy_number);
	sort(girls, girls + girl_number);
	for(int i = 0; i < boy_number; ++i)
		boy.enQueue(boys[i]);
	for(int i = 0; i < girl_number; ++i)
		girl.enQueue(girls[i]);
	// boy_number = boy.length();
	// girl_number = girl.length();
	int music_time = 0;
	for(; !music.isEmpty(); music_time += music.deQueue())
		for(; !boy.isEmpty() && boy.getHead() <= music_time && !girl.isEmpty() && girl.getHead() <= music_time;){
			boy_wait_time += music_time - boy.deQueue();
			girl_wait_time += music_time - girl.deQueue();
		}
	music_time -= music_length;
	for(; !boy.isEmpty();)
		boy_wait_time += music_time - boy.deQueue();
	for(; !girl.isEmpty();)
		girl_wait_time += music_time - girl.deQueue();
	printf("%.2f %.2f", double(boy_wait_time)/boy_number, double(girl_wait_time)/girl_number);
	return 0;
}