#include <cstdio>
#define SIZE 2010

int total_number;
int lengths[SIZE], added_length[SIZE] = {};
int half_number = 0, result = 0;

int main(){
	scanf("%d", &total_number);
	for(int i = 0; i < total_number; ++i){
		scanf("%d", &lengths[i]);
		added_length[i + 1] = added_length[i] + lengths[i];
	}
	for(int i = 0; i < total_number; ++i)
		for(int j = i; j < total_number; ++j){
			if(2 * (added_length[j] - added_length[i]) == added_length[total_number])
				++half_number;
		}
	result = half_number * (half_number - 1) / 2;
	printf("%d\n", result);
}