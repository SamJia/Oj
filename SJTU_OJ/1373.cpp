#include "cstdio"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#define SIZE 510
using namespace std;

int height[SIZE*SIZE];
int is_flag[SIZE*SIZE];
pair<int, int> link[2*SIZE*SIZE], diff[2*SIZE*SIZE];
int total_path = 0, root, total_flag_number = 0;
pair<int, int> father[SIZE*SIZE];
int row, colomn;
bool IsOk(int x, int y){
	return (x >= 0 && x < row && y >= 0 && y < colomn);
}

void Init(){
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < colomn; ++j){
			father[i * colomn + j].first = i * colomn + j;
			father[i * colomn + j].second = 0;
		}
}

int Find(int node){
	if(father[node].first == node)
		return node;
	else
		return father[node].first = Find(father[node].first);
}

int Union(int root1, int root2){
	if(root1 == root2)
		return root1;
	father[root1].first = root2;
	father[root2].second += father[root1].second;
	return root2;
}


int main(){
	scanf("%d%d", &row, &colomn);
	Init();
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < colomn; ++j)
			scanf("%d", &height[i * colomn + j]);
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < colomn; ++j){
			scanf("%d", &is_flag[i * colomn + j]);
			if(is_flag[i * colomn + j]){
				total_flag_number++;
				father[i * colomn + j].second = 1;
			}
		}

	for(int i = 0; i < row; ++i)
		for(int j = 1; j < colomn; ++j){
			diff[total_path] = pair<int, int>((int)abs(height[i * colomn + j] - height[i * colomn + (j - 1)]), total_path);
			link[total_path++] = pair<int, int>(i * colomn + j, i * colomn + (j - 1));
		}
	for(int i = 1; i < row; ++i)
		for(int j = 0; j < colomn; ++j){
			diff[total_path] = pair<int, int>((int)abs(height[i * colomn + j] - height[(i - 1) * colomn + j]), total_path);
			link[total_path++] = pair<int, int>(i * colomn + j, (i - 1) * colomn + j);
		}
	sort(diff, diff + total_path);
	for(int i = 0; i < total_path; ++i){
		root = Union(Find(link[diff[i].second].first), Find(link[diff[i].second].second));
		// printf("%d %d\n", father[root].second, total_flag_number);
		if (father[root].second == total_flag_number){
			printf("%d\n", diff[i].first);
			return 0;
		}
	}
	return 0;
}