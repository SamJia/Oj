/*
ID: sammail1
PROG: subset
LANG: C++
*/
#include <cstdio>
#define SIZE 1000
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

int total_number, require_sum, total_sum;
long long result[SIZE] = {1};

int main(){
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	scanf("%d", &total_number);
	total_sum = total_number * (total_number + 1) / 2;
	if(total_sum % 2 != 0){
		printf("0\n");
		return 0;
	}
	require_sum = total_sum / 2;
	for(int i = 1; i <= total_number; ++i){
		for(int j = SIZE - 100; j >= 0; --j)
			result[j + i] += result[j];
	}
	printf("%lld\n", result[require_sum] / 2);
}