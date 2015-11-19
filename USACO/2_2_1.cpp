/*
ID: sammail1
PROG: preface
LANG: C++
*/
#include <cstdio>
#define SIZE 10
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

int result[SIZE] = {};
int value[SIZE] = {1, 5, 10, 50, 100, 500, 1000};
char translate[SIZE] = {"IVXLCDM"};
int total_number;

void Pattern(int number, int *tmp_result) {
	if (number < 4)
		tmp_result[0] += number;
	else if (number == 4) {
		tmp_result[0] += 1;
		tmp_result[1] += 1;
	}
	else if (number < 9) {
		tmp_result[0] += number - 5;
		tmp_result[1] += 1;
	}
	else if (number == 9) {
		tmp_result[0] += 1;
		tmp_result[2] += 1;
	}
}


void Calculate(int number) {
	int tmp[SIZE];
	int pow10[] = {1, 10, 100, 1000};
	for (int i = 0; i < 4; ++i) {
		Pattern(number / pow10[i], result + 2 * i);
		number %= pow10[i];
	}
}

int main() {
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	scanf("%d", &total_number);
	for (int i = 1; i <= total_number; ++i)
		Calculate(i);
	for (int i = 0; result[i]; ++i)
		printf("%c %d\n", translate[i], result[i]);
	return 0;
}