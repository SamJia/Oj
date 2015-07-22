#include <iostream>
using namespace std;
#define SIZE 100010
#define HEI first
#define NUM second
int plane[SIZE];
pair<int, int> heap[SIZE];
int plane_number;
char command[10];

void MinHeap(int position){
	pair<int, int> tmp;
	for(; position > 1 && heap[position>>1] > heap[position]; position>>=1){
		tmp = heap[position>>1];
		heap[position>>1] = heap[position];
		heap[position] = tmp;
	}
}

void Maintain(int the_plane, int decrease_height){
	int position = plane[the_plane];
	pair<int, int> tmp;
	heap[position].HEI -= decrease_height;
	for(; position > 1 && heap[position>>1] > heap[position]; position>>=1){
		tmp = heap[position>>1];
		heap[position>>1] = heap[position];
		heap[position] = tmp;
		plane[heap[position].NUM] = position;
		plane[heap[position>>1].NUM] = position>>1;
	}
}

int FindMin(int min_height, int root_pos = 1){
	if(root_pos > plane_number)
		return 0x7fffffff;
	if(heap[root_pos].HEI > min_height)
		return heap[root_pos].NUM;
	return min(FindMin(min_height, root_pos<<1), FindMin(min_height, (root_pos<<1) + 1)); 
}

int main(){
	cin >> plane_number;
	for(int i = 1; i <= plane_number; ++i){
		cin >> heap[i].HEI;
		heap[i].NUM = i;
		MinHeap(i);
	}
	for(int i = 1; i <= plane_number; ++i)
		plane[heap[i].NUM] = i;
	while(cin >> command){
		if(command[0] == 'd'){
			int the_plane, decrease_height;
			cin >> the_plane >> decrease_height;
			Maintain(the_plane, decrease_height);
		}
		else{
			int min_height;
			cin >> min_height;
			int the_plane = FindMin(min_height);
			cout << the_plane << '\n';
		}
	}
	return 0;
}