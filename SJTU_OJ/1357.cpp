#include "cstdio"
#define SIZE 30

char matrix[SIZE];

int queue[10], head, tail;

bool IsLink(int node1, int node2){
	int big = node1 > node2 ? node1 : node2;
	int small = node1 < node2 ? node1 : node2;
	int tmp = node1 > node2 ? (node1 - node2) : (node2 - node1);
	if(small % 5 == 4 && big % 5 == 0)
		return false;
	return (tmp == 1 || tmp == 5);
}

bool IsValid(int nodes[10]){
	int h_num = 0;

	for(int i = 1; i <= 7; ++i){
		h_num += (matrix[nodes[i]] == 'H');
		if(h_num > 3)
			return false;
	}
	return true;
	head = 0;
	tail = 1;
	queue[0] = 1;
	bool flag[10] = {0, 1};
	for(; head < tail && tail < 7; head++)
		for(int i = 1; i <= 7; ++i){
			if(!flag[i] && IsLink(nodes[i], nodes[queue[head]])){
				flag[i] = true;
				queue[tail++] = i;
			}
		}
	// if(tail == 7){
	// 	// for(int i = 0; i < 7; ++i)
	// 	for(int i = 1; i <= 7; ++i)
	// 		printf("%c", matrix[nodes[i]]);
	// 	for(int i = 1; i <= 7; ++i)
	// 		printf("%d ", nodes[i]);
	// 	printf("\n");
	// }

	return (tail == 7);
}

int main(){
	for(int i = 0; i < 5; ++i)
		scanf("%s", matrix + i*5);
	int i[10] = {};
	// printf("asd%d\n", IsValid(i));
	int result = 0;
	// printf("%s\n", matrix);
	for(i[1] = 0; i[1] < 25; ++i[1]){
		for(i[2] = i[1] + 1; i[2] < 25; ++i[2]){
			for(i[3] = i[2] + 1; i[3] < 25; ++i[3]){
				for(i[4] = i[3] + 1; i[4] < 25; ++i[4]){
					for(i[5] = i[4] + 1; i[5] < 25; ++i[5]){
						for(i[6] = i[5] + 1; i[6] < 25; ++i[6]){
							for(i[7] = i[6] + 1; i[7] < 25; ++i[7]){
								if(IsValid(i))
									result++;
							}
						}
					}
				}
			}
		}
	}
	printf("%d", result);
	return 0;
}
