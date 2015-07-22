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
//--------------------------
int number_of_fruits = 0, fruits[10010] = {0};
// ifstream fin(".txt");
//--------------------------
void Input();
int FindMinStrength();
void Output(int min_strength);
//--------------------------

main(){
	Input();
	int min_strength = FindMinStrength();
	Output(min_strength);
}

void Input(){
	cin >> number_of_fruits;
	for(int i = 0; i < number_of_fruits; ++i)
		cin >> fruits[i];
	sort(fruits, fruits + number_of_fruits);
}

int FindMinStrength(){
	int min_strength = 0, tmp_number;
	for(int i = 1; i < number_of_fruits; ++i){
		min_strength += fruits[i] += fruits[i - 1];
		for(int j = i + 1; j < number_of_fruits && fruits[j] < fruits[j - 1]; ++j){
			tmp_number = fruits[j];
			fruits[j] = fruits[j - 1];
			fruits[j - 1] = tmp_number;
		}
	}
	return(min_strength);
}

void Output(int min_strength){
	cout << min_strength;
}