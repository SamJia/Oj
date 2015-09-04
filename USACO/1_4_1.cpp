/*
ID: sammail1
PROG: ariprog
LANG: C++
*/
#include <cstdio>
#define SIZE 130000
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); (x_ > y_ ? x_ : y_)})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); (x_ < y_ ? x_ : y_)})
#define ABS(x) ({typeof(x) x_ = (x); (x_ > 0 ? x_ : -x_)})

int square_length, max_base, max_number;
bool bisquare[SIZE] = {};

void Init(){
	for(int i = 0; i <= max_base; ++i)
		for(int j = i; j <= max_base; ++j)
			bisquare[i*i + j*j] = true;
	max_number = 2 * max_base * max_base;
}

bool Check(int start, int diff){
	for(int i = 0; i < square_length; ++i)
		if(!bisquare[start + diff * i])
			return false;
	return true;
}

int main(){
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	scanf("%d%d", &square_length, &max_base);
	Init();
	bool flag = false;
	for(int i = 1; i <= max_number / (square_length-1); ++i)
		for(int j = 0; j <= max_number - i * (square_length-1); ++j)
			if(Check(j, i)){
				printf("%d %d\n", j, i);
				flag = true;
			}
	if(!flag)
		printf("NONE\n");
	return 0;
}