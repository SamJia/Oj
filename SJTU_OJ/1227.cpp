#include "cstdio"
#define SIZE 1010000
// #define MIN(x,y) ((x)<(y)?(x):(y))


struct Node
{
	Node(int data = 0, Node *next = NULL) : data_(data), next_(next){}
	int data_;
	Node *next_;
};

int total_number, tmp;
Node *head = new Node();

void Sort(){
	for(Node *p = head, *q, *min_pre; p->next_; p = p->next_){
		for(min_pre = p, q = p; q->next_; q = q->next_)
			if(q->next_->data_ < min_pre->next_->data_)
				min_pre = q;
		q = min_pre->next_;
		min_pre->next_ = q->next_;
		q->next_ = p->next_;
		p->next_ = q;
	}
}

int main(){
	scanf("%d", &total_number);
	Node *p = head;
	for(int i = 0; i < total_number; ++i){
		scanf("%d", &tmp);
		p = p->next_ = new Node(tmp);
	}
	Sort();
	for(p = head->next_; p; p = p->next_)
		printf("%d ", p->data_);
}