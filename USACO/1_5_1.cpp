/*
ID: sammail1
PROG: numtri
LANG: C++
*/
#include <cstdio>
#define SIZE 1100
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

int triangle[SIZE][SIZE];
int total_row_number;
int result[SIZE][SIZE];

int main(){
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	scanf("%d", &total_row_number);
	for(int i = 0; i < total_row_number; ++i)
		for(int j = 0; j <= i; ++j)
			scanf("%d", &triangle[i][j]);
	result[0][0] = triangle[0][0];
	for(int i = 0; i < total_row_number - 1; ++i)
		for(int j = 0; j <= i; ++j){
			result[i+1][j] = MAX(result[i+1][j], result[i][j] + triangle[i+1][j]);
			result[i+1][j+1] = MAX(result[i+1][j+1], result[i][j] + triangle[i+1][j+1]);
		}
	int max_result = 0;
	for(int i = 0; i < total_row_number; ++i)
		max_result = MAX(max_result, result[total_row_number-1][i]);
	printf("%d\n", max_result);
	return 0;
}