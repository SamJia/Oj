/*
ID: sammail1
PROG: palsquare
LANG: C++
*/
#include <cstdio>
#include <cstring>
#define SIZE 20
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x,y) ((x)<0?-(x):(x))

char number[SIZE], square[SIZE];
int base;
char map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

void Change(int num){
	int squ = num * num, i;
	for(i = 0; num; num /= base, ++i)
		number[i] = map[num % base];
	number[i] = '\0';
	int len = strlen(number);
	char tmp;
	for(i = 0; i < len - i - 1; ++i){
		tmp = number[i];
		number[i] = number[len - i - 1];
		number[len - i - 1] = tmp;
	}
	for(i = 0; squ; squ /= base, ++i)
		square[i] = map[squ % base];
	square[i] = '\0';
}

bool Check(){
	int len = strlen(square);
	for(int i = 0; i < len - i - 1; ++i)
		if(square[i] != square[len - i - 1])
			return false;
	return true;
}

int main(){
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	scanf("%d", &base);
	for(int i = 1; i <= 300; ++i){
		Change(i);
		if(Check())
			printf("%s %s\n", number, square);
	}
	return 0;
}