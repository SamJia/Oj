#include <cstdio>
#define SIZE 110000
#define UPPER 1000000007

int total_number, tmp, total_command;
long long result = 0;

int main(){
	scanf("%d", &total_number);
	for(int i = 0; i < total_number; ++i){
		scanf("%d", &tmp);
		result = (result + tmp) % UPPER;
	}
	scanf("%d", &total_command);
	for(int i = 0; i < total_command; ++i)
		result = (result + result) % UPPER;
	printf("%lld\n", result);
}