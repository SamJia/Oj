/****************************************
*                                       *
*     Copyright:Sam Jia                 *
*     email:sammailbox@126.com          *
*										*
*										*
****************************************/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define SIZE 32000
#define strength first
#define intelligence second
//--------------------------
int available_iq[SIZE] = {0}, tmp_available_iq[SIZE] = {0}, changed_number[SIZE] = {0};
pair<int, int> activity[410];
int number_of_activities = 0, how_many_changed = 0;
//--------------------------
void Input();
int FindMaxProduct();
void DoThisActivity(int number_of_this_time);
void ChangeMaxProduct();
int ReturnResult();
void Output(int);
//--------------------------

main(){
	Input();
	int result = FindMaxProduct();
	Output(result);
}

void Input(){
	for (int i = 0; i < SIZE; ++i)
		available_iq[i] = tmp_available_iq[i] = -30001;
	cin >> number_of_activities;
	int init_strength;
	cin >> init_strength;
	cin >> available_iq[init_strength];
	for(int i = 0; i < number_of_activities; ++i)
		cin >> activity[i].strength >> activity[i].intelligence;
}

int FindMaxProduct(){
	for(int i = 0; i < number_of_activities; ++i){
		DoThisActivity(i);
		ChangeMaxProduct();
	}
	return(ReturnResult());
}

void DoThisActivity(int number_of_this_time){
	int tmp_strength, tmp_iq;
	for(int i = 0; i < SIZE; ++i)
		if(available_iq[i] >= -30000){
			tmp_strength = i + activity[number_of_this_time].strength;
			tmp_iq = available_iq[i] + activity[number_of_this_time].intelligence;
			if(tmp_strength >= 0 && tmp_iq > tmp_available_iq[tmp_strength]){
				tmp_available_iq[tmp_strength] = tmp_iq;
				changed_number[how_many_changed++] = tmp_strength;
			}
		}
}

void ChangeMaxProduct(){
	for(int i = 0; i < how_many_changed; ++i)
		available_iq[changed_number[i]] = tmp_available_iq[changed_number[i]];
	how_many_changed = 0;
}

int ReturnResult(){
	int max_product = 0;
	for(int i = 1; i < SIZE; ++i)
		if(available_iq[i] > 70)
			max_product = max(max_product, i * available_iq[i]);
	return(max_product);
}

void Output(int result){
	if(result)
		cout << result;
	else
		cout << "Death";
}