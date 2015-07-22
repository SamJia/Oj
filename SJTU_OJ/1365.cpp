#include <cstdio>
#include <iostream>
#include <algorithm>
#define SIZE 1001000
using namespace std;

struct Node{
	Node(long long begin = 0, long long end = 0, Node *next = NULL) : begin_(begin), end_(end), next_(next){}
	long long begin_, end_;
	Node *next_;
};

pair<long long, long long> groups[SIZE] = {};
long long total_number, total_time, result = 0, begin, speed, end, pos;
pair<long long, long long> b_and_e[SIZE];

int Check(int number);

int main(){
	scanf("%d%d", &total_number, &total_time);
	for(int i = 0; i < total_number; ++i){
		scanf("%d%d", &begin, &speed);
		end = begin + speed * total_time;
		b_and_e[i].first = begin;
		b_and_e[i].second = end;
	}
	sort(b_and_e, b_and_e + total_number);
	for(int i = 0; i < total_number; ++i){
		pos = Check(i);
		groups[pos] = b_and_e[i];
	}
	printf("%d\n", result);
	return 0;
}

int Check(int number){
	for(int i = 0; i < result; ++i){
		if(groups[i].first < b_and_e[number].first && groups[i].second < b_and_e[number].second)
			return i;
	}
	return result++;
}