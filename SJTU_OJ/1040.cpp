#include <cstdio>
#include <iostream>
using namespace std;
#define SIZE 1000100
#define LEFT first
#define RIGHT second

pair<int, int> tree[SIZE] = {};
int queue[SIZE] = {}, node_number;

main(){
	scanf("%d", &node_number);
	int root;
	for(int i = 0; i < node_number; ++i){
		scanf("%d", &root);
		if(tree[root].LEFT)
			tree[root].RIGHT = i;
		else
			tree[root].LEFT = i;
	}
	int head = 0, tail = 1;
	while(head < tail){
		printf("%d ", queue[head]);
		if(tree[head].LEFT)
			queue[tail++] = tree[head].LEFT;
		if(tree[head].RIGHT)
			queue[tail++] = tree[head].RIGHT;
	}
}