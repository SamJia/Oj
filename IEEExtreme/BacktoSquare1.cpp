#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define SIZE 1010

int total_square_number;
double probality[SIZE], result;

int main(){
	for(scanf("%d", &total_square_number); total_square_number; scanf("%d", &total_square_number)){
		if(total_square_number == 1){
			printf("%d\n", 1);
			continue;
		}
		for(int i = 1; i < total_square_number; ++i)
			scanf("%lf", &probality[i]);
		// for(int i = 0; i < total_square_number - 1; ++i)
		// 	printf("%llf ", probality[i]);
		result = 1;
		// for(int i = 0; i < total_square_number - 1; ++i)
		// 	result *= (1 + probality[i]) / probality[i];
		// result /= (1 + probality[total_square_number - 2]);
		for(int i = total_square_number - 2; i > 0; --i)
			result = result * probality[i] + 1;
		for(int i = 1; i < total_square_number; ++i)
			result /= probality[i];
		// printf("%lf\n", result);
		printf("%d\n", (int)round(result) + 1);
	}

	// double a = 0.5;
	// result = 0;
	// for(int i = 1; i <= 1000; ++i, a /= 2){
	// 	result += a * i;
	// }
	// printf("%lf\n", result);

	// int count = 0;
	// printf("rand max:%d\n", RAND_MAX);
	// srand(time(0));
	// for(int i = 0; i < 1000000; ++i){
	// 	// printf("i:%d\n", i);
	// 	while(0.5 > (rand() / 32767.0))
	// 		++count;
	// 	++count;
	// }
	// printf("%lf\n", count / 1000000.0);
	// srand(time(0));
	// for(scanf("%d", &total_square_number); total_square_number; scanf("%d", &total_square_number)){
	// 	if(total_square_number == 1){
	// 		printf("%d\n", 1);
	// 		continue;
	// 	}
	// 	for(int i = 1; i < total_square_number; ++i)
	// 		scanf("%lf", &probality[i]);
	// 	int count = 0;
	// 	printf("total:%d\n", total_square_number);
	// 	for(int i = 0; i < 100000; ++i)
	// 		for(int pos = 1; pos != total_square_number;){
	// 			// printf("i:%d\n", i);
	// 			if(probality[pos] > (rand() / 32768.0))
	// 				++pos;
	// 			else
	// 				pos = 1;
	// 			++count;
	// 		}
	// 	printf("%lf\n", count / 100000.0);
	// }
}