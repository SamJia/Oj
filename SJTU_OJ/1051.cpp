#include "cstdio"
#define SIZE 10010

struct Node
{
	Node(int number = 0) : number_(number), next_(NULL){}
	int number_;
	Node *next_;
};

int total_number, command_number, command;
Node *head = new Node();

void Input();
int Compute();
void Output(int result);

int main(){
	Input();
	int result = Compute();
	Output(result);
	return 0;
}

void Input(){
	scanf("%d", &total_number);
	Node *p = head;
	int tmp = 0;
	for(int i = 0; i < total_number; ++i){
		scanf("%d", &tmp);
		p->next_ = new Node(tmp);
		p = p->next_;
	}
}

int Compute(){
	int count = 0;
	scanf("%d", &command_number);
	for(int i = 0; i < command_number; ++i){
		scanf("%d", &command);
		for(Node *p = head; p->next_; p = p->next_){
			++count;
			if(p->next_->number_ == command){
				Node *tmp = p->next_;
				p->next_ = tmp->next_;
				tmp->next_ = head->next_;
				head->next_ = tmp;
				break;
			}
		}
		// printf("count:%d\n", count);
	}
	return count;
}

void Output(int result){
	printf("%d\n", result);
}