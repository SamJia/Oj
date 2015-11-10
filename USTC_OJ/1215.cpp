#include <cstdio>
#define SIZE 41000
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

int total_number, different, head, tail, result, tmp;
int numbers[SIZE];

int compute(int diff) {
	int last = (numbers[0] + diff) / different;
	tmp = 1;
	int result = 0;
	for (int i = 1; i < 2 * total_number - 1; ++i) {
		if ((numbers[i] + diff) / different == last)
			++tmp;
		else {
			last = (numbers[i] + diff) / different;
			result = MAX(result, tmp);
			tmp = 1;
		}
	}
	return MIN(MAX(result, tmp), total_number);
}

int main() {
	while (true) {
		scanf("%d%d", &total_number, &different);
		if (total_number == 0 && different == 0)
			break;
		for (int i = 0; i < total_number; ++i) {
			scanf("%d", &numbers[i]);
			numbers[total_number + i] = numbers[i];
		}
		result = 0;
		++different;
		for (int i = 0; i < different; ++i) {
			tmp = compute(i);
			// printf("tmp:%d\n", tmp);
			result = MAX(result, tmp);
		}
		printf("%d\n", result);
	}
}