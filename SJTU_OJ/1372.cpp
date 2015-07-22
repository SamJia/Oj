#include <cstdio>
#include <iostream>
#ifndef SIZE
#define SIZE 1001000
#endif

#ifndef MAX
#define MAX(x,y) ((x)>(y)?(x):(y))
#endif
using namespace std;

long long total_number, radixs[2], results[2];
char numbers[2][10];

long long GetNumber(int pos){
	return radixs[pos] * radixs[pos] * (numbers[pos][0] - '0') + radixs[pos] * (numbers[pos][1] - '0') + (numbers[pos][2] - '0');
}

int main(int argc, char const *argv[])
{
	cin >> total_number;
	for(int i = 0; i < total_number; ++i){
		cin >> numbers[0] >> numbers[1];
		radixs[0] = 10;//MAX(MAX(numbers[0][0]-'0', numbers[0][1]-'0'), numbers[0][2]-'0') + 1;
		radixs[1] = 10;//MAX(MAX(numbers[1][0]-'0', numbers[1][1]-'0'), numbers[1][2]-'0') + 1;
		do{
			results[0] = GetNumber(0);
			results[1] = GetNumber(1);
			if(results[0] < results[1])
				++radixs[0];
			else if(results[0] > results[1])
				++radixs[1];
			// cout << results[0] << ' ' << results[1] << '\n';
			// printf("%d %d\n", results[0] , results[1]);
		} while(results[0] != results[1] && radixs[0] <= 15000);
		cout << radixs[0] << ' ' << radixs[1] << '\n';
	}
	return 0;
}