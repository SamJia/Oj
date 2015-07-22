#include "cstdio"
#include "cstring"
#define SIZE 20100

int link_number[SIZE], border[SIZE][2], father[SIZE], father_default[SIZE], node_number[SIZE], node_number_default[SIZE];
bool require[SIZE];
int total_node_number, total_test_number, total_border_number, para, result;

void Init();
int Compute();
void Swap(int &a, int &b);
int getFather(int node);

int main(){
	for(int i = 0; i < SIZE; ++i){
		father_default[i] = i;
		node_number_default[i] = 1;
	}
	scanf("%d", &total_test_number);
	for(int i = 0; i < total_test_number; ++i){
		scanf("%d%d", &total_node_number, &total_border_number);
		Init();
		for(int j = 0; j < total_node_number - 1; ++j)
			scanf("%d%d", &border[j][0], &border[j][1]);
		for(int j = 0; j < total_border_number; ++j){
			scanf("%d", &para);
			require[para] = 1;
		}
		result = Compute();
		printf("%d\n", result);
	}
	return 0;
}

void Init(){
	memset(link_number, 0, sizeof(link_number[0]) * (total_node_number + 10));
	memset(require, 0, sizeof(require[0]) * (total_node_number + 10));
	memcpy(father, father_default, sizeof(father[0]) * (total_node_number + 10));
	memcpy(node_number, node_number_default, sizeof(node_number[0]) * (total_node_number + 10));
}

int Compute(){
	int father1, father2;
	for(int i = 0; i < total_node_number - 1; ++i){
		father1 = getFather(border[i][0]);
		father2 = getFather(border[i][1]);
		if(father1 > father2)
			Swap(father1, father2);
		if(require[i]){
			link_number[father1]++;
			link_number[father2]++;
		}
		else{
			father[father1] = father2;
			node_number[father2] += node_number[father1];
			link_number[father2] += link_number[father1];
			link_number[father1] = 0;
		}
	}
	int nums[100] = {};
	for(int i = 1; i <= total_node_number; ++i){
		if(link_number[i] > 2 || nums[0] > 2)
			return 0;
		if(link_number[i] == 1)
			nums[++nums[0]] = node_number[i];
	}
	return nums[1] * nums[2];
}

void Swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int getFather(int node){
	if(father[father[node]] != father[node])
		father[node] = getFather(father[node]);
	return father[node];
}