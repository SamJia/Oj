/*
ID: sammail1
PROG: wormhole
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 20
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x,y) ((x)<0?-(x):(x))

int total_hole_number, rows[SIZE] = {}, pairs[SIZE];
int result;
bool flag[SIZE] = {};
pair<int, int> pos[SIZE];

void Preprocess(){
	sort(pos, pos + total_hole_number);
	for(int i = 1; i < total_hole_number; ++i)
		if(pos[i].first == pos[i-1].first)
			rows[i] = rows[i-1];
		else
			rows[i] = rows[i-1] + 1;
	rows[total_hole_number] = rows[total_hole_number - 1] + 1;
}

bool GetDestination(int start_pos){
	for(int pos = pairs[start_pos]; rows[pos] == rows[pos + 1]; pos = pairs[pos+1])
		if(pos + 1 == start_pos)
			return false;
	return true;
}

bool IsCircle(){
	for(int i = 0; i < total_hole_number; ++i)
		if(!GetDestination(i))
			return true;
	return false;
}

void Compute(int remain_hole){
	int hole1, hole2;
	for(hole1 = 0; flag[hole1] == true; ++hole1);
	for(hole2 = hole1 + 1; hole2 < total_hole_number; ++hole2){
		if(flag[hole2] == false){
			pairs[hole1] = hole2;
			pairs[hole2] = hole1;
			if(remain_hole == 2){
				// printf("pairs[0]: %d\n", pairs[0]);
				if(IsCircle()){
					// printf("pairs[0]: %d\n", pairs[0]);
					++result;
				}
			}
			else{
				flag[hole1] = flag[hole2] = true;
				Compute(remain_hole - 2);
				flag[hole1] = flag[hole2] = false;
			}
		}
	}
}

int main(){
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	scanf("%d", &total_hole_number);
	for(int i = 0; i < total_hole_number; ++i)
		scanf("%d%d", &pos[i].second, &pos[i].first);
	Preprocess();
	// for(int i = 0; i < total_hole_number; ++i)
	// 	printf("%d ", rows[i]);
	Compute(total_hole_number);
	printf("%d\n", result);
	return 0;
}