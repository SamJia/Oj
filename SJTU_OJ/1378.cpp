#include <cstdio>

int total_test_number, total_right_number, total_wrong_number;
double result, tmp;

int main(){
	scanf("%d", &total_test_number);
	for(int i = 0; i < total_test_number; ++i){
		scanf("%d%d", &total_right_number, &total_wrong_number);
		if(total_wrong_number == 0)
			printf("%.6lf\n", (double) total_right_number);
		else{
			result = 0;
			tmp = 1;
			for(int j = 0; j <= total_right_number; ++j){
				result += (j + 1) * tmp * ((double) total_wrong_number) / (total_right_number - j + total_wrong_number);
				tmp *= 1 - ((double) total_wrong_number) / (total_right_number - j + total_wrong_number);
			}
			printf("%.6lf\n", result);
		}
	}
}