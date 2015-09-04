/*
ID: sammail1
PROG: sprime
LANG: C++
*/
#include <cstdio>
#define SIZE 100000
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

int result[10][SIZE] = {{}, {2, 3, 5, 7}};
int r_number[10] = {0, 4};
int rib;

bool IsPrime(int num){
	for(int i = 2; i * i <= num; ++i)
		if(num % i == 0)
			return false;
	return true;
}

int main(){
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	scanf("%d", &rib);
	int tmp;
	for(int i = 2; i <= rib; ++i)
		for(int j = 0; j < r_number[i-1]; ++j)
			for(int k = 1; k < 10; k += 2){
				tmp = result[i-1][j] * 10 + k;
				if(IsPrime(tmp))
					result[i][r_number[i]++] = tmp;
			}
	for(int i = 0; i < r_number[rib]; ++i)
		printf("%d\n", result[rib][i]);
	return 0;
}