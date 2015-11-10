#include <cstdio>
#define SIZE 650

int total_number;
int square[SIZE][SIZE];
int queue[2 * SIZE], tail = 0;
int sum = 0, tmp;

void Check(int number){
	if(sum != tmp)
		queue[tail++] = number;
}

int main(){
	scanf("%d", &total_number);
	for(int i = 0; i < total_number; ++i)
		for(int j = 0; j < total_number; ++j)
			scanf("%d", &square[i][j]);
	for(int i = 0; i < total_number; ++i)
		sum += square[i][i];
	// column
	for(int j = total_number - 1; j >= 0; --j){
		tmp = 0;
		for(int i = 0; i < total_number; ++i)
			tmp += square[i][j];
		Check(-(j + 1));
	}
	//antidiagonal
	tmp = 0;
	for(int i = 0; i < total_number; ++i)
		tmp += square[i][total_number - 1 - i];
	Check(0);
	// row
	for(int i = 0; i < total_number; ++i){
		tmp = 0;
		for(int j = 0; j < total_number; ++j)
			tmp += square[i][j];
		Check(i + 1);
	}
	printf("%d\n", tail);
	for(int i = 0; i < tail; ++i)
		printf("%d\n", queue[i]);
}