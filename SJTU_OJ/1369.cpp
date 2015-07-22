#include <cstdio>
#define MAX_NUM 1000000000
#define MAX_LENGTH 150
struct Num
{
	Num(int number = 0){
		number_[0] = number;
		for(int i = 1; i < MAX_LENGTH; ++i)
			number_[i] = 0;
	}
	int number_[MAX_LENGTH];

	Num &operator+=(Num &num2){
		for(int i = 0, carry = 0; i < MAX_LENGTH; ++i){
			number_[i] += carry + num2.number_[i];
			carry = number_[i] / MAX_NUM;
			number_[i] %= MAX_NUM;
		}
	}
};

Num *result;
int total_numebr, step_a, step_b;

int main(){
	scanf("%d%d%d", &total_numebr, &step_a, &step_b);
	if(step_a > step_b){
		int tmp = step_a;
		step_a = step_b;
		step_b = tmp;
	}
	result = new Num[step_b];
	result[0].number_[0] = 1;
	for(int i = 0; i < total_numebr; ++i){
		result[(i + step_a) % step_b] += result[i % step_b];
		// for(int j = 0; j < step_b; ++j)
		// 	printf("%d ", result[j].number_[0]);
		// printf("\n");
	}
	int i = MAX_LENGTH - 1;
	for(; i > 0 && !result[total_numebr % step_b].number_[i]; --i);
	printf("%d", result[total_numebr % step_b].number_[i--]);
	for(; i >= 0; --i){
		for(int j = MAX_NUM / 10; j > 0; result[total_numebr % step_b].number_[i] %= j, j /= 10)
		printf("%d", result[total_numebr % step_b].number_[i] / j);
	}
}
