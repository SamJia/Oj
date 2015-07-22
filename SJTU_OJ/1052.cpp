#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE1 110
#define SIZE2 210

int sets[SIZE1][SIZE2], numbers[SIZE1], set_number, command_number, para1, para2;
char command;

void InputAndInit();
void Compute();
void Output();

int main(){
	InputAndInit();
	Compute();
	Output();
	return 0;
}

void InputAndInit(){
	cin >> set_number;
	for(int i = 0; i < set_number; ++i)
		cin >> numbers[i];
	for(int i = 0; i < set_number; ++i){
		for(int j = 0; j < numbers[i]; ++j)
			cin >> sets[i][j];
		sort(sets[i], sets[i] + numbers[i]);
		int new_num = min(1, numbers[i]);
		for(int j = new_num; j < numbers[i]; ++j)
			if(sets[i][j] != sets[i][j-1])
				sets[i][new_num++] = sets[i][j];
		numbers[i] = new_num;
	}
}

void Compute(){
	cin >> command_number;
	for(int i = 0; i < command_number; ++i){
		cin >> command >> para1 >> para2;
		para1--;
		para2--;
		int new_num = 0, pos1 = 0, pos2 = 0;
		if(command == '+'){
			while(pos1 < numbers[para1] || pos2 < numbers[para2]){
				if(pos1 >= numbers[para1])
						sets[set_number][new_num++] = sets[para2][pos2++];
				else if(pos2 >= numbers[para2])
						sets[set_number][new_num++] = sets[para1][pos1++];
				else{
					if(sets[para1][pos1] < sets[para2][pos2])
						sets[set_number][new_num++] = sets[para1][pos1++];
					else if(sets[para2][pos2] < sets[para1][pos1])
						sets[set_number][new_num++] = sets[para2][pos2++];
					else{
						sets[set_number][new_num++] = sets[para1][pos1++];
						pos2++;
					}
				}
			}
			for(int j = 0; j < new_num; ++j)
				sets[para1][j] = sets[set_number][j];
			numbers[para1] = new_num;
		}
		else if(command == '-'){
			while(pos1 < numbers[para1] || pos2 < numbers[para2]){
				if(pos1 >= numbers[para1])
						sets[para1][new_num++] = sets[para2][pos2++];
				else if(pos2 >= numbers[para2])
						sets[para1][new_num++] = sets[para1][pos1++];
				else{
					if(sets[para1][pos1] < sets[para2][pos2])
						sets[para1][new_num++] = sets[para1][pos1++];
					else if(sets[para2][pos2] < sets[para1][pos1])
						sets[para1][new_num++] = sets[para2][pos2++];
					else{
						pos1++;
						pos2++;
					}
				}
			}
			numbers[para1] = new_num;
		}
		else{
			while(pos1 < numbers[para1] && pos2 < numbers[para2]){
				if(sets[para1][pos1] < sets[para2][pos2])
					pos1++;
				else if(sets[para2][pos2] < sets[para1][pos1])
					pos2++;
				else{
					sets[para1][new_num++] = sets[para1][pos1++];
					pos2++;
				}
			}
			numbers[para1] = new_num;
		}
	}
}

void Output(){
	for(int i = 0; i < set_number; ++i){
		for(int j = 0; j < numbers[i]; ++j)
			cout << sets[i][j] << ' ';
		cout << '\n';
	}
}