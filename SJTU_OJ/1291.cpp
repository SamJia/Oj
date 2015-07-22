#include <cstdio>
#define UP 1000000007
#define SIZE 1010

long long result[SIZE] = {1, 1};
long long tmp[SIZE];
int total_number, right_number;

long long GetRightNumber(int number){
	int tmp = number;
	int result = 0;
	for(; tmp & (tmp - 1); tmp &= (tmp - 1));
	result = (tmp - 2) / 2;
	number -= tmp - 1;
	if(number > (tmp >> 1))
		result += number - (tmp >> 1);
	return result;
}

long long C_N_M(int n, int m){
	long long result = 1;
	for(int i = 0; i < m; ++i)
		tmp[i] = n - i;
	for(int i = 1; i <= m; ++i)
		for(int j = 0; j < m; ++j)
			if(!(tmp[j] % i)){
				tmp[j] /= i;
				break;
			}
	for(int i = 0; i < m; ++i){
		result = (result * tmp[i]) % UP;
	}
	return result;
}

int main(){
	scanf("%d", &total_number);
	for(int i = 2; i <= total_number; ++i){
		right_number = GetRightNumber(i);
		result[i] = C_N_M(i - 1, right_number);
		result[i] = (result[i] * result[right_number]) % UP;
		result[i] = (result[i] * result[i - right_number - 1]) % UP;
	}
	// for(total_number = 1; total_number <= 10; ++total_number){
	if(total_number == 0)
		printf("0\n");
	else if(total_number == 1)
		printf("%d\n", result[total_number]);
	else
		printf("%d\n", (2 * result[total_number]) % UP);
	// }
}