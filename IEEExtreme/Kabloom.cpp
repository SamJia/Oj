#include <cstdio>
#include <cstring>
#define SIZE 1010
#define MAX(x,y) ((x)>(y)?(x):(y))

int total_number;
char card[SIZE][2];
int points[SIZE] = {};
int most_point[SIZE][SIZE] = {};

void Init(){
	points['A'] = 20;
	points['J'] = points['Q'] = points['K'] = 15;
	for(int i = '2'; i <= '9'; ++i)
		points[i] = i - '0';
	points['T'] = 10;
	points['R'] = 50;
}

int Match(int num1, int num2){
	if(card[num1][0] == card[num2][1])
		return points[card[num1][0]];
	else if(card[num1][0] == 'R' || card[num2][1] == 'R')
		return points[card[num1][0] + card[num2][1] - 'R'];
	return 0;
}

int main(){
	Init();
	for(scanf("%d", &total_number); total_number; scanf("%d", &total_number)){
		memset(most_point, 0, sizeof(most_point[0][0]) * SIZE * SIZE);
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < total_number; ++j)
				scanf(" %c", &card[j][i]);
		int tmp;
		for(int i = 1; i <= total_number; ++i)
			for(int j = 1; j <= total_number; ++j){
				most_point[i][j] = MAX(most_point[i-1][j], most_point[i][j-1]);
				tmp = most_point[i-1][j-1] + Match(i-1, j-1);
				most_point[i][j] = MAX(most_point[i][j], tmp);
			}
		printf("%d\n", 2 * most_point[total_number][total_number]);
	}

}