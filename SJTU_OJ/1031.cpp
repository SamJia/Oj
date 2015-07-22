#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define MAX_H 110
#define MIN_H 0
#define N_2 10000

int n = 0, n__2 =0, big, small, road[N_2] = {0}, next[4]={1,0,0,-1};
char path[N_2] = {0};

inline int min(int a, int b){
	return(a < b ? a : b);
}

inline int max(int a, int b){
	return(a > b ? a : b);
}


void init_path(){
	for(int i = 0; i < n__2; ++i)
		path[i] = 0;
}

void input(){
	// ifstream fin("1031.txt");
	cin >> n;
	n__2 = n * n;
	next[1]=n;
	next[2]=-n;
	for(int i = 0; i < n__2; ++i)
		cin >> road[i];
	// fin.close();
}

bool check(int point,int i){
	if(point < 0 || point >= n__2 || path[point])
		return(0);
	if(i==0 && !(point%n))
		return(0);
	if(i==3 && !((point+1)%n))
		return(0);
	return(1);
}

bool dfs(int begin, int end){
	if(road[begin] < small || road[begin] > big)
		return(0);
	if(begin==end)
		return(1);
	path[begin] = 1;
	for(int i = 0; i < 4; ++i)
		if(check(begin+next[i],i))
			if(dfs(begin+next[i],end))
				return(1);
	return(0);
}


int min_height(int begin, int end){
	int max_result = MAX_H, min_result = MIN_H, result = 0;
	while(max_result > min_result){
		result = (max_result + min_result) / 2;
		for(small = max(road[begin] - result,0), big = small + result; small <= road[begin] && big <= MAX_H; ++small, ++big){
			init_path();
			if(dfs(begin, end)){
				max_result = result;
				break;
			}
		}
		if(max_result > result)
			min_result = result + 1;
	}
	return(max_result);
}

main(){
	input();
	int min_h=min_height(0,n__2-1);
	cout<<min_h<<'\n';
}