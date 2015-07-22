#include <iostream>
#include <fstream>
using namespace std;

int total_number = 0, number_list[1010] = {}, saved_date[1010] = {};

void Input();
int FindMaxNumber();
int ReturnMaxNumber();
void Output(int max_number);

main(){
	Input();
	int max_number = FindMaxNumber();
	Output(max_number);
}

void Input(){
	cin >> total_number;
	for(int i = 1; i <= total_number; ++i)
		cin >> number_list[i];
}

int FindMaxNumber(){
	for(int i = 1; i <= total_number; ++i)
		for(int j = i; j > 0; --j)
			saved_date[j] = max(saved_date[j], saved_date[j - 1] + (number_list[i] == j));
	return(ReturnMaxNumber());
}

int ReturnMaxNumber(){
	int max_number = 0;
	for(int i = 1; i <= total_number; ++i)
		max_number = max(max_number, saved_date[i]);
	return(max_number);
}

void Output(int max_number){
	cout << max_number;
}