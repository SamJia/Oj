#include <cstdio>
#define SIZE 1001000
#define A 1
#define B 2
#define C 5

int total_test_number, query;
long long result[SIZE][3] = {1};

int main(){
	for(int i = 0; i < SIZE - 100; ++i){
		result[i+A][0] += result[i][0];
		result[i+B][1] += result[i][0];
		result[i+C][2] += result[i][0];

		result[i+B][1] += result[i][1];
		result[i+C][2] += result[i][1];

		result[i+C][2] += result[i][2];
	}

	scanf("%d", &total_test_number);
	for(int i = 0; i < total_test_number; ++i){
		scanf("%d", &query);
		printf("%lld\n", result[query][0] + result[query][1] + result[query][2]);
	}
}