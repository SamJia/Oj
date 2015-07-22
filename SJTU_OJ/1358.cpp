#include "cstdio"
#define SIZE 1000100

struct Node
{
	Node(int number = 0, Node *next = NULL) : number_(number), sub_size_(0), next_(next){}
	int number_;
	int sub_size_;
	Node *next_;
};
Node link[SIZE] = {};

int link_number[SIZE] = {};
int total_node_number, half_number, node1, node2;

int GetSubSize(int node, int father = 0);
bool IsValid(int node);


int main(){
	scanf("%d", &total_node_number);
	half_number = total_node_number / 2;
	for(int i = 1; i < total_node_number; ++i){
		scanf("%d%d", &node1, &node2);
		link[node1].next_ = new Node(node2, link[node1].next_);
		link[node2].next_ = new Node(node1, link[node2].next_);
		link_number[node1]++;
		link_number[node2]++;
	}
	GetSubSize(node1);
	for(int i = 1; i <= total_node_number; ++i){
		if(IsValid(i))
			printf("%d\n", i);
	}
	return 0;
}

int GetSubSize(int node, int father){
	Node *father_point = NULL;
	int sub_size = 0;
	for(Node *p = link[node].next_; p; p = p->next_){
		if(p->number_ == father)
			father_point = p;
		else
			sub_size += (p->sub_size_ = GetSubSize(p->number_, node));
		// printf("%d %d %d\n", node, p->number_, p->sub_size_);
	}
	if(father_point)
		father_point->sub_size_ = total_node_number - sub_size - 1;
	return sub_size + 1;
}

bool IsValid(int node){
	for(Node *p = link[node].next_; p; p = p->next_)
		if(p->sub_size_ > half_number)
			return false;
	return true;
}