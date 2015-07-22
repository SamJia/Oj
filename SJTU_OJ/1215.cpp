#include <cstdio>
#define SIZE 20010
int heap[SIZE];
int total_command_number, tmp_number, heap_size = 1;
char command[10];

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(){
	scanf("%d", &total_command_number);
	for(int i = 1; i <= total_command_number; ++i){
		scanf("%s", &command);
		if(command[0] == 'i'){
			scanf("%d", &tmp_number);
			heap[heap_size++] = tmp_number;
			for(int i = heap_size - 1; i > 1 && heap[i>>1] > heap[i]; i >>= 1)
				swap(heap[i], heap[i>>1]);
		}
		else if(command[0] == 'm')
			printf("%d\n", heap[1]);
		else{
			heap[1] = heap[--heap_size];
			for(int i = 1, j = 2; j < heap_size; i = j, j = i << 1){
				if(j + 1 < heap_size && heap[j+1] < heap[j])
					j++;
				if(heap[i] > heap[j])
					swap(heap[i], heap[j]);
				else
					break;
			}
		}
	}
	return 0;
}