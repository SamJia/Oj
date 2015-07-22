#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 10
int not_exist = 0, exist = 1, clock_table[SIZE], move_method[SIZE] = {0}, success_method[30][SIZE] = {not_exist};
int method_clock_dic[SIZE][6]={{0},{1,2,4},{1,2,3,5},{2,3,6},{1,4,5,7},{1,3,5,7,9},{3,5,6,9},{4,7,8},{5,7,8,9},{6,8,9}};

void InputAndInit(){
	freopen("input", "r", stdin);
	for(int i = 1; i < 10; ++i)
		cin >> clock_table[i];
}

int CountSteps(){
	int count_of_steps = 0;
	for(int i = 1; i < 10; ++i)
		count_of_steps += move_method[i];
	return(count_of_steps);
}

bool NowMethodIsGreater(int saved_method[]){
	for(int i = 1; i < 10; ++i)
		if(move_method[i] < saved_method[i])
			return(1);
		else if(move_method[i] > saved_method[i])
			return(0);
	return(0);
}

void Update(int save_pos[]){
	for(int i = 0; i < 10; ++i)
		save_pos[i] = move_method[i];
	save_pos[0] = exist;
}

int SaveMethod(){
	int count_of_steps = CountSteps();
	if(success_method[count_of_steps][0] == exist)
		if(NowMethodIsGreater(success_method[count_of_steps]))
			return(0);
	Update(success_method[count_of_steps]);
	return(0);
}

int CountChange(int dic_of_one_clock[]){
	int count = 0;
	for(int i = 0; dic_of_one_clock[i]; ++i)
		count += move_method[dic_of_one_clock[i]];
	count %= 4;
	count *= 3;
	return(count);
}

bool MethodIsRight(){
	for(int i = 1; i < 10; ++i){
		if(clock_table[i] + CountChange(method_clock_dic[i]) != 12)
			return(0);
	}
	return(1);
}

bool ChangeMethod(){
	move_method[9] += 1;
	for(int i = 9; move_method[i] == 4; --i){
		move_method[i - 1] += 1;
		move_method[i] = 0;
	}
	if(move_method[0])
		return(0);
	return(1);
}
void Output();
void FindMethod(){
	while(1){
		if(MethodIsRight()){
			SaveMethod();
			Output();
		}
		if(!ChangeMethod())
			break;
	}
}

void PrintSeveralTimes(int value, int times){
	for(; times; --times)
		cout << value << ' ';
}

void Output(){
	for(int i = 0; i < 28; ++i)
		if(success_method[i][0] == exist){
			for(int j = 1; j < 10; ++j)
				PrintSeveralTimes(j, success_method[i][j]);
			break;
		}
	cout << '\n';
}

main(){
	InputAndInit();
	FindMethod();
	// Output();
}