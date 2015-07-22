#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define HEIGHT first
#define NUMBER second
#define UP first
#define DOWN second

int n, road[2010], change[2010];
pair<int, int>  result[2010][2010] = {};

main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> road[i];
		change[i] = road[i];
	}
	sort(change, change + n);
	for(int i = 0; i < n; ++i)
		result[0][i].UP = result[0][i].DOWN = abs(road[0] - change[i]);
	for(int i = 1, min_cost = 0x7fffffff; i < n; ++i, min_cost = 0x7fffffff)
		for(int j = 0; j < n; ++j){
			min_cost = min(min_cost, result[i - 1][j].UP);
			result[i][j].UP = min_cost + abs(road[i] - change[j]);
		}
	for(int i = 1, min_cost = 0x7fffffff; i < n; ++i, min_cost = 0x7fffffff)
		for(int j = n - 1; j >= 0; --j){
			min_cost = min(min_cost, result[i - 1][j].DOWN);
			result[i][j].DOWN = min_cost + abs(road[i] - change[j]);
		}
	int min_cost = 0x7fffffff;
	for(int i = 0; i < n; ++i){
		min_cost = min(min_cost, result[n - 1][i].UP);
		min_cost = min(min_cost, result[n - 1][i].DOWN);
	}
	cout << min_cost;
}