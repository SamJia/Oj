/*
ID: sammail1
PROG: combo
LANG: C++
*/
#include <cstdio>
#define SIZE 55
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x,y) ((x)<0?-(x):(x))

int total_number;
int password[2][3], diff[3];

int Same(int number1, int number2){
	if (number1 < number2){
		int tmp = number1;
		number1 = number2;
		number2 = tmp;
	}
	int difference = MIN(number1 - number2, number2 + total_number - number1);
	return MIN(MAX(0, 5 - difference), total_number);
}

int main(){
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
	scanf("%d", &total_number);
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 3; ++j)
			scanf("%d", &password[i][j]);
	for(int i = 0; i < 3; ++i)
		diff[i] = Same(password[0][i], password[1][i]);
	int possibility = MIN(5, total_number);
	printf("%d\n", 2 * possibility * possibility * possibility - diff[0] * diff[1] * diff[2]);
	return 0;
}