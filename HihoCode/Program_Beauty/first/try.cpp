#include "iostream"
#include "cmath"
using namespace std;

long long int f(long long int a, long long int b){
	return a+1;
}

main(){
	long long int a = 10000000000000;
	long long int b = 20000000000000;
	cout << f(a, b);
}