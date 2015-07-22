#include "cstdio"
#define SIZE 1100000

int father[SIZE] = {}, link[SIZE][4] = {}, road_next[SIZE] = {};
bool broken[SIZE][4] = {};

int total_row_number, quest1, quest2;
int pos, wall, pos2;

void Init(){
	link[1][2] = 2;
	link[1][3] = 3;
	for(int i = 2, k = 2; i <= total_row_number; ++i)
		for(int j = 1; j <= i; ++j, ++k){
			father[i] = -1;
			link[k][0] = j == 1 ? 0 : (k - i);
			link[k][1] = j == i ? 0 : (k - i + 1);
			link[k][2] = i == total_row_number ? 0 : (k + i);
			link[k][3] = i == total_row_number ? 0 : (k + i + 1);
		}
}

// int FindPos(){
// 	if(wall == 0){
// 		if(row[pos-1] != row[pos])
// 			return -1;
// 		return pos - row[pos];
// 	}
// 	else if(wall == 1){
// 		if(row[pos+1] != row[pos])
// 			return -1;
// 		return pos - row[pos] + 1;
// 	}
// 	else if(wall == 2){
// 		if(row[pos + row[pos]] == 0)
// 			return -1;
// 		return pos + row[pos];
// 	}
// 	else if(wall == 3){
// 		if(row[pos + row[pos] + 1] == 0)
// 			return -1;
// 		return pos + row[pos] + 1;
// 	}
// }

int Find(int pos){
	int root = pos;
	for(; father[root] > 0; root = father[root]);
	for(int tmp; pos != root; tmp = father[pos], father[pos] = root, pos = tmp);
	return root;
}

void Union(int pos, int pos2){
	int root1 = Find(pos), root2 = Find(pos2);
	// printf("%d,%d\n", root1, root2);
	if(root1 == root2)
		return;
	if(father[root1] > father[root2]){
		father[root2] += father[root1];
		father[root1] = root2;
	}
	else{
		father[root1] += father[root2];
		father[root2] = root1;
	}
}


bool DFS(int pos){
	if(pos == quest2)
		return true;
	for(int i = 0; i < 4; ++i){
		if(link[pos][i] && !road_next[link[pos][i]] && broken[pos][i]){
			road_next[pos] = link[pos][i];
			if(DFS(link[pos][i]))
				return true;
		}
	}
	road_next[pos] = 0;
	return false;
}

void Output(){
	DFS(quest1);
	for(int i = quest1; i != quest2; i = road_next[i])
		printf("%d ", i);
	printf("%d", quest2);
}

int main(){
	scanf("%d%d%d", &total_row_number, &quest1, &quest2);
	Init();
	while (Find(quest1) != Find(quest2)){
		scanf("%d%d", &pos, &wall);
		if(link[pos][wall] > 0){
			broken[pos][wall] = true;
			broken[link[pos][wall]][3-wall] = true;
			Union(pos, link[pos][wall]);
		}
		// printf("%d,%d\n", );
	}
	Output();
}