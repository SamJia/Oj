/*
ID: sammail1
PROG: castle
LANG: C++
*/
#include <cstdio>
#define SIZE 60
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

int total_row_number, total_colomn_number, total_room_number = 0;
int wall[SIZE][SIZE], room[SIZE][SIZE] = {}, number[SIZE*SIZE] = {};
int result, pos_x, pos_y, direction;

void DFS(int x, int y){
	room[x][y] = total_room_number;
	++number[total_room_number];
	if(y > 0 && !(wall[x][y] & 1) && !room[x][y-1])
		DFS(x, y - 1);
	if(x > 0 && !(wall[x][y] & 2) && !room[x-1][y])
		DFS(x - 1, y);
	if(y < total_colomn_number - 1 && !(wall[x][y] & 4) && !room[x][y+1])
		DFS(x, y + 1);
	if(x < total_row_number - 1 && !(wall[x][y] & 8) && !room[x+1][y])
		DFS(x + 1, y);
}

int main(){
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	scanf("%d%d", &total_colomn_number, &total_row_number);
	for(int i = 0; i < total_row_number; ++i)
		for(int j = 0; j < total_colomn_number; ++j)
			scanf("%d", &wall[i][j]);
	for(int i = 0; i < total_row_number; ++i)
		for(int j = 0; j < total_colomn_number; ++j)
			if(!room[i][j]){
				++total_room_number;
				DFS(i, j);
			}
	// for(int i = 0; i < total_row_number; ++i){
	// 	for(int j = 0; j < total_colomn_number; ++j)
	// 		printf("%d ", room[i][j]);
	// 	printf("\n");
	// }
	printf("%d\n", total_room_number);
	result = 0;
	for(int i = 1; i <= total_room_number; ++i)
		result = MAX(number[i], result);
	printf("%d\n", result);
	result = 0;
	for(int j = 0; j < total_colomn_number; ++j)
		for(int i = total_row_number - 1; i >= 0; --i){
			if(i > 0 && room[i][j] != room[i-1][j] && number[room[i][j]] + number[room[i-1][j]] > result){
				result = number[room[i][j]] + number[room[i-1][j]];
				pos_x = i;
				pos_y = j;
				direction = 2;
			}
			if(j < total_colomn_number - 1 && room[i][j] != room[i][j+1] && number[room[i][j]] + number[room[i][j+1]] > result){
				result = number[room[i][j]] + number[room[i][j+1]];
				pos_x = i;
				pos_y = j;
				direction = 4;
			}
		}
	printf("%d\n", result);
	printf("%d %d %c\n", pos_x + 1, pos_y + 1, (direction == 2 ? 'N' : 'E'));
	return 0;
}