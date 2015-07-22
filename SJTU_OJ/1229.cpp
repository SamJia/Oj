#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 100100

struct Unit{
	bool number_;
	Unit *next_;
	Unit(bool number = 0, Unit *p = NULL) : number_(number), next_(p){}
};

int total_number, numbers[SIZE];
Unit *state[SIZE][4] = {};

void InputAndInit();
void FindMines();
bool Check(int pos, int num1, int num2, int num3);
void Output();

main(){
	InputAndInit();
	FindMines();
	Output();
}

void InputAndInit(){
	cin >> total_number;
	char tmp;
	for(int i = total_number - 1; i >= 0; --i){
		cin >> tmp;
		numbers[i] = tmp - '0';
	}
	if(total_number == 1){
		cout << (numbers[0] != 0) << '\n' << (numbers[0] != 0);
		exit(0);
	}
	for(int i = 0; i < 4; ++i)
		if(Check(total_number - 2, i / 2, i % 2, 0)){
			state[total_number - 2][i] = new Unit(i / 2, new Unit(i % 2));
		}
}

void FindMines(){
	for(int i = total_number - 3; i >= 0; --i){
		for(int j = 3; j >= 0; --j)
			if(state[i + 1][j % 2 * 2 + 1] && Check(i, j / 2, j % 2, 1))
				state[i][j] = new Unit(j / 2, state[i + 1][j % 2 * 2 + 1]);
			else if(state[i + 1][j % 2 * 2] && Check(i, j / 2, j % 2, 0))
				state[i][j] = new Unit(j / 2, state[i + 1][j % 2 * 2]);
	}
}

bool Check(int pos, int num1, int num2, int num3){
	if(pos)
		if(!numbers[pos - 1] && num1 || numbers[pos - 1] == 3 && !num1)
			return 0;
	if(numbers[pos] != -6)
		if(numbers[pos] < num1 + num2 || numbers[pos] - num1 - num2 > 1)
			return 0;
	if(numbers[pos + 1] != -6)
		if(numbers[pos + 1] != num1 + num2 + num3)
			return 0;
	return 1;
}

void Output(){
	int i;
	for(i = 3; i >= 0 && !state[0][i]; --i);
	int length = 0;
	char output_data[SIZE] = {};
	for(Unit *p = state[0][i]; p; p = p->next_){
		output_data[--total_number] = p->number_ + '0';
		if(p->number_)
			++length;
	}
	cout << length << '\n' << output_data;
}