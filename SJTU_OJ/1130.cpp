#include <iostream>
using namespace std;
class MixNum{
public:
	MixNum(int mem, int den) : num_(mem / den), mem_(mem % den), den_(den){}
	const MixNum &operator+=(const MixNum &);
	long long num_, mem_, den_;
};

int getlen(long long num){
	int len = 0;
	for(; num; num /= 10, ++len);
	return len;
}

main(){
	int n;
	cin >> n;
	MixNum result(n, 1);
	for(int i = 2; i <= n; ++i)
		result += *(new MixNum(n, i));
	int numlen = getlen(result.num_), memlen = getlen(result.mem_), denlen = getlen(result.den_);
	if(result.mem_){
		for(int i = 0; i < numlen + 1; ++i)
			cout << ' ';
		cout << result.mem_ << '\n' << result.num_ << ' ';
		for(int i = 0; i < denlen; ++i)
			cout << '-';
		cout << '\n';
		for(int i = 0; i < numlen + 1; ++i)
			cout << ' ';
		cout << result.den_ << '\n';
	}
	else
		cout << result.num_;
}

long long FindGCD(long long num1, long long num2){
	for(long long divisor = num1 % num2;divisor; num1 = num2, num2 = divisor, divisor = num1 % num2);
	return num2;
}

const MixNum & MixNum::operator+=(const MixNum &num){
	mem_ = mem_ * num.den_ + den_ * num.mem_;
	den_ = den_ * num.den_;
	long long gcd = FindGCD(mem_, den_);
	mem_ /= gcd;
	den_ /= gcd;
	num_ += (num.num_ + mem_ / den_);
	mem_ %= den_;
}
