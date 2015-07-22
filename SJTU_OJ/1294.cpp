#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define SIZE 100010
int remainder[2000000] = {1};
char result[2000000] = {}, tmp;
int main(){
	int n = 0, d = 1, quo, pos = 0;
	cin >> n >> d;
	quo = n / d;
	do{
		result[pos++] = quo % 10 + '0';
		quo /= 10;
	}while(quo);
	for(int i = 0, j = pos - 1; i < j; ++i, --j){
		tmp = result[i];
		result[i] = result[j];
		result[j] = tmp;
	}
	if(n % d){
		result[pos++] = '.';
		// cout << 1;
		for(n = n % d * 10; !remainder[n]; n = n % d * 10){
			result[pos++] = n / d + '0';
			remainder[n] = pos;
		}
		result[pos] = '\0';
		if(n == 0)
			cout << result;
		else{
			for(int i = pos; i >= remainder[n] - 1; --i)
				result[i + 1] = result[i];
			result[remainder[n] - 1] = '(';
			result[pos + 1] = ')';
			result[pos + 2] = '\0';
			cout << result;
		}
	}
	else
		cout << result << ".0";
	return 0;
}