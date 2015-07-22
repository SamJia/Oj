#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define SIZE 600060

int glamor[SIZE], l_son[SIZE], r_son[SIZE], depth[SIZE];
int total_number = 0, group_number, command_number, command, para1, para2;

void Merge(int root, int para1, int para2);
int SortAndGetDepth(int root);

int main(){
	scanf("%d%d", &group_number, &command_number);
	// cin >> group_number >> command_number;
	total_number = group_number;
	for(int i = 0; i < group_number; ++i){
		r_son[i] = total_number;
		l_son[total_number] = r_son[total_number] = -1;
		// cin >> glamor[total_number++];
		scanf("%d", &glamor[total_number++]);
	}
	for(int i = 0; i < command_number; ++i){
		// cin >> command;
		scanf("%d", &command);
		if(command == 0){
			scanf("%d%d", &para1, &para2);
			// cin >> para1 >> para2;
			Merge(para1, r_son[para1], r_son[para2]);
			SortAndGetDepth(r_son[para1]);
		}
		else if(command == 1){
			scanf("%d", &para1);
			// cin >> para1;
			if(r_son[para1] == -1){
				cout << "-1\n";
				continue;
			}
			// cout << glamor[r_son[para1]] << '\n';
			printf("%d\n", glamor[r_son[para1]]);
			Merge(para1, l_son[r_son[para1]], r_son[r_son[para1]]);
			SortAndGetDepth(r_son[para1]);
		}
		else{
			l_son[total_number] = r_son[total_number] = -1;
			scanf("%d%d", &para1, &glamor[total_number]);
			// cin >> para1 >> glamor[total_number];
			Merge(para1, r_son[para1], total_number++);
			SortAndGetDepth(r_son[para1]);
		}
	}
	return 0;
}

void Merge(int root, int para1, int para2){
	while(para1 != -1 && para2 != -1){
		if (glamor[para2] < glamor[para1]){
			r_son[root] = para2;
			para2 = r_son[para2];
		}
		else{
			r_son[root] = para1;
			para1 = r_son[para1];
		}
		root = r_son[root];
	}
	if(para1 == -1)
		r_son[root] = para2;
	else
		r_son[root] = para1;
}

int SortAndGetDepth(int root){
	if(root == -1)
		return -1;
	int l_depth = -1, r_depth =  SortAndGetDepth(r_son[root]);
	if(l_son[root] != -1)
		l_depth = depth[l_son[root]];
	if(l_depth < r_depth){
		int tmp = l_son[root];
		l_son[root] = r_son[root];
		r_son[root] = tmp;
	}
	depth[root] = min(l_depth, r_depth) + 1;
	return depth[root];
}
