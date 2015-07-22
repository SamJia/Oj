#include <cstdio>
#include <cmath>

bool IsPrime(int number){
	int max_limit = (int)sqrt(number);
	for(int i = 2; i <= max_limit; ++i)
		if(number % i == 0)
			return false;
	return true;
}

int main(){
	int number, result1, result2;
	scanf("%d", &number);
	if(number % 2 == 0){
		for(result1 = result2 = number / 2; true; --result1, ++result2)
			if(IsPrime(result1) && IsPrime(result2)){
				printf("%d %d", result1, result2);
				return 0;
			}
	}
	else{
		if(IsPrime(number - 2))
			printf("%d %d", 2, number - 2);
		else
			printf("NO");
	}
	return 0;
}