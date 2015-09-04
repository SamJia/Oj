/*
ID: sammail1
PROG: pprime
LANG: C++
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define SIZE 200000
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

int result[SIZE];
int result_numebr = 0;
int lower, upper;

int CreatePalNum(int pal_part, int mid){
	int pal_num = pal_part;
	if(mid >= 0)
		pal_num = pal_num * 10 + mid;
	for(; pal_part; pal_part /= 10)
		pal_num = pal_num * 10 + pal_part % 10;
	return pal_num;
}

bool IsPrime(int num){
	for(int i = 2; i * i <= num; ++i)
		if(num % i == 0)
			return false;
	return true;
}

int main(){
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	scanf("%d%d", &lower, &upper);
	int pal_num;
	for(int i = -1; i < 10; ++i)
		for(int j = 0; j < 10000; ++j){
			pal_num = CreatePalNum(j, i);
			if(lower <= pal_num && pal_num <= upper && IsPrime(pal_num))
				result[result_numebr++] = pal_num;
		}
	sort(result, result + result_numebr);
	for(int i = 0; i < result_numebr; ++i)
		printf("%d\n", result[i]);
	return 0;
}