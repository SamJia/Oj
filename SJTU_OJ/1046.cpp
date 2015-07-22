#include <cstdio>
#define SIZE 100010
int l_son[SIZE] = {}, r_son[SIZE] = {}, father[SIZE] = {}, is_red[SIZE] = {}, red_number[SIZE] = {}, node_number[SIZE] = {};
int total_number, color_number, query_number;
int root, son1, son2, to_color, tmp_number;

int FindSonNumber(int root);
int FindRedNumber(int root);

int main(){
	scanf("%d%d%d", &total_number, &color_number, &query_number);
	for(int i = 0; i < total_number; ++i){
		scanf("%d%d%d", &root, &son1, &son2);
		l_son[root] = son1;
		r_son[root] = son2;
		father[son1] = father[son2] = root;
		// node_number[son1] = node_number[son2] = 1;
		tmp_number = bool(son1) + bool(son2);
		// if(tmp_number)
		// 	for(; root; root = father[root])
		// 		node_number[root] += tmp_number;
	}
	for(int i = 1; i <= total_number; ++i)
		if(father[i] == 0)
			node_number[i] = FindSonNumber(i) + 1;
	// for(int i = 1; i <= total_number; ++i)
	// 	printf("%d:%d ", i, node_number[i]);
	node_number[0] = 0;
	for(int i = 0; i < color_number; ++i){
		scanf("%d%d", &root, &to_color);
		to_color %= node_number[root];
		while(to_color != node_number[l_son[root]]){
			if(to_color < node_number[l_son[root]])
				root = l_son[root];
			else{
				to_color -= (node_number[l_son[root]] + 1);
				root = r_son[root];
			}
		}
		is_red[root] = 1;
		// if(!is_red[root]){
		// 	is_red[root] = 1;
		// 	for(; root; root = father[root])
		// 		++red_number[root];
		// }
	}
	for(int i = 1; i <= total_number; ++i)
		if(father[i] == 0)
			red_number[i] = FindRedNumber(i);
	// for(int i = 1; i <= total_number; ++i)
	// 	printf("%d:%d ", i, red_number[i]);
	for(int i = 0; i < query_number; ++i){
		scanf("%d", &root);
		printf("%d\n", red_number[root]);
	}
	return 0;
}

int FindSonNumber(int root){
	if(l_son[root])
		node_number[l_son[root]] = FindSonNumber(l_son[root]) + 1;
	if(r_son[root])
		node_number[r_son[root]] = FindSonNumber(r_son[root]) + 1;
	return node_number[l_son[root]] + node_number[r_son[root]]; 
}

int FindRedNumber(int root){
	if(l_son[root])
		red_number[l_son[root]] = FindRedNumber(l_son[root]);
	if(r_son[root])
		red_number[r_son[root]] = FindRedNumber(r_son[root]);
	return red_number[l_son[root]] + red_number[r_son[root]] + is_red[root]; 
}