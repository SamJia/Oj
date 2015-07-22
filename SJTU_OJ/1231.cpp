#include "cstdio"
#define SIZE 1010000

int father[SIZE] = {};

int total_number, quest1, quest2;
int node1, node2;

int main(){
	scanf("%d%d%d", &total_number, &quest1, &quest2);
	for(int i = 1; i <= total_number; ++i){
		scanf("%d%d", &node1, &node2);
		father[node1] = father[node2] = i;
	}
	int depth1 = 0, depth2 = 0;
	for(int i = quest1; i; i = father[i], ++depth1);
	for(int i = quest2; i; i = father[i], ++depth2);
	for(; depth1 > depth2; quest1 = father[quest1], --depth1);
	for(; depth2 > depth1; quest2 = father[quest2], --depth2);
	for(; quest1 != quest2; quest1 = father[quest1], quest2 = father[quest2]);
	printf("%d\n", quest1);
}