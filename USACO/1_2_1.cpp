/*
ID: sammail1
PROG: milk2
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 5100
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x,y) ((x)<0?-(x):(x))

pair<int, int> inteval[SIZE];
int total_inteval_number;
int max_milk_time = 0, max_no_milk_time = 0, start_time, end_time;

int main(){
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	scanf("%d", &total_inteval_number);
	for(int i = 0; i < total_inteval_number; ++i)
		scanf("%d%d", &inteval[i].first, &inteval[i].second);
	sort(inteval, inteval + total_inteval_number);
	start_time = inteval[0].first;
	end_time = inteval[0].second;
	for(int i = 1; i < total_inteval_number; ++i){
		if(inteval[i].first > end_time){
			max_milk_time = MAX(max_milk_time, end_time - start_time);
			max_no_milk_time = MAX(max_no_milk_time, inteval[i].first - end_time);
			start_time = inteval[i].first;
		}
		end_time = MAX(end_time, inteval[i].second);
	}
	max_milk_time = MAX(max_milk_time, end_time - start_time);
	printf("%d %d\n", max_milk_time, max_no_milk_time);
	return 0;
}