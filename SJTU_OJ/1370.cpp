#include <cstdio>
#define SIZE 165

int total_test_number, total_peach_number, total_day_number, answer;
int result[2*SIZE][2*SIZE];

void Init(){
	for(int i = 0; i < SIZE; ++i)
		for(int j = 0; j < SIZE; ++j)
			result[i][j] = 0;
	result[0][1] = 1;
	answer = 0;
}

void Compute(){
	for(int i = 0; i < total_day_number; ++i)
		for(int j = total_peach_number; j >= 0; --j)
			for(int k = 1; k <= total_peach_number; ++k){
				for(int addi = k; addi <= total_peach_number - j; ++addi)
					result[j+addi][addi] += result[j][k];
				result[j][k] = 0;
			}
	for(int i = 0; i <= total_peach_number; ++i)
		answer += result[total_peach_number][i];
	// for(int i = 0; i <= total_peach_number; ++i){
	// 	for(int j = 0; j < total_peach_number; ++j)
	// 		printf("%d ", result[i][j]);
	// 	printf("\n");
	// }

}

int main(){
	scanf("%d", &total_test_number);
	for(int i = 0; i < total_test_number; ++i){
		scanf("%d%d", &total_peach_number, &total_day_number);
		Init();
		Compute();
		printf("%d\n", answer);
	}
}