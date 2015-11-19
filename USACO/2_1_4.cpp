/*
ID: sammail1
PROG: hamming
LANG: C++
*/
#include <cstdio>
#define SIZE 520
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

int distance[SIZE][SIZE];
int results[SIZE];
int total_number, total_bits, require_distance, upper_bound, record = 0;

int GetDistance(int num1, int num2) {
	int result = 0;
	for (int tmp = num1 ^ num2; tmp; tmp -= tmp & ~(tmp - 1))
		++result;
	return result;
}

bool Check(int num, int result_number) {
	for (int i = 0; i < result_number; ++i)
		if (distance[results[i]][num] < require_distance)
			return false;
	return true;
}

void PrintResult(int number) {
	for (int i = 0; i < number; i += 10) {
		printf("%d", results[i]);
		for (int j = 1; j < 10 && i + j < number; ++j)
			printf(" %d", results[i + j]);
		// if(i + 10 < number)
		printf("\n");
	}
}

bool GetResult(int start_num = 0, int result_number = 0) {
	if (result_number == total_number)
		return true;
	for (int i = start_num; i < upper_bound; ++i) {
		if (Check(i, result_number)) {
			results[result_number] = i;
			if (GetResult(i + 1, result_number + 1))
				return true;
		}
	}
	return false;
}


int main() {
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	for (int i = 0; i < SIZE; ++i)
		for (int j = i + 1; j < SIZE; ++j)
			distance[i][j] = GetDistance(i, j);
	MAX(record, record)
	// printf("distance=%d\n", distance[7][25]);
	scanf("%d%d%d", &total_number, &total_bits, &require_distance);
	upper_bound = 1 << total_bits;
	if (GetResult())
		PrintResult(total_number);
	return 0;
}