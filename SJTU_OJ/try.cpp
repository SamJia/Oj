#include "cstdio"
#include "iostream"
#include "cmath"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define SIZE 2000000
using namespace std;

void sq_sort(int *first, int *last, int pos = 1<<30){
	int *left = first, *right = last - 1;
	int tmp;
	if(first != last){
		while(left != right){
			while(left != right && ((*left)&pos) == 0)
				++left;
			while(left != right && ((*right)&pos) != 0)
				--right;
			if(left != right){
				tmp = *left;
				*left = *right;
				*right = tmp;
			}
		}
		if(((*left)&pos) == 0)
			++left;
		if(pos > 1){
			sq_sort(first, left, pos>>1);
			sq_sort(left, last, pos>>1);
		}
	}
}

void q_sort(int *first, int *last){
	int *left = first, *right = last - 1;
	int mid = *left;
	int tmp;
	if(first < last){
		while(left < right){
			while(left < right && *right >= mid)
				--right;
			if(left < right)
				*(left++) = *right;
			while(left < right && *left <= mid)
				++left;
			if(left < right)
				*(right--) = *left;
			// while(left < right && *right >= mid)
			// 	--right;
			// *left = *right;
			// while(left < right && *left <= mid)
			// 	++left;
			// *right = *left;
		}
		*left = mid;
		// for(int *p = first; p != last; ++p)
		// 	printf("%d ", *p);
		// printf("\n");
		q_sort(first, left);
		q_sort(left + 1, last);
	}
}

int array1[SIZE], array2[SIZE], array3[SIZE];
long long result;
int begin_time;

int main(){
	// printf("%d\n", (RAND_MAX<<16)+RAND_MAX+RAND_MAX+1);
	srand(time(0));
	for(int i = 0; i < SIZE; ++i)
		array3[i] = array2[i] = array1[i] = ((rand()<<16)+rand())%50000;
	begin_time = clock();
	sort(array1, array1 + SIZE);
	cout << "q_sort in algorithm use time : " << (clock() - begin_time) << '\n';
	begin_time = clock();
	sq_sort(array2, array2 + SIZE);
	cout << "sq_sort use time : " << (clock() - begin_time) << '\n';
	for(int i = 0; i < SIZE; ++i)
		if(array1[i] != array2[i]){
			printf("wrong\n");
			break;
		}
	printf("right\n");
	begin_time = clock();
	q_sort(array3, array3 + SIZE);
	cout << "q_sort use time : " << (clock() - begin_time) << '\n';
	for(int i = 0; i < SIZE; ++i)
		if(array1[i] != array3[i]){
			printf("wrong\n");
			break;
		}
		// printf("%d ", array3[i]);
	printf("right\n");
	return 0;
}