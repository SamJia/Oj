#include "cstdio"
#define SIZE 1010000
// #define MIN(x,y) ((x)<(y)?(x):(y))

int total_number;
int numbers[SIZE];

int MidPos(int a, int b, int c){
	if(((numbers[a] - numbers[b]) ^ (numbers[a] - numbers[c])) >> 31)
		return a;
	else if(((numbers[b] - numbers[a]) ^ (numbers[b] - numbers[c])) >> 31)
		return b;
	else
		return c;
}

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void PreProcess(int begin, int end){
	swap(numbers[begin],numbers[MidPos(begin, end, (begin + end) / 2)]);
}

void qsort(int begin, int end){
	if(begin + 1 >= end)
		return;
	PreProcess(begin, end);
	int mid_value = numbers[begin];
	int i = begin, j = end-1;
	while(i < j){
		for(; i < j && numbers[j] > mid_value; --j);
		if(i < j)
			numbers[i++] = numbers[j];
		for(; i < j && numbers[i] < mid_value; ++i);
		if(i < j)
			numbers[j--] = numbers[i];
	}
	numbers[i] = mid_value;
	qsort(begin, i);
	qsort(j+1, end);
}

int main(){
	scanf("%d", &total_number);
	for(int i = 0; i < total_number; ++i)
		scanf("%d", &numbers[i]);
	qsort(0, total_number);
	for(int i = 0; i < total_number; ++i)
		printf("%d ", numbers[i]);
}