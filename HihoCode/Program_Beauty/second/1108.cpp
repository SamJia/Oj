#include <cstdio>
#include <iostream>
#define SIZE 110
using namespace std;

pair<int, int> link[SIZE][SIZE];
int linked_number[SIZE] = {};
int total_node_number, total_query_number, node1, node2, dis;
int result[SIZE], queue[SIZE];

void Init();
void Compute();
	
int main(){
	scanf("%d", &total_node_number);
	for(int i = 1; i < total_node_number; ++i){
		scanf("%d%d%d", &node1, &node2, &dis);
		link[node1][linked_number[node1]].first = node2;
		link[node1][linked_number[node1]++].second = dis;
		link[node2][linked_number[node2]].first = node1;
		link[node2][linked_number[node2]++].second = dis;
	}
	scanf("%d", &total_query_number);
	for(int i = 0; i < total_query_number; ++i){
		scanf("%d%d", &node1, &node2);
		Init();
		Compute();
		printf("%d\n", result[node2]);
	}
	return 0;
}

void Init(){
	for(int i = 1; i <= total_node_number; ++i)
		result[i] = -1;
	result[node1] = 0;
	queue[0] = node1;
}

void Compute(){
	for(int queue_head = 0, queue_tail = 1, node = queue[0]; true; node = queue[++queue_head]){
		for(int i = 0; i < linked_number[node]; ++i)
			if(result[link[node][i].first] == -1){
				result[link[node][i].first] = result[node] + link[node][i].second;
				if(link[node][i].first == node2)
					return;
				queue[queue_tail++] = link[node][i].first;
			}
	}
}