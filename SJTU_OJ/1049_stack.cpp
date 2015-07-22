#include "iostream"
#include "cstring"
#define DEFAULT_LENGTH 100
using namespace std;

class FlowOut{};
class IsEmpty{};

template <typename T>
class SeqStack
{
public:
	SeqStack(bool expandable = true);
	SeqStack(SeqStack<T> &stack);
	~SeqStack();
	bool is_empty() const;
	int max_length() const;
	void set_max_length(int max_length, bool expandable = false);
	int length() const;
	void push(T data);
	void clear();
	T top() const;
	T pop();
	void traverse();
	SeqStack<T> &operator=(SeqStack<T> &stack);

	friend ostream &operator<<(ostream &os, SeqStack<T> &stack){
		for (int i = stack.length_ - 1; i >= 0; --i)
			os << stack.data_[i] << ' ';
		os << '\n';
		return os;
	}

private:
	T *data_;
	int max_length_, length_;
	bool expandable_;
};


template <typename T>
SeqStack<T>::SeqStack(bool expandable) : data_(new T[DEFAULT_LENGTH]), max_length_(DEFAULT_LENGTH), length_(0), expandable_(expandable){}

template <typename T>
SeqStack<T>::SeqStack(SeqStack<T> &stack) : data_(new T[stack.max_length_]), max_length_(stack.max_length_), length_(stack.length_), expandable_(stack.expandable_){
	memcpy(data_, stack.data_, sizeof(T)*length_);
}

template <typename T>
SeqStack<T>::~SeqStack(){
	delete[] data_;
}

template <typename T>
bool SeqStack<T>::is_empty() const{
	return !bool(length_);
}

template <typename T>
int SeqStack<T>::max_length() const{
	return max_length_;
}

template <typename T>
void SeqStack<T>::set_max_length(int max_length, bool expandable){
	max_length_ = max_length;
	expandable_ = expandable;
	if (length_ > max_length_)
		throw FlowOut();
	T *tmp = new T[max_length_];
	memcpy(tmp, data_, sizeof(T)*length_);
	delete[] data_;
	data_ = tmp;
}

template <typename T>
int SeqStack<T>::length() const{
	return length_;
}

template <typename T>
void SeqStack<T>::push(T data){
	if(length_ == max_length_){
		if (!expandable_)
			throw FlowOut();
		max_length_ *= 2;
		T *tmp = new T[max_length_];
		memcpy(tmp, data_, sizeof(T)*length_);
		delete[] data_;
		data_ = tmp;
	}
	data_[length_++] = data;
}

template <typename T>
void SeqStack<T>::clear(){
	delete[] data_;
	data_ = new T[DEFAULT_LENGTH];
	max_length_ = DEFAULT_LENGTH;
	length_ = 0;
}

template <typename T>
T SeqStack<T>::top() const{
	if (length_ <= 0)
		throw IsEmpty();
	return data_[length_-1];
}

template <typename T>
T SeqStack<T>::pop(){
	if (length_ <= 0)
		throw IsEmpty();
	return data_[--length_];
}

template <typename T>
void SeqStack<T>::traverse(){
	for (int i = 0; i < length_; ++i){

	}	
}

template <typename T>
SeqStack<T> &SeqStack<T>::operator=(SeqStack<T> &stack){
	delete[] data_;
	max_length_ = stack.max_length_;
	length_ = stack.length_;
	expandable_ = stack.expandable_;
	data_ = new T[max_length_];
	memcpy(data_, stack.data_, sizeof(T)*length_);
	return *this;
}

int total_test_number, total_train_number, total_stack_length, tmp;
SeqStack<int> required, saved, tmp_stack, wait_train;

int main(){
	cin >> total_test_number;
	for(int i = 0; i < total_test_number; ++i, required.clear(), saved.clear(), wait_train.clear()){
		cin >> total_train_number >> total_stack_length;
		for(int i = 0; i < total_train_number; ++i){
			cin >> tmp;
			tmp_stack.push(tmp);
		}
		for(int i = 0; i < total_train_number; ++i){
			required.push(tmp_stack.pop());
			wait_train.push(total_train_number - i - 1);
		}
		saved.set_max_length(total_stack_length+1);
		try{
			while(!required.is_empty()){
				if (saved.is_empty() || saved.top() != required.top())
					saved.push(wait_train.pop());
				else{
					saved.pop();
					required.pop();
				}
			}
			cout << "YES\n";
		}
		catch(...){
			cout << "NO\n";
		}
	}
}