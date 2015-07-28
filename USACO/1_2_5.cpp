/*
ID: sammail1
PROG: dualpal
LANG: C++
*/
#include <cstdio>
#include <cstring>
#define SIZE 20
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x,y) ((x)<0?-(x):(x))

char number[SIZE];
int output_number, min_number;

void Change(int num, int base){
	int i;
	for(i = 0; num; num /= base, ++i)
		number[i] = num % base + '0';
	number[i] = '\0';
}

int Pal(){
	int len = strlen(number);
	for(int i = 0; i < len - i - 1; ++i)
		if(number[i] != number[len - i - 1])
			return 0;
	return 1;
}

bool Check(int num){
	int right_number = 0;
	for(int i = 2; i <= 10; ++i){
		Change(num, i);
		right_number += Pal();
	}
	return right_number >= 2;
}

int main(){
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	scanf("%d%d", &output_number, &min_number);
	for(int i = min_number+1; output_number; ++i){
		if(Check(i)){
			printf("%d\n", i);
			--output_number;
		}
	}
	return 0;
}