#include "cstdio"
#define BIAS 2001000
#define SIZE 510
#define RANGE 5000000

int lists[4][SIZE];
int total_number;
int occur[RANGE] = {};

int main(){
	scanf("%d", &total_number);
	for(int i = 0; i < total_number; ++i){
		scanf("%d%d%d%d", &lists[0][i], &lists[1][i], &lists[2][i], &lists[3][i]);
	}
	for(int i = 0; i < total_number; ++i)
		for(int j = 0; j < total_number; ++j)
			++occur[lists[0][i] + lists[1][j] + BIAS];
	int result = 0;
	for(int i = 0; i < total_number; ++i)
		for(int j = 0; j < total_number; ++j)
			result += occur[-(lists[2][i] + lists[3][j]) + BIAS];
	printf("%d\n", result);
}