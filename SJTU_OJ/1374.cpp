#include "cstdio"
#include <iostream>
#define SIZE 210
#define SIZE2 400000
using namespace std;

struct Node
{
	Node(int node = 0, int len = 0, Node *next = NULL) : node_(node), len_(len), next_(next){}
	int node_, len_;
	Node *next_;	
};

Node in[SIZE], out[SIZE];
int result[SIZE][SIZE] = {};
pair<int, int> queue[SIZE2];
int total_node_number, total_middle_number, total_edge_number, total_query_number;
int node1, node2, len;
int head = 0, tail = 0;
int tmp;
long long total_result_number, total_length;

int main(){
	scanf("%d%d%d%d", &total_node_number, &total_edge_number, &total_middle_number, &total_query_number);
	for(int i = 1; i <= total_node_number; ++i)
		for(int j = 1; j <= total_node_number; ++j)
			result[i][j] = 0x7fffffff;
	for(int i = 0; i < total_edge_number; ++i){
		scanf("%d%d%d", &node1, &node2, &len);
		in[node2].next_ = new Node(node1, len, in[node2].next_);
		out[node1].next_ = new Node(node2, len, out[node1].next_);
	}
	for(int i = 1; i <= total_middle_number; ++i){
		queue[tail].first = queue[tail].second = i;
		tail++;
		result[i][i] = 0;
	}
	// printf("%d %d\n", head, tail);
	for(; head < tail; ++head){
		for(Node *p = in[queue[head].first].next_; p; p = p->next_){
			tmp = result[queue[head].first][queue[head].second] + p->len_;
			// printf("%d %d %d\n", p->node_, queue[head].second, tmp);
			if(result[p->node_][queue[head].second] > tmp){
				result[p->node_][queue[head].second] = tmp;
				queue[tail].first = p->node_;
				queue[tail++].second = queue[head].second;
			}
		}
		for(Node *p = out[queue[head].second].next_; p; p = p->next_){
			tmp = result[queue[head].first][queue[head].second] + p->len_;
			// printf("%d %d %d\n", queue[head].first, p->node_, tmp);
			if(result[queue[head].first][p->node_] > tmp){
				result[queue[head].first][p->node_] = tmp;
				queue[tail].first = queue[head].first;
				queue[tail++].second = p->node_;
			}
		}
	}
	for(int i = 0; i < total_query_number; ++i){
		scanf("%d%d", &node1, &node2);
		if(result[node1][node2] < 0x7fffffff){
			total_result_number++;
			total_length += result[node1][node2];
		}
	}
	printf("%lld\n%lld", total_result_number, total_length);

	return 0;
}