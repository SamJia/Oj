#include <cstdio>
#define SIZE 100010
int l_son[2][SIZE] = {}, r_son[2][SIZE] = {}, father[2][SIZE] = {}, value[2][SIZE] = {}, queue[2][SIZE];
int total_node_number[2], node1, node2, tmp_value, root[2];

bool Check(int root1, int root2);

int main(){
	scanf("%d", &total_node_number[0]);
	for(int i = 1; i <= total_node_number[0]; ++i){
		scanf("%d%d%d", &node1, &node2, &tmp_value);
		l_son[0][i] = node1;
		r_son[0][i] = node2;
		value[0][i] = tmp_value;
		father[0][node1] = father[0][node2] = i;
	}
	for(root[0] = 1; father[0][root[0]]; ++root[0]);

	scanf("%d", &total_node_number[1]);
	for(int i = 1; i <= total_node_number[1]; ++i){
		scanf("%d%d%d", &node1, &node2, &tmp_value);
		l_son[1][i] = node1;
		r_son[1][i] = node2;
		value[1][i] = tmp_value;
		father[1][node1] = father[1][node2] = i;
	}
	for(root[1] = 1; father[1][root[1]]; ++root[1]);

	printf("%c", Check(root[0], root[1]) ? 'Y' : 'N');
	return 0;
}

bool Check(int root1, int root2){
	if(!(root1 || root2)) // root1 = root2 = 0
		return true;
	if(!(root1 && root2)) // one of them is 0
		return false;
	return (Check(l_son[0][root1], l_son[1][root2]) && value[0][root1] == value[1][root2] && Check(r_son[0][root1], r_son[1][root2]));
}