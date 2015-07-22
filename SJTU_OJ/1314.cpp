#include "cstdio"
#define SIZE 110

bool tree[SIZE][SIZE], flag;
int total_test_number, total_node_number, node1, node2;

void Init();

int main(){
	scanf("%d", &total_test_number);
	for(int i = 0; i < total_test_number; ++i){
		Init();
		scanf("%d", &`total_node_number);
		for(int j = 1; j < total_node_number; ++j){
			scanf("%d%d", &node1, &node2);
			tree[node1][node2] = tree[node2][node1] = true;
		}
		scanf("%d", &total_node_number);
		for(int j = 1; j < total_node_number; ++j){
			scanf("%d%d", &node1, &node2);
			if(!tree[node1][node2]){
				flag = false;
				printf("asd\n");
				break;
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}

void Init(){
	for(int i = 0; i < SIZE; ++i)
		for(int j = 0; j < SIZE; ++j)
			tree[i][j] = false;
	flag = true;
}