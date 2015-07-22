#include <iostream>
#include <ctime>
#include <cstdio>
#include <fstream>
using namespace std;

struct Node
{
	Node(int data = 0) : data_(data), left_(NULL), right_(NULL){}
	int data_;
	Node *left_, *right_;
};

Node *reverse(int array[], int &pos, int root, int size){
	if(pos >= size || array[pos] >= root)
		return NULL;
	Node *tmp = new Node(array[pos++]);
	tmp->left_ = reverse(array, pos, tmp->data_, size);
	tmp->right_ = reverse(array, pos, root, size);
	return tmp;
}

Node *reverse(int array[], int size){
	int pos = 0;
	return reverse(array, pos, 0x7fffffff, size);
}

void traverse(Node *root){
	Node *queue[100] = {root};
	int head = 0, tail = 1;
	for(; head < tail; ++head){
		printf("%d ", queue[head]->data_);
		if(queue[head]->left_)
			queue[tail++] = queue[head]->left_;
		if(queue[head]->right_)
			queue[tail++] = queue[head]->right_;
	}
}

#define SIZE 100000000
int array[SIZE], array2[SIZE], array3[SIZE];

int main(){
	// int array[] = {120, 110, 100, 95, 115, 118, 116, 130, 125, 121, 122, 135, 140, 150, 145, 155};
	// Node *root = reverse(array, 16=;;;;;
	// traverse(root);
	// return 0;
	// int begin = clock();
	// for(int i = 0; i < SIZE; ++i){
	// 	// scanf("%d", &array[i]);
	// 	cin >> array[i];
	// }
	// int total_time = clo;ck() - begin;
	// for(int i = 0; i < SIZE; ++i){
	// 	printf("%d\n", array[i]);
	// 	// cout << array[i] << '\n';
	// }
	// ofstream fout("time.txt");
	// fout << total_time;
	// printf("%d\n", clock() - begin);
	int begin;
	begin = clock();
	int tmp;
	for(int *p = array; p < &array[SIZE]; ++p)
		*p = 2;
	printf("pointer spend time : %d\n", clock() - begin);
	begin = clock();
	for(int *p = array2; p < &array2[SIZE]; ++p)
		*p = 3;
	printf("pointer spend time : %d\n", clock() - begin);
	begin = clock();
	for(int i = 0; i < SIZE; ++i)
		array3[i] = 1;
	printf("array spend time : %d\n", clock() - begin);
	while(true);
}

