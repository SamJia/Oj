/*
ID: sammail1
PROG: milk
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 5500
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x,y) ((x)<0?-(x):(x))

pair<int, int> prices[SIZE];
int total_demand, total_farmer_number, cost = 0;

int main(){
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	scanf("%d%d", &total_demand, &total_farmer_number);
	for(int i = 0; i < total_farmer_number; ++i)
		scanf("%d%d", &prices[i].first, &prices[i].second);
	sort(prices, prices + total_farmer_number);
	for(int i = 0; i < total_farmer_number; ++i){
		if(total_demand <= prices[i].second){
			cost += total_demand * prices[i].first;
			break;
		}
		cost += prices[i].first * prices[i].second;
		total_demand -= prices[i].second;
	}
	printf("%d\n", cost);
	return 0;
}