#include <cstdio>
#define SIZE 250

int total_test_number, total_number, tmp;
long long result, count[SIZE];

void Init(){
	result = 0;
	for(int i = 0; i < SIZE; ++i)
		count[i] = 0;
}

void Compute(){
	for(int i = 0; i < SIZE - 10; ++i){
		result += count[i] * (total_number - count[i]);
		count[i+1] += count[i];
	}
}

int main(){
	scanf("%d", &total_test_number);
	for(int i = 0; i < total_test_number; ++i){
		Init();
		scanf("%d", &total_number);
		for(int j = 0; j < total_number; ++j){
			scanf("%d", &tmp);
			++count[tmp];
		}
		Compute();
		printf("%lld\n", result);
	}
}