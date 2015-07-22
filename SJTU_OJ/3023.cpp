/****************************************
*                                       *
*     Coperight:Sam Jia                 *
*     email:sammailbox@126.com          *
*										*
*										*
****************************************/

#include <iostream>
#include <fstream>
using namespace std;
//--------------------------
int number_of_people = 0;
int heigth_of_people[110] = {0}, max_increase_found[110] = {0}, max_decrease_found[110] = {0};
//--------------------------
void Input();
void FindMaxIncrease();
void FindMaxDecrease();
int FindMaxPeopleRemain();
void Output(int);
//--------------------------

main(){
	Input();
	FindMaxIncrease();
	FindMaxDecrease();
	int max_people_remain = FindMaxPeopleRemain();
	Output(max_people_remain);
}

void Input(){
	cin >> number_of_people;
	for(int i = 0; i < number_of_people; ++i)
		cin >> heigth_of_people[i];
}

void FindMaxIncrease(){
	int max_number = 0;
	max_increase_found[0] = 1;
	for(int i = 0; i < number_of_people; ++i){
		max_number = 0;
		for(int j = 0; j < i; ++j)
			if(heigth_of_people[i] > heigth_of_people[j])
				max_number = max(max_number, max_increase_found[j]);
		max_increase_found[i] = max_number + 1;
	}
}

void FindMaxDecrease(){
	int max_number = 0;
	max_decrease_found[number_of_people - 1] = 1;
	for(int i = number_of_people - 1; i >= 0; --i){
		max_number = 0;
		for(int j = number_of_people - 1; j > i; --j)
			if(heigth_of_people[i] > heigth_of_people[j])
				max_number = max(max_number, max_decrease_found[j]);
		max_decrease_found[i] = max_number + 1;
	}
}

int FindMaxPeopleRemain(){
	int max_people_remain = 0, tmp_max = 0;
	for(int i = 0; i < number_of_people; ++i){
		tmp_max = max_increase_found[i] + max_decrease_found[i] - 1;
		max_people_remain = max(max_people_remain, tmp_max);
	}
	return(max_people_remain);
}

void Output(int max_people_remain){
	cout << number_of_people - max_people_remain;
}