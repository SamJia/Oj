/*
ID: sammail1
PROG: skidesign
LANG: C++
*/
#include <cstdio>
#define SIZE 1100
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

int total_hill_number, result = 0x7fffffff, height[SIZE];

int FindCost(int low, int high){
	int tmp_result = 0;
	for(int i = 0; i < total_hill_number; ++i){
		if(height[i] < low)
			tmp_result += (low - height[i]) * (low - height[i]);
		else if(height[i] > high) 
			tmp_result += (height[i] - high) * (height[i] - high);
	}
	return tmp_result;
}

int main(){
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
	scanf("%d", &total_hill_number);
	for(int i = 0; i < total_hill_number; ++i)
		scanf("%d", &height[i]);
	for(int i = 0; i <= 100 - 17; ++i)
		result = MIN(result, FindCost(i, i + 17));
	printf("%d\n", result);
	return 0;
}