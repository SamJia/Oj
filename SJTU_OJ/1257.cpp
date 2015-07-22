#include "cstdio"
#define SIZE 100100
int l_son[SIZE] = {}, r_son[SIZE] = {}, father[SIZE] = {};
int total_command_number, command, para1, para2, para3;

void Insert(int root, int left, int right);
void Query(int node);
void SwapTree(int node);
void PreOrderTraverse(int root);

template <typename T>
void Swap(T &a, T &b);


int main(){
	father[1] = 1;
	scanf("%d", &total_command_number);
	for(int i = 0; i < total_command_number; ++i){
		scanf("%d", &command);
		if(command == 1){
			scanf("%d%d%d", &para1, &para2, &para3);
			Insert(para1, para2, para3);
		}
		else if(command == 2){
			scanf("%d", &para1);
			Query(para1);
		}
		else if(command == 3){
			scanf("%d", &para1);
			SwapTree(para1);
		}
	}
	PreOrderTraverse(1);
	return 0;
}

void Insert(int root, int left, int right){
	if(!father[root] || l_son[root] || r_son[root] || father[left] || father[right] || left == right){
		printf("Error!\n");
		return;
	}
	l_son[root] = left;
	r_son[root] = right;
	father[left] = father[right] = root;
	printf("Ok!\n");
}

void Query(int node){
	if(!father[node]){
		printf("Error!\n");
		return;
	}
	printf("%d %d %d\n", node == 1 ? 0 : father[node], l_son[node], r_son[node]);
}

void SwapTree(int node){
	if(!father[node] || node == 1){
		printf("Error!\n");
		return;
	}
	Swap(l_son[father[node]], r_son[father[node]]);
	printf("%d\n", l_son[father[node]] + r_son[father[node]] - node);
}

template <typename T>
void Swap(T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp;
}

void PreOrderTraverse(int root){
	printf("%d ", root);
	if(l_son[root])
		PreOrderTraverse(l_son[root]);
	if(r_son[root])
		PreOrderTraverse(r_son[root]);
}