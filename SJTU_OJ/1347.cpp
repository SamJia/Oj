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

#define SIZE 1010
char text[SIZE], colors[6][10] = {"<red>", "<yellow>", "<blue>", "</red>", "</yellow>", "</blue>"};
int count = 0, color_count[3] = {}, length;
SeqStack<int> stack;

bool Compare(int &pos, int num){
	for(int i = 0; colors[num][i] && text[pos+i]; ++i)
		if(text[pos+i] != colors[num][i])
			return false;
	pos += strlen(colors[num])-1;
	return true;
}

void Check(int &pos){
	int color = -1;
	for(int i = 0; i < 6; ++i)
		if(Compare(pos, i)){
			color = i;
			break;
		}
	// cout << color << '\n';
	if(color > 2){
		color_count[stack.top()] += count;
		stack.pop();
		count = 0;
	}
	else if(color >= 0){
		if(!stack.isEmpty())
			color_count[stack.top()] += count;
		stack.push(color);
		count = 0;
	}
}

int main(){
	cin.getline(text, 1010, '\n');
	length = strlen(text);
	for(int i = 0; i < length; ++i){
		// cout << text[i]; 
		if(text[i] == '<')
			Check(i);
		else if(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z')
			count++;
	}
	cout << color_count[0] << ' ' << color_count[1] << ' ' << color_count[2];
	return 0;
}