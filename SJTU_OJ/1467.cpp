#include "cstdio"
#define SIZE 35000
int list1[SIZE], list2[SIZE];
int total_number1, total_number2, result = 0;

int main(){
	scanf("%d%d", &total_number1, &total_number2);
	for(int i = 0; i < total_number1; ++i)
		scanf("%d", &list1[i]);
	for(int i = 0; i < total_number2; ++i)
		scanf("%d", &list2[i]);
	for(int i = 0; i < total_number1; ++i)
		for(int j = 0; j < total_number2; ++j)
			if((list1[i] ^ list2[j]) > result)
				result = list1[i] ^ list2[j];
	printf("%d", result);
	return 0;
}