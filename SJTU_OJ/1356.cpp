#include "cstdio"
#define SIZE 100100

struct Node
{
	Node(int number = 0, Node *next = NULL) : number_(number), next_(next){}
	int number_;
	Node *next_;
};
Node link[SIZE] = {};

int link_number[SIZE] = {}, result[SIZE];
int total_node_number, total_query_number, root, node1, node2;

void Init();
void Updata(int node, int father = -1);


int main(){
	scanf("%d%d", &total_node_number, &root);
	Init();
	for(int i = 1; i < total_node_number; ++i){
		scanf("%d%d", &node1, &node2);
		link[node1].next_ = new Node(node2, link[node1].next_);
		link[node2].next_ = new Node(node1, link[node2].next_);
		link_number[node1]++;
		link_number[node2]++;
	}
	Updata(root);
	scanf("%d", &total_query_number);
	for(int i = 0; i < total_query_number; ++i){
		scanf("%d", &node1);
		printf("%d\n", result[node1]);
	}
	return 0;
}

void Init(){
	for(int i = 0; i < total_node_number; ++i){
		result[i] = -1;
	}
}

void Updata(int node, int father){
	for(Node *p = link[node].next_; p; p = p->next_){
		if(p->number_ != father){
			if(p->number_ > result[node])
				result[node] = p->number_;
			Updata(p->number_, node);
		}
	}
}