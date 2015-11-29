/*
ID: sammail1
PROG: runround
LANG: C++
*/
#include <cstdio>
#define SIZE 10
#define MIN(x,y) ((x)<(y)?(x):(y))

int lower_bound, digits[SIZE] = {}, min_result = 0x7fffffff;
bool choose[SIZE] = {};

bool CheckRunAround(int length) {
	int count = 1, pos = (digits[0]) % length;
	for (; pos != 0 && count < length; pos = (pos + digits[pos]) % length)
		++count;
	return (pos == 0 && count == length);
}

void Calculate(int length, int number) {
	if (number > lower_bound) {
		if (CheckRunAround(length))
			min_result = MIN(number, min_result);
		return;
	}
	for (int i = 1; i < 10; ++i) {
		if (!choose[i]) {
			digits[length] = i;
			choose[i] = true;
			Calculate(length + 1, number * 10 + i);
			choose[i] = false;
		}
	}
}

int main() {
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	scanf("%d", &lower_bound);
	Calculate(0, 0);
	printf("%d\n", min_result);
	return 0;
}