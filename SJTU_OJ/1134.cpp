#include <iostream>
using namespace std;
#define sleeped first
#define conscious second

pair<int, int> sleep_at_first[5010] = {}, not_at_first[5010] = {};
int total_time, sleep_time, effect_list[5010];

void Input();
int FindMaxeffect();
void OperateFirst(int pos_to_decided);
void OperateNotFist(int pos_to_decided);
void Output(int result);

main(){
	Input();
	int result = FindMaxeffect();
	Output(result);
}

void Input(){
	cin >> total_time >> sleep_time;
	for(int i = 0; i < total_time; ++i)
		cin >> effect_list[i];
}

int FindMaxeffect(){
	if(total_time == sleep_time){
		int result = 0, min_effect = 10000000;
		for(int i = 0; i < total_time; ++i){
			result += effect_list[i];
			min_effect = min(min_effect, effect_list[i]);
		}
		return (result - min_effect);
	}
	for(int i = 1; i < total_time; ++i){
		OperateFirst(i);
		OperateNotFist(i);
	}
	int result = max(sleep_at_first[sleep_time].sleeped + effect_list[0], sleep_at_first[sleep_time].conscious);
	result = max(result, not_at_first[sleep_time].sleeped);
	result = max(result, not_at_first[sleep_time].conscious);
	return result;
}

void OperateFirst(int pos_to_decided){
	int end_pos = max(sleep_time - total_time + pos_to_decided, 1);
	for(int i = min(pos_to_decided + 1, sleep_time); i > end_pos; --i){
		sleep_at_first[i].conscious = max(sleep_at_first[i].conscious, sleep_at_first[i].sleeped);
		sleep_at_first[i].sleeped = max(sleep_at_first[i - 1].conscious, sleep_at_first[i - 1].sleeped + effect_list[pos_to_decided]);
	}
	sleep_at_first[1].sleeped = -10000000;
}

void OperateNotFist(int pos_to_decided){
	int end_pos = max(sleep_time - total_time + pos_to_decided, 1);
	for(int i = min(pos_to_decided, sleep_time); i > end_pos; --i){
		not_at_first[i].conscious = max(not_at_first[i].conscious, not_at_first[i].sleeped);
		not_at_first[i].sleeped = max(not_at_first[i - 1].conscious, not_at_first[i - 1].sleeped + effect_list[pos_to_decided]);
	}
}

void Output(int result){
	cout << result;
}