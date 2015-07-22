#include <algorithm>
#include <cstdio>
#include <iostream>
#define SIZE 100100
using namespace std;

int total_number;
pair<int,int> times[SIZE];

int main(){
	scanf("%d", &total_number);
	for(int i = 0; i < total_number; ++i)
		scanf("%d%d", &times[i].second, &times[i].first);
	sort(times, times + total_number);
	int result = 0, last_time = 0;
	for(int i = 0; i < total_number; ++i)
		if(times[i].second >= last_time){
			result++;
			last_time = times[i].first;
		}
	printf("%d\n", result);
}