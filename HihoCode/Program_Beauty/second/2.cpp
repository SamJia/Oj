#include <iostream>
#include <cstdio>
#define SIZE 100100
using namespace std;

struct Node
{
	Node(int number = 0) : number_(number), next_(NULL){}
	int number_;
	Node *next_;
};

void Init();
void Operate(int node, int color);

int main(){
	scanf("%d", &total_test_number);
	for(int i = 0; i < total_test_number; ++i){
		printf("Case #%d:\n", i+1);
		scanf("%d", &total_node_number);
		Init();
		for(int j = 1; j < total_node_number; ++j){
			scanf("%d %d", &node1, &node2);
			link_pointer[node1]->next_ = new Node(node2);
			link_pointer[node1] = link_pointer[node1]->next_;
			link_pointer[node2]->next_ = new Node(node1);
			link_pointer[node2] = link_pointer[node2]->next_;
		}
		scanf("%d", &total_operate_number);
		for(int j = 0; j < total_operate_number; ++j){
			scanf("%d", &command);
			if(command == 2){
				scanf("%d %d", &node1, &node2);
				Operate(node1, node2);
			}
			else
				printf("%d\n", result);
		}
	}
	return 0;
}

void Init(){
	for(int i = 1; i <= total_node_number; ++i){
		for(Node *p = link[i].next_, *q; p; p = q){
			q = p->next_;
			delete p;
		}
		link_pointer[i] = &link[i];
		colors[i] = 0;
	}
	result = 1;
}

void Operate(int node, int color){
	int before = 1, after = 1;
	for(Node *p = link[node].next_; p; p = p->next_){
		if(colors[node] != colors[p->number_])
			before++;
		if(color != colors[p->number_])
			after++;
	}
	colors[node] = color;
	result += after - before;
}