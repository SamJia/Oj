#include <cstdio>
#define SIZE 100100
#define ABS(x) ((x)<0?(-(x)):(x))

int total_number, total_query_number;
int heap[SIZE];
int sum = 0, tmp;

void Down(int root = 1){
	tmp = heap[root];
	int i = root, j = 2 * root;
	for(; j <= total_number; i = j, j = 2 * i){
		if(j + 1 <= total_number && heap[j+1] > heap[j])
			++j;
		if(tmp >= heap[j])
			break;
		heap[i] = heap[j];
	}
	heap[i] = tmp;
}

int main(){
	scanf("%d%d", &total_number, &total_query_number);
	for(int i = 1; i <= total_number; ++i){
		scanf("%d", &tmp);
		sum += tmp;
		heap[i] = ABS(sum);
	}
	for(int i = total_number / 2; i >= 1; --i)
		Down(i);
	// for(int i = 1; i <= total_number; ++i)
	// 	printf("%d ", heap[i]);
	for(int i = 0; i < total_query_number; ++i){
		printf("%d\n", heap[1]);
		heap[1] = heap[total_number--];
		Down();
	}

}