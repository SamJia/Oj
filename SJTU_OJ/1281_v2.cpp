#include <cstdio>
#define SIZE 35

int x_move[8];
int y_move[8];
int map[SIZE][SIZE];
int queue[100000][2];
int head = 0, tail = 1;
int total_row_number, total_colomn_number, jump1, jump2, x_next, y_next;

bool Check(int x, int y){
	return (x >= 0) && (x < total_row_number) && (y >= 0) && (y < total_colomn_number);
}

int bfs(){
	for(; head < tail; ++head){
		for(int i = 0; i < 8; ++i){
			x_next = queue[head][0] + x_move[i];
			y_next = queue[head][1] + y_move[i];
			if(Check(x_next, y_next)){
				if(map[x_next][y_next] == 4)
					return map[queue[head][0]][queue[head][1]] + 1 - 100;
				else if(map[x_next][y_next] == 1){
					map[x_next][y_next] = map[queue[head][0]][queue[head][1]] + 1;
					queue[tail][0] = x_next;
					queue[tail++][1] = y_next;
				}
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d%d%d%d", &total_row_number, &total_colomn_number, &jump1, &jump2);
	x_move[0] = x_move[1] = jump1;
	x_move[2] = x_move[3] = -jump1;
	x_move[4] = x_move[5] = jump2;
	x_move[6] = x_move[7] = -jump2;
	y_move[0] = y_move[2] = jump2;
	y_move[1] = y_move[3] = -jump2;
	y_move[4] = y_move[6] = jump1;
	y_move[5] = y_move[7] = -jump1;
	for(int i = 0; i < total_row_number; ++i)
		for(int j = 0; j < total_colomn_number; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 3){
				queue[0][0] = i;
				queue[0][1] = j;
				map[i][j] = 100;
			}
		}
	printf("%d\n", bfs());

}