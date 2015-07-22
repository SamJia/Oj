#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define SIZE 100010
#define POINTS second
#define TIME first

int backets_number;
int points[SIZE] = {};
pair<int, int> backets[SIZE] = {};
int time_number = 1, remain_time[SIZE] = {};
map<int, int> time_to_number;
long long result = 0;

void Input();
void CreateTree();
void FindMaxPoints();
void FindProperTime(int disappear_time, int point);
void Output();

main(){
	Input();
	FindMaxPoints();
	Output();
}

void Input(){
	cin >> backets_number;
	for(int i = 0; i < backets_number; ++i)
		cin >> backets[i].TIME >> backets[i].POINTS;
	sort(backets, backets + backets_number);
	CreateTree();
}

void CreateTree(){
	remain_time[0] = backets[0].TIME;
	time_to_number[backets[0].TIME] = 0;
	for(int i = 1; i < backets_number; ++i){
		if(backets[i].TIME != backets[i - 1].TIME){
			remain_time[time_number++] = backets[i].TIME - backets[i - 1].TIME;
			time_to_number[backets[i].TIME] = time_number - 1;
		}
	}
}

bool cmp(const pair<int, int> &num1, const pair<int, int> &num2){
	if(num1.POINTS == num2.POINTS)
		return num1.TIME < num2.TIME;
	return num1.POINTS < num2.POINTS;
}

void FindMaxPoints(){
	int proper_time;
	sort(backets, backets + backets_number, cmp);
	for(int i = backets_number - 1; i >= 0; --i){
		FindProperTime(backets[i].TIME, backets[i].POINTS);
	}
}

void FindProperTime(int disappear_time, int point){
	for(int i = time_to_number[disappear_time]; i >= 0; --i){
		if(remain_time[i]){
			--remain_time[i];
			time_to_number[disappear_time] = i;
			points[i] = 1;
			result += point;
			break;
		}
	}
}

void Output(){
	cout << result;
}