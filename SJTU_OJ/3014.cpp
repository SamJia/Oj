#include <iostream>
#include <algorithm>
#include <cmath>
#define SIZE 1010
using namespace std;

int pair_number, min_weight_difference = 0;
int men[SIZE] = {0}, women[SIZE] = {0};

void Input();
void FindMinDifference();
void Output();

main(){
	Input();
	FindMinDifference();
	Output();
}

void Input(){
	cin >> pair_number;
	for(int i = 0; i < pair_number; ++i)
		cin >> men[i];
	for(int i = 0; i < pair_number; ++i)
		cin >> women[i];
}

void FindMinDifference(){
	sort(men, men + pair_number);
	sort(women, women + pair_number);
	for(int i = 0; i < pair_number; ++i)
		min_weight_difference += abs(men[i] - women[i]);
}

void Output(){
	cout << min_weight_difference;
}