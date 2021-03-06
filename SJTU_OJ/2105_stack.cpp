#define SIZE 100100
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
	bool isEmpty() const;
	int maxLength() const;
	void setMaxLength(int max_length, bool expandable = false);
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
bool SeqStack<T>::isEmpty() const{
	return !bool(length_);
}

template <typename T>
int SeqStack<T>::maxLength() const{
	return max_length_;
}

template <typename T>
void SeqStack<T>::setMaxLength(int max_length, bool expandable){
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

int main(int argc, char const *argv[])
{
	SeqStack<int> stack;
	int total_number, tmp, height[SIZE];
	long long result = 0;
	cin >> total_number;
	height[0] = -2;
	height[total_number+1] = -1;
	for(int i = 1; i <= total_number; ++i)
		cin >> height[i];
	for(int i = 0; i <= total_number+1; ++i){
		while(!stack.isEmpty() && height[stack.top()] >= height[i]){
			tmp = stack.pop();
			result = max(result, (long long)height[tmp] * (i - stack.top() - 1));
		}
		stack.push(i);
	}
	cout << result;
	return 0;
}