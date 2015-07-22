#include "cstdio"
#include "iostream"
#define SIZE 20100
#define NUM first
#define MARK second
using namespace std;

struct Node
{
	Node(int number = 0, bool mark = 0, Node *next = NULL) : number_(number), mark_(mark), next_(next){}
	int number_;
	bool mark_;
	Node *next_;
};

Node link[SIZE] = {};
int total_node_number, total_test_number, total_border_number, para, num1, num2;
int paras[SIZE][3];

void Init();
pair<int, int> GetNodeNumber(int node, int father);

int main(){
	scanf("%d", &total_test_number);
	for(int i = 0; i < total_test_number; ++i){
		scanf("%d%d", &total_node_number, &total_border_number);
		Init();
		for(int j = 0; j < total_node_number - 1; ++j)
			scanf("%d%d", &paras[j][0], &paras[j][1]);
		for(int j = 0; j < total_border_number; ++j){
			scanf("%d", &para);
			paras[para][2] = 1;
		}
		for(int j = 0; j < total_node_number - 1; ++j){
			link[paras[j][0]].next_ = new Node(paras[j][1], paras[j][2], link[paras[j][0]].next_);
			link[paras[j][1]].next_ = new Node(paras[j][0], paras[j][2], link[paras[j][1]].next_);
		}
		// printf("node1:%d, node2:%d\n", paras[para][0], paras[para][1]);
		num1 = GetNodeNumber(paras[para][0], paras[para][1]).NUM;
		num2 = GetNodeNumber(paras[para][1], paras[para][0]).NUM;
		// printf("num1:%d, num2:%d\n", num1, num2);
		printf("%d\n", num1 * num2);
	}
}

void Init(){
	for(int i = 0; i <= total_node_number; ++i){
		for(Node *p = link[i].next_, *q; p; p = q){
			q = p->next_;
			delete p;
		}
		link[i].next_ = NULL;
		paras[i][2] = 0;
	}
}

pair<int, int> GetNodeNumber(int node, int father){
	pair<int, int> result(0, 0), tmp;
	bool mark = false;
	// printf("node:%d, fahter:%d, number:%d, mark:%d\n", node, father, result.NUM, result.MARK);
	for(Node *p = link[node].next_; p; p = p->next_){
		if(p->number_ == father){
			if(p->mark_)
				mark = true;
			continue;
		}
		tmp = GetNodeNumber(p->number_, node);
		result.MARK += tmp.MARK;
		if(tmp.MARK)
			result.NUM = tmp.NUM;
		if(!result.MARK)
			result.NUM += tmp.NUM;
	}
	if(result.MARK > 1)
		result.NUM = 0;
	if(result.MARK == 0){
		result.NUM++;
		if(mark)
			result.MARK = 1;
	}
	// printf("node:%d, fahter:%d, number:%d, mark:%d\n", node, father, result.NUM, result.MARK);
	return result;
}