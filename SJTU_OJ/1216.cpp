#include <iostream>
#include <cstdio>
#define SIZE 20010
using namespace std;

int heap[SIZE] = {0x7fffffff};
int total_command_number, heap_size = 1, para1, para2;
char command[20];

template <typename T>
void Swap(T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp;
}

int main(){
	scanf("%d", &total_command_number);
	for(int i = 1; i <= total_command_number; ++i){
		scanf("%s %d", &command, &para1);
		if(command[0] == 'i'){
			heap[heap_size++] = para1;
			for(int i = heap_size - 1; i > 1 && heap[i>>1] > heap[i]; i >>= 1)
				Swap(heap[i], heap[i>>1]);
		}
		else if(command[0] == 'd'){
			scanf("%d", &para2);
			heap[para1] -= para2;
			if(para2 >= 0)
				for(int i = para1; i > 1 && heap[i>>1] > heap[i]; i >>= 1)
					Swap(heap[i], heap[i>>1]);
			else
				for(int i = para1, j = para1 << 1; j < heap_size; i = j, j = i << 1){
					if(j + 1 < heap_size && heap[j+1] < heap[j])
						j++;
					if(heap[i] > heap[j])
						Swap(heap[i], heap[j]);
					else
						break;
				}
		}
		else{
			int result = 0;
			for(int i = 1; i < heap_size; ++i)
				if(heap[i] > para1 && heap[i] < heap[result])
					result = i;
			printf("%d\n", result);
		}
	}
	return 0;
}