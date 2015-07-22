#include <iostream>
#include <cstring>
using namespace std;

long long Find(char upper_limit[]);
long long LenToNum(int len);
long long ToNum(char *start);
bool Check(char upper_limit[]);


main(){
	char low[20], high[20];
	cin >> low >> high;
	long long result = Find(high) - Find(low);
	if(Check(low))
		++result;
	cout << result;
}

long long Find(char upper_limit[]){
	int len = strlen(upper_limit);
	long long result = 0;
	for(int i = 1; i < len; ++i)
		result += LenToNum(i);
	result += (upper_limit[0] - '1') * LenToNum(len) / 9;
	result += upper_limit[0] <= upper_limit[len - 1] ? ToNum(upper_limit + 1) + 1 : ToNum(upper_limit + 1);
	return result;
}
	
long long LenToNum(int len){
	long long result = 9;
	for(int i = 2; i < len; ++i)
		result *= 10;
	return result;
}

long long ToNum(char *start){
	long long result = 0;
	for(;*start && *(start + 1); ++start)
		result = result * 10 + *start - '0';
	return result;
}

bool Check(char upper_limit[]){
	int len = strlen(upper_limit);
	if(upper_limit[0] == upper_limit[len - 1])
		return 1;
	return 0;
}