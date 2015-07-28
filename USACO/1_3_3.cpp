/*
ID: sammail1
PROG: crypt1
LANG: C++
*/
#include <cstdio>
#define SIZE 50
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x,y) ((x)<0?-(x):(x))

bool ok[SIZE] = {};
int total_ok_number, tmp, result = 0;
int pow10[] = {1, 10, 100, 1000, 10000, 100000};

bool Check(int number, int length){
	if(number < pow10[length - 1] || number >= pow10[length])
		return false;
	for(; number; number /= 10)
		if(!ok[number % 10])
			return false;
	return true;
}

int main(){
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	scanf("%d", &total_ok_number);
	for(int i = 0; i < total_ok_number; ++i){
		scanf("%d", &tmp);
		ok[tmp] = true;
	}
	for(int i = 100; i < 1000; ++i)
		for(int j = 10; j < 100; ++j)
			if(Check(i, 3) && Check(j, 2) && Check(i * (j % 10), 3) && 
				Check(i * (j / 10), 3) && Check(i * j, 4))
				++result;
	printf("%d\n", result);
	return 0;
}