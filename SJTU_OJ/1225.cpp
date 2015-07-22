#include "cstdio"
#define POST 0x001fffff
#define PRE 0xffe00000
#define SIZE 0x00200000

struct Node
{
	Node(int data = 0, Node *next = NULL) : data_(data), next_(next){}
	int data_;
	Node *next_;
};

int total_number;
Node occur[SIZE];
int result = 0, number, pre, post;

bool Check();


int main(){
	scanf("%d", &total_number);
	for(int i = 0; i < total_number; ++i){
		scanf("%d", &number);
		pre = (number & PRE)>>20;
		post = number & POST;
		if(!Check()){
			occur[post].next_ = new Node(pre, occur[post].next_);
			++result;
		}
	}
	printf("%d\n", result);
	return 0;
}

bool Check(){
	for(Node *p = occur[post].next_; p; p = p->next_)
		if(p->data_ == pre)
			return true;
	return false;
}