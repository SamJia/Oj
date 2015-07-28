/*
ID: sammail1
PROG: barn1
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 250
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x,y) ((x)<0?-(x):(x))

int total_board_number, total_stall_number, total_occupied_number, result;
int occupied_stall[SIZE], diff[SIZE] = {};

int main(){
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	scanf("%d%d%d", &total_board_number, &total_stall_number, &total_occupied_number);
	for(int i = 0; i < total_occupied_number; ++i)
		scanf("%d", &occupied_stall[i]);
	sort(occupied_stall, occupied_stall + total_occupied_number);
	result = occupied_stall[total_occupied_number - 1] - occupied_stall[0] + 1;
	for(int i = 0; i < total_occupied_number - 1; ++i)
		diff[i] = occupied_stall[i + 1] - occupied_stall[i] - 1;
	sort(diff, diff + total_occupied_number - 1, greater<int>());
	for(int i = 0; i < total_board_number - 1; ++i)
		result -= diff[i];
	printf("%d\n", result);
	return 0;
}