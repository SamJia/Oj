#include <iostream>
#include <algorithm>
#include <cstdio>
#define SIZE 2510
using namespace std;

int numbers[SIZE] = {0x7fffffff};
int total_number, total_query_number, query;

bool Exist();

int main(){
	scanf("%d", &total_number);
	for(int i = 0; i < total_number; ++i)
		scanf("%d", numbers + i);
	sort(numbers, numbers + total_number);
	scanf("%d", &total_query_number);
	for(int i = 0; i < total_query_number; ++i){
		scanf("%d", &query);
		printf("%c\n", Exist() ? 'Y' : 'N');
	}
	return 0;
}

bool Exist(){
	for(int begin = 0, end = total_number, mid; begin < end;){
		mid = (begin + end) / 2;
		if(numbers[mid] < query)
			begin = mid + 1;
		else if(numbers[mid] == query)
			return true;
		else
			end = mid;
	}
	return false;
}