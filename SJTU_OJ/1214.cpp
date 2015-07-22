#include <cstdio>
#define SIZE 100010
int l_son[SIZE] = {}, r_bro[SIZE] = {}, upper[SIZE] = {}, value[SIZE] = {}, queue[SIZE];
int total_node_number, node1, node2, tmp_value, root;

void FrontTraverse(int node);
void BackTraverse(int node);
void LevelTraverse(int node);

int main(){
	scanf("%d", &total_node_number);
	for(int i = 1; i <= total_node_number; ++i){
		scanf("%d%d%d", &node1, &node2, &tmp_value);
		l_son[i] = node1;
		r_bro[i] = node2;
		value[i] = tmp_value;
		upper[node1] = upper[node2] = i;
	}
	for(root = 1; upper[root]; ++root);
	FrontTraverse(root);
	printf("\n");
	BackTraverse(root);
	printf("\n");
	LevelTraverse(root);
	printf("\n");
	return 0;
}

void FrontTraverse(int node){
	printf("%d ", value[node]);
	for(int i = l_son[node]; i; i = r_bro[i])
		FrontTraverse(i);
}


void BackTraverse(int node){
	for(int i = l_son[node]; i; i = r_bro[i])
		BackTraverse(i);
	printf("%d ", value[node]);
}

void LevelTraverse(int node){
	queue[0] = node;
	for(int head = 0, tail = 1; head < tail; head++){
		printf("%d ", value[queue[head]]);
		for(int i = l_son[queue[head]]; i; i = r_bro[i])
			queue[tail++] = i;
	}
}
