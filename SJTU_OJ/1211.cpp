#include <cstdio>
#define SIZE 100010
int l_son[SIZE] = {}, r_son[SIZE] = {}, father[SIZE] = {}, queue[SIZE];
int total_node_number, node1, node2, root;

int main(){
	scanf("%d", &total_node_number);
	for(int i = 1; i <= total_node_number; ++i){
		scanf("%d%d", &node1, &node2);
		l_son[i] = node1;
		r_son[i] = node2;
		father[node1] = father[node2] = i;
	}
	for(root = 1; father[root]; ++root);
	queue[0] = root;
	for(int queue_head = 0, queue_tail = 1, node = queue[0], get_leaf = 0; queue_head < queue_tail; node = queue[++queue_head]){
		if(l_son[node]){
			if(get_leaf){
				printf("N");
				return 0;
			}
			queue[queue_tail++] = l_son[node];
		}
		else
			get_leaf = 1;
		if(r_son[node]){
			if(get_leaf){
				printf("N");
				return 0;
			}
			queue[queue_tail++] = r_son[node];
		}
		else
			get_leaf = 1;
	}
	printf("Y");
	return 0;
}