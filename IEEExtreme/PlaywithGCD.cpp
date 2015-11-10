#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 11000
#define UPPER 1000000007
#define value first
#define count second

int count_number[SIZE] = {}, total_ball, tmp, total_distinct_numebr = 0, total_query, query;
pair<int, int> numberANDcount[110] = {};
long long pow2[SIZE];
long long result[SIZE] = {};
long long tmp_result[SIZE] = {};

void ComputePow() {
	pow2[0] = 1;
	for (int i = 1; i < SIZE; ++i)
		pow2[i] = pow2[i - 1] * 2 % UPPER;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int GCD(int a, int b) {
	if (a == 0 || b == 0)
		return a + b;
	if (a < b)
		swap(a, b);
	int tmp;
	while (tmp = a % b) {
		a = b;
		b = tmp;
	}
	return b;
}

void Compute() {
	result[0] = 1;
	int gcd;
	for (int i = 0; i < total_distinct_numebr; ++i) {
		memset(tmp_result, 0, sizeof(tmp_result[0]) * SIZE);
		for (int j = 0; j < SIZE; ++j) {
			if (result[j]) {
				gcd = GCD(numberANDcount[i].value, j);
				tmp_result[gcd] = (tmp_result[gcd] + result[j] * (pow2[numberANDcount[i].count] - 1)) % UPPER;
			}
		}
		for (int j = 0; j < SIZE; ++j)
			result[j] = (result[j] + tmp_result[j]) % UPPER;
	}
}

int main() {
	ComputePow();
	scanf("%d", &total_ball);
	for (int i = 0; i < total_ball; ++i) {
		scanf("%d", &tmp);
		++count_number[tmp];
	}
	for (int i = 0; i < SIZE; ++i)
		if (count_number[i])
			numberANDcount[total_distinct_numebr++] = pair<int, int>(i, count_number[i]);
	Compute();
	scanf("%d", &total_query);
	for (int i = 0; i < total_query; ++i) {
		scanf("%d", &query);
		printf("%lld\n", result[query]);
	}
}