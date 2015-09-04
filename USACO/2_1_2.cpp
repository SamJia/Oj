/*
ID: sammail1
PROG: frac1
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 40000
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

struct Frac {
	int numerator_, denominator_;
};

bool cmp(const Frac &a, const Frac &b){
	return a.numerator_ * b.denominator_ < b.numerator_ * a.denominator_;
}

Frac fractions[SIZE];
int frac_numebr = 2, max_den;

bool Check(int numerator, int denominator){
	int tmp;
	while(tmp = denominator % numerator){
		denominator = numerator;
		numerator = tmp;
	}
	return numerator == 1;
}

int main(){
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	scanf("%d", &max_den);
	fractions[0].numerator_ = 0;
	fractions[0].denominator_ = 1;
	fractions[1].numerator_ = 1;
	fractions[1].denominator_ = 1;
	for(int j = 2; j <= max_den; ++j)
		for(int i = 1; i < j; ++i)
			if(Check(i, j)){
				fractions[frac_numebr].numerator_ = i;
				fractions[frac_numebr++].denominator_ = j;
			}
	sort(fractions, fractions + frac_numebr, cmp);
	for(int i = 0; i < frac_numebr; ++i)
		printf("%d/%d\n", fractions[i].numerator_, fractions[i].denominator_);
	return 0;
}