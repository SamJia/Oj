#include <cstdio>
#include <cstring>

// int board[10][10];

int vertical[20] = {0,0};
int pos[] = {0, 1};
int total_case;
int tmp, total_size, total_piece;
int size, pos1, pos2;
char state;

struct Board {
	Board() : layer(0){}
	int board_[7][7];
	int layer;
	void Print(){
		for(int j = 0; j < total_size; ++j){
			for(int k = 0; k < total_size; ++k)
				printf("%d ", board_[j][k]);
			printf("\n");
		}

	}
};

Board queue[100];
int head = 0, tail = 1;

int BFS(){
	for(; head < tail; ++head){
		if(queue[head].board_[1][total_size-1] == 1)
			return queue[head].layer;
		printf("head:%d\n", head);
		for(int i = 1; i <= total_piece+1; ++i){
			if(vertical[i]){
				int j;
				printf("%d\n", i);
				queue[head].Print();
				for(j = 0; queue[head].board_[j][pos[i]] != i; ++j);
				printf("%d %d\n", j, pos[i]);
				if(j != 0 && queue[head].board_[j-1][pos[i]] == 0){
					queue[tail] = queue[head];
					queue[tail].layer++;
					// queue[tail].board_[j-1][pos[i]] = queue[tail].board_[j][pos[i]];
					// for(j; queue[tail].board_[j][pos[i]] == i; ++j);
					// queue[tail++].board_[j-1][pos[j]] = 0;
				}
				// for(j = 6; queue[head].board_[j][pos[i]] != i; --j);
				// if(j != total_size - 1 && queue[head].board_[j+1][pos[i]] != 0){
				// 	queue[tail] = queue[head];
				// 	queue[tail].layer++;
				// 	queue[tail].board_[j+1][pos[i]] = queue[tail].board_[j][pos[i]];
				// 	for(j; queue[tail].board_[j][pos[i]] == i; --j);
				// 	queue[tail++].board_[j+1][pos[i]] = 0;
				// }
			}
			// else{
			// 	int j;
			// 	for(j = 0; queue[head].board_[pos[i]][j] != i; ++j);
			// 	if(j != 0 && queue[head].board_[pos[i]][j-1] == 0){
			// 		queue[tail] = queue[head];
			// 		queue[tail].layer++;
			// 		queue[tail].board_[pos[i]][j-1] = queue[tail].board_[pos[i]][j];
			// 		for(j; queue[tail].board_[pos[i]][j] == i; ++j);
			// 		queue[tail++].board_[pos[j]][j-1] = 0;
			// 	}
			// 	for(j = 6; queue[head].board_[pos[i]][j] != i; --j);
			// 	if(j != total_size - 1 && queue[head].board_[pos[i]][j+1] != 0){
			// 		queue[tail] = queue[head];
			// 		queue[tail].layer++;
			// 		queue[tail].board_[pos[i]][j+1] = queue[tail].board_[pos[i]][j];
			// 		for(j; queue[tail].board_[pos[i]][j] == i; --j);
			// 		queue[tail++].board_[pos[i]][j+1] = 0;
			// 	}
			// }
		}
	}
}


int main(){
	scanf("%d", &total_case);
	for(int i = 0; i < total_case; ++i){
		memset(queue[0].board_, 0, sizeof(queue[0].board_[0][0]) * 10 * 10);
		scanf("%d", &tmp);
		queue[0].board_[1][tmp] = queue[0].board_[1][tmp+1] = 1;
		scanf("%d%d", &total_size, &total_piece);
		for(int j = 0; j < total_piece; ++j){
			scanf("%d %c %d%d", &size, &state, &pos1, &pos2);
			if(state == 'V'){
				vertical[j+2] = 1;
				pos[j+2] = pos2;
				for(int k = 0; k < size; ++k)
					queue[0].board_[pos1+k][pos2] = j+2;
			}
			else{
				pos[j+2] = pos1;
				for(int k = 0; k < size; ++k){
					// printf("%d %d\n", pos1, pos2+k);
					queue[0].board_[pos1][pos2+k] = j+2;
				}
				// printf("123\n");
			}
		}
		printf("%d\n", BFS());
	}
	// printf("exit\n");
}