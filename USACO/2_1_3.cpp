/*
ID: sammail1
PROG: sort3
LANG: C++
*/
#include <cstdio>
#define SIZE 1200
#define MAX(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ > y_ ? x_ : y_;})
#define MIN(x,y) ({typeof(x) x_ = (x); typeof(y) y_ = (y); x_ < y_ ? x_ : y_;})
#define ABS(x) ({typeof(x) x_ = (x); x_ > 0 ? x_ : -x_;})

int total_number, number[SIZE], result;
int pos1, pos2, pos3;

int FindLast(int target, int end){
	for(int i = total_number - 1; i >= end; --i)
		if(number[i] == target)
			return i;
	return end - 1;
}

int FindFirst(int target, int start){
	for(int i = start + 1; i < total_number; ++i)
		if(number[i] == target)
			return i;
	return total_number;
}

void Swap(int &a, int &b){
	int tmp = a;
	b = a;
	a = tmp;
}

int main(){
	// freopen("sort3.in", "r", stdin);
	// freopen("sort3.out", "w", stdout);
	scanf("%d", &total_number);
	for(int i = 0; i < total_number; ++i)
		scanf("%d", &number[i]);
	for(int i = 0; i < total_number; ++i){
		if(number[i] == 2){
			pos1 = FindFirst(1, i);
			if(pos1 < total_number){
				Swap(number[i], number[pos1]);
				++result;
			}
		}
		else if(number[i] == 3){
			pos1 = FindLast(1, i);
			if(pos1 > i){
				Swap(number[i], number[pos1]);
				++result;
			}
			else{
				pos2 = FindLast(2, i);
				if(pos2 > i){
					Swap(number[i], number[pos2]);
					++result;
				}
				else
					break;
			}
		}
	}
	printf("%d\n", result);
	return 0;
}